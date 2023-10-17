#ifndef SRC_FILE_IO_H_
#define SRC_FILE_IO_H_

#include <stdio.h>

#include "cipher.h"
#include "encode.h"

int readFile();
int writeToFile();
int fileOutput(FILE* ptr);
int fileInput(FILE* ptr);

#endif  // SRC_FILE_IO_H_
