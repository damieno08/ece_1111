
// check if header is defined and define it if not
//
#ifndef _p03
#define _p03

// define the maximum length of a line we can read
//
#define MAX_LINE_LENGTH 9999

// include files
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "p03_00.cc"

// function prototypes

// will count the number of lines within input file
//
int countLines(char* file);
char** getLineText(char* file);
void printString(char** stringArray, FILE* file);
void cleanStringArrayMemory(char** strs);

// end definition
//
#endif
