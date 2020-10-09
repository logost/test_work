#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include "modular_inverse.h"
#include "test.h"

/**
Implement a function to compute a number y, where y = (1/x) mod N,  0<x<N, N is prime number; x,y belong to GF(N)
 
Please use C language and do not use standard or 3rd party libraries for computations.
 
For each task the code should contain,
a processing function that implements the requested algorithm
a test function that checks the outcome of the processing function
‘main’ function that generates input data for the processing functions and checks the processing outcome
*/
int main(int argc, char **argv)
{
    if (argc == 2 && argv[1][0] == 't')
        return unit_tests();

    {
        clock_t start = clock(), diff;

        /* check all inverses on base of 10.000.000-th prime number */
        #define PRIME_10_000_000TH 39916801
        for (int i = 1; i < PRIME_10_000_000TH; i++)
            check_inverse(i, inverse(i, PRIME_10_000_000TH), PRIME_10_000_000TH);

        diff = clock() - start;

        int msec = diff * 1000 / CLOCKS_PER_SEC;
        printf("Calcultaing %u inverses taken %d seconds %d milliseconds", PRIME_10_000_000TH - 1, msec/1000, msec%1000);
    }

    return 0;
}