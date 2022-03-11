#include "mySimpleComputer.h"

int sc_memoryInit () {
  for (int i = 0; i < RAM_SIZE; i++) {
    RAM_GLOBAL[i] = 0; 
  }

  return EXIT_SUCCESS;
}

int sc_memorySet (int address, int value) {
  int exit_flag = EXIT_SUCCESS;
  if (0 <= address && address < RAM_SIZE) {
    RAM_GLOBAL[address] = value;
  } else {
    exit_flag = EXIT_FAILURE;
  }

  return exit_flag;
}

int sc_memoryGet (int address, int * value) {
  int exit_flag = EXIT_SUCCESS;
  if (0 <= address && address < RAM_SIZE) {
    *value = RAM_GLOBAL[address];
  } else {
    exit_flag = EXIT_FAILURE;
  }

  return exit_flag;  
}

int sc_memorySave(char *filename) {
  int exit_flag = EXIT_SUCCESS;
  
  FILE *outFile;
  if ((outFile = fopen(filename, "wb")) == NULL) {
    exit_flag = EXIT_FAILURE;
  } else {
    fwrite(RAM_GLOBAL, sizeof(int), RAM_SIZE, outFile);
    fclose(outFile);
  }

  return exit_flag;
}

int sc_memoryInit_S (RAM_Simple_Computer *RAM) {
  int exit_flag = EXIT_SUCCESS;
  RAM->RAM_array = (int*) malloc(RAM_SIZE * sizeof(int));

  if (RAM->RAM_array != NULL) {
    for (int i = 0; i < RAM_SIZE; i++) {
      RAM->RAM_array[i] = 0;
    }
    RAM->value_type = NORMAL_VALUE;
  } else {
    printf("Memory allocation error!");
    exit_flag = EXIT_FAILURE;
    RAM->value_type = MEMORY_ERROR;
  }

  return exit_flag;
}

/* int main() {
  RAM_Simple_Computer RAM_1;

  int value = 2;

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

  printf("%d", value);

  sc_memoryGet(5, &value);

  printf("%d", value);

} */
