#include <stdio.h>

// функция остаток от деления
int(ODD(int x, int y)) {
  if (x < 0) {
    x *= -1;
  } else if (y < 0) {
    y *= -1;
  }
  int res = x - y;
  if (x <= y) {
    res = 0;

  } else {
    while ((res - y) >= 0) {
      res -= y;
    }
  }
  return res;
}

// функция простого числа
int prost(int x) {
  if (x <= 0) {
    x *= (-1);
  }

  if (x == 1) {
    return 1;
  } else {
    for (int i = 2; i < x; i++) {
      if (ODD(x, i) == 0) {
        return 0;
      }
    }
    return 1;
  }
}

// функция наибольший простой делитель

int NPD(int x) {
  int check = 0;
  if (x < 0) {
    x *= -1;
  }
  for (int i = x; i >= 2; i--) {
    if (ODD(x, i) == 0 && prost(i) == 1) {
      return i;
    } else {
      check = 1;
    }
  }
  if (check != 1) {
    return x;
  }

  return 0;
}

// основная функция
int main() {
  int num;
  char otstup = '\0';

  if (2 != scanf("%d%c", &num, &otstup) || otstup != '\n' || num == 0 ||
      num == 1) {
    printf("n/a");
  } else {
    printf("%d", NPD(num));
  }

  return 0;
}