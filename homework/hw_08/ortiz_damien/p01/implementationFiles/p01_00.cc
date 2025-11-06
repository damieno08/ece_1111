#include "../p01.h"


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
    fprintf(stderr, "Matrix file '%s 'does not exist\n", argument);
    return nullptr;
  }
  
  char buffer[MAXIMUM_LINE_LENGTH +1];
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

