#include "myBigChar.h"

int bc_printA (char * str) {
  int exit_flag = EXIT_SUCCESS;

	printf("\E(0%s", str);
	printf("\E(B");

  return exit_flag;
}

int bc_box(int x1, int y1, int x2, int y2) {
  int exit_falg = EXIT_SUCCESS;

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

  return exit_falg;
}

void bc_bigcharLayout(int *A, int number) {
  number = number % 16;
  switch(number) {
    case 0:
      A[0] = 4291019715;
      A[1] = 3284386815;
      break;
    case 1:
      A[0] = 3233857728;
      A[1] = 3233870048;
      break;
    case 2:
      A[0] = 4278586392;
      A[1] = 811647868;
      break;
    case 3:
      A[0] = 1009000496;
      A[1] = 539239484;
      break;
    case 4:
      A[0] = 538976288;
      A[1] = 1009001508;
      break;
    case 5:
      A[0] = 1008738336;
      A[1] = 1006896188;
      break;
    case 6:
      A[0] = 1009001532;
      A[1] = 67372092;
      break;
    case 7:
      A[0] = 538976368;
      A[1] = 538976316;
      break;
    case 8:
      A[0] = 405021732;
      A[1] = 405021720;
      break;
    case 9:
      A[0] = 1009000480;
      A[1] = 1009001532;
      break;
    case 10: //a
      A[0] = 405021752;
      A[1] = 538977340;
      break;
    case 11: //b
      A[0] = 405021724;
      A[1] = 67372036;
      break;
    case 12: //c
      A[0] = 405013508;
      A[1] = 67380248;
      break;
    case 13: //d
      A[0] = 405021752;
      A[1] = 538976288;
      break;
    case 14: //e
      A[0] = 405013508;
      A[1] = 1009001496;
      break;
    case 15: //f
      A[0] = 67372046;
      A[1] = 67379349;
      break;
    default:
      return;
    }
}

int bc_printbigchar(int *A, int x, int y, colors_t clolor, colors_back_t color_back) {
  int exit_flag = EXIT_SUCCESS;

  mt_gotoXY(x, y);
  mt_setbgcolor(clolor);
  mt_setfgcolor(color_back);
  int k = 1;
  for(int i = 0; i < 8; i++) {
    for(int j = 0; j < 8; j++) { 
      if (i == 4) {
        k = 0;
      }

      if (A[k] % 2) {
        bc_printA("\u2588");
      } else {
        bc_printA(" ");
      }
      A[k] = A[k] >> 1;
      mt_gotoXY(x, y+j+1);
    }
    x++;
    mt_gotoXY(x, y);
  }
  mt_setbgcolor(9);
  mt_setfgcolor(9);

  mt_gotoXY(x + 1, 0);

  return exit_flag;
}

int bc_setbigcharpos(int * big, int x, int y, int value) {
  int exit_flag = EXIT_FAILURE;

  if (value == 1) {
      big[y/5] |= 1 << ((y - 1) * 8 + x -1);
      exit_flag = EXIT_SUCCESS;
  } else if (value == 0) {
      big[y/5] &= ~(1 << ((y - 1) * 8 + x - 1));
      exit_flag = EXIT_SUCCESS;
  }

  return exit_flag;
}

int bc_getbigcharpos(int * big, int x, int y, int *value) {
  int exit_flag = EXIT_SUCCESS;
  if(x < 1 || x > 8 || y < 1 || y > 8) {
    exit_flag = EXIT_FAILURE;
  } else {
    *value = (big[y/5] >> ((y - 1) * 8 + x - 1)) & 0x1;
  }

  return exit_flag;
}

int bc_bigcharwrite(int fd, int * big, int count) {
  int exit_flag = EXIT_SUCCESS;
  write(fd, big, sizeof(count) * 2 * count);
  close(fd);
  return exit_flag;
}

int bc_bigcharread(int fd, int * big, int need_count, int * count) {
  int exit_flag = EXIT_SUCCESS;
  *count = read(fd, big, sizeof(need_count) * 2 * need_count) / 8;
  if (*count == 0) {
    exit_flag = EXIT_FAILURE;
  }
  close(fd);
  return exit_flag;
}

void initialize_management_console(int MEMEORY_ARR[], int *buf_array, int x, int y, int number) {
  bc_bigcharLayout(buf_array, number);

  bc_box(x, y, 60, 80);

  bc_printbigchar(buf_array, 1, 2, WHITE, BLACK);
}

int main() {
  int *buf_array, number = 0;
  buf_array = (int*) malloc(2 * sizeof(int));

  // initialize_management_console(RAM_GLOBAL, buf_array, 0, 0, 1);

  bc_box(0, 0, 60, 80);

  bc_bigcharLayout(buf_array, number);
  bc_printbigchar(buf_array, 1, 2, WHITE, BLACK);

  char key, c;
    while (key != 'Q') {
      mt_gotoXY(61, 0);
      if ((scanf("%c%c", &key, &c) == 2) && (c == '\n') && ((key == ' ') || (key == 'l') ||
      (key == 's') || (key == 'r') || (key == 't') || (key == 'i') ||
      (key == 'U+0071') || (key == 'C') || (key == 'Q'))) {
        if (key == 'Q') {
          mt_clrsrc();
          break;
        } else if (key == 'C') {
            if (number < 15) {
              number++;
            } else {
              number = 0;
            }
            
            mt_clrsrc();
            bc_box(0, 0, 60, 80);
            bc_bigcharLayout(buf_array, number);
            bc_printbigchar(buf_array, 1, 2, WHITE, BLACK);
        } else if ((key == 'a') || (key == 'A')) {

            mt_clrsrc();
            bc_box(0, 0, 60, 80);
        } else if ((key == 'm') || (key == 'M')) {

            mt_clrsrc();
            bc_box(0, 0, 60, 80);
        } else if ((key == 'k') || (key == 'K')) {

            mt_clrsrc();
            bc_box(0, 0, 60, 80);
        } else if (key == ' ') {
            mt_clrsrc();
            bc_box(0, 0, 60, 80);
            }
      } else if (scanf("%c%c", &key, &c) == EOF) {
          break;
          } else {
          mt_clrsrc();
          bc_box(0, 0, 60, 80);
          fflush(NULL);
      }
  }
}
