#ifndef SRC_PRINT_MODULE_H_
#define SRC_PRINT_MODULE_H_

#define Module_load_success_message "Output stream module load: success\n"
#define Log_prefix "[LOG]"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void print_log(char (*print)(char), char* message);

char print_char(char ch);

void print_docs(short mask, int documents_count, ...);

#endif
