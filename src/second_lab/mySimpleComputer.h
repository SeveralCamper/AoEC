#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#include <stdio.h>
#include <stdlib.h>

#define S21_PI 3.14159265358979323846

#define S21_EPS 1e-250
#define S21_EPSILON 0.0000001

#define S21_NANF __builtin_nanf("0x7fc00000")
#define S21_INFL __builtin_infl()
#define S21_HUGE_VAL __builtin_huge_vall()

long int s21_abs(int x);
long double s21_fabs(double x);
long double s21_sqrt(double x);
long double s21_ceil(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_pow(double base, double exp);

long double s21_row(int free_member, int sign, int step, int start_pow,
                    double x);

long double s21_exp(double x);
long double s21_sin(double x);
long double s21_cos(double x);
long double s21_tan(double x);

long double s21_log(double x);

long double s21_atan(double x);
long double s21_asin(double x);
long double s21_acos(double x);

#endif  //  SRC_S21_MATH_H_
