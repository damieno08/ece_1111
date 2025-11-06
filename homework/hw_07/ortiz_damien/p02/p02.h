// define header if it doesnt exist
//
#ifndef _p02

#define _p02

// include files
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function prototypes
//
unsigned int charToBinary(char x);
char* hexStringToBinary(char* hex);
unsigned int intToBinary(int x);
void reverseString(char* str);
void formatFourBit(char* str, int numChars);
char* compareBits(char* binarytext, char* binaryMask, char* op);

#endif
