#include "logger.h"

FILE* log_init(char* path) {
    FILE* ptr = fopen(path, "a+");
    if (ptr == NULL) return NULL;
    return ptr;
}

void logcat(FILE* ptr, char* message, enum log_level level) {
    if (ptr == NULL) printf("nullptr :(\n");
    switch (level) {
        case 0:
            fprintf(ptr, "%-7s ", "DEBUG");
            break;
        case 1:
            fprintf(ptr, "%-7s ", "TRACE");
            break;
        case 2:
            fprintf(ptr, "%-7s ", "INFO");
            break;
        case 3:
            fprintf(ptr, "%-7s ", "WARNING");
            break;
        case 4:
            fprintf(ptr, "%-7s ", "ERROR");
            break;
    }

    time_t raw;
    struct tm* timeinfo = (struct tm*)malloc(sizeof(struct tm));
    time(&raw);
    timeinfo = localtime_r(&raw, timeinfo);
    int hour = timeinfo->tm_hour;
    int min = timeinfo->tm_min;
    int sec = timeinfo->tm_sec;
    fprintf(ptr, "%02d:%02d:%02d ", hour, min, sec);

    fprintf(ptr, "%s\n", message);

    free(timeinfo);
}

void log_close(FILE* ptr) { fclose(ptr); }

char* createMes(char* path, int mode) {
    //! DO NOT FORGET TO FREE THE MEMORY AT THE CALL POINT

    char* mes = (char*)calloc((50 + strlen(path)), sizeof(char));

    switch (mode) {
        /* Mode variable explanation
         * First digit is case in main()
         * Second digit is error state of the action
         */
        case 10:
            // case 10: File read without errors
            s21_strcpy(mes, "read from ");
            s21_strcat(mes, path);
            break;
        case 11:
            // case 11: File read with errors
            s21_strcpy(mes, "unsuccessful read from ");
            s21_strcat(mes, path);
            break;
        case 20:
            // case 20: File write without errors
            s21_strcpy(mes, "line append to ");
            s21_strcat(mes, path);
            break;
        case 21:
            // case 21: File write with errors
            s21_strcpy(mes, "unsuccessful line append to ");
            s21_strcat(mes, path);
            break;
        case 30:
            // case 30: Directory encrypted with Caesar's cipher without errors
            s21_strcpy(mes, "Caesar's encrypted directory ");
            s21_strcat(mes, path);
            break;
        case 31:
            // case 31: Directory encrypted with Caesar's cipher with errors
            s21_strcpy(mes, "unsuccessful directory Caesar's encryption ");
            s21_strcat(mes, path);
            break;
        case 40:
            // case 40: Directory encrypted with DES without errors
            s21_strcpy(mes, "encrypted with DES directory ");
            s21_strcat(mes, path);
            break;
        case 41:
            // case 41: Directory encrypted with DES with errors
            s21_strcpy(mes, "unsuccessful directory encryption with DES: ");
            s21_strcat(mes, path);
            break;
    }
    return mes;
}
