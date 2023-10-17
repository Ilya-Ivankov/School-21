#include <stdio.h>

#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == 1) {
        printf("n/a");
        return 1;
    }
    output(data, n);
    output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));

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
    printf("%d\n", *(a + n - 1));
}

int max(int *a, int n) {
    int max_x = *a;
    for (int *p = a; p - a < n; p++) {
        if (*p > max_x) {
            max_x = *p;
        }
    }
    return max_x;
}

int min(int *a, int n) {
    int min_x = *a;
    for (int *p = a; p - a < n; p++) {
        if (*p < min_x) {
            min_x = *p;
        }
    }
    return min_x;
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

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d %d %.6lf %.6lf", max_v, min_v, mean_v, variance_v);
}