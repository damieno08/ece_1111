// check if the header already exists and create it if not
//
#ifndef _p01
#define _p01

// include files 
//
#include <stdio.h>
#include <stdlib.h>

// create function prototypes to be used in main file
//
float** getMatrix(char* argument,int* rows, int* cols);
float** multMatrices(float** mat1, float** mat2, int rowsMat1, int rowsMat2 , int colsMat1, int colsMat2);
void cleanAndPrint(float** mat1, int rows, int cols, const char* name);

#endif 
