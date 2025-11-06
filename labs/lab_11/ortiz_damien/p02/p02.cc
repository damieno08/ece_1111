// file: /data/courses/ece_1111/2025_01_fall/labs/lab_11/ortiz_damien/p02/p02.cc/
//
// Version History: 
// 20251103 create initial file

// include files 
//
#include "p02.h"

// Program will sort numbers based on comparison
// logic library
//

// main program
//
int main(int argc, char** argv){
  
  // check if number of arguments is correct
  //
  if(argc == 3){
  
    char* fileName = argv[1];

    char* endFile = argv[2];
    
    // create function pointer and set it to compare
    // function
    //
    int (*compare)(const void*, const void*);
    
    compare = comp;

    // get line count and exit program if failed
    //
    int numLines = countLines(fileName);
    if(!numLines)
      return 1;

    // create list of numbers and exit if failed
    //
    bigNum* ints = getIntegers(fileName, numLines);
    if(!ints)
      return 1;

    // sort the array of all integers
    //
    qsort(ints, numLines, sizeof(struct bigNum), compare);

    // write result to target file
    //
    FILE* endF = fopen(endFile, "w");
    
    for(int i = 0; i < numLines; i++){
      
      fprintf(endF, "%d\n", ints[i]);      
      
    }
    
    fprintf(stdout, "Output file created.\n");
    
    fclose(endF);
    
    // delete memory allocated for array
    //
    delete[] ints;

    // exit gracefully
    //
    return 0;
  }

  // print error of arguments to user
  //
  fprintf(stderr, "Incorrect number of arguments.\n");
  fprintf(stdout, "Usage: p02.exe <input_file> <output_file>\n");

  // exit with errors
  //
  return 1;
}

