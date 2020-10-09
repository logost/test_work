#include <stdio.h>
#include <time.h>
#include "modular_inverse.h"

#define CHECK_INVERSE(NUMB, Q) ({\
    int _ret = 0; \
    do { \
        typeof(Q) _q = (Q); \
        typeof(Q) _num = (NUMB); \
        typeof(Q) _inv = inverse(_num, _q); \
        if (((uint64_t)_inv * _num) % _q != 1) { \
            printf("%s = %u incorrect: %u * %u mod %u == %u\n", "inverse(" # NUMB  ", " # Q ")", _inv, _inv, _num, _q, (_inv * _num) % _q) ; \
            _ret = -1; \
        } \
    } while (0); \
    _ret; })

int tests()
{
    int ret = 0;

    /* check the example from the webpage */
    ret |= CHECK_INVERSE(17, 29);
    /* check the inverse on base of max 32-bit prime number */
    ret |= CHECK_INVERSE(17, 4294967291);

    /* check all inverses on base of 1000-th prime number */
    for (int i = 1; i < 7919; i++)
        ret |= CHECK_INVERSE(i, 7919);

    if (!ret)
        printf("Tests PASSED\n");
    else
        printf("Tests FAILED\n");
        
}

int main(int argc, char **argv)
{
    if (argc == 2 && argv[1][0]=='t')
        return tests();

    {
        clock_t start = clock(), diff;

        /* check all inverses on base of 10.000.000-th prime number */
        for (int i = 1; i < 39916801; i++)
            inverse(i, 39916801);
        diff = clock() - start;

        int msec = diff * 1000 / CLOCKS_PER_SEC;
        printf("Calcultaing 39916800 inverses taken %d seconds %d milliseconds", msec/1000, msec%1000);
    }

    return 0;
}