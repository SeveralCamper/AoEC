#include <check.h>
#include <math.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

#include "../mySimpleComputer.h"

// S21 ABS

#define STAT_MEAN_ARR_LONG 5

const long double statMeanArr[STAT_MEAN_ARR_LONG] = {S21_NANF, -S21_NANF,
                                                     S21_INFL, -S21_INFL, 0};

START_TEST(s21_abs_Check) {
  int N = 2147483647;
  int resault = 0, x = 0;
  int statMeanArr[3] = {2147483647, -2147483647, 0};
  for (int i = 0; i < 100; i++) {
    x = pow((-1), i) * (int)(rand()) / RAND_MAX * N;
    long int res_s21 = s21_abs(x);
    long int res_origin = abs(x);

    if ((__int128_t)res_s21 == (__int128_t)res_origin) {
      resault = 1;
    }
    if (resault == 1) {
      ck_assert_int_eq(resault, 1);
    }
  }

  for (int i = 0; i < 3; i++) {
    x = statMeanArr[i];
    long int res_s21 = s21_abs(x);
    long int res_origin = abs(x);
    if ((__int128_t)res_s21 == (__int128_t)res_origin) {
      resault = 1;
    }
    if (resault == 1) {
      ck_assert_int_eq(resault, 1);
    }
  }
}
END_TEST

// S21 FABS

START_TEST(s21_fabs_Check) {
  long int N = 1000000000000000;
  int resault = 0;
  long double statMeanArr[5] = {S21_NANF, -S21_NANF, S21_INFL, -S21_INFL, 0.0};
  double x;
  for (int i = 0; i < 100; i++) {
    int inf = 0, nan = 0;
    x = pow((-1), i) * (double)(rand()) / RAND_MAX * N;
    double res_s21 = s21_fabs(x);
    double res_origin = fabs(x);
    if (isnan(res_s21) != 0 && isnan(res_origin) != 0) {
      nan = 1;
    }

    if (isinf(res_s21) != 0 && isinf(res_origin) != 0) {
      inf = 1;
    }

    if (fabs(res_origin - res_s21) <= S21_EPSILON * fabs(res_origin) &&
        inf != 1 && nan != 1) {
      resault = 1;
    }
    if (resault == 1) {
      ck_assert_int_eq(resault, 1);
    }
  }

  for (int i = 0; i < 5; i++) {
    x = statMeanArr[i];
    double res_s21 = s21_fabs(x);
    double res_origin = fabs(x);
    if (res_s21 == res_origin) {
      resault = 1;
    }
    if (resault == 1) {
      ck_assert_int_eq(resault, 1);
    }
  }
}
END_TEST

// S21 SQRT

START_TEST(s21_sqrt_Check) {
  long int N = 1000000000000000;
  int resault = 0;
  double x;
  for (int i = 0; i < 100; i++) {
    int inf = 0, nan = 0;
    x = (double)(rand()) / RAND_MAX * N;
    double res_s21 = s21_sqrt(x);
    double res_origin = sqrt(x);
    if (isnan(res_s21) != 0 && isnan(res_origin) != 0) {
      nan = 1;
    }

    if (isinf(res_s21) != 0 && isinf(res_origin) != 0) {
      inf = 1;
    }

    if (fabs(res_origin - res_s21) <= S21_EPSILON * fabs(res_origin) &&
        inf != 1 && nan != 1) {
      resault = 1;
    }
    if (resault == 1) {
      ck_assert_int_eq(resault, 1);
    }
  }

  for (int i = 0; i < 5; i++) {
    x = statMeanArr[i];
    double res_s21 = s21_sqrt(x);
    double res_origin = sqrt(x);
    if (res_s21 == res_origin) {
      resault = 1;
    }
    if (resault == 1) {
      ck_assert_int_eq(resault, 1);
    }
  }
}
END_TEST

// S21 CEIL

