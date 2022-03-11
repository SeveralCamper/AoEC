#include <check.h>
#include <math.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

#include "mySimpleComputer.h"

// MSC sc_memoryInit

START_TEST(sc_memoryInit_test) {
  RAM_Simple_Computer RAM_1;

  sc_memoryInit();

  sc_memoryInit_S(&RAM_1);

  for (int i = 0; i < RAM_SIZE; i++) {
    if (i == RAM_SIZE - 1) {
      printf("%d\n\n", RAM_GLOBAL[i]);
    } else {
      printf("%d", RAM_GLOBAL[i]);
    }
  }

    for (int i = 0; i < RAM_SIZE; i++) {
    if (i == RAM_SIZE - 1) {
      printf("%d\n", RAM_1.RAM_array[i]);
    } else {
      printf("%d", RAM_1.RAM_array[i]);
    }
  }

  ck_assert_int_eq(1, 1);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("MSC_Check");
  SRunner *sr = srunner_create(s1);
  int nf;

  // ADD CASES

  // S21 ABS

  TCase *sc_memoryInit_case = tcase_create("sc_memoryInit_test");
  suite_add_tcase(s1, sc_memoryInit_case);



  // ADD TESTS


  // S21 ABS +

  tcase_add_test(sc_memoryInit_case, sc_memoryInit_test);

  //  Запустить всё это дело
  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}

 // ПРИМЕРЧИК ОСТАВИМ
