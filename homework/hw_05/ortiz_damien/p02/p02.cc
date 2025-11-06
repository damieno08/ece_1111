// file: /data/courses/ece_1111/current/homework/hw_05/ortiz_damien/p02/p02.cc
//

// include files
//
#include <stdio.h>
#include <stdlib.h>

// main program
//
int main(int argc, char** argv) {

  // create a bunch of variables with different types
  //
  char c = 'q';
  short int i = 27;
  long j = 27272727;
  float sum = 27.272727272727;

  // demonstrate how each variable type is printed
  //
  fprintf(stdout, "The value of c is %c\n", c);
  fprintf(stdout, "The value of i is %d\n", i);
  fprintf(stdout, "The value of j is %ld\n", j);
  fprintf(stdout, "The value of sum is %f\n", sum);
}
