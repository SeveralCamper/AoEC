#ifndef MY_TERM_H_
#define MY_TERM_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define RAM_SIZE 100

// Flags
#define  NORMAL_VALUE 0
#define  OVERFLOW 1
#define  MEMORY_ERROR 2
#define  INVALID_COMMAND 3

// Commands
#define READ 10
#define WRITE 11

#define LOAD 20
#define STORE 21

#define ADD 30
#define SUB 31
#define DIVIDE 32
#define MUL 33

#define JUMP 40
#define JNEG 41
#define JZ 42
#define HALT 43

#define NOT 51
#define AND 52
#define OR 53
#define XOR 54
#define JNS 55
#define JC 56
#define JNC 57
#define JP 58
#define JNP 59
#define CHL 60
#define SHR 61
#define RCL 62
#define RCR 63
#define NEG 64
#define ADDC 65
#define SUBC 66
#define LOGLC 67
#define LOGRC 68
#define RCCL 69
#define RCCR 70
#define MOVA 71
#define MOVR 72
#define MOVCA 73
#define MOVCR 74
#define ADDC_C 75
#define SUBC_C 76

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
int sc_regGet (int register_n, int * value);
int sc_memoryGet (int address, int * value);
int sc_commandEncode(int command, int operand, int *value);
int sc_commandDecode(int value, int *command, int *operand);

int sc_memoryInit_S (RAM_Simple_Computer *RAM);

#endif  //  MY_TERM_H_
