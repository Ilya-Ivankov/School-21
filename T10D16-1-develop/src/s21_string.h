#ifndef S21_STRING_H
#define S21_STRING_H

int s21_strlen(const char* data);
int s21_strcmp(const char* str1, const char* str2);
char* s21_strcpy(char* dest, const char* src);
char* s21_strcat(char* dest, const char* src);
const char* s21_strchr(const char* str, int c);
int s21_strstr(const char* src1, const char* src2);
const char* s21_strchr(const char* str, int c);
char* s21_strtok(char* str, const char* delimiters);

#endif
