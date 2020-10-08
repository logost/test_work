
#include <errno.h>

float fourth_root(float val)
{
    float res;

    /* TODO: add actual clculation here */ 
    res = val;

    return res;
}

int compute_fourth_roots(float *in, float *out, unsigned int len)
{
    unsigned int i;
    float *res;

    if (!in || !out)
        return -EINVAL;

    for (i = 0; i < len; i++) {
        *out = fourth_root(*in);
        in++;
        out++;
    }

    return 0;
}