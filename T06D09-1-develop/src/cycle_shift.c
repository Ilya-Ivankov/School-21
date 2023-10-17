#include <stdio.h>
#define NMAX 10

int input(int *a, int *n, int *sdvig);
void output(int *a, int n);

void sotr(int *a, int n, int sdvig);
void sdvig_f(int *a, int n, int sdvig);
void output(int *a, int n);

int main() {
  int data[NMAX], n, sdvig;
  if (input(data, &n, &sdvig) == 1) {
    printf("n/a");
  } else {
    sdvig_f(data, n, sdvig);
    output(data, n);
  }
  return 0;
}

int input(int *a, int *n, int *sdvig) {
  int error = 0;
  if (scanf("%d", n) != 1 || *n > NMAX || *n < 1) {
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
  if (scanf("%d", sdvig) != 1) {
    error = 1;
  }
  if (getchar() != '\n') {
    error = 1;
  }
  return error;
}

void sotr(int *a, int n, int sdvig) {
  if (sdvig > 0) {
    int temp = *a;
    for (int i = 0; i < n - 1; i++) {
      *(a + i) = *(a + i + 1);
    }
    *(a + n - 1) = temp;
  } else {
    int temp = *(a + n - 1);
    for (int i = n - 1; i >= 0; i--) {
      *(a + i) = *(a + i - 1);
    }
    *a = temp;
  }
}

void sdvig_f(int *a, int n, int sdvig) {
  if (sdvig > 0) {
    for (int i = 0; i < sdvig; i++) {
      sotr(a, n, sdvig);
    }
  } else if (sdvig < 0) {
    for (int i = 0; i > sdvig; i--) {
      sotr(a, n, sdvig);
    }
  }
}

void output(int *a, int n) {
  for (int *p = a; p - a < n - 1; p++) {
    printf("%d ", *p);
  }
  printf("%d", *(a + n - 1));
}