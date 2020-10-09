#include <stdio.h>
#include <stdint.h>
#include "modular_inverse.h"

uint32_t inverse(uint32_t a, uint32_t n_prime)
{
    int64_t t = 0, newt = 1;
    int64_t r = n_prime, newr = a;

    while (newr != 0) {
        int64_t tmp = newt;
        uint32_t quitient = r / newr;

        newt = t - quitient * newt;
        t = tmp;
        tmp = newr;
        newr = r - quitient * newr;
        r = tmp;
    }

    if (t < 0) {
        t = t + n_prime;
    }

    return t;
}
