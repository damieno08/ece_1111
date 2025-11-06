// file: /data/courses/ece_1111/2025_01_fall/labs/lab_07/ortiz_damien/p01/p01.cc/
//

// Version History: 
// 20251006 create initial file
// 20251007 create functions

// Program will take two vector files and compute their product
//

// include files
//
#include "p01.h"

// function takes in a file, error status integer, row count, and column count and returns
// 2D array of matrix within file
//
float** getMatrix(char* argument,int* rows, int* cols){

  // read file and check if the file exists
  //
  FILE *firstMatFile = fopen(argument, "r");

  if (firstMatFile == NULL){

    // tell user fie doesn't exist and exits
    //
    fprintf(stdout, "First matrix file does not exist\n");
    return nullptr;
  }
  
  char buffer[255];
  int rowCount = 0;
  int colCount = 0;
  int oldCol = 0;
  int firstRow = 1;

  // reads every line of file counting how many rows and cols it has
  //
  while (fgets(buffer, sizeof(buffer), firstMatFile) != NULL){
    char* ptr = buffer;
    int read;
    float value;
    int colInThisRow = 0;
    while (sscanf(ptr, "%f%n", &value, &read) == 1){      
      ptr += read;
      colInThisRow++;
      
    }

    // check if column size is consistent
    //
    if(firstRow){
      colCount = colInThisRow;
      firstRow = 0;
    }else {
      if (colCount != colInThisRow){

	      // tell user column sizes are inconsistent and exit
	      //
	      fprintf(stdout, "The matrix column sizes are inconsistent in the file '%s'\n", argument);
        fclose(firstMatFile);
        return nullptr;
      }
      
    }
    
    rowCount++;    
  }

  // create space for matrix we will return
  //
  float **mat1 = new float*[rowCount];
  for (int i = 0; i < rowCount; i++) {
    
    mat1[i] = new float[colCount];
  }

  // make pointer go back to start of file
  //
  rewind(firstMatFile);

  int r = 0;

  // fill matrix with values
  //
  while (fgets(buffer, sizeof(buffer), firstMatFile) != NULL){
    char* ptr = buffer;
    int read;
    float value;
    int c= 0;
    while (sscanf(ptr, "%f%n", &value, &read) == 1){      
      ptr += read;
      mat1[r][c] = value;
      c++;
    }
    r++;
  }

  // return the size of the matrix
  //
  *rows = rowCount;
  *cols = colCount;

  // safely close the file after use
  //
  fclose(firstMatFile);
  
  return mat1;
}

// Function will multiply two matrices
//
float** multMatrices(float** mat1, float** mat2, int rowsMat1, int rowsMat2 , int colsMat1, int colsMat2){

  float** result = new float*[rowsMat1];

  // check if multiplication dimensions work and exit if it does not
  //
  if (rowsMat2 != colsMat1){
    fprintf(stdout, "Matrices are not compatible for multiplication\n");
    delete[] result;
    return nullptr;
  }

  // perform multiplication and put value in result matrix
  //
  for (int i = 0; i < rowsMat1; i++){
    result[i] = new float[colsMat2];
    for(int j = 0; j < colsMat2; j++){
       result[i][j] = 0;
       for (int k = 0; k < colsMat1; k++) {
            result[i][j] += mat1[i][k] * mat2[k][j]; 
        }
    }
  }

  
  return result;
}

// print the result and delete the heap stored variables
//
void cleanAndPrint(float** mat1, int rows, int cols, const char* name) {

  // print matrix name then its values
  //
  fprintf(stdout, "%s:\n", name);
  
  for (int i = 0; i < rows; i ++){

    for(int j = 0; j < cols; j++){

      fprintf(stdout, "%.2f ", mat1[i][j]);
      
    }
    fprintf(stdout, "\n");
    
  }

  // delete all memory allocated to the matrix
  //
  for (int i = 0; i < rows; i++) {
    delete[] mat1[i];
  }  
  
  delete[] mat1;
    
  }

// main program
//

int main(int argc, char** argv){

  // check if there are enough arguments
  //
  if (argc == 3){

    // create first matrix and sizes
    //
    int rowCount;
    int colCount;
    float** mat1 = getMatrix(argv[1], &rowCount, &colCount);

    // check if matrix was created successfully
    //
    if (!mat1)
      return 1;
  

    // create second matrix and sizes
    //    
    int rowCount2;
    int colCount2;
    float** mat2 = getMatrix(argv[2], &rowCount2, &colCount2);

    // check if matrix was created successfully
    //
    if (!mat2){
      cleanAndPrint(mat1, rowCount, colCount, "First Matrix");
      return 1;
    }
    
    // compute the multiplication and return the result with sizes
    //
    float** result = multMatrices(mat1, mat2, rowCount, rowCount2, colCount, colCount2); 

    // check if matrix was created successfully
    //
    if (!result){
      cleanAndPrint(mat1,rowCount,colCount ,"First Matrix");
      cleanAndPrint(mat2,rowCount2, colCount2, "Second Matrix");
      return 1;
    }
    // print all input matrices and the output matrix while deleting allocated memory
    //
    cleanAndPrint(mat1,rowCount,colCount ,"First Matrix");
    cleanAndPrint(mat2,rowCount2, colCount2, "Second Matrix");
    cleanAndPrint(result,rowCount, colCount2, "Result Matrix");
    return 0;
  }

  // when there aren't enough arguments we print the usage and an error before exiting with errors
  //
  fprintf(stdout, "Not enough arguments\n");
  fprintf(stdout, "Usage: p01.exe <matrixFile1> <matrixFile2>\n");
  return 1;

}
