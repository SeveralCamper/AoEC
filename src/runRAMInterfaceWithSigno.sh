#!/bin/bash

# python3 ../materials/linters/cpplint.py --extensions=c *.h
python3 ../materials/linters/cpplint.py --extensions=c *.c

gcc -Wall -Werror -Wextra mySimpleComputer.c myBigChar.c myTerm.c -o RAMInterface
./RAMInterface
