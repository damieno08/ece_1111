#include "../p01.h"

// function will take in an argument list, operation, and number of arguments then compute the expected value
//
void computeOperation(char** argv, char* operation, int argc){
  if (argc ==5){

    // perform addition, subtraction, or multiplication based on operation string
    // and calling said function
    //
    if (!strcmp(operation, "addition")){
      
      int rows;
      int cols;
      int rows2;
      int cols2;

      // read the first matrix
      //
      float** matrix1 = getMatrix(argv[3], &rows, &cols);
      if(!matrix1)
	exit(0);

      // read the second matrix
      //
      float** matrix2 = getMatrix(argv[4], &rows2, &cols2);
      if(!matrix2){
	cleanAndPrint(matrix1, rows, cols, "First Matrix");
	exit(0);
      }


      // return the result
      //
      float** result = addMatrices(matrix1, matrix2, rows, rows2, cols, cols2);
      if(!result){
	cleanAndPrint(matrix1, rows, cols, "First Matrix");
	cleanAndPrint(matrix2, rows2, cols2, "Second Matrix");
	exit(0);
      }

      // print result and delete allocated memory
      //
      cleanAndPrint(matrix1, rows, cols, "First Matrix");
      cleanAndPrint(matrix2, rows2, cols2, "Second Matrix");
      cleanAndPrint(result, rows, cols, "Result Matrix");
    }
    
    else if (!strcmp(operation, "multiplication")){
      
      int rows;
      int cols;
      int rows2;
      int cols2;

      // get first matrix
      //
      float** matrix1 = getMatrix(argv[3], &rows, &cols);
      if(!matrix1)
	exit(0);

      // get second matrix
      //
      float** matrix2 = getMatrix(argv[4], &rows2, &cols2);
      if(!matrix2){
	cleanAndPrint(matrix1, rows, cols, "First Matrix");
	exit(0);
      }

      // return result matrix
      //
      float** result = multMatrices(matrix1, matrix2, rows, rows2, cols, cols2);
      if(!result){
	cleanAndPrint(matrix1, rows, cols, "First Matrix");
	cleanAndPrint(matrix2, rows2, cols2, "Second Matrix");
	exit(0);
      }

      // print results and delete allocated memory
      //
      cleanAndPrint(matrix1, rows, cols, "First Matrix");
      cleanAndPrint(matrix2, rows2, cols2, "Second Matrix");
      cleanAndPrint(result, rows, cols, "Result Matrix");
      
    }
  else if (!strcmp(operation, "subtraction")){
    
    int rows;
    int cols;
    int rows2;
    int cols2;
    
    // get first matrix
    //
    float** matrix1 = getMatrix(argv[3], &rows, &cols);
    if(!matrix1)
      exit(0);
    
    // get second matrix
    //
    float** matrix2 = getMatrix(argv[4], &rows2, &cols2);
    if(!matrix2){
      cleanAndPrint(matrix1, rows, cols, "First Matrix");
      exit(0);
    }
    
    // return result matrix
    //
    float** result = multMatrices(matrix1, matrix2, rows, rows2, cols, cols2);
    if(!result){
      cleanAndPrint(matrix1, rows, cols, "First Matrix");
      cleanAndPrint(matrix2, rows2, cols2, "Second Matrix");
      exit(0);
    }
    
    // print results and delete allocated memory
    //
    cleanAndPrint(matrix1, rows, cols, "First Matrix");
    cleanAndPrint(matrix2, rows2, cols2, "Second Matrix");
    cleanAndPrint(result, rows, cols, "Result Matrix");
    
  }
  else{

    // tell user the operation wasn't valid
    //
    fprintf(stderr,"Error: operation not valid.\n");
    
  }
  }
  if (argc ==4){
    if(!strcmp(operation, "determinant")){
      
      int rows;
      int cols;

      // get first matrix
      //
      float** matrix1 = getMatrix(argv[3], &rows, &cols);
      if(!matrix1)
	exit(0);

      // get result matrix
      //
      float result = determinant(matrix1, rows, cols);

      // print result and delete memory
      //
      cleanAndPrint(matrix1, rows, cols, "Matrix");
      fprintf(stdout, "Result:\n%.2f\n", result);
      
  }
    else{

      // tell user they made error
      //
      fprintf(stderr, "Error: only determinant operation may take in one input matrix.\n");
      
    }
  }
}