START_TEST(s21_ceil_Check) {
  long int N = 1000000000000000;
  int resault = 0;
  double x;
  for (int i = 0; i < 100; i++) {
    int inf = 0, nan = 0;
    x = (double)(rand()) / RAND_MAX * N;
    double res_s21 = s21_ceil(x);
    double res_origin = ceil(x);
    if (isnan(res_s21) != 0 && isnan(res_origin) != 0) {
      nan = 1;
    }

    if (isinf(res_s21) != 0 && isinf(res_origin) != 0) {
      inf = 1;
    }

    if (fabs(res_origin - res_s21) <= S21_EPSILON * fabs(res_origin) &&
        inf != 1 && nan != 1) {
      resault = 1;
    }
    if (resault == 1) {
      ck_assert_int_eq(resault, 1);
    }
  }

  for (int i = 0; i < 5; i++) {
    x = statMeanArr[i];
    double res_s21 = s21_ceil(x);
    double res_origin = ceil(x);
    if (res_s21 == res_origin) {
      resault = 1;
    }
    if (resault == 1) {
      ck_assert_int_eq(resault, 1);
    }
  }
}
END_TEST

// S21 FLOOR

START_TEST(s21_floor_Check) {
  long int N = 1000000000000000;
  int resault = 0;
  double x;
  for (int i = 0; i < 100; i++) {
    int inf = 0, nan = 0;
    x = (double)(rand()) / RAND_MAX * N;
    double res_s21 = s21_floor(x);
    double res_origin = floor(x);
    if (isnan(res_s21) != 0 && isnan(res_origin) != 0) {
      nan = 1;
    }

    if (isinf(res_s21) != 0 && isinf(res_origin) != 0) {
      inf = 1;
    }

    if (fabs(res_origin - res_s21) <= S21_EPSILON * fabs(res_origin) &&
        inf != 1 && nan != 1) {
      resault = 1;
    }
    if (resault == 1) {
      ck_assert_int_eq(resault, 1);
    }
  }

  for (int i = 0; i < 5; i++) {
    x = statMeanArr[i];
    double res_s21 = s21_floor(x);
    double res_origin = floor(x);
    if (res_s21 == res_origin) {
      resault = 1;
    }
    if (resault == 1) {
      ck_assert_int_eq(resault, 1);
    }
  }
}
END_TEST

// S21 FMOD

START_TEST(s21_fmod_Check) {
  long int N = 1000000000000000;
  int resault = 0;
  double x, y;
  for (int i = 0; i < 100; i++) {
    int inf = 0, nan = 0;
    x = (double)(rand()) / RAND_MAX * N;
    y = (double)(rand()) / RAND_MAX * N;
    double res_s21 = s21_fmod(x, y);
    double res_origin = fmod(x, y);
    if (isnan(res_s21) != 0 && isnan(res_origin) != 0) {
      nan = 1;
    }

    if (isinf(res_s21) != 0 && isinf(res_origin) != 0) {
      inf = 1;
    }

    if (fabs(res_origin - res_s21) <= S21_EPSILON * fabs(res_origin) &&
        inf != 1 && nan != 1) {
      resault = 1;
    }
    if (resault == 1) {
      ck_assert_int_eq(resault, 1);
    }
  }

  for (int i = 0; i < STAT_MEAN_ARR_LONG; i++) {
    x = statMeanArr[i];
    y = (double)(rand()) / RAND_MAX * N;
    double res_s21 = s21_fmod(x, y);
    double res_origin = fmod(x, y);
    if (res_s21 == res_origin) {
      resault = 1;
    }
    if (resault == 1) {
      ck_assert_int_eq(resault, 1);
    }
  }

  for (int i = 0; i < STAT_MEAN_ARR_LONG; i++) {
    x = (double)(rand()) / RAND_MAX * N;
    y = statMeanArr[i];
    double res_s21 = s21_fmod(x, y);
    double res_origin = fmod(x, y);
    if (res_s21 == res_origin) {
      resault = 1;
    }
    if (resault == 1) {
      ck_assert_int_eq(resault, 1);
    }
  }

  for (int i = 0; i < STAT_MEAN_ARR_LONG; i++) {
    x = statMeanArr[i];
    y = statMeanArr[i];
    double res_s21 = s21_fmod(x, y);
    double res_origin = fmod(x, y);
    if (res_s21 == res_origin) {
      resault = 1;
    }
    if (resault == 1) {
      ck_assert_int_eq(resault, 1);
    }
  }
}
END_TEST

