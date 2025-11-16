// file: /data/courses/ece_1111/2025_01_fall/homework/hw_12/ortiz_damien/p02/p02.cc/
//
// Version History: 
// 20251113 create initial file

// include files 
//
#include "p02.h"

// Program will read a file and print out the frequency of each word
// in ascending order
//

// main program
//
int main(int argc, char** argv) {

  if(argc == 2){
  // create instance of class
  //
  ComputeWordFrequencies cwf(argv[1]);

  // read and print each word frequency
  //
  cwf.parseFile();
  cwf.printFrequencies();

  // exit gracefully
  //
  return 0;
  
  }
  
  // tell user they used incorrect number of arguments
  //
  else{

    fprintf(stderr, "Error with argument usage.\n");
    fprintf(stderr, "Usage: p02.exe <file>\n");    

  }
}
