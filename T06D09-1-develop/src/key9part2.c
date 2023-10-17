#include <stdio.h>
#define LEN 100

int Input(int *buff, int *len);
int Add(int *buff1, int len1, int *buff2, int len2, int *result,
        int *result_length);
int Subtraction(int *buff1, int len1, int *buff2, int len2, int *result,
                int *result_length);
int CheckSum(int *arr, int *s);
int CheckSubtraction(int *arr, int *s);
void Output(int *arr, int size, int result_length);

int main() {
  int buff1[100], len1, buff2[100], len2, result[101], result_length = 0;
  int result2[100];

  if (Input(buff1, &len1)) {
    printf("n/a");
  } else {
    if (Input(buff2, &len2)) {
      printf("n/a");
    } else {
      if (Add(buff1, len1, buff2, len2, result, &result_length)) {
        Output(result, 101, result_length);
        printf("\n");
        result_length = 0;

        if (Subtraction(buff1, len1, buff2, len2, result2, &result_length)) {
          Output(result2, 100, result_length);
        }
      }
    }
  }

  return 0;
}

int Input(int *buff, int *len) {
  char c;
  int index = 0;
  int state = 0;
  int sc = 0;
  int temp = 0;
  do {
    sc = scanf("%d", &temp);

    if (sc != 1 || temp < 0 || temp > 9) {
      state = 1;
      break;
    } else {
      buff[index] = temp;
      index++;
    }
    c = getchar();

    if (index == 100) {
      state = 1;
      break;
    }
  } while (c != '\n');

  *len = index;

  return state;
}

int CheckSum(int *arr, int *s) {
  int state = 0;
  for (int i = 100; i >= *s; i--) {
    if (arr[i] >= 10) {
      if (i > 0) {
        if (i == *s) {
          arr[i - 1] = 1;
          arr[i] -= 10;
          *s -= 1;
        } else {
          arr[i - 1] += 1;
          arr[i] -= 10;
        }
      } else {
        state = 1;
        break;
      }
    }
  }
  return state;
}

int Add(int *arr1, int s1, int *arr2, int s2, int *res, int *res_s) {
  int s_max = 0;
  if (s1 > s2) {
    s_max = s1;
  } else {
    s_max = s2;
  }

  for (int i = 100; i >= (101 - s_max); i--) {
    s1--;
    s2--;
    if (s1 >= 0 && s2 >= 0) {
      res[i] = arr1[s1] + arr2[s2];
    } else if (s1 >= 0 && s2 < 0) {
      res[i] = arr1[s1];
    } else if (s1 < 0 && s2 >= 0) {
      res[i] = arr2[s2];
    } else {
      break;
    }
  }
  *res_s = 101 - s_max;
  int state = 1;
  if (CheckSum(res, res_s)) {
    printf("n/a");
    state = 0;
  }

  return state;
}

int CheckSubtraction(int *arr, int *s) {
  int state = 1;

  for (int i = *s; i < 100; i++) {
    if (i == *s && arr[i] < 0) {
      state = 0;
      break;
    }

    if (arr[i] < 0) {
      int j = i;
      int k = 1;
      while (arr[j - k] <= 0) {
        k++;
      }
      arr[j - k] -= 1;
      k--;
      while (k != 0) {
        arr[i - k] += 9;
        k--;
      }
      arr[j] += 10;
    }
  }
  return state;
}

int Subtraction(int *arr1, int s1, int *arr2, int s2, int *res, int *res_s) {
  int success = 1;
  int s_max = s1;
  if (s1 > s2) {
    s_max = s1;
  } else if (s1 == s2) {
    for (int i = 0; i < s_max; i++) {
      if (arr1[i] > arr2[i]) {
        break;
      }

      if (arr2[i] > arr1[i]) {
        success = 0;
        break;
      }
    }
  } else {
    success = 0;
  }

  if (success) {
    for (int i = 99; i >= (100 - s_max); i--) {
      s1--;
      s2--;

      if (s1 >= 0 && s2 >= 0) {
        res[i] = arr1[s1] - arr2[s2];
      } else if (s1 >= 0 && s2 < 0) {
        res[i] = arr1[s1];
      } else if (s1 < 0 && s2 >= 0) {
        res[i] = arr2[s2];
      } else {
        break;
      }
    }
    *res_s = 100 - s_max;
  }

  if (success) {
    success = CheckSubtraction(res, res_s);

    while (res[*res_s] == 0 && *res_s < 99) {
      *res_s += 1;
    }
  }
  return success;
}

void Output(int *arr, int size, int result_length) {
  for (int i = result_length; i < size; i++) {
    printf("%d ", arr[i]);
  }
}
