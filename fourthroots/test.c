#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "fourth_roots.h"

#define CHECK_INT(COND, EXPECTED) ({\
    int _ret = 0; \
    do {\
        typeof(COND) _cond = COND; \
        if (_cond != (EXPECTED)) \
            printf("%s = %d instead of %d\n", #COND, _cond, (EXPECTED)) ; \
    } while (0); \
    _ret; })

#define CHECK_FLOAT(COND, EXPECTED, EPSILON) ({ \
    int _ret = 0; \
    do {\
        typeof(COND) _cond = COND; \
        printf("checking %.38f against %.38f\n", _cond, EXPECTED);\
        if (fabs(_cond - (EXPECTED)) > EPSILON) { \
            printf("%s = %.38f instead of %.38f\n", #COND, _cond, (EXPECTED)); \
            _ret = -1; \
        } \
    } while (0); \
    (ret); })

struct test_case_t {
    unsigned int len;
    float epsilon;
    float vec[];
};

static struct test_case_t test_vec_1 = {1, __FLT_EPSILON__, 16.0};
static struct test_case_t test_vec_2 = {2, __FLT_EPSILON__, {16.0, 81.0}};
static struct test_case_t test_vec_max = {1, __FLT_EPSILON__, __FLT_MAX__};
static struct test_case_t test_vec_0 = {0, __FLT_EPSILON__, 0};
static struct test_case_t test_vec_09 = {4, __FLT_EPSILON__/ 1e7, {0.6561, 0.00006561, 0.000000006561, 0.0000000000006561}};
static struct test_case_t test_vec_min = {5, __FLT_EPSILON__ / 1e10, {__FLT_EPSILON__, __FLT_EPSILON__*__FLT_EPSILON__, __FLT_EPSILON__*__FLT_EPSILON__*__FLT_EPSILON__*__FLT_EPSILON__, __FLT_EPSILON__*__FLT_EPSILON__*__FLT_EPSILON__*__FLT_EPSILON__*__FLT_EPSILON__, __FLT_MIN__}};
struct test_case_t test_vec_neg = {1, __FLT_EPSILON__, -1.0};

static int test_vec(struct test_case_t *tc)
{
    float *res = malloc(tc->len * sizeof(float));
    int ret = 0;

    if (!res)
        return -1;

    CHECK_INT(compute_fourth_roots(tc->vec, res, tc->len, tc->epsilon), 0);
    for(int i = 0; i < tc->len; i++)
        ret |= CHECK_FLOAT(res[i], (float)sqrt(sqrt(tc->vec[i])), tc->epsilon);

    return ret;
}

static int test_neg(struct test_case_t *tc)
{
    float *res = malloc(tc->len * sizeof(float));
    int ret = 0;

    if (!res)
        return -1;

    CHECK_INT(compute_fourth_roots(tc->vec, res, tc->len, tc->epsilon), 0);
    for(int i = 0; i < tc->len; i++)
        ret |= CHECK_INT(_isnanf(res[i]), 1);

    return ret;
}

int tests()
{
    int res = 0;

    res |= test_vec(&test_vec_1);
    res |= test_vec(&test_vec_2);
    res |= test_vec(&test_vec_max);
    res |= test_vec(&test_vec_0);
    res |= test_vec(&test_vec_09);
    res |= test_vec(&test_vec_min);
    res |= test_neg(&test_vec_neg);

    if (!res)
        printf("Tests PASSED\n");
    else
        printf("Tests FAILED\n");

}