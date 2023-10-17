#include <stdio.h>

int input(int *a, int NMAX);
void quicksort(int *a, int low, int high);
void output(int *a, int NMAX);
void swap(int *a, int *b);
int partition(int *a, int low, int high);
void copy_arr(int *a, int *b, int NMAX);

void piramida(int *a, int high);

int main() {
  int NMAX = 10;
  int data[NMAX];
  int data2[NMAX];
  if (input(data, NMAX) == 1) {
    printf("n/a");
  } else {
    copy_arr(data, data2, NMAX);
    quicksort(data, 0, NMAX - 1);
    output(data, NMAX);
    printf("\n");
    piramida(data2, NMAX - 1);
    output(data2, NMAX);
  }
  return 0;
}

int input(int *a, int NMAX) {
  int error = 0;
  for (int *p = a; p - a < NMAX; p++) {
    if (scanf("%d", p) != 1) {
      error = 1;
    }
  }
  if (getchar() != '\n') {
    error = 1;
  }
  return error;
}

int partition(int *a, int low, int high) {
  int pivot = *(a + (high));
  int i = (low - 1);

  for (int j = low; j <= high - 1; j++) {
    if (*(a + j) < pivot) {
      i++;
      swap(a + i, a + j);
    }
  }
  swap(a + i + 1, a + high);
  return (i + 1);
}

void quicksort(int *a, int low, int high) {
  if (low < high) {
    int pi = partition(a, low, high);
    quicksort(a, low, pi - 1);
    quicksort(a, pi + 1, high);
  }
}

void output(int *a, int NMAX) {
  for (int *p = a; p - a < NMAX - 1; p++) {
    printf("%d ", *p);
  }
  printf("%d", *(a + NMAX - 1));
}

void copy_arr(int *a, int *b, int NMAX) {
  for (int i = 0; i < NMAX; i++) {
    *(b + i) = *(a + i);
  }
}

void piramida(int *a, int high) {
  if (high > 0) {
    int max_i = 0;
    int max = *a;
    for (int i = 0; i < high; i++) {
      if (*(a + i) > max) {
        max = *(a + i);
        max_i = i;
      }
    }
    if (*(a + high) < max) {
      swap(a + max_i, a + high);
    }
    piramida(a, high - 1);
  }
}

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}