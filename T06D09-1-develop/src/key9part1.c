/*------------------------------------
        Здравствуй, человек!
        Чтобы получить ключ
        поработай с комментариями.
-------------------------------------*/

#include <stdio.h>

int input(int *a, int *n);
void output(int *buffer, int length);
int sum_numbers(int *buffer, int length);

int find_numbers(int *buffer, int length, int number, int *numbers);

/*------------------------------------
        Функция получает массив данных
        через stdin.
        Выдает в stdout особую сумму
        и сформированный массив
        специальных элементов
        (выбранных с помощью найденной суммы):
        это и будет частью ключа
-------------------------------------*/
int main() {
  int NMAX = 10;
  int length;
  int data[NMAX];
  int data2[NMAX];
  if (input(data, &length) == 1) {
    printf("n/a");

  } else {
    if (sum_numbers(data, length) == 0) {
      printf("n/a");

    } else {
      printf("%d\n", sum_numbers(data, length));
    }
    if (find_numbers(data, length, sum_numbers(data, length), data2) == 0) {
      printf("n/a");

    } else {
      output(data2,
             find_numbers(data, length, sum_numbers(data, length), data2));
    }
  }
  return 1;
}

/*------------------------------------
        Функция должна находить
        сумму четных элементов
        с 0-й позиции.
-------------------------------------*/
// int sum_numbers(int *buffer, int length) {
//   int sum = 0;

//   for (int i = 1; i < length; i++) {
//     if (i % 2 != 0) {
//       sum = sum + buffer[i];
//     }
//   }

//   return sum;
// }

/*------------------------------------
        Функция должна находить
        все элементы, на которые нацело
        делится переданное число и
        записывает их в выходной массив.
-------------------------------------*/

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

void output(int *buffer, int length) {
  for (int *p = buffer; p - buffer < length - 1; p++) {
    printf("%d ", *p);
  }
  printf("%d", *(buffer + length - 1));
}

int sum_numbers(int *buffer, int length) {
  int sum = 0;
  for (int *p = buffer; p - buffer < length; p++) {
    if (*p % 2 == 0 && *p != 0) {
      sum += *p;
    }
  }
  return sum;
}

int find_numbers(int *buffer, int length, int number, int *numbers) {

  int num_divisors = 0;
  for (int i = 0; i < length; ++i) {
    if (*(buffer + i) != 0) {
      if (number % *(buffer + i) == 0) {
        *(numbers + num_divisors) = *(buffer + i);
        ++num_divisors;
      }
    }
  }
  return num_divisors;
}
