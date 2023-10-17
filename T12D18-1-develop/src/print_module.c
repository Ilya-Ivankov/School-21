#include "print_module.h"

// Функция для вывода символа
char print_char(char ch) { return putchar(ch); }

// Функция для вывода лога
void print_log(char (*print)(char), char* message) {
    time_t raw;
    struct tm* timeinfo = (struct tm*)malloc(sizeof(struct tm));
    time(&raw);
    timeinfo = localtime_r(&raw, timeinfo);
    int hour = timeinfo->tm_hour;
    int min = timeinfo->tm_min;
    int sec = timeinfo->tm_sec;
    printf("%s %02d:%02d:%02d ", Log_prefix, hour, min, sec);

    // Вывод каждого символа сообщения
    while (*message != '\0') {
        print(*message);
        message++;
    }

    free(timeinfo);
}

// Функция для вывода доступности документов
void print_docs(short mask, int documents_count, ...) {
    va_list ptr;
    va_start(ptr, documents_count);
    int ct = 0;
    // Перебор битов в маске и вывод соответствующей информации о документе
    while (mask > 0) {
        if (ct == documents_count) break;
        ct++;
        char* str = va_arg(ptr, char*);
        if ((mask % 2) == 1) {
            printf("%d. %-15s: ", ct, str);
            printf("доступно\n");
        } else {
            printf("%d. %-15s: ", ct, str);
            printf("недоступно\n");
        }
        mask /= 2;
    }
    va_end(ptr);
}
