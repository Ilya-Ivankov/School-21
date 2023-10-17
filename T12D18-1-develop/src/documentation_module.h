#ifndef SRC_DOCUMENTATION_MODULE_H_
#define SRC_DOCUMENTATION_MODULE_H_

#include <stdio.h>
#include <string.h>

#define Documents "Linked lists", "Queues", "Maps", "Binary Trees"
#define Available_document "Binary Trees"
#define Documents_count 4

short check_available_documentation_module(int (*validate)(char*), int document_count, ...);

int validate(char* data);

#endif