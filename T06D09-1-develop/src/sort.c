#include <stdio.h>

int input(int *a, int NMAX);
void sort(int *a, int NMAX);
void output(int *a, int NMAX);

int main() {
  int NMAX = 10;
  int data[NMAX];
  if (input(data, NMAX) == 1) {
    printf("n/a");
  } else {
    sort(data, NMAX);
    output(data, NMAX);
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

void sort(int *a, int NMAX) {
  int temp;
  for (int *p = a; p - a < NMAX; p++) {
    for (int *pp = a; pp - a < NMAX - (p - a) - 1; pp++) {
      if (*pp > *(pp + 1)) {
        temp = *pp;
        *pp = *(pp + 1);
        *(pp + 1) = temp;
      }
    }
  }
}

void output(int *a, int NMAX) {
  for (int *p = a; p - a < NMAX - 1; p++) {
    printf("%d ", *p);
  }
  printf("%d", *(a + NMAX - 1));
}