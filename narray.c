/**
 * @file    narray.c
 * @brief   数値配列操作関数群
 *
 * @author  Kojo Sugita
 * @date    2009-09-22
 */

#include "narray.h"

/**
 * double型の配列を初期化する
 * @param[out] a 初期化する配列
 * @param[in] init 初期化データ
 * @param[in] n 配列の要素数
 */
void init_array(double *a, double init, size_t n)
{
    unsigned int i;
    for (i = 0; i < n; i++) {
        a[i] = init;
    }
}

/**
 * int型の配列を初期化する
 * @param[out] a 初期化する配列
 * @param[in] init 初期化データ
 * @param[in] n 配列の要素数
 */
void init_array_i(int *a, int init, size_t n)
{
    unsigned int i;
    for (i = 0; i < n; i++) {
        a[i] = init;
    }
}


/**
 * double型の配列が等しいかどうかを判定する
 * @param[in] a1 配列1
 * @param[in] a2 配列2
 * @param[in] n 比較する配列の要素数
 * @retval 1 等しい
 * @rarval 0 等しくない
 */
int equals_array(double *a1, double *a2, size_t n)
{
    unsigned int i;
    for (i = 0; i < n; i++) {
        if (a1[i] != a2[i]) {
            return 0;
        }
    }
    return 1;
}

/**
 * int型の配列が等しいかどうかを判定する
 * @param[in] a1 配列1
 * @param[in] a2 配列2
 * @param[in] n 比較する配列の要素数
 * @retval 1 等しい
 * @rarval 0 等しくない
 */
int equals_array_i(int *a1, int *a2, size_t n)
{
    unsigned int i;
    for (i = 0; i < n; i++) {
        if (a1[i] != a2[i]) {
            return 0;
        }
    }
    return 1;
}

/**
 * 配列の要素をコピーする
 * @param[out] dst 出力配列
 * @param[in] src 入力配列
 * @param[in] n 配列の要素数
 * @return dst
 */
double *arycpy(double *dst, const double *src, size_t n)
{
    unsigned int i;
    for (i = 0; i < n; i++) {
        dst[i] = src[i];
    }
    return dst;
}

/**
 * 配列の要素をコピーする
 * @param[out] dst 出力配列
 * @param[in] src 入力配列
 * @param[in] n 配列の要素数
 * @return dst
 */
int *arycpy_i(int *dst, const int *src, size_t n)
{
    unsigned int i;
    for (i = 0; i < n; i++) {
        dst[i] = src[i];
    }
    return dst;
}

/**
 * 配列をソートする
 * @param[in/out] base 配列
 * @param[in] n 配列の要素数
 * @param[in] compar 比較関数
 * @return dst
 */
void sort(double *base, size_t n, int (*compar)(const double *, const double *))
{
    /* qsort 関数を使用して並び替える */
    qsort(base, n, sizeof(double), (int (*)(const void *, const void *))compar);
}

/**
 * 配列をソートする
 * @param[in/out] base 配列
 * @param[in] n 配列の要素数
 * @param[in] compar 比較関数
 * @return dst
 */
void sort_i(int *base, size_t n, int (*compar)(const int *, const int *))
{
    /* qsort 関数を使用して並び替える */
    qsort(base, n, sizeof(int), (int (*)(const void *, const void *))compar);
}

/**
 * 配列の値がpredicateで指定された関数で真となる場合substitutionに置き換える
 * @param[in] source 入力配列
 * @param[out] result 出力配列
 * @param[in] predicate 述語を返す関数へのポインタ
 * @param[in] subsitution 置き換える文字
 * @param[in] n 配列の要素数
 * @return 置き換えた数
 */
int replace(const double *source, double *result, int (*predicate)(double), double substitution, size_t n)
{
    unsigned int i;
    int count = 0;

    for ( i = 0; i < n; i++ ) {
        if ( predicate(source[i]) ) {
            result[i] = substitution;
            count++;
        } else {
            result[i] = source[i];
        }
    }

    return count;
}

/**
 * 配列の値がpredicateで指定された関数で真となる場合substitutionに置き換える
 * @param[in] source 入力配列
 * @param[out] result 出力配列
 * @param[in] predicate 述語を返す関数へのポインタ
 * @param[in] subsitution 置き換える文字
 * @param[in] n 配列の要素数
 * @return 置き換えた数
 */