// S21 EXP

START_TEST(s21_exp_Check) {
  int N = 10000;
  int resault = 0;
  for (int i = 0; i < 100; i++) {
    int inf = 0, nan = 0;
    double x = pow((-1), i) * (double)(rand()) / RAND_MAX * N;
    double res_s21 = s21_exp(x);
    double res_origin = exp(x);
    if (isnan(res_s21) != 0 && isnan(res_origin) != 0) {
      nan = 1;
    }

    if (isinf(res_s21) != 0 && isinf(res_origin) != 0) {
      inf = 1;
    }
    if (inf != 1 && nan != 1) {
      while (res_s21 >= 9999999999999999) {
        res_s21 = res_s21 / 10;
      }

      while (res_origin >= 9999999999999999) {
        res_origin = res_origin / 10;
      }
      if ((__int128_t)res_s21 == (__int128_t)res_origin) {
        resault = 1;
      }
      if (resault == 1) {
        ck_assert_int_eq(resault, 1);
      }
    }
  }
}
END_TEST

// S21 LOG

START_TEST(s21_log_Check) {
  long int N = 1000000;
  int resault = 0;
  double x;
  for (int i = 0; i < 100; i++) {
    int inf = 0, nan = 0;
    x = pow(-1, i) * (double)(rand()) / RAND_MAX * N;
    double res_s21 = s21_log(x);
    double res_origin = log(x);
    if (isnan(res_s21) != 0 && isnan(res_origin) != 0) {
      nan = 1;
    }

    if (isinf(res_s21) != 0 && isinf(res_origin) != 0) {
      inf = 1;
    }

    if (fabs(res_origin - res_s21) <= S21_EPSILON * fabs(res_origin) &&
        inf != 1 && nan != 1) {
      resault = 1;
    }
    if (resault == 1) {
      ck_assert_int_eq(resault, 1);
    }
  }

  for (int i = 0; i < STAT_MEAN_ARR_LONG; i++) {
    x = statMeanArr[i];
    double res_s21 = s21_log(x);
    double res_origin = log(x);
    if (res_s21 == res_origin) {
      resault = 1;
    }
    if (resault == 1) {
      ck_assert_int_eq(resault, 1);
    }
  }
}
END_TEST

// S21 POW

START_TEST(s21_pow_Check) {
  long int N = 10000;
  int resault = 0;
  double x, y;
  for (int i = 0; i < 100; i++) {
    int inf = 0, nan = 0;
    x = pow(-1, i) * (double)(rand()) / RAND_MAX * N;
    y = (double)(rand()) / RAND_MAX * N;
    double res_s21 = s21_pow(x, y);
    double res_origin = pow(x, y);
    if (isnan(res_s21) != 0 && isnan(res_origin) != 0) {
      nan = 1;
    }

    if (isinf(res_s21) != 0 && isinf(res_origin) != 0) {
      inf = 1;
    }

    if (fabs(res_origin - res_s21) <= S21_EPSILON * fabs(res_origin) &&
        inf != 1 && nan != 1) {
      resault = 1;
    }
    if (resault == 1) {
      ck_assert_int_eq(resault, 1);
    }
  }

  for (int i = 0; i < STAT_MEAN_ARR_LONG; i++) {
    x = statMeanArr[i];
    y = (double)(rand()) / RAND_MAX * N;
    double res_s21 = s21_pow(x, y);
    double res_origin = pow(x, y);
    if (res_s21 == res_origin) {
      resault = 1;
    }
    if (resault == 1) {
      ck_assert_int_eq(resault, 1);
    }
  }

  for (int i = 0; i < STAT_MEAN_ARR_LONG; i++) {
    x = (double)(rand()) / RAND_MAX * N;
    y = statMeanArr[i];
    double res_s21 = s21_pow(x, y);
    double res_origin = pow(x, y);
    if (res_s21 == res_origin) {
      resault = 1;
    }
    if (resault == 1) {
      ck_assert_int_eq(resault, 1);
    }
  }

  for (int i = 0; i < STAT_MEAN_ARR_LONG; i++) {
    x = statMeanArr[i];
    y = statMeanArr[i];
    double res_s21 = s21_pow(x, y);
    double res_origin = pow(x, y);
    if (res_s21 == res_origin) {
      resault = 1;
    }
    if (resault == 1) {
      ck_assert_int_eq(resault, 1);
    }
  }
}
END_TEST

