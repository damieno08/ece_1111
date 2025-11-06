// file: /data/courses/ece_1111/2025_01_fall/homework/hw_10/ortiz_damien/p02/p02.cc/
//
// Version History: 
// 20251030 create initial file

// include files 
//
#include "p02.h"

// Program will convert binary string into
// decimal number
//

// main program
//
int main(int argc, char** argv){

  // check for proper number of arguments
  //
  if(argc == 2){

    // convert string to number
    //
    int i =  binaryToDecimal(argv[1]);

    // exit with errors if it fails
    //
    if(!i)
      return 1;
    
    // print out formatted answer
    //
    fprintf(stdout, "Input binary number: %s\n", argv[1]);
    fprintf(stdout, "Output decimal number: %d\n",i);


    // exit gracefully
    //
    return 0;
    
  }

  // error case with incorrect number of arguments
  //
  else{

    // show user usage
    //
    fprintf(stderr, "Incorrect number of arguments\n");
    fprintf(stderr, "Usage: p02.exe <binary number>\n");
    
  }
}
