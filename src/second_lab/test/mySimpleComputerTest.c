#include <check.h>
#include <math.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

#include "../mySimpleComputer.h"

// MSC sc_memoryInit

START_TEST(sc_memoryInit_test) {
  RAM_Simple_Computer RAM_1;
  int success_flag = 1;

  sc_memoryInit();

  sc_memoryInit_S(&RAM_1);

  for (int i = 0; i < RAM_SIZE; i++) {
    if (RAM_1.RAM_array[i] != 0 || RAM_1.RAM_array[i] != RAM_GLOBAL[i] ||
    RAM_1.value_type != 0) {
      success_flag = 0;
      break;
    }
  }

  ck_assert_int_eq(success_flag, 1);
}
END_TEST

// MSC sc_memorySet

START_TEST(sc_memorySet_test) {
  int success_flag = 1;

  sc_memoryInit();

  sc_memorySet(5, 10);

  if (RAM_GLOBAL[5] != 10) {
    success_flag = 0;
  }
  ck_assert_int_eq(success_flag, 1);

  for (int i = 0; i < RAM_SIZE; i++) {
    sc_memorySet(i, i + 1);
    if (RAM_GLOBAL[i] != i + 1) {
      success_flag = 0;
    }

    ck_assert_int_eq(success_flag, 1);
  }
}
END_TEST

START_TEST(sc_memorySet_exception_test) {
  int success_flag = 1;

  sc_memoryInit();

  int exeption_exit = sc_memorySet(101, 10);

  for (int i = 0; i < RAM_SIZE; i++) {
    if (RAM_GLOBAL[i] != 0 || exeption_exit != 1) {
      success_flag = 0;
      break;
    }
  }

  ck_assert_int_eq(success_flag, 1);

  exeption_exit = sc_memorySet(-2, 0);

  for (int i = 0; i < RAM_SIZE; i++) {
    if (RAM_GLOBAL[i] != 0 || exeption_exit != 1) {
      success_flag = 0;
      break;
    }
  }

  ck_assert_int_eq(success_flag, 1);
}
END_TEST

// MSC sc_memoryGet

START_TEST(sc_memoryGet_test) {
  int success_flag = 1;
  int exeption_exit = 0;

  sc_memoryInit();

  sc_memoryGet(5, &exeption_exit);

  if (exeption_exit != RAM_GLOBAL[5]) {
    success_flag = 0;
  }
  ck_assert_int_eq(success_flag, 1);

  for (int i = 0; i < RAM_SIZE; i++) {
    sc_memoryGet(i, &exeption_exit);
    if (RAM_GLOBAL[i] != exeption_exit) {
      success_flag = 0;
    }

    ck_assert_int_eq(success_flag, 1);
  }
}
END_TEST

START_TEST(sc_memoryGet_exception_test) {
  int success_flag = 1;

  sc_memoryInit();

  int exeption_exit = 5;
  sc_memoryGet(101, &exeption_exit);

  for (int i = 0; i < RAM_SIZE; i++) {
    if (RAM_GLOBAL[i] != 0 || exeption_exit != 5) {
      success_flag = 0;
      break;
    }
  }

  ck_assert_int_eq(success_flag, 1);

  sc_memoryGet(-1, &exeption_exit);

  for (int i = 0; i < RAM_SIZE; i++) {
    if (RAM_GLOBAL[i] != 0 || exeption_exit != 5) {
      success_flag = 0;
      break;
    }
  }

  ck_assert_int_eq(success_flag, 1);
}
END_TEST

// MSC sc_memorySave and sc_memoryLoad

START_TEST(sc_memorySave_and_sc_memoryLoad_test) {
  int success_flag = 1;
  char string1[15] = "file1.txt";

  sc_memoryInit();

  sc_memorySave(string1);

  for (int i = 0; i < RAM_SIZE; i++) {
    RAM_GLOBAL[i] = 9;
  }

  sc_memoryLoad(string1);

  for (int i = 0; i < RAM_SIZE; i++) {
    if (RAM_GLOBAL[i] != 0) {
      success_flag = 0;
      break;
    }
  }

  ck_assert_int_eq(success_flag, 1);
}
END_TEST

START_TEST(sc_memorySave_and_sc_memoryLoad_exception_test) {
  int success_flag = 1;
  int exeption_exit = 0;
  char string1[15] = "file1.txt";
  char string2[15] = "file2.txt";

  sc_memoryInit();

  sc_memorySave(string1);

  for (int i = 0; i < RAM_SIZE; i++) {
    RAM_GLOBAL[i] = 9;
  }
  
  exeption_exit = sc_memoryLoad(string2);

  for (int i = 0; i < RAM_SIZE; i++) {
    if (RAM_GLOBAL[i] != 9 && exeption_exit != 1) {
      success_flag = 0;
      break;
    }
  }

  ck_assert_int_eq(success_flag, 1);
}
END_TEST

// sc_regInit

