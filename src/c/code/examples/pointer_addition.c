#include <stdio.h>
#include <stdlib.h>

double sum0(size_t len, double const* a) {
    double ret = 0.0;

    for (size_t i = 0; i < len; i++) {
        ret += *(a + i);
    }

    return ret;
}

double sum1(size_t len, double const* a) {
    double ret = 0.0;

    for (double const* p = a; p < a+len; p++) {
        ret += *p;
    }

    return ret;
}

double sum2(size_t len, double const* a) {
    double ret = 0.0;

    for (double const* const aStop = a+len; a < aStop; a++) {
        ret += *a;
    }

    return ret;
}
