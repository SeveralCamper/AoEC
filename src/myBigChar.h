#ifndef MY_BIG_CHAR_H_
#define MY_BIG_CHAR_H_

#include "myTerm.h"

/*  2-ое задание

infocmp:

enter_alt_charset_mode - "\E[11m",

exit_alt_charset_mode - "\E[10m",

acs_chars - http://citforum.ru/operating_systems/manpages/TERMINFO.4.shtml

3-ое задание



*/

int bc_printA (char* str);
int bc_box(int x1, int y1, int x2, int y2);
int bc_bigcharwrite(int fd, int * big, int count);
int bc_setbigcharpos(int *big, int x, int y, int value);
int bc_getbigcharpos(int *big, int x, int y, int *value);
int bc_bigcharread(int fd, int * big, int need_count, int *count);
int bc_printbigchar(int* p, int x, int y, colors_t clolor, colors_back_t clolor_back);

void bc_bigcharLayout(int*, int);

#endif  //  MY_BIG_CHAR_H_