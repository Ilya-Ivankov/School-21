#include "data_stat.h"

double variance(double *data, int n) {
    double variance_v = 0.0;
    double mean_v_v = mean(data, n);
    for (double *p = data; p - data < n; p++) {
        variance_v += (((*p - mean_v_v) * (*p - mean_v_v)) * (1.0 / (double)n));
    }
    return variance_v;
}

double mean(double *data, int n) {
    double meane_v = 0.0;
    for (double *p = data; p - data < n; p++) {
        meane_v += *p * (1.0 / (double)n);
    }

    return meane_v;
}

double max(double *data, int n) {
    double max_x = *data;
    for (double *p = data; p - data < n; p++) {
        if (*p > max_x) {
            max_x = *p;
        }
    }
    return max_x;
}

double min(double *data, int n) {
    double min_x = *data;
    for (double *p = data; p - data < n; p++) {
        if (*p < min_x) {
            min_x = *p;
        }
    }
    return min_x;
}

void sort(double *data, int n) {
    double temp;
    for (double *p = data; p - data < n; p++) {
        for (double *pp = data; pp - data < n - (p - data) - 1; pp++) {
            if (*pp > *(pp + 1)) {
                temp = *pp;
                *pp = *(pp + 1);
                *(pp + 1) = temp;
            }
        }
    }
}
