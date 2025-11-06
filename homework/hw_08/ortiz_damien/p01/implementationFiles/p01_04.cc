#include "../p01.h"

// function to get minor within the determinant
  //
  float** getMinor(float** mat, int n, int p, int q) {
    float** minor = new float*[n-1];
    for(int i = 0; i < n-1; i++)
      minor[i] = new float[n-1];
    
    int rowOffset = 0, colOffset = 0;
    for(int i = 0; i < n; i++) {
      if(i == p) { rowOffset = 1; continue; }
      colOffset = 0;
      for(int j = 0; j < n; j++) {
	if(j == q) { colOffset = 1; continue; }
	minor[i - rowOffset][j - colOffset] = mat[i][j];
      }
    }
    return minor;
  }

float determinant(float** mat1, int rows, int cols){

  // check if the matrix is square
  //
  if (rows != cols) {

    // return null if wrong dimensions while also alerting user
    //
    char err[] = "Error: determinants are only possible with square matrices.\n";
    fwrite(err, sizeof(char), strlen(err), stderr);
    return NAN;
  }

  // check what size matrix we have and only use cofactor expansion if necessary
  //
  if (rows == 1)
    return mat1[0][0];
  if (rows == 2)
    return mat1[0][0]*mat1[1][1] - mat1[0][1]*mat1[1][0];

  // perform cofactor expansions and return result
  //
  float result = 0.0;
  for (int j = 0; j < cols; j++) {
    float** minor = getMinor(mat1, rows, 0, j);
    result += (j % 2 == 0 ? 1 : -1) * mat1[0][j] * determinant(minor, rows-1, cols-1);
    
    // Free the minor matrix
    //
    for(int k = 0; k < rows-1; k++)
      delete[] minor[k];
      delete[] minor;
  }

  // return value of determinant
  //
  return result;
  
}
