// file: /data/courses/ece_1111/2025_01_fall/labs/lab_10/ortiz_damien/p02/p02.h
//

// define header if not already defined
//
#ifndef _p02
#define _p02

#define MAXIMUM_LINE_LENGTH 9999

// include files
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "p02_00.cc"
#include "p02_01.cc"

// function prototypes
//
void initBuffer(Buffer& buff);
void freeBuffer(Buffer& buff);
void writeLine(Buffer& buff, char* string);
void printWindow(Buffer& buff);
void readFile(FILE* fp, Buffer& buff);
int containsWord(const char* line, const char* word);
char** getFileList(char** argv, int argc, Buffer& buff, int* num);

#endif

// end of file
