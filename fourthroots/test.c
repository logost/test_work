#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "fourth_roots.h"

#define EPSILON __FLT_EPSILON__

#define CHECK_INT(COND, EXPECTED) \
    do {\
        typeof(COND) _cond = COND; \
        if (_cond != (EXPECTED)) \
            printf("%s = %d instead of %d\n", #COND, _cond, (EXPECTED)) ; \
    } while (0)

#define CHECK_FLOAT(COND, EXPECTED) \
    do {\
        typeof(COND) _cond = COND; \
        if (fabs(_cond - (EXPECTED)) > EPSILON) \
            printf("%s = %.38f instead of %.38f\n", #COND, _cond, (EXPECTED)); \
    } while (0)

struct test_case_t {
    unsigned int len;
    float vec[];
};

static struct test_case_t test_vec_1 = {1, 16.0};
static struct test_case_t test_vec_2 = {2, {16.0, 81.0}};
static struct test_case_t test_vec_max = {1, __FLT_MAX__};
static struct test_case_t test_vec_0 = {0, 0};
static struct test_case_t test_vec_09 = {4, 0.6561, 0.00006561, 0.000000006561, 0.0000000000006561};
static struct test_case_t test_vec_min = {1, __FLT_MIN__};
struct test_case_t test_vec_neg = {1, -1.0};

static int test_vec(struct test_case_t *tc)
{
    float *res = malloc(tc->len * sizeof(float));

    if (!res)
        return -1;

    CHECK_INT(compute_fourth_roots(tc->vec, res, tc->len, EPSILON), 0);
    for(int i = 0; i < tc->len; i++)
        CHECK_FLOAT(res[i], (float)sqrt(sqrt(tc->vec[i])));

    return 0;
}

static int test_neg(struct test_case_t *tc)
{
    float *res = malloc(tc->len * sizeof(float));

    if (!res)
        return -1;

    CHECK_INT(compute_fourth_roots(tc->vec, res, tc->len, EPSILON), 0);
    for(int i = 0; i < tc->len; i++)
        CHECK_INT(_isnanf(res[i]), 1);


    return 0;
}

int tests()
{
    int res = 0;

    res |= test_vec(&test_vec_1);
    res |= test_vec(&test_vec_2);
    res |= test_vec(&test_vec_max);
    res |= test_vec(&test_vec_0);
    res |= test_vec(&test_vec_09);
    res |= test_neg(&test_vec_neg);

    if (!res)
        printf("Tests PASSED\n");
    else
        printf("Tests FAILED\n");

}