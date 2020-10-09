#include <stdio.h>
#include <stdint.h>
#include "modular_inverse.h"
#include "test.h"

int check_inverse(uint32_t num, uint32_t inv, uint32_t modular)
{
    int ret = 0;
    uint32_t mul;
    
    mul = ((uint64_t)inv * num) % modular;

    if (mul != 1) {
        printf("inverse(%u, %u) = %u incorrect: %u * %u mod %u == %u\n", num, modular, inv, inv, num, modular, mul);
        ret = -1;
    }

    return ret;
}

#define TEST_INVERSE(NUM, MODULAR) \
    check_inverse((NUM), inverse((NUM), (MODULAR)), (MODULAR))

int unit_tests()
{
    int ret = 0;

    /* check the example from the webpage */
    ret |= TEST_INVERSE(17, 29);
    /* check the inverse by modular of max 32-bit prime number */
    ret |= TEST_INVERSE(17, 4294967291);

    /* check all inverses by modular of 1000-th prime number */
    for (int i = 1; i < 7919; i++)
        ret |= TEST_INVERSE(i, 7919);

    if (!ret)
        printf("Tests PASSED\n");
    else
        printf("Tests FAILED\n");
        
}