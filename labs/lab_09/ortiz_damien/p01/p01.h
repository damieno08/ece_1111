// file: /data/courses/ece_1111/2025_01_fall/labs/lab_09/ortiz_damien/p01.h

// define header if not already defined
//
#ifndef _p01
#define _p01

// create max length of a line
//
#define MAX_LINE_LENGTH 9999

// include files
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "p01_00.cc"
#include "p01_01.cc"

// function prototypes
//
int countLines(char* file);

char** getLineText(char* file);

void printString(char** stringArray, FILE* file);

void mysort(char** lines, int numLines, char* op);

#endif

// end of file
