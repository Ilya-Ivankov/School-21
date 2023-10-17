#include <stdio.h>
#include <stdlib.h>
#define NMAX 100

int input(int *data, int n, int m);  // функция для заполнения массива
int check(int *a, int *n, int *m);  // функция которая проверяет размерность матрицы
void alloc_1(int n, int m);
void alloc_2(int n, int m);
void alloc_3(int n, int m);
void alloc_4(int n, int m);
void output(int *data, int n, int m);

int main() {
    int n, m, a;
    if (check(&a, &n, &m) == 1) {
        printf("n/a");
    } else {
        if (a == 1) {
            alloc_1(n, m);
        } else if (a == 2) {
            alloc_2(n, m);
        } else if (a == 3) {
            alloc_3(n, m);
        } else if (a == 4) {
            alloc_4(n, m);
        }
    }
    return 0;
}

int input(int *data, int n, int m) {
    int error = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (error) {
                break;
            }
            if (scanf("%d", (data + m * i + j)) != 1) {
                error = 1;
            }
        }
    }
    return error;
}

int check(int *a, int *n, int *m) {
    int error = 0;
    if (scanf("%d", a) != 1 || *a > 4 || *a < 1) {
        error = 1;
    } else {
        if (*a == 1) {
            if (scanf("%d", n) != 1 || scanf("%d", m) != 1 || *n > 100 || *m > 100 || *n < 1 || *m < 1) {
                error = 1;
            }
        } else {
            if (scanf("%d", n) != 1 || scanf("%d", m) != 1 || *n < 1 || *m < 1) {
                error = 1;
            }
        }
    }
    return error;
}

void alloc_1(int n, int m) {
    int data[NMAX][NMAX];
    if (input(&data[0][0], n, m) == 1) {
        printf("n/a");
    } else {
        output(&data[0][0], n, m);
    }
}

void alloc_2(int n, int m) {
    int **single_arr_matrix = malloc(m * sizeof(int *));
    int *ptr = malloc(n * m * sizeof(int));
    for (int i = 0; i < m; i++) {
        single_arr_matrix[i] = &ptr[i * n];
    }
    if (input(ptr, n, m) == 1) {
        printf("n/a");
    } else {
        output(ptr, n, m);
        free(ptr);
        free(single_arr_matrix);
    }
}

void alloc_3(int n, int m) {
    int **pointer_arr = malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        pointer_arr[i] = malloc(n * sizeof(int));
    }
    if (input(&pointer_arr[0][0], n, m) == 1) {
        printf("n/a");
    } else {
        output(&pointer_arr[0][0], n, m);
        for (int i = 0; i < m; i++) {
            free(pointer_arr[i]);
        }
        free(pointer_arr);
    }
}

void alloc_4(int n, int m) {
    int **pointer_arr = malloc(m * sizeof(int *));
    int *values_arr = malloc(m * n * sizeof(int));
    for (int i = 0; i < m; i++) {
        pointer_arr[i] = &values_arr[i * n];
    }

    if (input(values_arr, n, m) == 1) {
        printf("n/a");
    } else {
        output(&pointer_arr[0][0], n, m);
        free(values_arr);
        free(pointer_arr);
    }
}

void output(int *data, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", *(data + m * i + j));
            if (j != m - 1) {
                printf(" ");
            }
        }
        if (i != n - 1) {
            printf("\n");
        }
    }
}
