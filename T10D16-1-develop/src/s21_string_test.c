#include "s21_string.h"

#include <stdio.h>

void s21_strlen_test();
void s21_strcmp_test();
void s21_strcpy_test();
void s21_strcat_test();
void s21_strchr_test();
void s21_strstr_test();
void s21_strtok_test();

int main() {
#ifdef Quest_1
    s21_strlen_test();
#endif
#ifdef Quest_2
    s21_strcmp_test();
#endif
#ifdef Quest_3
    s21_strcpy_test();
#endif
#ifdef Quest_4
    s21_strcat_test();
#endif
#ifdef Quest_5
    s21_strchr_test();
#endif
#ifdef Quest_6
    s21_strstr_test();
#endif
#ifdef Quest_7
    s21_strtok_test();
#endif
    return 0;
}

void s21_strlen_test() {
    char *test_data[] = {"school", "", "21", "DATA", "Data"};
    int test_data_num[] = {6, 0, 2, 4, 4};
    for (int i = 0; i < 5; i++) {
        printf("%s\n", test_data[i]);
        printf("%d\n", s21_strlen(test_data[i]));
        if (s21_strlen(test_data[i]) != test_data_num[i]) {
            if (i != 4) {
                printf("FAIL\n");
            } else {
                printf("FAIL");
            }

        } else {
            if (i != 4) {
                printf("SUCCESS\n");
            } else {
                printf("SUCCESS");
            }
        }
    }
}

void s21_strcmp_test() {
    char *test_data_right[] = {"eleonora", "mulbash", "romashina", "vannash", "ivankova"};
    char *test_data_left[] = {"Eleonora", "bash", "romashina", "vannasha", "ivankove"};
    int test_data_num[] = {1, 1, 0, -1, -1};
    for (int i = 0; i < 5; i++) {
        printf("%s %s\n", test_data_right[i], test_data_left[i]);
        printf("%d\n", s21_strcmp(test_data_right[i], test_data_left[i]));

        if (s21_strcmp(test_data_right[i], test_data_left[i]) != test_data_num[i]) {
            if (i != 4) {
                printf("FAIL\n");
            } else {
                printf("FAIL");
            }

        } else {
            if (i != 4) {
                printf("SUCCESS\n");
            } else {
                printf("SUCCESS");
            }
        }
    }
}

void s21_strcpy_test() {
    char *src[] = {"Hello, world!", "Bye, world!", "TopGamer in the world!", "Hello, hello!", ""};

    for (int i = 0; i < 5; i++) {
        char dest[s21_strlen(src[i]) + 1];
        s21_strcpy(dest, src[i]);

        printf("%s\n", src[i]);
        printf("%s\n", dest);
        if (s21_strcmp(dest, src[i]) == 0) {
            if (i != 4) {
                printf("SUCCESS\n");
            } else {
                printf("SUCCESS");
            }

        } else {
            if (i != 4) {
                printf("FAIL\n");
            } else {
                printf("FAIL");
            }
        }
    }
}

void s21_strcat_test() {
    char src[][100] = {"Hello, world!", "Bye, world!", "TopGamer in the world!", "Hello, hello!", ""};
    char src_2[][10] = {"?", "#", "&", "**!", ""};
    char res[][30] = {"Hello, world!?", "Bye, world!#", "TopGamer in the world!&", "Hello, hello!**!", ""};

    for (int i = 0; i < 5; i++) {
        printf("%s %s\n", src[i], src_2[i]);
        s21_strcat(src[i], src_2[i]);

        printf("%s\n", src[i]);
        if (s21_strcmp(src[i], res[i]) == 0) {
            if (i != 4) {
                printf("SUCCESS\n");
            } else {
                printf("SUCCESS");
            }

        } else {
            if (i != 4) {
                printf("FAIL\n");
            } else {
                printf("FAIL");
            }
        }
    }
}

void s21_strchr_test() {
    char *str = "Hi, i like school 21!";
    char *check[] = {"i", "I", "o", "s", "3"};
    const char *res[] = {&str[1], NULL, &str[14], &str[11], NULL};

    for (int i = 0; i < 5; i++) {
        printf("%s %c\n", str, check[i][0]);
        if (s21_strchr(str, check[i][0]) == NULL) {
            printf("NULL\n");
        } else {
            printf("%p\n", s21_strchr(str, check[i][0]));
        }
        if (s21_strchr(str, check[i][0]) == (const char *)res[i]) {
            if (i != 4) {
                printf("SUCCESS\n");
            } else {
                printf("SUCCESS");
            }

        } else {
            if (i != 4) {
                printf("FAIL\n");
            } else {
                printf("FAIL");
            }
        }
    }
}

void s21_strstr_test() {
    char *str = "Hi, i like school 21!";
    char *str2[] = {"like", "i ", "Hi", "23", "O"};
    int res[] = {6, 4, 0, -1, -1};

    for (int i = 0; i < 5; i++) {
        printf("%s %s\n", str, str2[i]);
        if (s21_strstr(str, str2[i]) == -1) {
            printf("NULL\n");
        } else {
            printf("%d\n", s21_strstr(str, str2[i]));
        }

        if (s21_strstr(str, str2[i]) == res[i]) {
            if (i != 4) {
                printf("SUCCESS\n");
            } else {
                printf("SUCCESS");
            }

        } else {
            if (i != 4) {
                printf("FAIL\n");
            } else {
                printf("FAIL");
            }
        }
    }
}

void s21_strtok_test() {
    char str[] = "Hello, world! How are you today?";
    const char str1[] = "Hello, world! How are you today?";
    const char delimiters[] = " ,!";
    const char *res[] = {"Hello", "world", "How", "are", "you", "today?"};
    int i = 0;
    char *token = s21_strtok(str, delimiters);
    while (token != NULL) {
        printf("%s ", str1);
        printf("%s\n", token);

        printf("%s\n", token);

        if (s21_strcmp(token, res[i]) == 0) {
            if (i != 6) {
                printf("SUCCESS\n");
            } else {
                printf("SUCCESS");
            }

        } else {
            if (i != 6) {
                printf("FAIL\n");
            } else {
                printf("FAIL");
            }
        }

        i++;

        token = s21_strtok(0, delimiters);
    }
}