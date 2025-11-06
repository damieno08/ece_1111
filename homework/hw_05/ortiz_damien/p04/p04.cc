// file: /data/courses/ece_1111/current/homework/hw_05/ortiz_damien/p04/p04.cc
//
//

// include files
//
#include <stdio.h>
#include <stdlib.h>

// main program
//
int main(int argc, char** argv) {

  // creates buffer which will hold each line
  //
  char line[256];

  // loops through every line of the file then prints the line onto the
  // terminal just like the cat command
  //
  while (fgets(line, sizeof(line), stdin) != NULL){
    fprintf(stdout, "%s", line);
  }
}
