// file: /data/courses/ece_1111/current/labs/lab_05/ortiz_damien/p03/p03.cc
//

// Version History:
// 09222025 create initial file
//

// program will create a table of every int from 0 to 255 and print
// its value onto a table in hexadecimal, octal, and its char equivalent
//

// include files
//
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// main program
//
int main(int argc, char** argv) {

  // loops fro, 0 to 255
  //
  for (int i = 0; i<256; i++){

    // creates unsigned char so that we are able to do all values
    // from 0 to 255 or we would stop at 127
    //
    unsigned char c = i;

    if (isprint(c)){
      
      // prints table of values of the current number
      //
      fprintf(stdout, "| %d | %x | %o | %c |\n", i,i,i,c);
      
    }else{

      // skips any characters we cant print
      //
      fprintf(stdout, "| %d | %x | %o | N/A |\n", i,i,i);
      
    }
  }
}
