CC = gcc -std=c11
CFLAGS = -Wall -Werror -Wextra
LIBS = -lcheck -lsubunit -lrt -lpthread -lm
TARGET1 = ../bin/mySimpleComputer
TARGET2 = ../bin/myTerm
TARGET3 = ../bin/myBigChar
TESTTARGET1 = ../../bin/mySimpleComputerTest
OS := $(shell uname -s)

ifeq ($(OS), Linux)
	OPEN = xdg-open
	ADD_LIB = -lm -lrt -lpthread -D_GNU_SOURCE
	BREW = .
endif
ifeq ($(OS), Darwin)
	OPEN = open
	ADD_LIB = 
	BREW = {$HOME}/homebrew
endif

PATH := $(PATH):$(BREW)/bin
GCOV = --coverage

all: clean myBigChar.a

$(TARGET1): mySimpleComputer.o mySimpleComputer.a
	$(CC) mySimpleComputer.o $(CFLAGS) $(LIBS) $(GCOV) -L. mySimpleComputer.a -o $@

$(TARGET2): mySimpleComputer.o myTerm.o myTerm.a
	$(CC) mySimpleComputer.o myTerm.o $(CFLAGS) $(LIBS) $(GCOV) -L. myTerm.a -o $@

$(TARGET3): mySimpleComputer.o myTerm.o myBigChar.o myBigChar.a
	$(CC) mySimpleComputer.o myTerm.o myBigChar.o $(CFLAGS) $(LIBS) $(GCOV) -L. myBigChar.a -o $@

mySimpleComputer.o: mySimpleComputer.c
	$(CC) -c mySimpleComputer.c $(CFLAGS) $(LIBS) -o $@

myTerm.o: myTerm.c
	$(CC) -c myTerm.c $(CFLAGS) $(LIBS) -o $@

myBigChar.o: myBigChar.c
	$(CC) -c myBigChar.c $(CFLAGS) $(LIBS) -o $@

mySimpleComputer.a: mySimpleComputer.o
	ar rcs $@ $^
	ranlib $@
	cp $@ lib$@

myTerm.a: myTerm.o
	ar rcs $@ $^
	ranlib $@
	cp $@ lib$@

myBigChar.a: myBigChar.o
	ar rcs $@ $^
	ranlib $@
	cp $@ lib$@

run1: $(TARGET1)
	.././bin/mySimpleComputer

run2: $(TARGET2)
	.././bin/myTerm

run3: $(TARGET3)
	.././bin/myBigChar

gcov_report: clean test/mySimpleComputerTest.c mySimpleComputer.c
	-mkdir report
	$(CC) $(GCOV) test/mySimpleComputerTest.c mySimpleComputer.c $(CFLAGS) $(ADD_LIB) $(LIBS) -lcheck
	$(CC) $(GCOV) -c mySimpleComputer.c $(CFLAGS) $(LIBS) -o mySimpleComputer.o
	$(CC) $(GCOV) -c test/mySimpleComputerTest.c $(CFLAGS) $(LIBS) -o test/mySimpleComputerTest.o
	$(CC) $(GCOV) -o $@ test/mySimpleComputerTest.o mySimpleComputer.o $(CFLAGS) $(LIBS) -lcheck
	-./$@
	gcov test/mySimpleComputerTest.c
	lcov -t test/mySimpleComputerTest -o test/mySimpleComputerTest.info -c -d .
	genhtml -o report test/mySimpleComputerTest.info
	$(OPEN) ./report/index.html

$(TESTTARGET1): mySimpleComputer.a test/mySimpleComputerTest.o mySimpleComputer.o
	$(CC) test/mySimpleComputerTest.c mySimpleComputer.o $(CFLAGS) $(LIBS) -o $@
	

test/mySimpleComputerTest.o: test/mySimpleComputerTest.c mySimpleComputer.h
	$(CC) $(CFLAGS) $(LIBS) -c test/mySimpleComputerTest.c -o $@ 
	$(CC) $(CFLAGS) $(LIBS) -c mySimpleComputer.c -o $@

test: $(TESTTARGET1)
	./$(TESTTARGET1)

clean:	
		rm -rf *.txt
		rm -rf gcov_report
		rm -rf mySimpleComputer
		rm -rf mySimpleComputer.a
		rm -rf ../../bin/mySimpleComputer
		rm -rf ../../bin/mySimpleComputerTest
		rm -rf *.o *.so *.a fizz *.gc* *.info report *.out *.gcda *.so *.gcno *.info
		rm -rf test/*.o test/*.so test/*.a  test/*.gcda  test/*.so  test/*.gcno  test/*.info

rebuild: clean all

.PHONY: all clean test rebild mySimpleComputer.a
