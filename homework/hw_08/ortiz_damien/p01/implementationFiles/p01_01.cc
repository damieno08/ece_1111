#include "../p01.h"

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
