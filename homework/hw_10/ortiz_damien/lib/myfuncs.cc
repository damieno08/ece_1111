#include "myfuncs.h"

// function will perform exponential operations
// using a for loop
//

float mypow_for(float x, long y){

  int result = 1;
  
  for(int i = 0 ; i < y; i ++){

    result*=x;
    
  }

  return result;

}


// function performs exponential operations
// using recursion
//
float mypow_rec(float x, long y){

  if (y>0){
    return x*mypow_rec(x, y-1);
  } else{

    return 1;
  }

}


// function will take in string form of binary number and
// convert it to decimal
//
int binaryToDecimal(char* binaryText){

  // put string backwards so we can index forwards
  //
  char backString[strlen(binaryText)+1];
  
  for(int i =0 ; i < strlen(binaryText); i++){

    backString[i] = binaryText[strlen(binaryText) - 1 - i];    

    // check that we only enter 1 or 0
    //
    if(binaryText[i]-'0' != 1 && binaryText[i] - '0' != 0){

      // tell user their error
      //
      fprintf(stderr, "Error: Only use binary integers.\n");

      // return a failure
      //
      return 0;
      
    }
    
  }

  // return the decimal number
  //
  int result = 0;
  
  for(int i = 0; i < strlen(backString); i ++ ){

    result+= (backString[i] - '0') * (int)pow(2, i);

  }  
  
  return result;
  
}


