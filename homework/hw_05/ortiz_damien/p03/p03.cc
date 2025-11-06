// file: /data/courses/ece_1111/current/homework/hw_05/ortiz_damien/p03/p03.cc
//
//

// include files
//
#include <stdio.h>
#include <stdlib.h>

// main program
//
int main(int argc, char** argv) {

  // creates a bunch of variables of different types
  //
  char c = 'q';
  short int i = 27;
  long j = 27272727;
  float sum = 27.272727272727;

  // prints each variable, but the float has two decimal points in
  // its format
  //
  fprintf(stdout, "The value of c is %c\n", c);
  fprintf(stdout, "The value of j is %ld\n", j);
  fprintf(stdout, "The value of i is %d and the value of sum is %.2f\n", i,sum);
}
