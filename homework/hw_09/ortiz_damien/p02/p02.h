// file: /data/courses/ece_1111/2025_01_fall/labs/lab_09/ortiz_damien/p01.h

// create header if not already created
//
#ifndef _p02
#define _p02

// create max line size
//
#define MAX_LINE_LENGTH 9999

// include files
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "p02_00.cc"
#include "p02_01.cc"

// function prototypes
//
int countLines(char* file);

char** getLineText(char* file);

void printString(char** stringArray, FILE* file);

void mysort(char** lines, int numLines, char* op);

#endif

// end of file
