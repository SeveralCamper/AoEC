#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define RAM_SIZE 100

#define  NORMAL_VALUE 0
#define  OVERFLOW 1
#define  MEMORY_ERROR 2
#define  INVALID_COMMAND 3

typedef enum {
  NORMAL_VALUE_S = 0,
  OVERFLOW_S = 1,
  MEMORY_ERROR_S = 2,
  INVALID_COMMAND_S = 3
} value_type_t;


typedef struct {
  int *RAM_array;
  int flag_register;
  value_type_t value_type;
} RAM_Simple_Computer;

int flag_register;
int RAM_GLOBAL[RAM_SIZE];

int sc_memoryInit ();
int sc_regInit (void);
int sc_memoryLoad(char *filename);
int sc_memorySave (char * filename);
int sc_regSet (int register_n, int value);
int sc_memorySet (int address, int value);
int sc_memoryGet (int address, int * value);

int sc_memoryInit_S (RAM_Simple_Computer *RAM);

#endif  //  SRC_S21_MATH_H_
