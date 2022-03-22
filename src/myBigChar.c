#include "myBigChar.h"

int bc_printA (char * str) {
	printf("\E(0%s", str);
	printf("\E(B");

    return EXIT_SUCCESS;
}

int bc_box(int x1, int y1, int x2, int y2) {
  mt_gotoXY(y1, x1); //upper
  printf("\u250C");
  for(int i = 0; i < x2-x1; i++)
  {
   bc_printA("\u2500");
  }
  bc_printA("\u2510");

  for(int i = 0; i < y2-y1; i++) //leftright
  {
    mt_gotoXY(y1+i+1, x1);
    bc_printA("\u2502");
    mt_gotoXY(y1+i+1, x2+1);
    bc_printA("\u2502");
  }

  mt_gotoXY(y2+1, x1); //lower
  bc_printA("\u2514");
  for(int i = 0; i < x2-x1; i++)
  {
    bc_printA("\u2500");
  }
  bc_printA("\u2518");
}

int main() {
    char ar_ch[10] = "abcdefghij";
    bc_printA(&ar_ch);
}
