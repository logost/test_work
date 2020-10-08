/**
 
Implement a function to compute the array of fourth roots from the input array with the type float.
Implement a function to compute a number y, where y = (1/x) mod N,  0<x<N, N is prime number; x,y belong to GF(N)
 
Please use C language and do not use standard or 3rd party libraries for computations.
 
For each task the code should contain,
a processing function that implements the requested algorithm
a test function that checks the outcome of the processing function
‘main’ function that generates input data for the processing functions and checks the processing outcome
 
*/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <errno.h>
#include "fourth_roots.h"
#include "test.h"

int main(int argc, char** argv)
{
    if (argc == 2 && argv[1][0]=='t')
        return tests();

    float *vec = malloc(1000000*sizeof(float));
    float *res = malloc(1000000*sizeof(float));
    if (!vec || !res)
        return -ENOMEM;

    for (int i = 0; i < 1000000; i++) {
        vec[i] =  (float)rand()/(float)(__FLT_MAX__);;
    }

    {
        clock_t start = clock(), diff;
        compute_fourth_roots(vec, res, 1000000, 0.000001);
        diff = clock() - start;

        int msec = diff * 1000 / CLOCKS_PER_SEC;
        printf("Calcultaing 1 000 000 fourth roots taken %d seconds %d milliseconds", msec/1000, msec%1000);
    }

    return 0;
}