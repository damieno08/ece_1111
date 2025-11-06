// file: /data/courses/ece_1111/2025_01_fall/homework/hw_07/ortiz_damien/p03/p03/p03.cc
//
// Version History: 
// 20251011 create initial file

// include files 
//
#include "p03.h"

// Program will read a file then print the lines ignoring
// any line that starts with #
//

// main program
//

int main(int argc, char** argv){

  // check if proper number of arguments
  //
  if (argc ==2){

    // read first file
    //
    FILE* readingFile = fopen(argv[1], "r");

    // check if first file exists
    //
    if(readingFile==NULL){
      fprintf(stdout, "File does not exist.\n");
      return 1;
    }
    
    char string[255];

    // read every line within the file
    //
    while(fgets(string, sizeof(string), readingFile) != NULL){
      int i = 0;

      // remove any whitespace before the strings
      //
      while (isspace((unsigned char)string[i])) {
	i++;
      }

      // check if the line starts with # to ignore it
      //
      if (string[i] != '#'){
	float numInLine;
	if (sscanf(string, "%f", &numInLine) != 0){
	  fprintf(stdout, "%10.4f\n", numInLine);
	}
	
	// print if the line does not start with #
	//
	else
	  fprintf(stdout, "%s", string);
      }
    }

    // close the file we opened
    //
    fclose(readingFile);

    // exit gracefully
    //
    return 0;
  }

  // errors when incorrect number of arguments
  //
  fprintf(stderr, "Error: incorrect number of arguments.\n");
  fprintf(stderr, "Usage: p03.exe <file>\n");

  // exit with errors
  //
  return 1;
}
