
#ifndef _COMPARING_H_
#define _COMPARING_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int positive(double x);
int positive_i(int x);
int negative(double x);
int negative_i(int x);
int zero(double x);
int zero_i(int x);
int even(int n);
int odd(int n);
int asc(const double *val1, const double *val2);
int asc_i(const int *val1, const int *val2);
int desc(const double *val1, const double *val2);
int desc_i(const int *val1, const int *val2);
int abs_asc(const double *val1, const double *val2);
int abs_asc_i(const int *val1, const int *val2);
int abs_desc(const double *val1, const double *val2);
int abs_desc_i(const int *val1, const int *val2);

#endif /*_COMPARING_H_*/