// S21 SIN

START_TEST(s21_sin_Check) {
  long int N = 10000000000;
  int resault = 0;
  double x;
  for (int i = 0; i < 100; i++) {
    int inf = 0, nan = 0;
    x = pow(-1, i) * (double)(rand()) / RAND_MAX * N;
    double res_s21 = s21_sin(x);
    double res_origin = sin(x);
    if (isnan(res_s21) != 0 && isnan(res_origin) != 0) {
      nan = 1;
    }

    if (isinf(res_s21) != 0 && isinf(res_origin) != 0) {
      inf = 1;
    }

    if (fabs(res_origin - res_s21) <= S21_EPSILON * fabs(res_origin) &&
        inf != 1 && nan != 1) {
      resault = 1;
    }
    if (resault == 1) {
      ck_assert_int_eq(resault, 1);
    }
  }

  for (int i = 0; i < STAT_MEAN_ARR_LONG; i++) {
    x = statMeanArr[i];
    double res_s21 = s21_sin(x);
    double res_origin = sin(x);
    if (res_s21 == res_origin) {
      resault = 1;
    }
    if (resault == 1) {
      ck_assert_int_eq(resault, 1);
    }
  }
}
END_TEST

// S21 COS

START_TEST(s21_cos_Check) {
  long int N = 10000000000;
  int resault = 0;
  double x;
  for (int i = 0; i < 100; i++) {
    int inf = 0, nan = 0;
    x = pow(-1, i) * (double)(rand()) / RAND_MAX * N;
    double res_s21 = s21_cos(x);
    double res_origin = cos(x);
    if (isnan(res_s21) != 0 && isnan(res_origin) != 0) {
      nan = 1;
    }

    if (isinf(res_s21) != 0 && isinf(res_origin) != 0) {
      inf = 1;
    }

    if (fabs(res_origin - res_s21) <= S21_EPSILON * fabs(res_origin) &&
        inf != 1 && nan != 1) {
      resault = 1;
    }
    if (resault == 1) {
      ck_assert_int_eq(resault, 1);
    }
  }

  for (int i = 0; i < STAT_MEAN_ARR_LONG; i++) {
    x = statMeanArr[i];
    double res_s21 = s21_cos(x);
    double res_origin = cos(x);
    if (res_s21 == res_origin) {
      resault = 1;
    }
    if (resault == 1) {
      ck_assert_int_eq(resault, 1);
    }
  }
}
END_TEST

// S21 TAN

START_TEST(s21_tan_Check) {
  long int N = 10000000000;
  int resault = 0;
  double x;
  for (int i = 0; i < 100; i++) {
    int inf = 0, nan = 0;
    x = pow(-1, i) * (double)(rand()) / RAND_MAX * N;
    double res_s21 = s21_tan(x);
    double res_origin = tan(x);
    if (isnan(res_s21) != 0 && isnan(res_origin) != 0) {
      nan = 1;
    }

    if (isinf(res_s21) != 0 && isinf(res_origin) != 0) {
      inf = 1;
    }

    if (fabs(res_origin - res_s21) <= S21_EPSILON * fabs(res_origin) &&
        inf != 1 && nan != 1) {
      resault = 1;
    }
    if (resault == 1) {
      ck_assert_int_eq(resault, 1);
    }
  }

  for (int i = 0; i < STAT_MEAN_ARR_LONG; i++) {
    x = statMeanArr[i];
    double res_s21 = s21_tan(x);
    double res_origin = tan(x);
    if (res_s21 == res_origin) {
      resault = 1;
    }
    if (resault == 1) {
      ck_assert_int_eq(resault, 1);
    }
  }
}
END_TEST

