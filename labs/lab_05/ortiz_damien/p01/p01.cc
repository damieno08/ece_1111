// file: /data/courses/ece_1111/current/labs/lab_05/ortiz_damien/p01/p01.cc
//

// Version History:

// 09222025 add error checking for argument length and type
// 09222025 create inital file

// program will take in float argument and print out value of argument
// alongside file name
//

// include files
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// main program
//
int main(int argc, char** argv) {

  // check if there are enough statements
  
  if (argc == 2){
  
    // creates pointer to say when the end of float is
    //
    char *endptr;

    // checks if the string can become a float; returns a zero at the end
    // pointer if it does not
  
    float value = strtof(argv[1], &endptr);

    // true or false for if the value was a float
    //
    bool inputType = (*endptr == '\0');
    
    // checks that second command is a float
    //
    if(!inputType){

      fprintf(stdout, "Error: second argument should be a float\n");
    
    } else{

      // create char pointer that fprintf will reference
      //
      char* programName = argv[0];
    
      // create floating point number by converting string to int usinf
      // atof which is ASCII string to float function 
      //
      float sum = atof(argv[1]);

      // creates formatted print statement 
      //
      fprintf(stdout, "program name: %s sum = %f\n", programName, sum );
    
    }

  }  
  else{

      // error message for incorrect number of arguments
      //
      fprintf(stdout, "Error: incorrect number of argument\n");
	    fprintf(stdout, "Usage: p01.exe <float>\n");
    }
  // returns 0 when the main function is complete
  //
  return 0;
}
