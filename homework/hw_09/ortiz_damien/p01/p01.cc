// file: /data/courses/ece_1111/2025_01_fall/labs/lab_09/ortiz_damien/p01.cc/
//

// Version History: 
// 20251021 create initial file

// include files 
//
#include "p01.h"

// Program will sort a text file lexically using bubble sorting
//

// main program
//
int main(int argc, char** argv){

  // create clock to measure time of function
  //
  clock_t start, end;
  double cpu_time_used;

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

    // start timer
    //
    start = clock();
    
    // sort lines using bubble sorting
    //
    mysort(lines, lineCount, op);          


    // end timer
    //
    end = clock();

    // calculate time spent on function
    //
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // tell user function process time
    //
    fprintf(stdout, "Function time: %f", cpu_time_used);

    // only print string if correct option was used
    //
    if (!strcmp(op, "-a") || !strcmp(op, "-d") ||  !strcmp(op, "-u") )
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
