#include "myBigChar.h"

int bc_printA (char * str) {
	printf("\E(0%s", str);
	printf("\E(B");

    return EXIT_SUCCESS;
}

int mt_clrsrc(void) {
    printf("\033c");

    return EXIT_SUCCESS;
}

int mt_gotoXY (int x, int y) {
    printf("\033[%d;%dH", x, y);

    return EXIT_SUCCESS;
}

int bc_box(int x1, int y1, int x2, int y2) {
  mt_clrsrc();

  mt_gotoXY(y1, x1);
  for(int i = 0; i < x2 - x1; i++) {
    if (i == 0) {
      printf("\u250C");
    } else {
      bc_printA("\u2500");
    }
  }
  bc_printA("\u2510");

  for(int i = 0; i < y2-y1; i++) {
    mt_gotoXY(y1+i+2, x1);
    bc_printA("\u2502");
    mt_gotoXY(y1+i+2, x2+1);
    bc_printA("\u2502");
  }

  mt_gotoXY(y2+1, x1);
  bc_printA("\u2514");
  for(int i = 0; i < x2 - x1 - 1; i++) {
    bc_printA("\u2500");
  }
  bc_printA("\u2518\n");

  return EXIT_SUCCESS;
}

int main() {
  bc_box(0, 0, 60, 60);

  printf(" \u250C");
  bc_printA("\u2510");
  bc_printA("\u2500");
  bc_printA("\u2518");
  bc_printA("\u2514");
  bc_printA("\u2502\n");
}