int replace_i(const int *source, int *result, int (*predicate)(int), int substitution, size_t n)
{
    unsigned int i;
    int count = 0;

    for ( i = 0; i < n; i++ ) {
        if ( predicate(source[i]) ) {
            result[i] = substitution;
            count++;
        } else {
            result[i] = source[i];
        }
    }

    return count;
}

/**
 * 配列の値がしきい値以下の場合substitutionに置き換える
 * @param[in] source 入力配列
 * @param[out] result 出力配列
 * @param[in] threshold しきい値
 * @param[in] subsitution 置き換える文字
 * @param[in] n 配列の要素数
 * @return 置き換えた値の個数
 */
int threshold(const double *source, double *result, double threshold, double substitution, size_t n)
{
    unsigned int i;
    int convCount = 0;

    for ( i = 0; i < n; i++ ) {
        /* しきい値よりも大きいか */
        if ( source[i] > threshold ) { /* yes */
            result[i] = source[i];
            convCount++;

        } else { /* no */
            result[i] = substitution;

        }
    }
    return convCount;
}

/**
 * 配列の値がしきい値以下の場合substitutionに置き換える
 * @param[in] source 入力配列
 * @param[out] result 出力配列
 * @param[in] threshold しきい値
 * @param[in] subsitution 置き換える文字
 * @param[in] n 配列の要素数
 * @return 置き換えた値の個数
 */
int threshold_i(const int *source, int *result, int threshold, int substitution, size_t n)
{
    unsigned int i;
    int convCount = 0;

    for ( i = 0; i < n; i++ ) {
        /* しきい値よりも大きいか */
        if ( source[i] > threshold ) { /* yes */
            result[i] = source[i];
            convCount++;

        } else { /* no */
            result[i] = substitution;

        }
    }
    return convCount;
}

/**
 * 配列の値がpredicateで指定された関数で真となる場合のみのデータをresultに格納する
 * @param[in] source 入力配列
 * @param[out] result 出力配列
 * @param[in] predicate 述語を返す関数へのポインタ
 * @param[in] n 配列の要素数
 * @return resultの要素数
 */
int filter(const double *source, double *result, int (*predicate)(double), size_t n)
{
    unsigned int i;
    int j = 0;

    for ( i = 0; i < n; i++ ) {
        if ( predicate(source[i]) ) {
            result[j++] = source[i];
        }
    }

    return j;
}

/**
 * 配列の値がpredicateで指定された関数で真となる場合のみのデータをresultに格納する
 * @param[in] source 入力配列
 * @param[out] result 出力配列
 * @param[in] predicate 述語を返す関数へのポインタ
 * @param[in] n 配列の要素数
 * @return resultの要素数
 */
int filter_i(const int *source, int *result, int (*predicate)(int), size_t n)
{
    unsigned int i;
    int j = 0;

    for ( i = 0; i < n; i++ ) {
        if ( predicate(source[i]) ) {
            result[j++] = source[i];
        }
    }

    return j;
}

/**
 * 配列の要素すべてをfuncで指定された関数の引数として渡し，結果をresultに格納する
 * @param[in] source 入力配列
 * @param[out] result 出力配列
 * @param[in] func 適用する関数
 * @param[in] n 配列の要素数
 * @return resultの要素数
 */
int map(const double *source, double *result, double (*func)(double), size_t n)
{
    unsigned int i;

    for ( i = 0; i < n; i++ ) {
        result[i] = func(source[i]);
    }

    return i;
}

/**
 * 配列の要素すべてをfuncで指定された関数の引数として渡し，結果をresultに格納する
 * @param[in] source 入力配列
 * @param[out] result 出力配列
 * @param[in] func 適用する関数
 * @param[in] n 配列の要素数
 * @return resultの要素数
 */
int map_i(const int *source, int *result, int (*func)(int), size_t n)
{
    unsigned int i;

    for ( i = 0; i < n; i++ ) {
        result[i] = func(source[i]);
    }

    return i;
}

