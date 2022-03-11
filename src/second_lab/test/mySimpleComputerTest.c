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


  // ADD TESTS


  // sc_memoryInit

  tcase_add_test(sc_memoryInit_case, sc_memoryInit_test);

  // sc_memorySet

  tcase_add_test(sc_memorySet_case, sc_memorySet_test);
  tcase_add_test(sc_memorySet_exception_case, sc_memorySet_exception_test);

  //  Запустить всё это дело
  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}

 // ПРИМЕРЧИК ОСТАВИМ
