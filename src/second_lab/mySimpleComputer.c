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
  outFile = fopen(filename, "wb");
  fwrite(RAM_GLOBAL, sizeof(int), RAM_SIZE, outFile);
  fclose(outFile);

  return exit_flag;
}

int sc_memoryLoad(char *filename) {
  int exit_flag = EXIT_SUCCESS;

  FILE *inFile;
  if ((inFile = fopen(filename, "rb")) == NULL) {
    exit_flag = EXIT_FAILURE;
  } else {
    fread(RAM_GLOBAL, sizeof(int), RAM_SIZE, inFile);
    fclose(inFile);
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
    RAM->value_type = NORMAL_VALUE_S;
  } else {
    printf("Memory allocation error!");
    exit_flag = EXIT_FAILURE;
    RAM->value_type = MEMORY_ERROR_S;
  }

  return exit_flag;
}

int sc_regInit (void) {
  int exit_flag = EXIT_SUCCESS;

  flag_register = 0;

  return exit_flag;
}

int sc_regSet (int register_n, int value) {
  int exit_flag = EXIT_SUCCESS;
  
  if (register_n < NORMAL_VALUE_S || register_n > INVALID_COMMAND) {
    exit_flag = EXIT_FAILURE;
  } else {
    register_n = value;
  }

  return exit_flag;
}

int main() {
  char string1[15] = "file1.txt";
  int exit_flag = 0;

  sc_memoryInit();

  sc_memorySave(string1);

  for (int i = 0; i < RAM_SIZE; i++) {
    RAM_GLOBAL[i] = 9;
  }

  for (int i = 0; i < RAM_SIZE; i++) {
    if (i == RAM_SIZE - 1) {
      printf("%d\n", RAM_GLOBAL[i]);
    } else {
      printf("%d", RAM_GLOBAL[i]);
    }
  }

  sc_memoryLoad(string1);

  exit_flag = sc_regSet(-2, 15);
  printf("%d\n", exit_flag);

  for (int i = 0; i < RAM_SIZE; i++) {
    if (i == RAM_SIZE - 1) {
      printf("%d\n", RAM_GLOBAL[i]);
    } else {
      printf("%d", RAM_GLOBAL[i]);
    }
  }
}
