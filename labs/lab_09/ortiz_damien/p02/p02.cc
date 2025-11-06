// file: /data/courses/ece_1111/2025_01_fall/labs/lab_09/ortiz_damien/p02/p02.cc/
//

// Version History: 
// 20251021 create initial file

// include files 
//
#include "p02.h"

// Program will sort a text file lexically using selection sorting
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

  // sort lines using selection sorting
  //
  mysort(lines, lineCount, op);

  // check for valid sorting order
  //
  if (!strcmp(op, "-a") || !strcmp(op, "-d"))
    printString(lines, stdout); 

  // delete any allocated memory
  //
  cleanStringArrayMemory(lines);

  // exit gracefully
  //
  return 0;
  }

  // error case for incorrect number of arguments
  //
  fprintf(stderr, "Incorrect usage.\n");
  fprintf(stdout, "Usage: p01.exe [option] <text_file>\n");

  // exit with errors
  //
  return 1;
}

// end of file
