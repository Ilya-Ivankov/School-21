#include "documentation_module.h"

#include <stdarg.h>

// Функция валидации документа
int validate(char* data) {
    // Проверка на соответствие переданного документа доступному документу
    int validation_result = !strcmp(data, Available_document);
    return validation_result;
}

// Функция для проверки доступности документов
short check_available_documentation_module(int (*validate)(char*), int document_count, ...) {
    int is_error = 0;
    int sum = 16384;
    va_list ptr;
    va_start(ptr, document_count);
    int step = 1;
    // Проверка на превышение максимального количества документов
    if (document_count > 13) is_error = 1;
    if (is_error == 0) {
        while (document_count--) {
            char* str = va_arg(ptr, char*);
            // Вычисление суммы доступности документов с помощью битовой операции
            sum += validate(str) * step;
            step *= 2;
        }
    }
    va_end(ptr);
    return sum;
}
