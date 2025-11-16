// file: /data/courses/ece_1111/2025_01_fall/labs/lab_11/ortiz_damien/p03/p03.cc/
//
// Version History: 
// 20251103 create initial file

// include files 
//
#include "p03.h"

// Program will use a macro to compare
// randomly generated numbers
//

// main program
//

int main(int argc, char** argv){

  // check for number of arguments
  //
  if(argc == 2){

    // create range of random numbers
    //
    long max = 100000000000L;
    long min = -100000000000L;

    // set seed so numbers are actually random
    //
    srand(time(NULL));

    int N = 0;
    
    // check that only a positive number has been entered for N
    //
    for(int i = 0 ; i < strlen(argv[1]); i++){
      if(isdigit(argv[1][i])){
	N = atoi(argv[1]);
      } else{
	
	// print error and exit if letter entered for N
	//
	fprintf(stderr, "Non numerical value detected.\n");
	return 1;
	
      }
    }
    
    // loop and print each random number and comparison
    //    
    for(int i = 0; i < N; i++){
      
      long randomNumber1 = ((long)rand() * RAND_MAX + rand()) % (max - min + 1) + min;
      long randomNumber2 = ((long)rand() * RAND_MAX + rand()) % (max - min + 1) + min;
      fprintf(stdout, "Iteration: %d\n", i+1);
      fprintf(stdout, "First Number: %ld\n", randomNumber1);
      fprintf(stdout, "Second Number: %ld\n", randomNumber2);
      fprintf(stdout, "Comparison Value: %d\n\n", COMPARE(randomNumber1, randomNumber2));
      
    }  

    // exit gracefully
    //
    return 0;
    
  }

  // print errors when incorrect number of args
  //
  fprintf(stderr, "Error in number of arguments.\n");
  fprintf(stderr, "Usage: p03.exe <integer>.\n");

  // exit with errors
  //
  return 1;
}
