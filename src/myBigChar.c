#include "myBigChar.h"

int bc_printA (char * str)
{
	printf("\E(0%s", str);
	printf("\E(B");
}

int main() {
    char ar_ch[10] = "abcdefghij";
    bc_printA(&ar_ch);
}
