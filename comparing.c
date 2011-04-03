/**
 * @file    comparing.c
 * @brief   述語関数群
 *
 * @author  Kojo Sugita
 * @date    2009-09-22
 */

#include "comparing.h"

/**
 * 正なら真を返す
 */
int positive(double x)
{
    return ((x >= 0)? 1 : 0);
}

/**
 * 正なら真を返す
 */
int positive_i(int x)
{
    return ((x >= 0)? 1 : 0);
}

/**
 * 負なら真を返す
 */
int negative(double x)
{
    return ((x < 0)? 1 : 0);
}

/**
 * 負なら真を返す
 */
int negative_i(int x)
{
    return ((x < 0)? 1 : 0);
}

/**
 * 0なら真を返す
 */
int zero(double x)
{
    return ((x == 0)? 1 : 0);
}

/**
 * 0なら真を返す
 */
int zero_i(int x)
{
    return ((x == 0)? 1 : 0);
}

/**
 * 偶数なら真を返す
 */
int even(int n)
{
    return ((n % 2 == 0)? 1 : 0);
}

/**
 * 奇数なら真を返す
 */
int odd(int n)
{
    return ((n % 2 != 0)? 1 : 0);
}

/**
 * 比較関数（昇順）
 */
int asc(const double *val1, const double *val2)
{
    if ( *val1 < *val2 ) {
        return -1;
    } else if ( *val1 == * val2 ) {
        return 0;
    } else {
        return 1;
    }
}

/**
 * 比較関数（昇順）
 */
int asc_i(const int *val1, const int *val2)
{
    return *val1 - *val2;
}

/**
 * 比較関数（降順）
 */
int desc(const double *val1, const double *val2)
{
    if ( *val1 > *val2 ) {
        return -1;
    } else if ( *val1 == * val2 ) {
        return 0;
    } else {
        return 1;
    }
}

/**
 * 比較関数（降順）
 */
int desc_i(const int *val1, const int *val2)
{
    return *val2 - *val1;
}

/**
 * 比較関数（絶対値の昇順）
 */
int abs_asc(const double *val1, const double *val2)
{
    double diff;
    diff = fabs(*val1) - fabs(*val2);

    if ( diff > 0 ) {
        return 1;
    } else if ( diff = 0 ) {
        return 0;
    } else {
        return -1;
    }
}

/**
 * 比較関数（絶対値の昇順）
 */
int abs_asc_i(const int *val1, const int *val2)
{
    return (int)(fabs((double)*val1) - fabs((double)*val2));
}

/**
 * 比較関数（絶対値の降順）
 */
int abs_desc(const double *val1, const double *val2)
{
    double diff;
    diff = fabs(*val1) - fabs(*val2);

    if ( diff < 0 ) {
        return 1;
    } else if ( diff = 0 ) {
        return 0;
    } else {
        return -1;
    }
}

/**
 * 比較関数（絶対値の降順）
 */
int abs_desc_i(const int *val1, const int *val2)
{
    return (int)(fabs((double)*val2) - fabs((double)*val1));
}
