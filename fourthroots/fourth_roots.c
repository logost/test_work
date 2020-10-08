#include <errno.h>
#include <stdio.h>
#include <math.h>

static double _dabs(double val)
{
    if (val < 0)
        return -val;

    return val;
}

float fourth_root(float val, float epsilon)
{
    float res;
    double x = 1, y = val, x_prev;

    if (val < 0)
        return NAN;

    do {
        x_prev = x;
        x = (x_prev + x_prev + x_prev + y / (x_prev * x_prev * x_prev)) * 0.25 ;
    } while (_dabs(x - x_prev) > epsilon);

    res = x;

    return res;
}

int compute_fourth_roots(float *in, float *out, unsigned int len, float epsilon)
{
    float *end = in + len;
    float *res;

    if (!in || !out)
        return -EINVAL;

    if (!len)
        return 0;

    do {
        *out = fourth_root(*in, epsilon);
        in++;
        out++;
    } while (in != end);

    return 0;
}