#ifndef MY_TERM_H_
#define MY_TERM_H_

#include "mySimpleComputer.h"

/*  2-ое задание

infocmp:

"\033c"  -  Очищает экран и помещает курсор в левый верхний угол (строка 0, позиция 0) (clear_screen)

"\033[l;cH"  -  Перемещает курсор в строку l и позицию c (cursor_address)

Командная строка и внешний вид терминала определяются переменной среды PS1. Согласно странице man Bash, 
PS1 представляет собой основную строку, которая отображается, когда оболочка готова к чтению команды.

Чтобы стало яснее, давайте выведем текущее содержимое PS1 в нашей системе (в вашем случае результат может выглядеть иначе):

\[\e]0;\u@\h: \w\a\]${debian_chroot:+($debian_chroot)}\[\033[01;32m\]\u@\h\[\033[00m\]:\[\033[01;34m\]\w\[\033[00m\]\$

Фактически, мы можем настроить три аспекта:

Формат текста: 0 - нормальный, 1 - жирный, 2 - тусклый, 3 - курсив, 4 - подчеркнутый

Цвет текста: заданы в enum colors

Фон текста: заданы в enum colors_back

PS1="\e[A;B;Cm[\u@\h \W]$" -  Задание цвета последующих выводимых символов (set_a_background),
где A, B, C - параметры цвета букв, цвета фона и формата в любом порядке;
 
PS1="\e[A;B;Cm[\u@\h \W]$" -  Определение цвета фона для последующих выводимых символов (set_a_foreground),
где A, B, C  -  параметры цвета букв, цвета фона и формата в любом порядке;

"\033[?25l"  -   Скрытие курсора (cursor_invisible).

"\033[?25h"  -  Восстановление курсора (cursor_visible).


3-ое задание

echo -e "\033c"  -  очищает экран;

echo -e "\033[5;10H \e[31;40;1m$HOSTNAME Misha\e[m"  -  выводит в пятой строке, начиная с 10 символа Ваше имя красными буквами на черном фоне;

echo -e "\033[6;8H \e[32;47;1mIP-014\e[m"  -  в шестой строке, начиная с 8 символа Вашу группу зеленым цветом на белом фоне;

echo -e "\033[10;1H \e[m"  -  перемещает курсор в 10 строку, 1 символ и возвращает настройки цвета в значения «по
умолчанию».

*/

typedef enum {
  BLACK = 30, RED, GREEN, YELLOW, BLUE, PURPLE, TURQUOISE, WHITE, GRAY, NOTHING
} colors_t;

typedef enum {
  BLACK_B = 40, RED_B, GREEN_B, YELLOW_B, BLUE_B, PURPLE_B, TURQUOISE_B, WHITE_B, GRAY_B, NOTHING_B
} colors_back_t;

int mt_clrsrc(void);
int mt_gotoXY (int x, int y);
int mt_setfgcolor (colors_t color);
int mt_setbgcolor (colors_back_t color_back);
int mt_getscreensize (int * rows, int * cols);

#endif  //  MY_TERM_H_
