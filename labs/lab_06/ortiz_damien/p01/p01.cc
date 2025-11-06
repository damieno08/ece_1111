// file: /data/courses/ece_1111/2025_01_fall/labs/lab_06/ortiz_damien/p01/p01/p01.cc
//
// Version History: 
// 20250930 create initial file
// 20251003 add error checking

// Program will take in two vectors and a constant to compute dot product

// include files 
//
#include <stdio.h>
#include <stdlib.h>

// main program
//
int main(int argc, char** argv){

  // error checking for number of inputs
  //  
  if (argc == 4){

    // creates pointer for both input files  
    //
    FILE *f1 = fopen(argv[1], "r");
    FILE *f2 = fopen(argv[2], "r");

    // checks if first file exists
    //
    if (f1 == NULL) {
      fprintf(stderr, "First file does not exist.\n");
      return 1;
    }
    
    // check if second file exists    
    //
    if (f2 == NULL) {
      fprintf(stderr, "Second file does not exist.\n");
      return 1;
    }

    // create variables to hold lines and dimension sizes
    //
    char buffer[255];
    int dim1, dim2;

    // create dimension size of both vectors
    //
    dim1 = atoi(fgets(buffer, sizeof(buffer), f1));
    dim2 = atoi(fgets(buffer, sizeof(buffer), f2));

    if (dim1 != dim2){
      fprintf(stderr, "Vector sizes do not match.\n");
      return 1;
    }

    // create empty floats to create vectors late
    //
    float vector[dim1];
    float vector2[dim2];
    float result = 0;

    // turn command line into usable constant
    //
    float c = atof(argv[3]);

    // check if constant is numerical or they entered a char
    //
    int constCheck = sscanf(argv[3], "%f", &c);

    // check if third argument is constant and print warning
    //
    if (constCheck != 1){

      fprintf(stderr, "Third argument must be constant.\n");
      
      return 1;
      
    }
    
    // loop will check for numerical values and add them to the vector
    //
    for (int i = 0; i < dim1; i++){

      fgets(buffer, sizeof(buffer), f1);    

      int numFloats = sscanf(buffer, "%f", &vector[i]);
      
      // error statement for when vector contains letters
      //
      if (numFloats != 1){
	fprintf(stderr, "Vector contains non numerical input.\n");
	return 1;
      }
      
    }
    
    // loop will check for numerical values and add them to the second vector
    //
    for (int i =  0; i < dim2; i++){

      fgets(buffer, sizeof(buffer), f2);
      
      int numFloats = sscanf(buffer, "%f", &vector2[i]);

      // error statement for when vector contains letters
      //
      if (numFloats != 1){
	fprintf(stderr, "Vector contains non numerical input.\n");
	return 1;
      }
    }
      // print the dimension and results of adding 
      //
      fprintf(stdout, "The dimension size is %d\n", dim1);
      fprintf(stdout, "The resulting vector is:\n");

      // loop calculates dot product of the two vectors
      //
      for (int i = 0; i < dim2; i ++){

	result += vector[i] * vector2[i];
      }

      result += c;
      
      fprintf(stdout, "%.4f\n", result);

      
      // close program succesfully
      //
      return 0;
    }
  
  else{
    
    // error statement for not enough arguments
    //
    fprintf(stderr, "Error: wrong number of inputs\n");
    fprintf(stderr, "Usage: p01.exe <vectorFile1> <vectorFile2> <constant>\n");
    
  }
}
