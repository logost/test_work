#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "fourth_roots.h"

#define CHECK_INT(COND, EXPECTED) \
    do {\
        typeof(COND) _cond = COND; \
        if (_cond != (EXPECTED)) \
            printf("%s = %d instead of %d\n", #COND, _cond, (EXPECTED)) ; \
    } while (0)

#define EPSILON 0.0000001
#define CHECK_FLOAT(COND, EXPECTED) \
    do {\
        typeof(COND) _cond = COND; \
        if (abs(_cond - (EXPECTED)) > EPSILON) \
            printf("%s = %f instead of %f\n", #COND, _cond, (EXPECTED)); \
    } while (0)

struct test_case_t {
    unsigned int len;
    float vec[];
};

static struct test_case_t test_vec_1 = {16.0, 1};
static struct test_case_t test_vec_2 = {16.0, 81.0, 2};

static int test_vec(struct test_case_t *tc)
{
    float *res = malloc(tc->len * sizeof(float));

    if (!res)
        return -1;

    CHECK_INT(compute_fourth_roots(tc->vec, res, tc->len, __FLT_EPSILON__), 0);
    for(int i = 0; i < tc->len; i++)
        CHECK_FLOAT(res[i], sqrt(sqrt(tc->vec[i])));

    return 0;
}

int tests()
{
    int res = 0;

    res |= test_vec(&test_vec_1);
    res |= test_vec(&test_vec_2);

    if (!res)
        printf("Tests PASSED\n");
    else
        printf("Tests FAILED\n");

}