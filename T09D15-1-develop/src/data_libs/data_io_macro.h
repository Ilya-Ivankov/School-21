#ifndef DATA_IO_MACRO_H
#define DATA_IO_MACRO_H

#include <stdio.h>

#define input(data, n) {\
    int i;\
    scanf("%d", n);\
    *data = (double*)malloc(*n * sizeof(double));\
    for (i = 0; i < *n; i++)\
        scanf("%lf", &(*data)[i]);\
}

#define output(data, n) {\
    int i;\
    for (i = 0; i < n; i++)\
        printf("%.2lf ", data[i]);\
    printf("\n");\
}

#endif
