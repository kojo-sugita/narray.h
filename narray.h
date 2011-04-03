
#ifndef _NARRAY_H_
#define _NARRAY_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* fold用 */
#define FOLD_ADD 1
#define FOLD_SUB 2
#define FOLD_MULT 3
#define FOLD_DIV 4

void init_array(double *a, double init, size_t n);
void init_array_i(int *a, int init, size_t n);
int equals_array(double *a1, double *a2, size_t n);
int equals_array_i(int *a1, int *a2, size_t n);
double *arycpy(double *dst, const double *src, size_t n);
int *arycpy_i(int *dst, const int *src, size_t n);
void sort(double *base, size_t n, int (*compar)(const double *, const double *));
void sort_i(int *base, size_t n, int (*compar)(const int *, const int *));
int replace(const double *source, double *result, int (*predicate)(double), double substitution, size_t n);
int replace_i(const int *source, int *result, int (*predicate)(int), int substitution, size_t n);
int threshold(const double *source, double *result, double threshold, double substitution, size_t n);
int threshold_i(const int *source, int *result, int threshold, int substitution, size_t n);
int filter(const double *source, double *result, int (*predicate)(double), size_t n);
int filter_i(const int *source, int *result, int (*predicate)(int), size_t n);
int map(const double *source, double *result, double (*func)(double), size_t n);
int map_i(const int *source, int *result, int (*func)(int), size_t n);
double foldl(int mode, double init, const double *ary, int from, int to);
int foldl_i(int mode, int init, const int *ary, int from, int to);
double foldr(int mode, double init, const double *ary, int from, int to);
int foldr_i(int mode, int init, const int *ary, int from, int to);

#endif /*_NARRAY_H_*/
