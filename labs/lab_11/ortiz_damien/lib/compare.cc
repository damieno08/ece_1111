#include "compare.h"

// function will compare two values and return 1, 0, or -1 based on
// if they are even or odd
//
int comp(const void *a, const void *b) {

  // convert any input into longs
  //
  signed long ia = *(signed long*)a;
  signed long ib = *(signed long*)b;

  // use terniary opeerator to check if even or odd
  //
  int aEven = ia%2==0 ? 1:0;
  int bEven = ib%2==0 ? 1:0;

  // return values based on even and odd
  //
  if(aEven && bEven){

    // both even
    //
    if (ia<ib) return -1;
    if (ia==ib) return 0; 
    if (ia>ib) return 1;

  }

  // both odd
  //
  else if(!aEven && !bEven){

    if (ia>ib) return 1;
    if (ia==ib) return 0; 
    if (ia<ib) return -1;

  } else{

  // one odd one even
  //
  if (abs(ia) < abs(ib)) return -1;
  if (abs(ia) == abs(ib)) return 0;
  if (abs(ia) > abs(ib)) return 1;
  }
  
  return 0;
  
}
