#include "myTerm.h"

int mt_clrsrc(void) {
    printf("\33c\e[3J");

    return EXIT_SUCCESS;
}

int mt_gotoXY (int x, int y) {
    printf("\033[%d;%dH", x, y);

    return EXIT_SUCCESS;
}

int mt_setfgcolor (colors_t color) {
    printf("\e[%dm", color);

    return EXIT_SUCCESS;
}

int mt_setbgcolor (colors_back_t color_back) {
    printf("\e[%dm", color_back);

    return EXIT_SUCCESS;
}

int mt_getscreensize (int * rows, int * cols) {
    printf("getsize -s %d %d", *rows, *cols);
    
    return EXIT_SUCCESS;
}

/* int main() {
    int W, H;
    W = 80;
    H = 10;
    printf("hehe");
    mt_clrsrc();
    mt_gotoXY(20,10);
    printf("hehe");

    mt_setfgcolor(GREEN);
    printf("hehe");
    mt_setfgcolor(WHITE_B);
    printf("hehe");

    mt_getscreensize(&W,&H);

    return 0;
} */