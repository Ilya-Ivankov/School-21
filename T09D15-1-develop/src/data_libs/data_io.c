#include "data_io.h"

#include <stdio.h>
#include <stdlib.h>

int input(double **data, int *n) {
    int error = 0;
    if (scanf("%d", n) != 1 || *n < 1) {
        error = 1;
    } else {
        *data = (double *)malloc((*n) * sizeof(double));
        for (int i = 0; i < *n; i++) {
            if (error == 1) {
                break;
            }
            if (scanf("%lf", (&(*data)[i])) != 1.0) {
                error = 1;
            }
        }
    }
    return error;
}

void output(double *data, int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2lf", (data)[i]);
        if (i != n - 1) {
            printf(" ");
        }
    }
}
