// file: /data/courses/ece_1111/2025_01_fall/labs/lab_12/ortiz_damien/p01/p01.h

// define header if not defined
//
#ifndef _p01
#define _p01

// include files
//
#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <unordered_set>

// macro for maximum line size
//
#define MAX_LINE_LENGTH 999

// create sets to check if operations are valid
//
std::unordered_set<std::string> OPTIONS {"addition", "subtraction", "multiplication"};
std::unordered_set<std::string> OPERATOR {"-o", "-operation"};

// class that contains matrix
//
class MyMatrix{

protected:

  // our matrix data
  //
  std::vector<std::vector<float>> matrix;

  // our matrix dimensions
  //
  int rows;
  int cols;
  
public:

  // constructor where 1x1 is default
  //
  MyMatrix(int r = 1, int c = 1){
    rows = r;
    cols = c;
  }

  // function to read data into matrix
  //
  bool read(char* file);

  // function to display matrix
  //
  bool display(FILE* fp);

  // get dimenions
  //
  int getRows();
  int getCols();

  // redfine operator to add each element
  //x
  MyMatrix operator+(const MyMatrix& mat) const{
    
    // check that sizes match
    //
    if(rows == mat.rows && cols == mat.cols){
      MyMatrix result(rows,cols);
      for(int i = 0; i< rows; i++){
	std::vector<float> row;
	for(int j =0 ; j< cols; j++){
	  row.push_back(matrix[i][j] + mat.matrix[i][j]);
	}

	result.matrix.push_back(row);

      }


      // return result
      //      
      return result;
      
    } else{

      // tell user if error happened
      //
      fprintf(stderr, "Incorrect dimensions for addition.\n");
      return MyMatrix(0,0);
    }
         
  }

  // change subtract operator to subtract each element
  //
  MyMatrix operator-(const MyMatrix& mat) const{
    
    // check sizes match
    //
    if(rows == mat.rows && cols == mat.cols){
      MyMatrix result(rows, cols);
      for(int i = 0; i< rows; i++){
	std::vector<float> row;
	for(int j =0 ; j< cols; j++){
	  row.push_back(matrix[i][j] - mat.matrix[i][j]);
	}
	result.matrix.push_back(row);
	
      }
      
      // return result
      //
      return result;
      
    } else{

      // tell user sizes dont match
      //
      fprintf(stderr, "Incorrect dimensions for subtraction.\n");
      return MyMatrix(0,0);
    }
      
    

  }

  // overwrite multiplication
  //
  MyMatrix operator*(const MyMatrix& mat) const{

    // check that dimensions work
    //
    if(cols == mat.rows){
      MyMatrix result(rows, mat.cols);

      // perform matrix multiplication
      //
      for(int i = 0; i< rows; i++){
	std::vector<float> row;
	for(int j = 0; j < mat.cols; j++){
	  
	  float num = 0;
	  for(int k = 0; k < cols; k++){
	    num += matrix[i][k] * mat.matrix[k][j];
	  }
	  row.push_back(num);
	}
	result.matrix.push_back(row);
      }

      return result;
      
    } else{

      // tell user dimensions dont work
      //
      fprintf(stderr, "Incorrect dimensions for multiplication.\n");
      return MyMatrix(0,0);
    }


  }
  
};

// include definitions of functions
//
#include "mat_00.cc"

#endif

// end of file
