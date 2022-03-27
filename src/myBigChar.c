#include "myBigChar.h"

int bc_printA (char * str) {
  int exit_flag = EXIT_SUCCESS;

	printf("\E(0%s", str);
	printf("\E(B");

  return exit_flag;
}

int bc_box(int x1, int y1, int x2, int y2) {
  int exit_falg = EXIT_SUCCESS;
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
    mt_gotoXY(y1+i+1, x1);
    bc_printA("\u2502");
    mt_gotoXY(y1+i+1, x2);
    bc_printA("\u2502");
  }

  mt_gotoXY(y2+1, x1);
  bc_printA("\u2514");
  for(int i = 0; i < x2 - x1 - 1; i++) {
    bc_printA("\u2500");
  }
  bc_printA("\u2518\n");

  mt_gotoXY(x2, 0);
  printf("\033[10;1H \e[m");

  return exit_falg;
}

void bc_bigcharLayout(int *A, int number) {
  number = number % 18;
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
      A[0] = 4290822336;
      A[1] = 4290822399;
      break;
    case 4:
      A[0] = 3233857728;
      A[1] = 4291019715;
      break;
    case 5:
      A[0] = 4290822336;
      A[1] = 4278387711;
      break;
    case 6:
      A[0] = 4291019715;
      A[1] = 4278387711;
      break;
    case 7:
      A[0] = 3233857728;
      A[1] = 3233857791;
      break;
    case 8:
      A[0] = 4291019715;
      A[1] = 4291019775;
      break;
    case 9:
      A[0] = 4290822336;
      A[1] = 4291019775;
      break;
    case 10: // A
      A[0] = 3284386755;
      A[1] = 4291019580;
      break;
    case 11: // B
      A[0] = 1069794243;
      A[1] = 1069794111;
      break;
    case 12: // C
      A[0] = 1019413251;
      A[1] = 50578236;
      break;
    case 13: // D
      A[0] = 1069794243;   // 
      A[1] = 3284386623;   // 
      break;
    case 14: // E
      A[0] = 4278387459;   // 11000000110000001100000011111111
      A[1] = 4278387711;   // 11111111110000001100000011111111
      break;
    case 15: // F
      A[0] = 50529027;     // 11000000110000001100000011000000
      A[1] = 4278387711;   // 11111111110000001100000011111111
      break;
    case 16: // +
      A[0] = 6168;
      A[1] = 4279769088;
      break;
    case 17: // -
      A[0] = 0;     
      A[1] = 4278190080;   
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
  printf("\033[10;1H \e[m");

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

void parse_el(int element) {
 char sign = '+';
  int num[4] = {0, 0, 0, 0}; 
  int count = 3;
  if (element < 0) {
    sign = '-';
    element *= -1;
  }
  while (element > 0) {
    num[count] = element % 10;
    element = element / 10;
    count--;
  }

  printf("%c%d%d%d%d ", sign,num[0],num[1],num[2],num[3]);
}

void initialize_management_console(int *buf_array, int number) {
  int str_pos = 0;
  
  mt_clrsrc();

  bc_box(1, 2, 62, 12);
  mt_gotoXY(2, 26);
  printf(" Memory ");

  for (int i = 0; i < RAM_SIZE; i++) {
    if (i % 10 == 0) {
      mt_gotoXY(str_pos + 3, 2);
      str_pos++;
    }
    parse_el(RAM_GLOBAL[i]);
  }

  bc_box(1, 14, 50, 22);
  for (int i = 0; i < 5; i++) {
    bc_bigcharLayout(buf_array, number);
    bc_printbigchar(buf_array, 15, (i * 10) + 2, WHITE, BLACK);
  }
  bc_box(64, 2, 93, 3);
  mt_gotoXY(2, 76);
  printf(" Accumulator ");
  bc_box(64, 5, 93, 6);
  bc_box(64, 8, 93, 9);
  bc_box(64, 11, 93, 12);

  bc_box(51, 14, 93, 22);

  for (int i = 0; i < 4; i++) {
    mt_gotoXY(i * 3 + 4, 94);
    printf(" ");
  }

  mt_gotoXY(24, 0);
  printf("Input\\Output:");
  mt_gotoXY(25, 0);
}

int main() {
  int *buf_array, number = 0, accumulator, instruction_counter;
  buf_array = (int*) malloc(2 * sizeof(int));

  initialize_management_console(buf_array, number);

  char key, c;
    while (key != 'Q') {
      if ((scanf("%c%c", &key, &c) == 2) && (c == '\n') && ((key == ' ') || (key == 'l') ||
      (key == 's') || (key == 'r') || (key == 't') || (key == 'i') ||
      (key == 'U+0071') || (key == 'C') || (key == 'Q'))) {
        if (key == 'Q') {
          mt_clrsrc();
          break;
        } else if (key == 'C') {
            if (number < 17) {
              number++;
            } else {
              number = 0;
            }

            initialize_management_console(buf_array, number);

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
