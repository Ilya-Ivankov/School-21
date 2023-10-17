/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even"
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/

#include <math.h>
#include <stdio.h>
#define NMAX 30

int input(int *a, int *n);
void result(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == 1) {
        printf("n/a");
        return 1;
    }
    result(data, n);

    return 0;
}

int input(int *a, int *n) {
    int error = 0;
    if (1 != scanf("%d", n) || *n > 10 || *n < 1) {
        error = 1;
    }

    for (int *p = a; p - a < *n; p++) {
        if (error) {
            break;
        }
        if (scanf("%d", p) != 1) {
            error = 1;
        }
    }
    if (getchar() != '\n') {
        error = 1;
    }
    return error;
}

double mean(int *a, int n) {
    double meane_v = 0.0;
    for (int *p = a; p - a < n; p++) {
        meane_v += *p * (1.0 / n);
    }

    return meane_v;
}

double variance(int *a, int n) {
    double variance_v = 0.0;
    double mean_v_v = mean(a, n);
    for (int *p = a; p - a < n; p++) {
        variance_v += (((*p - mean_v_v) * (*p - mean_v_v)) * (1.0 / n));
    }
    return variance_v;
}

void result(int *a, int n) {
    double Mx = mean(a, n);
    double Dx = variance(a, n);
    int result_v = 0;
    for (int *p = a; p - a < n; p++) {
        if ((*p % 2 == 0) && (*p > Mx - 1e-16) && *p < ((Mx + 3 * (sqrt(Dx))) + 1e-16) && *p != 0) {
            result_v = *p;
            break;
        }
    }
    printf("%d", result_v);
}