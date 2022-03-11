#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define RAM_SIZE 100

typedef enum {
  NORMAL_VALUE = 0,
  UNVALID_VALUE = 1,
  MEMORY_ERROR = 2
} value_type_t;


typedef struct {
  int *RAM_array;
  value_type_t value_type;
} RAM_Simple_Computer;

int RAM_GLOBAL[RAM_SIZE];

int sc_memoryInit ();
int sc_memoryLoad(char *filename);
int sc_memorySave (char * filename);
int sc_memorySet (int address, int value);
int sc_memoryGet (int address, int * value);

int sc_memoryInit_S (RAM_Simple_Computer *RAM);

#endif  //  SRC_S21_MATH_H_