// S21 ASIN

START_TEST(s21_asin_Check) {
  long int N = 10000000000;
  int resault = 0;
  double x;
  for (int i = 0; i < 100; i++) {
    int inf = 0, nan = 0;
    x = pow(-1, i) * (double)(rand()) / RAND_MAX * N;
    double res_s21 = s21_asin(x);
    double res_origin = asin(x);
    if (isnan(res_s21) != 0 && isnan(res_origin) != 0) {
      nan = 1;
    }

    if (isinf(res_s21) != 0 && isinf(res_origin) != 0) {
      inf = 1;
    }

    if (fabs(res_origin - res_s21) <= S21_EPSILON * fabs(res_origin) &&
        inf != 1 && nan != 1) {
      resault = 1;
    }
    if (resault == 1) {
      ck_assert_int_eq(resault, 1);
    }
  }

  for (int i = 0; i < STAT_MEAN_ARR_LONG; i++) {
    x = statMeanArr[i];
    double res_s21 = s21_asin(x);
    double res_origin = asin(x);
    if (res_s21 == res_origin) {
      resault = 1;
    }
    if (resault == 1) {
      ck_assert_int_eq(resault, 1);
    }
  }
}
END_TEST

// S21 ACOS

START_TEST(s21_acos_Check) {
  long int N = 10000000000;
  int resault = 0;
  double x;
  for (int i = 0; i < 100; i++) {
    int inf = 0, nan = 0;
    x = pow(-1, i) * (double)(rand()) / RAND_MAX * N;
    double res_s21 = s21_acos(x);
    double res_origin = acos(x);
    if (isnan(res_s21) != 0 && isnan(res_origin) != 0) {
      nan = 1;
    }

    if (isinf(res_s21) != 0 && isinf(res_origin) != 0) {
      inf = 1;
    }

    if (fabs(res_origin - res_s21) <= S21_EPSILON * fabs(res_origin) &&
        inf != 1 && nan != 1) {
      resault = 1;
    }
    if (resault == 1) {
      ck_assert_int_eq(resault, 1);
    }
  }

  for (int i = 0; i < STAT_MEAN_ARR_LONG; i++) {
    x = statMeanArr[i];
    double res_s21 = s21_acos(x);
    double res_origin = acos(x);
    if (res_s21 == res_origin) {
      resault = 1;
    }
    if (resault == 1) {
      ck_assert_int_eq(resault, 1);
    }
  }
}
END_TEST

// S21 ATAN

