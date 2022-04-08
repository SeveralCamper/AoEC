#ifndef MY_BIG_CHAR_H_
#define MY_BIG_CHAR_H_

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/time.h>

#include "myTerm.h"

struct itimerval nval, oval;

/*  2-ое задание

infocmp:

enter_alt_charset_mode - "\E[11m",

exit_alt_charset_mode - "\E[10m",

acs_chars - http://citforum.ru/operating_systems/manpages/TERMINFO.4.shtml

"\u250C"  -  левый верхний угол
"\u2510"  -  правый верхний угол
"\u2500"  -  горизонтальная плоска
"\u2518"  -  правый нижний угол
"\u2514"  -  левый верхний угол
"\u2502"  -  вертикальная полоска
"\u2588"  -  закрашеный прямоугольник

3-ое задание

echo -e "\033c"  -  очищает экран;

echo -e "\033[5;10H"  -  перемещает курсор на 5 символ 10 строки;

echo -e "\033[10;5H\u250C\u2500\u2500\u2500\u2500\u2500\u2500\u2510"
echo -e "\033[11;5H\u2502\u2588\u2588\u2588\u2588\u2588 \u2502"
echo -e "\033[12;5H\u2502     \u2588\u2502"
echo -e "\033[13;5H\u2502     \u2588\u2502"
echo -e "\033[14;5H\u2502\u2588\u2588\u2588\u2588\u2588 \u2502"
echo -e "\033[15;5H\u2502     \u2588\u2502"
echo -e "\033[16;5H\u2502     \u2588\u2502"
echo -e "\033[17;5H\u2502\u2588\u2588\u2588\u2588\u2588 \u2502"
echo -e "\033[18;5H\u2514\u2500\u2500\u2500\u2500\u2500\u2500\u2518"  -  выводит цифру 3

*/

int bc_printA (char* str);
int bc_box(int x1, int y1, int x2, int y2);
int bc_bigcharwrite(int fd, int * big, int count);
int bc_setbigcharpos(int *big, int x, int y, int value);
int bc_getbigcharpos(int *big, int x, int y, int *value);
int bc_bigcharread(int fd, int * big, int need_count, int *count);
int bc_printbigchar(int* p, int x, int y, colors_t clolor, colors_back_t clolor_back);

void print_keys();
void signalhandler(int signo);
void bc_bigcharLayout(int*, int);
void parse_el(int element, int current, int accum);
void print_info(int accumulator, int instruction_counter, char flag);
void initialize_management_console(int *buf_array, int number, int accumulator, int instruction_counter, int lab, char flag);

#endif  //  MY_BIG_CHAR_H_
