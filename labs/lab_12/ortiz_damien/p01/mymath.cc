// file: /data/courses/ece_1111/2025_01_fall/labs/lab_12/ortiz_damien/p01/p01.cc/
//
// Version History: 
// 20251110 create initial file

// include files 
//
#include "mymatrix.h"

// Program will read a matrix from a file, store this in a class called matrix,
// and then allow the user to call functions from the class to display and
// perform operations
//

// main program
//
int main(int argc, char** argv){

  // check that we have proper number of arguments
  //
  if(argc == 5){

    // create and read our matrices exiting
    // if they dont exist
    //
    MyMatrix matrix, matrix2;
    if(!matrix.read(argv[3])){
      return 1;
    }
    
    
    if(!matrix2.read(argv[4])){
      return 1;
    }

    // check that they tried to do a valid operation
    //
    if(OPERATOR.count(argv[1])){
      if (OPTIONS.count(argv[2])){

	// print results if operations are valid
	//
	fprintf(stdout, "First Matrix:\n");
	matrix.display(stdout);
	fprintf(stdout, "Second Matrix:\n");
	matrix2.display(stdout);
	fprintf(stdout, "Result:\n");
	performOp(argv[2], matrix, matrix2);
	
      }
      else{

	// tell user that there was an invalid operation
	//
	fprintf(stderr, "Undefined operation selected.\n");
	fprintf(stderr, "Usage: p01.exe -operation/-o <operation> <matrix_file> <matrix_file>\n");
	return 1;
	
      }
    } else{

      // tell user that there was an no valid option
      //
      fprintf(stderr, "Undefined option selected.\n");
      fprintf(stderr, "Usage: p01.exe -operation/-o <operation> <matrix_file> <matrix_file>\n");
      return 1;
      
    }

    // exit gracefully
    //
    return 0;
  }

  // tell user error when there are incorrect number of argument
  //
  else{
    
    fprintf(stderr, "Incorrect number of arguments.\n ");
    fprintf(stderr, "Usage: p01.exe -operation/-o <operation> <matrix_file> <matrix_file>\n");
    return 1;
    
  }
   
}

// end of file
