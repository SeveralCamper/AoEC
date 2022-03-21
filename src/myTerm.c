#include "myTerm.h"

int mt_clrsrc(void) {
    printf("\033c");
    return NORMAL_VALUE_S;
}

int mt_gotoXY (int line, int column) {
    printf("\033[%d;%dH", line, column);
    return NORMAL_VALUE_S;
}

int mt_setfgcolor (colors_t color) {
    printf("\e[%dm", color);
    return NORMAL_VALUE_S;
}

int mt_setbgcolor (colors_back_t color_back) {
    printf("\e[%dm", color_back);
    return NORMAL_VALUE_S;
}

int mt_getscreensize (int * rows, int * cols) {

}

int main() {
    printf("hehe");
    mt_clrsrc();
    mt_gotoXY(20,10);
    printf("hehe");

    mt_setfgcolor(GREEN);
    printf("hehe");
    mt_setfgcolor(WHITE_B);
    printf("hehe");

    return 0;
}