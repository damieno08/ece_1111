// file: /data/courses/ece_1111/2025_01_fall/homework/hw_08/ortiz_damien/p01/p01.h

#ifndef _p01

#define  _p01
#define MAXIMUM_LINE_LENGTH 9999

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "implementationFiles/p01_00.cc"
#include "implementationFiles/p01_01.cc"
#include "implementationFiles/p01_02.cc"
#include "implementationFiles/p01_03.cc"
#include "implementationFiles/p01_04.cc"
#include "implementationFiles/p01_05.cc"


float** getMatrix(char* argument,int* rows, int* cols);
float** multMatrices(float** mat1, float** mat2, int rowsMat1, int rowsMat2 , int colsMat1, int colsMat2);
void cleanAndPrint(float** mat1, int rows, int cols, const char* name);
float** addMatrices(float** mat1, float** mat2, int rowsMat1, int rowsMat2 , int colsMat1, int colsMat2);
float** subtractMatrices(float** mat1, float** mat2, int rowsMat1, int rowsMat2 , int colsMat1, int colsMat2);
float determinant(float** mat1, int rows, int cols);
void computeOperation(char** argv, char* operation, int argc);

#endif
