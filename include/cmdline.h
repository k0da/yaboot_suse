/*
 *  cmdline.h - Prompt handling
 *
 *  Copyright (C) 2001 Ethan Benson
 *
 *  Copyright (C) 1999 Benjamin Herrenschmidt
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

#ifndef CMDLINE_H
#define CMDLINE_H

#include <types.h>

extern char *cmdlineinit(void);
extern char *cmdlineedit(char *buf, void (*func) (const char *p));
extern char *passwdinit(void);
extern char *passwordedit(char *buf);

static inline int char_is_newline(int c)
{
	return c == '\n' || c == '\r';
}
static inline int char_is_backspace(int c)
{
	return c == '\b' || c == 0x7f;
}
static inline int char_is_tab(int c)
{
	return c == '\t';
}
static inline int char_to_ascii(int c)
{
	return c > 0x7f ? 0 : c < ' ' ? 0 : c;
}
#endif
