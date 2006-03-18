/*
 *  fs_iso.c - a non-implementation for the ISO9660 filesystem
 *
 *  Copyright (C) 1999 Benjamin Herrenschnidt
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

#include "ctype.h"
#include "types.h"
#include "stddef.h"
#include "file.h"
#include "prom.h"
#include "string.h"
#include "partition.h"
#include "fs.h"
#include "errors.h"

static int iso_open(	struct boot_file_t*	file,
			const char*		dev_name,
			struct partition_t*	part,
			const char*		file_name);
static int iso_read(	struct boot_file_t*	file,
			unsigned int		size,
			void*			buffer);
static int iso_seek(	struct boot_file_t*	file,
			unsigned long long	newpos);
static int iso_close(	struct boot_file_t*	file);

struct fs_t iso_filesystem =
{
	.name = "iso9660",
	.open = iso_open,
	.read = iso_read,
	.seek = iso_seek,
	.close = iso_close
};

static int
iso_open(	struct boot_file_t*	file,
		const char*		dev_name,
		struct partition_t*	part,
		const char*		file_name)
{
     return FILE_ERR_BAD_FSYS;
}

static int
iso_read(	struct boot_file_t*	file,
		unsigned int		size,
		void*			buffer)
{
     return FILE_ERR_BAD_FSYS;
}

static int
iso_seek(	struct boot_file_t*	file,
		unsigned long long	newpos)
{
     return FILE_ERR_BAD_FSYS;
}

static int
iso_close(	struct boot_file_t*	file)
{
     return 0;
}

/* 
 * Local variables:
 * c-file-style: "k&r"
 * c-basic-offset: 5
 * End:
 */
