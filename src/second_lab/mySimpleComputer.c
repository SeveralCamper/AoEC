#include "mySimpleComputer.h"

/* #define STAT_MEAN_ARR_LONG 7

const long double statMeanArr[STAT_MEAN_ARR_LONG] = {
    S21_NANF, -S21_NANF, S21_INFL, -S21_INFL, 0, 1, -1}; */


/* int main() {
  long int N = 100000;
  int resault = 0;
  double x;
  for (int i = 0; i < 100; i++) {
    int inf = 0, nan = 0;
    x = pow(-1, i) * (double)(rand()) / RAND_MAX * N;
    printf("\n\n%lf\n", x);
    double res_s21 = s21_atan(x);
    double res_origin = atan(x);
    printf("S21: %lf\n", res_s21);
    printf("ORIGIN: %lf\n", res_origin);
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
      printf("WIN");
    }
  }

  for (int i = 0; i < STAT_MEAN_ARR_LONG; i++) {
    x = statMeanArr[i];
    double res_s21 = s21_atan(x);
    double res_origin = atan(x);
    printf("\n\n%lf\n", x);
    printf("\n\nS21: %lf\n", res_s21);
    printf("ORIGIN: %lf\n\n", res_origin);
    if (res_s21 == res_origin) {
      resault = 1;
    }
    if (resault == 1) {
      printf("WIN");
    }
  }
} */
