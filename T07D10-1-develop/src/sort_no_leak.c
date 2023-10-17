#include <stdio.h>
#include <stdlib.h>

int input(int **a, int *n);
void sort(int *a, int n);
void output(int *a, int n);

int main() {
    int *data = NULL;
    int n;

    if (input(&data, &n) == 1) {
        printf("n/a");

    } else {
        sort(data, n);
        output(data, n);
    }

    free(data);
    return 0;
}

int input(int **a, int *n) {
    int error = 0;

    if (scanf("%d", n) != 1 || *n < 1) {
        error = 1;
    } else {
        *a = (int *)malloc((*n) * sizeof(int));
        if (*a == NULL) {
            printf("n/a");
            error = 1;
        }
    }
    for (int *p = *a; p - *a < *n; p++) {
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

void sort(int *a, int n) {
    int temp;
    for (int *p = a; p - a < n; p++) {
        for (int *pp = a; pp - a < n - (p - a) - 1; pp++) {
            if (*pp > *(pp + 1)) {
                temp = *pp;
                *pp = *(pp + 1);
                *(pp + 1) = temp;
            }
        }
    }
}

void output(int *a, int n) {
    for (int *p = a; p - a < n - 1; p++) {
        printf("%d ", *p);
    }
    printf("%d", *(a + n - 1));
}