START_TEST(sc_regInit_test) {
  flag_register = 2;

  sc_regInit();

  ck_assert_int_eq(flag_register, 0);
}
END_TEST

  // sc_regSet

START_TEST(sc_regSet_test) {
  char string1[15] = "file1.txt";
  int exit_flag = 0;

  sc_memoryInit();

  sc_memorySave(string1);

  for (int i = 0; i < RAM_SIZE; i++) {
    RAM_GLOBAL[i] = 9;
  }

  sc_memoryLoad(string1);

  exit_flag = sc_regSet(1, 2);

  ck_assert_int_eq(exit_flag, 0);
  ck_assert_int_eq(flag_register, 2);
}
END_TEST

START_TEST(sc_regSet_exception_test) {
  char string1[15] = "file1.txt";
  int exit_flag = 0;

  sc_memoryInit();

  sc_memorySave(string1);

  for (int i = 0; i < RAM_SIZE; i++) {
    RAM_GLOBAL[i] = 9;
  }

  flag_register = 4;

  sc_memoryLoad(string1);

  exit_flag = sc_regSet(-1, 2);

  ck_assert_int_eq(exit_flag, 1);
  ck_assert_int_eq(flag_register, 4);

  exit_flag = sc_regSet(5, 2);

  ck_assert_int_eq(exit_flag, 1);
  ck_assert_int_eq(flag_register, 4);
}
END_TEST

  // sc_regGet

START_TEST(sc_regGet_test) {
  char string1[15] = "file1.txt";
  int exit_flag = 0;

  sc_memoryInit();

  sc_memorySave(string1);

  for (int i = 0; i < RAM_SIZE; i++) {
    RAM_GLOBAL[i] = 9;
  }

  sc_memoryLoad(string1);

  exit_flag = sc_regGet(1, &exit_flag);

  ck_assert_int_eq(exit_flag, 0);
  ck_assert_int_eq(flag_register, 0);
}
END_TEST

START_TEST(sc_regGet_exception_test) {
  char string1[15] = "file1.txt";
  int exit_flag = 0;

  sc_memoryInit();

  sc_memorySave(string1);

  for (int i = 0; i < RAM_SIZE; i++) {
    RAM_GLOBAL[i] = 9;
  }

  flag_register = 4;

  sc_memoryLoad(string1);

  exit_flag = sc_regGet(-1, &exit_flag);

  ck_assert_int_eq(exit_flag, 1);
  ck_assert_int_eq(flag_register, 4);

  exit_flag = sc_regGet(5, &exit_flag);

  ck_assert_int_eq(exit_flag, 1);
  ck_assert_int_eq(flag_register, 4);
}
END_TEST

// sc_commandEncode

START_TEST(sc_commandEncode_test) {
  char string1[15] = "file1.txt";
  int exit_flag = 0;

  sc_memoryInit();

  sc_memorySave(string1);

  for (int i = 0; i < RAM_SIZE; i++) {
    RAM_GLOBAL[i] = 9;
  }

  sc_memoryLoad(string1);

  exit_flag = sc_commandEncode();

  ck_assert_int_eq(exit_flag, 0);
  ck_assert_int_eq(flag_register, 0);
}
END_TEST

START_TEST(sc_commandEncode_exception_test) {
  char string1[15] = "file1.txt";
  int exit_flag = 0;

  sc_memoryInit();

  sc_memorySave(string1);

  for (int i = 0; i < RAM_SIZE; i++) {
    RAM_GLOBAL[i] = 9;
  }

  flag_register = 4;

  sc_memoryLoad(string1);

  exit_flag = sc_regGet(-1, &exit_flag);

  ck_assert_int_eq(exit_flag, 1);
  ck_assert_int_eq(flag_register, 4);

  exit_flag = sc_regGet(5, &exit_flag);

  ck_assert_int_eq(exit_flag, 1);
  ck_assert_int_eq(flag_register, 4);
}
END_TEST

// sc_commandDecode

START_TEST(sc_commandDecode_test) {
  char string1[15] = "file1.txt";
  int exit_flag = 0;

  sc_memoryInit();

  sc_memorySave(string1);

  for (int i = 0; i < RAM_SIZE; i++) {
    RAM_GLOBAL[i] = 9;
  }

  sc_memoryLoad(string1);

  exit_flag = sc_regGet(1, &exit_flag);

  ck_assert_int_eq(exit_flag, 0);
  ck_assert_int_eq(flag_register, 0);
}
END_TEST

