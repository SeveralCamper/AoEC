#include "mySimpleComputer.h"

int sc_memoryInit () {
  for (int i = 0; i < RAM_SIZE; i++) {
    RAM_GLOBAL[i] = 0; 
  }

  return EXIT_SUCCESS;
}

int sc_memoryInit_S (RAM_Simple_Computer *RAM) {
  int exit_flag = EXIT_SUCCESS;
  RAM->RAM_array = (int*) malloc(RAM_SIZE * sizeof(int));

  if (RAM->RAM_array != NULL) {
    for (int i = 0; i < RAM_SIZE; i++) {
      RAM->RAM_array[i] = 0;
    }
  } else {
    printf("Memory allocation error!");
    exit_flag = EXIT_FAILURE;
    RAM->value_type = 2;
  }

  return exit_flag;
}

int main() {

  RAM_Simple_Computer RAM_1;

  sc_memoryInit();

  sc_memoryInit_S(&RAM_1);

  for (int i = 0; i < RAM_SIZE; i++) {
    if (i == RAM_SIZE - 1) {
      printf("%d\n\n", RAM_GLOBAL[i]);
    } else {
      printf("%d", RAM_GLOBAL[i]);
    }
  }

    for (int i = 0; i < RAM_SIZE; i++) {
    if (i == RAM_SIZE - 1) {
      printf("%d\n", RAM_1.RAM_array[i]);
    } else {
      printf("%d", RAM_1.RAM_array[i]);
    }
  }
}
