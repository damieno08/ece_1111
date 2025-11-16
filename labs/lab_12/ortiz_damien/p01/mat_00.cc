// include files
//
#include "mymatrix.h"

// function takes in the name of the file
// then reads its data into a matrix
//
bool MyMatrix::read(char* file){

  // open file if it exists and send an error if not
  //
  FILE* fp = fopen(file, "r");
  if(!fp){
    fprintf(stderr, "File '%s' does not exist", file);
    return false;
  }

  // read each line within the file and put that data
  // into the matrix within the class
  //
  int numRows = 0;
  int numCols = 0;
  int charsRead;
  float element;
  bool firstRun = true;
  char buffer[MAX_LINE_LENGTH+1];
  while(fgets(buffer, sizeof(buffer),fp)!=NULL){
    std::vector<float> row;
    char* ptr = buffer;
    numCols = 0;
    while (sscanf(ptr, "%f %n", &element, &charsRead) == 1){
    ptr += charsRead;
    numCols++;
    row.push_back(element);
    }

    // check if each row is the same size
    //
    if(firstRun){
      
      cols = numCols;
      firstRun = false;
      matrix.push_back(row);
    }
    else{

      if(cols == numCols){
	matrix.push_back(row);
	

      }
      else{
	fprintf(stderr,"Number of elements within each row do not match.\n");
	return false;
      }
    }
    numRows++;
  }

  // return a success, close file, and set the size stored in class
  //
  rows = numRows;

  fclose(fp);  
  return true;

}

// function displays the matrix stored inside class
//
bool MyMatrix::display(FILE* fp){

  // loop through and print each element
  //
  for(int i = 0; i < MyMatrix::rows; i++){

    for(int j = 0; j < MyMatrix::cols; j++){

      fprintf(fp, "%5.5f\t", matrix[i][j]);

    }

    fprintf(stdout, "\n");

  }

  // return success
  //
  return true;

}

// return the number of rows in the matrix
//
int MyMatrix::getRows(){

  return MyMatrix::rows;

}

// return the number of columns i the matrixs
//
int MyMatrix::getCols(){

  return MyMatrix::cols;

}

// check which operator and perform on matrices
//
void performOp(char* op, MyMatrix& mat1, MyMatrix& mat2){

  MyMatrix result;

  // check operation then perform it
  //
  if (!strcmp(op,"addition")){
    
    result = mat1 + mat2;

  }
  else if (!strcmp(op,"subtraction")){
    
    result = mat1 - mat2;

  }
  else if (!strcmp(op,"multiplication")){
    
    result = mat1 * mat2;

  } else{

    // error for invalid option
    //
    fprintf(stderr, "Invalid option.\n");

  }

  // display our result
  //
  result.display(stdout);

}

// end of file
