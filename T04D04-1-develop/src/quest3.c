#include <stdio.h>
int fibonacci(int n) {
  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return 1;
  }
  return fibonacci(n - 1) + fibonacci(n - 2);
}
int main() {
  int num;
  char otstup = '\0';

  if (2 != scanf("%d%c", &num, &otstup) || otstup != '\n' || num <= 0) {
    printf("n/a");
  } else {
    printf("%d", fibonacci(num));
  }

  return 0;
}