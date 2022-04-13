#ifndef SRC_MBR_H_
#define SRC_MBR_H_

#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct CHS {
    unsigned short cyl; 
    unsigned short head; 
    unsigned short sec; 
} tCHS;

typedef struct ECHS {
    unsigned short cyl; 
    unsigned short head; 
    unsigned short sec; 
} tLARGE;

typedef struct IDECHS {
    unsigned short cyl; 
    unsigned short head; 
    unsigned short sec; 
} tIDECHS;

typedef struct LBA {
    unsigned int lba; 
} tLBA;

typedef struct PART {
    int activ;
    tCHS beg;
    tCHS end;
    tLBA lba_beg;
    int size;
} tPART;

int g_lba2chs(tLBA orig, tCHS *dest);
int g_lba2large(tLBA orig, tLARGE *dest);
int g_lba2idechs(tLBA orig, tIDECHS *dest);
int g_chs2large(tCHS orig, tLARGE *dest);
int g_chs2lba(tCHS orig, tLBA * dest);
int g_chs2idechs(tIDECHS orig, tLBA *dest);
int g_large2chs(tLARGE orig, tCHS *dest);
int g_large2idechs(tLARGE orig, tIDECHS *dest);
int g_large2lba(tLARGE orig, tLBA *dest);
int g_idechs2chs(tIDECHS orig, tCHS *dest);
int g_idechs2lagre(tIDECHS orig, tLARGE * dest);
int g_idechs2lba(tIDECHS orig, tLBA * dest);

int a_lba2chs(tCHS geometry, tLBA orig, tCHS *dest);
int a_lba2large(tLARGE geometry, tLBA orig, tLARGE *dest);
int a_lba2idechs(tIDECHS geometry, tLBA orig, tIDECHS *dest);
int a_chs2lba(tCHS geometry, tCHS orig, tLBA * dest);
int a_large2lba(tLARGE geometry, tLARGE orig, tLBA *dest);
int a_idechs2lba(tIDECHS geometry, tIDECHS orig, tLBA *dest);
int a_large2chs(tLARGE geometry1, tCHS geometry2, tLARGE orig, tCHS *dest);
int a_large2idechs(tLARGE geometry1, tIDECHS geometry2, tLARGE orig, tIDECHS *dest);
int a_chs2large(tCHS geometry1, tLARGE geometry2, tCHS orig, tLARGE *dest);
int a_idechs2large(tIDECHS geometry1, tLARGE geometry2, tIDECHS orig, tLARGE *dest);
int a_chs2idechs(tCHS geometry1, tIDECHS geometry2, tCHS orig, tIDECHS *dest);
int a_idechs2chs(tIDECHS geometry1, tCHS geometry2, tIDECHS orig, tCHS *dest);

#endif  // SRC_MBR_H_