START_TEST(sc_commandDecode_exception_test) {
  char string1[15] = "file1.txt";
  int exit_flag = 0;

  sc_memoryInit();

  sc_memorySave(string1);

  for (int i = 0; i < RAM_SIZE; i++) {
    RAM_GLOBAL[i] = 9;
  }

  flag_register = 4;

  sc_memoryLoad(string1);

  exit_flag = sc_regGet(-1, &exit_flag);

  ck_assert_int_eq(exit_flag, 1);
  ck_assert_int_eq(flag_register, 4);

  exit_flag = sc_regGet(5, &exit_flag);

  ck_assert_int_eq(exit_flag, 1);
  ck_assert_int_eq(flag_register, 4);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("MSC_Check");
  SRunner *sr = srunner_create(s1);
  int nf;


  // ADD CASES

  // sc_memoryInit

  TCase *sc_memoryInit_case = tcase_create("sc_memoryInit_test");
  suite_add_tcase(s1, sc_memoryInit_case);

  // sc_memorySet

  TCase *sc_memorySet_case = tcase_create("sc_memorySet_test");
  suite_add_tcase(s1, sc_memorySet_case);

  TCase *sc_memorySet_exception_case = tcase_create("sc_memorySet_exception_test");
  suite_add_tcase(s1, sc_memorySet_exception_case);

  // sc_memoryGet

  TCase *sc_memoryGet_case = tcase_create("sc_memoryGet_test");
  suite_add_tcase(s1, sc_memoryGet_case);

  TCase *sc_memoryGet_exception_case = tcase_create("sc_memoryGet_exception_test");
  suite_add_tcase(s1, sc_memoryGet_exception_case);

  // sc_memorySave and sc_memoryLoad

  TCase *sc_memorySave_and_sc_memoryLoad_case = tcase_create("sc_memorySave_and_sc_memoryLoad_test");
  suite_add_tcase(s1, sc_memorySave_and_sc_memoryLoad_case);

  TCase *sc_memorySave_and_sc_memoryLoad_exception_case = tcase_create("sc_memorySave_and_sc_memoryLoad_exception_test");
  suite_add_tcase(s1, sc_memorySave_and_sc_memoryLoad_exception_case);

  // sc_regInit

  TCase *sc_regInit_case = tcase_create("sc_regInit_test");
  suite_add_tcase(s1, sc_regInit_case);

  // sc_regSet

  TCase *sc_regSet_case = tcase_create("sc_regSet_test");
  suite_add_tcase(s1, sc_regSet_case);

  TCase *sc_regSet_exception_case = tcase_create("sc_regSet_exception_test");
  suite_add_tcase(s1, sc_regSet_exception_case);

  // sc_regGet

  TCase *sc_regGet_case = tcase_create("sc_regGet_test");
  suite_add_tcase(s1, sc_regGet_case);

  TCase *sc_regGet_exception_case = tcase_create("sc_regGet_exception_test");
  suite_add_tcase(s1, sc_regGet_exception_case);

  // sc_commandEncode

  TCase *sc_commandEncode_case = tcase_create("sc_commandEncode_test");
  suite_add_tcase(s1, sc_commandEncode_case);

  TCase *sc_commandEncode_exception_case = tcase_create("sc_commandEncode_exception_test");
  suite_add_tcase(s1, sc_commandEncode_exception_case);

  // sc_commandDecode

  TCase *sc_commandDecode_case = tcase_create("sc_commandDecode_test");
  suite_add_tcase(s1, sc_commandDecode_case);

  TCase *sc_commandDecode_exception_case = tcase_create("sc_commandDecode_exception_test");
  suite_add_tcase(s1, sc_commandDecode_exception_case);


  // ADD TESTS


  // sc_memoryInit

  tcase_add_test(sc_memoryInit_case, sc_memoryInit_test);

  // sc_memorySet

  tcase_add_test(sc_memorySet_case, sc_memorySet_test);
  tcase_add_test(sc_memorySet_exception_case, sc_memorySet_exception_test);

  // sc_memoryGet

  tcase_add_test(sc_memoryGet_case, sc_memoryGet_test);
  tcase_add_test(sc_memoryGet_exception_case, sc_memoryGet_exception_test);

  // sc_memorySave and sc_memoryLoad

  tcase_add_test(sc_memorySave_and_sc_memoryLoad_case, sc_memorySave_and_sc_memoryLoad_test);
  tcase_add_test(sc_memorySave_and_sc_memoryLoad_exception_case, sc_memorySave_and_sc_memoryLoad_exception_test);

  // sc_regInit

  tcase_add_test(sc_regInit_case, sc_regInit_test);

  // sc_regSet

  tcase_add_test(sc_regSet_case, sc_regSet_test);
  tcase_add_test(sc_regSet_exception_case, sc_regSet_exception_test);

  // sc_regGet

  tcase_add_test(sc_regGet_case, sc_regGet_test);
  tcase_add_test(sc_regGet_exception_case, sc_regGet_exception_test);

  // sc_commandEncode

  tcase_add_test(sc_commandEncode_case, sc_commandEncode_test);
  tcase_add_test(sc_commandEncode_exception_case, sc_commandEncode_exception_test);

  //sc_commandDecode

  tcase_add_test(sc_commandDecode_case, sc_commandDecode_test);
  tcase_add_test(sc_commandDecode_exception_case, sc_commandDecode_exception_test);


  //  Запустить всё это дело
  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}

 // ПРИМЕРЧИК ОСТАВИМ
