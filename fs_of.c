/* OpenFirmware-based filesystem
   
   Copyright (C) 1999 Benjamin Herrenschmidt
   
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

   BrokenFirmware cannot "read" from the network. We use tftp "load" method
   for network boot for now, we may provide our own NFS implementation in
   a later version. That means that we allocate a huge block of memory for
   the entire file before loading it. We use the location where the kernel puts
   RTAS, it's not used by the bootloader and if freed when the kernel is booted.
   This will have to be changed if we plan to instanciate RTAS in the bootloader
   itself
   
*/

#include "ctype.h"
#include "types.h"
#include "stddef.h"
#include "stdlib.h"
#include "file.h"
#include "prom.h"
#include "string.h"
#include "partition.h"
#include "fs.h"


#define LOAD_BUFFER_POS		0x600000
#define LOAD_BUFFER_SIZE	0x400000

static int of_open(	struct boot_file_t*	file,
			const char*		dev_name,
			struct partition_t*	part,
			const char*		file_name);
static int of_read(	struct boot_file_t*	file,
			unsigned int		size,
			void*			buffer);
static int of_seek(	struct boot_file_t*	file,
			unsigned int		newpos);
static int of_close(	struct boot_file_t*	file);


static int of_net_open(		struct boot_file_t*	file,
				const char*		dev_name,
				struct partition_t*	part,
				const char*		file_name);
static int of_net_read(		struct boot_file_t*	file,
				unsigned int		size,
				void*			buffer);
static int of_net_seek(		struct boot_file_t*	file,
				unsigned int		newpos);


struct fs_t of_filesystem =
{
    "built-in",
    of_open,
    of_read,
    of_seek,
    of_close
};

struct fs_t of_net_filesystem =
{
    "built-in network",
    of_net_open,
    of_net_read,
    of_net_seek,
    of_close
};



static int
of_open(	struct boot_file_t*	file,
		const char*		dev_name,
		struct partition_t*	part,
		const char*		file_name)
{
	static char	buffer[1024];
	
#if DEBUG
	prom_printf("of_open(dev:%s, part: 0x%08lx, name:%s\n",
		dev_name, part, file_name);
#endif
	strncpy(buffer, dev_name, 1000);
	strcat(buffer, ":");
	if (part) {
		char pn[3];
		sprintf(pn, "%02d", part->part_number);
		strcat(buffer, pn);
	}
	if (file_name && strlen(file_name)) {
		if (part)
			strcat(buffer, ",");
		strcat(buffer, file_name);
	}
			
#if DEBUG
	prom_printf(" -> prom_open<%s>...\n", buffer);
#endif
	file->of_device = prom_open(buffer);
#if DEBUG
	prom_printf(" -> %08lx\n", file->of_device);
#endif
	file->pos = 0;
	file->buffer = NULL;
	if ((file->of_device == PROM_INVALID_HANDLE) || (file->of_device == 0))
		return FILE_ERR_NOTFOUND;
	
	return FILE_ERR_OK;
}

static int
of_net_open(	struct boot_file_t*	file,
		const char*		dev_name,
		struct partition_t*	part,
		const char*		file_name)
{
	static char	buffer[1024];
	
#if DEBUG
	prom_printf("of_net_open(dev:%s, part: 0x%08lx, name:%s\n",
		dev_name, part, file_name);
#endif
	strncpy(buffer, dev_name, 1000);
	strcat(buffer, ":0");
	if (file_name && strlen(file_name)) {
		strcat(buffer, ",");
		strcat(buffer, file_name);
	}
			
#if DEBUG
	prom_printf(" -> prom_open<%s>...\n", buffer);
#endif
	file->of_device = prom_open(buffer);
#if DEBUG
	prom_printf(" -> %08lx\n", file->of_device);
#endif
	file->pos = 0;
	if ((file->of_device == PROM_INVALID_HANDLE) || (file->of_device == 0))
		return FILE_ERR_NOTFOUND;
	
	file->buffer = prom_claim((void *)LOAD_BUFFER_POS, LOAD_BUFFER_SIZE, 0);
	if (file->buffer == (void *)-1) {
		prom_printf("Can't claim memory for TFTP download\n");
		prom_close(file->of_device);
		return FILE_ERR_NOTFOUND;
	}
	memset(file->buffer, 0, LOAD_BUFFER_SIZE);
#if DEBUG
	prom_printf("TFP...\n");
#endif
	file->len = prom_loadmethod(file->of_device, file->buffer);
#if DEBUG
	prom_printf("result: %d\n", file->len);
#endif
	
	return FILE_ERR_OK;
}

static int
of_read(	struct boot_file_t*	file,
		unsigned int		size,
		void*			buffer)
{
	unsigned int count;
	
	count = prom_read(file->of_device, buffer, size);
	file->pos += count;
	return count;
}

static int
of_net_read(	struct boot_file_t*	file,
		unsigned int		size,
		void*			buffer)
{
	unsigned int count, av;
	
	av = file->len - file->pos;
	count = size > av ? av : size; 
	memcpy(buffer, file->buffer + file->pos, count);
	file->pos += count;
	return count;
}

static int
of_seek(	struct boot_file_t*	file,
		unsigned int		newpos)
{
	if (prom_seek(file->of_device, newpos)) {
		file->pos = newpos;
		return FILE_ERR_OK;
	}
		
	return FILE_CANT_SEEK;
}

static int
of_net_seek(	struct boot_file_t*	file,
		unsigned int		newpos)
{
	file->pos = (newpos > file->len) ? file->len : newpos;
	return FILE_ERR_OK;
}

static int
of_close(	struct boot_file_t*	file)
{
#if DEBUG
	prom_printf("of_close<@0x%08lx>...\n", file->of_device);
#endif
	if (file->buffer) {
		prom_release(file->buffer, LOAD_BUFFER_SIZE);
	}
	prom_close(file->of_device);
	
	return 0;
}

