#include "cipher.h"

#include "encode.h"
#include "file_io.h"
#include "log_levels.h"
#include "logger.h"

int getChoice();
void menu(int mode);

int main() {
#ifdef LOG
    menu(1);
    return 0;
#else
    menu(0);
#endif
    return 0;
}

void menu(int mode) {
    int flag = 1;
    char* path = NULL;
    char* dirpath;
    FILE* logptr;
    char* logfile = NULL;
    if (mode) {
        logfile = getPath();
        logptr = log_init(logfile);
    }
    while (flag) {
        int is_error = 0;
        char err = 32;
        int choice = getChoice();
        switch (choice) {
            case -1:
                flag = 0;
                break;
            case 1:
                if (path != NULL) {
                    free(path);
                }

                path = getPath();

                is_error = readFile(path);
                if (!is_error) {
                    if (mode) {
                        char* mes = createMes(path, 10);
                        logcat(logptr, mes, info);
                        free(mes);
                    }
                    printf("\n");
                } else if (is_error && mode) {
                    char* mes = createMes(path, 11);
                    logcat(logptr, mes, error);
                    free(mes);
                }
                break;
            case 2:
                is_error = writeToFile(path);
                if (is_error) {
                    if (mode) {
                        char* mes = createMes(path, 21);
                        logcat(logptr, mes, error);
                        free(mes);
                        mes = createMes(path, 11);
                        logcat(logptr, mes, error);
                        free(mes);
                    }
                    continue;
                }
                if (!is_error) {
                    if (mode) {
                        char* mes = createMes(path, 20);
                        logcat(logptr, mes, info);
                        free(mes);
                        mes = createMes(path, 10);
                        logcat(logptr, mes, info);
                        free(mes);
                    }
                    readFile(path);
                    printf("\n");
                }
                break;
            case 3:
                dirpath = getPath();
                is_error = codeCaesars(dirpath);
                if (mode) {
                    if (!is_error) {
                        char* mes = createMes(dirpath, 30);
                        logcat(logptr, mes, info);
                        free(mes);
                    } else {
                        char* mes = createMes(dirpath, 31);
                        logcat(logptr, mes, error);
                        free(mes);
                        free(dirpath);
                    }
                }

                break;

            default:
                is_error = 1;
                while (err != '\n') err = getchar();
                break;
        }
        if (is_error == 1) {
            printf("n/a\n");
        }
    }
    if (path != NULL) free(path);
    log_close(logptr);
    free(logfile);
}

int getChoice() {
    int num = 0;
    if (scanf("%d", &num) != 1) return -2;
    return num;
}

char* getStr() {
    char* str = (char*)malloc(sizeof(char) * 10);
    int size = 0, k = 1;
    char c = ' ';
    scanf("%c", &c);
    if (c == '\n') scanf("%c", &c);
    while (c != '\n') {
        if (size > k * 10) {
            k++;
            char* tmp = (char*)realloc(str, sizeof(char) * 10 * k);
            if (tmp != NULL)
                str = tmp;
            else
                return NULL;
        }
        str[size++] = c;
        scanf("%c", &c);
    }
    str[size] = '\0';
    return str;
}

int s21_strlen(const char* str) {
    int i = 0, res = 0;

    while (str[i] != '\0') {
        res++;
        i++;
    }

    return res;
}

char* s21_strcpy(char* dest, char* src) {
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return dest;
}

char* s21_strcat(char* dest, char* addition) {
    int str1_length = s21_strlen(dest);
    int str2_length = s21_strlen(addition);

    for (int i = 0; i <= str2_length; i++) {
        dest[str1_length + i] = addition[i];
    }

    return dest;
}

char* getPath() {
    char* str = getStr();
    char* tmp = (char*)calloc((strlen(str) + 3), sizeof(char));
    s21_strcat(tmp, str);
    free(str);
    return tmp;
}