START_TEST(s21_atan_Check) {
  long int N = 10000000000;
  int resault = 0;
  double x;
  for (int i = 0; i < 100; i++) {
    int inf = 0, nan = 0;
    x = pow(-1, i) * (double)(rand()) / RAND_MAX * N;
    double res_s21 = s21_atan(x);
    double res_origin = atan(x);
    if (isnan(res_s21) != 0 && isnan(res_origin) != 0) {
      nan = 1;
    }

    if (isinf(res_s21) != 0 && isinf(res_origin) != 0) {
      inf = 1;
    }

    if (fabs(res_origin - res_s21) <= S21_EPSILON * fabs(res_origin) &&
        inf != 1 && nan != 1) {
      resault = 1;
    }
    if (resault == 1) {
      ck_assert_int_eq(resault, 1);
    }
  }

  for (int i = 0; i < STAT_MEAN_ARR_LONG; i++) {
    x = statMeanArr[i];
    double res_s21 = s21_atan(x);
    double res_origin = atan(x);
    if (res_s21 == res_origin) {
      resault = 1;
    }
    if (resault == 1) {
      ck_assert_int_eq(resault, 1);
    }
  }
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("StringSuite");
  SRunner *sr = srunner_create(s1);
  int nf;

  // ADD CASES

  // S21 ABS

  TCase *s21_abs_Case = tcase_create("s21_abs_Check");
  suite_add_tcase(s1, s21_abs_Case);

  // S21 FABS

  TCase *s21_fabs_Case = tcase_create("s21_fabs_Check");
  suite_add_tcase(s1, s21_fabs_Case);

  // S21 SQRT

  TCase *s21_sqrt_Case = tcase_create("s21_sqrt_Check");
  suite_add_tcase(s1, s21_sqrt_Case);

  // S21 CEIL

  TCase *s21_ceil_Case = tcase_create("s21_ceil__Check");
  suite_add_tcase(s1, s21_ceil_Case);

  // S21 FLOOR

  TCase *s21_floor_Case = tcase_create("s21_floor_Check");
  suite_add_tcase(s1, s21_floor_Case);

  // S21 FMOD

  TCase *s21_fmod_Case = tcase_create("s21_fmod_Check");
  suite_add_tcase(s1, s21_fmod_Case);

  // S21 EXP

  TCase *s21_exp_Case = tcase_create("s21_exp_Check");
  suite_add_tcase(s1, s21_exp_Case);

  // S21 LOG

  TCase *s21_log_Case = tcase_create("s21_log_Check");
  suite_add_tcase(s1, s21_log_Case);

  // S21 POW

  TCase *s21_pow_Case = tcase_create("s21_pow_Check");
  suite_add_tcase(s1, s21_pow_Case);

  // S21 SIN

  TCase *s21_sin_Case = tcase_create("s21_sin_Check");
  suite_add_tcase(s1, s21_sin_Case);

  // S21 COS

  TCase *s21_cos_Case = tcase_create("s21_cos_Check");
  suite_add_tcase(s1, s21_cos_Case);

  // S21 TAN

  TCase *s21_tan_Case = tcase_create("s21_tan_Check");
  suite_add_tcase(s1, s21_tan_Case);

  // S21 ASIN

  TCase *s21_asin_Case = tcase_create("s21_asin_Check");
  suite_add_tcase(s1, s21_asin_Case);

  // S21 ACOS

  TCase *s21_acos_Case = tcase_create("s21_acos_Check");
  suite_add_tcase(s1, s21_acos_Case);

  // S21 ATAN

  TCase *s21_atan_Case = tcase_create("s21_atan_Check");
  suite_add_tcase(s1, s21_atan_Case);

  // ADD TESTS

  // S21 ABS +

  tcase_add_test(s21_abs_Case, s21_abs_Check);

  // S21 FABS +

  tcase_add_test(s21_fabs_Case, s21_fabs_Check);

  // S21 SQRT +

  tcase_add_test(s21_sqrt_Case, s21_sqrt_Check);

  // S21 CEIL +

  tcase_add_test(s21_ceil_Case, s21_ceil_Check);

  // S21 FLOOR +

  tcase_add_test(s21_floor_Case, s21_floor_Check);

  // S21 FMOD +

  tcase_add_test(s21_fmod_Case, s21_fmod_Check);

  // S21 EXP +

  tcase_add_test(s21_exp_Case, s21_exp_Check);

  // S21 LOG +

  tcase_add_test(s21_log_Case, s21_log_Check);

  // S21 POW +

  tcase_add_test(s21_pow_Case, s21_pow_Check);

  // S21 SIN +

  tcase_add_test(s21_sin_Case, s21_sin_Check);

  // S21 COS +

  tcase_add_test(s21_cos_Case, s21_cos_Check);

  // S21 TAN +

  tcase_add_test(s21_tan_Case, s21_tan_Check);

  // S21 ASIN +

  tcase_add_test(s21_asin_Case, s21_asin_Check);

  // S21 ACOS +

  tcase_add_test(s21_acos_Case, s21_acos_Check);

  // S21 ATAN +

  tcase_add_test(s21_atan_Case, s21_atan_Check);

  //  Запустить всё это дело
  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}

 // ПРИМЕРЧИК ОСТАВИМ
