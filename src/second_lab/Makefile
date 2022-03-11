CC = gcc -std=c11
CFLAGS = -Wall -Werror -Wextra
LIBS = -lcheck -lsubunit -lrt -lpthread -lm
TESTTARGET = mySimpleComputerTest
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

all: clean mySimpleComputer.a

$(TARGET): mySimpleComputer.o mySimpleComputer.a
	$(CC) mySimpleComputer.o $(CFLAGS) $(LIBS) $(GCOV) -L. mySimpleComputer.a -o $@

mySimpleComputer.o: mySimpleComputer.c
	$(CC) -c mySimpleComputer.c $(CFLAGS) $(LIBS) -o $@

mySimpleComputer.a: mySimpleComputer.o
	ar rcs $@ $^
	ranlib $@
	cp $@ lib$@

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

$(TESTTARGET): mySimpleComputer.a test/mySimpleComputerTest.o mySimpleComputer.o
	$(CC) test/mySimpleComputerTest.c mySimpleComputer.o $(CFLAGS) $(LIBS) -o $@
	

test/mySimpleComputerTest.o: test/mySimpleComputerTest.c mySimpleComputer.h
	$(CC) $(CFLAGS) $(LIBS) -c test/mySimpleComputerTest.c -o $@ 
	$(CC) $(CFLAGS) $(LIBS) -c mySimpleComputer.c -o $@

test: $(TESTTARGET)
	./$(TESTTARGET)

clean:	
		rm -rf mySimpleComputer.a
		rm -rf gcov_report
		rm -rf mySimpleComputer
		rm -rf mySimpleComputerTest
		rm -rf *.o *.so *.a fizz *.gc* *.info report *.out *.gcda *.so *.gcno *.info
		rm -rf test/*.o test/*.so test/*.a  test/*.gcda  test/*.so  test/*.gcno  test/*.info

rebuild: clean all

.PHONY: all clean test rebild mySimpleComputer.a