/**
 * 畳み込みを計算する(foldl式)
 * @param[in] mode モード(FOLD_ADD: 和，FOLD_SUB: 差, FOLD_MULTI: 積,  FOLD_DIV: 商)
 * @param[in] init 初期値
 * @param[in] ary 入力配列
 * @param[in] from 開始インデックス
 * @param[in] to 終了インデックス
 * @return resultの要素数
 */
double foldl(int mode, double init, const double *ary, int from, int to)
{
    if ( from <= to ) {
        switch ( mode ) {
            case FOLD_ADD:
                return foldl(mode, init, ary, from, to - 1) + ary[to];
                break;

            case FOLD_SUB:
                return foldl(mode, init, ary, from, to - 1) - ary[to];
                break;

            case FOLD_MULT:
                return foldl(mode, init, ary, from, to - 1) * ary[to];
                break;

            case FOLD_DIV:
                return foldl(mode, init, ary, from, to - 1) / ary[to];
                break;

            default:
                return 0;
                break;
        }

    } else {
        return init;

    }

}

/**
 * 畳み込みを計算する(foldl式)
 * @param[in] mode モード(FOLD_ADD: 和，FOLD_SUB: 差, FOLD_MULTI: 積,  FOLD_DIV: 商)
 * @param[in] init 初期値
 * @param[in] ary 入力配列
 * @param[in] from 開始インデックス
 * @param[in] to 終了インデックス
 * @return 計算結果を返す
 */
int foldl_i(int mode, int init, const int *ary, int from, int to)
{
    if ( from <= to ) {
        switch ( mode ) {
            case FOLD_ADD:
                return foldl_i(mode, init, ary, from, to - 1) + ary[to];
                break;

            case FOLD_SUB:
                return foldl_i(mode, init, ary, from, to - 1) - ary[to];
                break;

            case FOLD_MULT:
                return foldl_i(mode, init, ary, from, to - 1) * ary[to];
                break;

            case FOLD_DIV:
                return foldl_i(mode, init, ary, from, to - 1) / ary[to];
                break;

            default:
                return 0;
                break;
        }

    } else {
        return init;

    }

}

/**
 * 畳み込みを計算する(foldr式)
 * @param[in] mode モード(FOLD_ADD: 和，FOLD_SUB: 差, FOLD_MULTI: 積,  FOLD_DIV: 商)
 * @param[in] init 初期値
 * @param[in] ary 入力配列
 * @param[in] from 開始インデックス
 * @param[in] to 終了インデックス
 * @return resultの要素数
 */
double foldr(int mode, double init, const double *ary, int from, int to)
{
    if ( from <= to ) {
        switch ( mode ) {
            case FOLD_ADD:
                return ary[from] + foldr(mode, init, ary, from + 1, to);
                break;

            case FOLD_SUB:
                return ary[from] - foldr(mode, init, ary, from + 1, to);
                break;

            case FOLD_MULT:
                return ary[from] * foldr(mode, init, ary, from + 1, to);
                break;

            case FOLD_DIV:
                return ary[from] / foldr(mode, init, ary, from + 1, to);
                break;

            default:
                return 0;
                break;
        }

    } else {
        return init;

    }
}

/**
 * 畳み込みを計算する(foldr式)
 * @param[in] mode モード(FOLD_ADD: 和，FOLD_SUB: 差, FOLD_MULTI: 積,  FOLD_DIV: 商)
 * @param[in] init 初期値
 * @param[in] ary 入力配列
 * @param[in] from 開始インデックス
 * @param[in] to 終了インデックス
 * @return 計算結果を返す
 */
int foldr_i(int mode, int init, const int *ary, int from, int to)
{
    if ( from <= to ) {
        switch ( mode ) {
            case FOLD_ADD:
                return ary[from] + foldr_i(mode, init, ary, from + 1, to);
                break;

            case FOLD_SUB:
                return ary[from] - foldr_i(mode, init, ary, from + 1, to);
                break;

            case FOLD_MULT:
                return ary[from] * foldr_i(mode, init, ary, from + 1, to);
                break;

            case FOLD_DIV:
                return ary[from] / foldr_i(mode, init, ary, from + 1, to);
                break;

            default:
                return 0;
                break;
        }

    } else {
        return init;

    }
}
