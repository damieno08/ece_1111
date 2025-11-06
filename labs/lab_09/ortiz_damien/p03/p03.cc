// file: /data/courses/ece_1111/2025_01_fall/labs/lab_09/ortiz_damien/p03/p03.cc/
//

// Version History: 
// 20251022 create initial file

// include files 
//
#include "p03.h"

// Program will sort text file using heap sorting
//

// main program
//
int main(int argc, char** argv){


  // check if there are proper number of arguments
  //
  if (argc == 3){

    char* fileName = argv[2];

    char* op = argv[1];

    // find number of lines in file and tell user if file doesn't exist
    //
    int lineCount = countLines(fileName);
    if(lineCount == -1)
      return 1;

    // create array of lines in file
    //
    char** lines = getLineText(fileName);  

    // sort lines using bubble sorting
    //
    mysort(lines, lineCount, op);          

    if (!strcmp(op, "-a") || !strcmp(op, "-d"))
      printString(lines, stdout); 


    // delete allocated memory
    //
    cleanStringArrayMemory(lines);

    // exit gracefully
    //
    return 0;
  }

  // error case for not enough arguments
  //
  fprintf(stderr, "Incorrect usage.\n");
  fprintf(stdout, "Usage: p01.exe [option] <text_file>\n");

  // exit with errors
  //
  return 1;
}

// end of file
