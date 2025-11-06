// file: /data/courses/ece_1111/2025_01_fall/homework/hw_10/ortiz_damien/p01/p01.cc/
//
// Version History: 
// 20251029 create initial file

// include files 
//
#include "p01.h"

// Program will calculate any exponent using
// recursion and a for loop
//

// main program
//
int main(int argc, char** argv){

  // check for proper number of arguments
  //
  if(argc == 3){

    char* endptr;
    char* endptr2;

    // try to convert each argument into a number
    // and return an error if not a number
    //
    float base = strtof(argv[1], &endptr);
    float exp = strtof(argv[2], &endptr2);
    if (endptr == argv[1]) {
      fprintf(stderr, "No conversion could be performed.\n");
      fprintf(stdout, "Usage: p01.exe <number 1> <number 2>\n");
      return 1;
    }
    if (endptr2 == argv[2]) {
      fprintf(stderr, "No conversion could be performed.\n");
      fprintf(stdout, "Usage: p01.exe <number 1> <number 2>\n");
      return 1;
    }

    // call and print out for loop power function
    //
    float num = mypow_for(base, atof(argv[2]));

    fprintf(stdout, "For Loop: pow(%5.2f ** %5.2f) = %5.2f\n", base, exp, num);


    // call and print out the recursion power function
    //
    float num2 = mypow_rec(atof(argv[1]), atof(argv[2]));
    
    fprintf(stdout, "Recursion: pow(%5.2f ** %5.2f) = %5.2f\n", base, exp, num2);


    // exit gracefully
    //
    return 0;
  }

  // when there aren't enough arguments or are too many
  //
  else{

    // tell user error
    //
    fprintf(stderr, "Error with number of arguments\n");
    fprintf(stdout, "Usage: p01.exe <number 1> <number 2>\n");


    // exit with errors
    //
    return 1;

  }
}

// end of file
