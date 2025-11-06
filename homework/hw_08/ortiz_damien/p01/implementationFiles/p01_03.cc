#include "../p01.h"

float** subtractMatrices(float** mat1, float** mat2, int rowsMat1, int rowsMat2 , int colsMat1, int colsMat2){

  float** result = new float*[rowsMat1];

  if (rowsMat1 != rowsMat2 || colsMat1 != colsMat2){
    // delete allocated memory and return null if wrong dimensions
    // while also alerting user
    //
    char err[] = "Error: dimensions do not match\n";
    fwrite(err, sizeof(char), strlen(err), stderr);
    delete[] result;
    return nullptr;    
  }  

  // subtract each element
  //
  for (int i = 0; i < rowsMat1; i++){
    
    result[i] = new float[colsMat1];
    
    for (int j = 0; j < colsMat1; j++){
      
      result[i][j] = mat1[i][j] - mat2[i][j];
      
    }
      
  }
  return result;
}

