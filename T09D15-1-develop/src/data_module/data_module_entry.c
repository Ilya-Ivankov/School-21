#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "data_process.h"

int main() {
    int n;
    double *data = NULL;
    // Don`t forget to allocate memory !
    if (input(&data, &n) == 1) {
        printf("ERROR");
    } else {
        if (normalization(data, n))
            output(data, n);
        else
            printf("ERROR");
        free(data);  // Освобождение памяти
    }
    return 0;
}
