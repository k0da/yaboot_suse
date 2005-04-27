/*
 *  elfextract.c - Extract the loadable program segment from an elf file.
 *
 *  Copyright 1996 Paul Mackerras.
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

#include <stdio.h>
#include <linux/elf.h>

FILE *fi, *fo;
char *ni, *no;
char buf[65536];

void
rd(void *buf, int len)
{
    int nr;

    nr = fread(buf, 1, len, fi);
    if (nr == len)
	return;
    if (ferror(fi))
	fprintf(stderr, "%s: read error\n", ni);
    else
	fprintf(stderr, "%s: short file\n", ni);
    exit(1);
}

int
main(int ac, char **av)
{
    unsigned nb, len, i;
    Elf32_Ehdr eh;
    Elf32_Phdr ph;
    unsigned long phoffset = 0;
    unsigned long phsize = 0;
    unsigned long prevaddr = 0;

    if (ac > 3 || (ac > 1 && av[1][0] == '-')) {
	fprintf(stderr, "Usage: %s [elf-file [image-file]]\n", av[0]);
	exit(0);
    }

    fi = stdin;
    ni = "(stdin)";
    fo = stdout;
    no = "(stdout)";

    if (ac > 1) {
	ni = av[1];
	fi = fopen(ni, "rb");
	if (fi == NULL) {
	    perror(ni);
	    exit(1);
	}
    }

    rd(&eh, sizeof(eh));
    if (eh.e_ident[EI_MAG0] != ELFMAG0
	|| eh.e_ident[EI_MAG1] != ELFMAG1
	|| eh.e_ident[EI_MAG2] != ELFMAG2
	|| eh.e_ident[EI_MAG3] != ELFMAG3) {
	fprintf(stderr, "%s: not an ELF file\n", ni);
	exit(1);
    }

    fseek(fi, eh.e_phoff, 0);
    phsize = 0;
    for (i = 0; i < eh.e_phnum; ++i) {
	rd(&ph, sizeof(ph));
	if (ph.p_type != PT_LOAD)
	    continue;
	if (phsize == 0 || prevaddr == 0) {
	    phoffset = ph.p_offset;
	    phsize = ph.p_filesz;
	} else
	    phsize = ph.p_offset + ph.p_filesz - phoffset;
	prevaddr = ph.p_vaddr;
    }
    if (phsize == 0) {
	fprintf(stderr, "%s: doesn't have a loadable segment\n", ni);
	exit(1);
    }

    if (ac > 2) {
	no = av[2];
	fo = fopen(no, "wb");
	if (fo == NULL) {
	    perror(no);
	    exit(1);
	}
    }

    fseek(fi, phoffset, 0);
    for (len = phsize; len != 0; len -= nb) {
	nb = len;
	if (nb > sizeof(buf))
	    nb = sizeof(buf);
	rd(buf, nb);
	if (fwrite(buf, 1, nb, fo) != nb) {
	    fprintf(stderr, "%s: write error\n", no);
	    exit(1);
	}
    }

    fclose(fo);
    fclose(fi);
    exit(0);
}
