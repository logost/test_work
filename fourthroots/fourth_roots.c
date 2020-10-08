#include <errno.h>

static float _fabs(float val)
{
    if (val < 0)
        return -val;

    return val;
}
float fourth_root(float val, float epsilon)
{
    float res;
    float x, x_prev;

    do {
        x_prev = x;
        x = 1/4*(3*x  + val/(x*x*x));
    } while (_fabs(x - x_prev) > epsilon);

    res = x;

    return res;
}

int compute_fourth_roots(float *in, float *out, unsigned int len, float epsilon)
{
    float *end = in + len;
    float *res;

    if (!in || !out)
        return -EINVAL;

    do {
        *out = fourth_root(*in, epsilon);
        in++;
        out++;
    } while (in != end);

    return 0;
}