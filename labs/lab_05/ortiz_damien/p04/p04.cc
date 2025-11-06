// file: /data/courses/ece_1111/current/labs/lab_05/ortiz_damien/p04/p04.cc
//

// Version History:
// 09222025 create initial file
// 09232025 comment and add error checking for input length

// program will act like the cat command
//

// include files
//
#include <stdio.h>

// main program
//
int main(int argc, char** argv) {

  // checks if there are at least two arguments in the command line
  //
  if (argc < 2){

    // error message if there aren't enough inputs
    //
    fprintf(stdout, "Error: Not enough inputs\n");
    fprintf(stdout, "Usage: p04.exe <filename>\n");
  }
  
  // code when there are enough inputs
  //
  else{

    // loops through every file before printing it
    //
    for (short int i = 1; i<argc ; i++){

      // creates char point which points to text entered onto argument
      //
      char* fileName = argv[i];

      // creates file pointer
      //
      FILE *filePointer;

      // opens file and redirects the open file data to pointer
      //
      filePointer = fopen(fileName, "r");

      // creates a char array that will store each line
      //
      char line[100];

      // loops through each existing line of the file printing it
      //
      while (fgets(line, sizeof(line), filePointer) != NULL) {
	fprintf(stdout,"%s", line);
      }

      // adds extra newline after the file
      //
      fprintf(stdout, "\n");

      // closes file after use
      //
      fclose(filePointer);
      
    }
  }
}
