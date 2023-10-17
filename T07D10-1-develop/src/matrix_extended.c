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
void math(int *data, int n, int m);

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
        math(&data[0][0], n, m);
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
        math(ptr, n, m);
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
        math(&pointer_arr[0][0], n, m);
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
        math(&pointer_arr[0][0], n, m);
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

void math(int *data, int n, int m) {
    int row[n];
    int col[m];

    for (int i = 0; i < n; i++) {
        int max = *(data + m * i);

        for (int j = 1; j < m; j++) {
            if (*(data + m * i + j) > max) {
                max = *(data + m * i + j);
            }
        }

        row[i] = max;
    }

    for (int j = 0; j < m; j++) {
        int min = *(data + j);

        for (int i = 1; i < n; i++) {
            if (*(data + m * i + j) < min) {
                min = *(data + m * i + j);
            }
        }

        col[j] = min;
    }

    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%d", row[i]);
        if (i != n - 1) {
            printf(" ");
        }
    }
    printf("\n");
    for (int i = 0; i < m; i++) {
        printf("%d", col[i]);
        if (i != m - 1) {
            printf(" ");
        }
    }
}
