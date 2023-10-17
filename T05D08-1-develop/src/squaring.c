#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == 1) {
        printf("n/a");
        return 1;
    }
    squaring(data, n);
    output(data, n);
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

void output(int *a, int n) {
    for (int *p = a; p - a < n - 1; p++) {
        printf("%d ", *p);
    }
    printf("%d", *(a + n - 1));
}

void squaring(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        *p *= *p;
    }
}
