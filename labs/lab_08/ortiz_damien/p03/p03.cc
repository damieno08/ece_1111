// file: /data/courses/ece_1111/2025_01_fall/labs/lab_08/ortiz_damien/p03/p03.cc
//

// Version History: 
// 20251014 create initial file

// include files
//
#include "p03.h"

// Program will read a file then 
// print its line number alongside its value
// ex) 27: this is text
//

// main program
//
int main(int argc, char** argv){
    
    // check if there are correct number of arguments
    //
    if ( argc == 2){

      // return array containing each line of text
      //
      char** strs = getLineText(argv[1]);

      // print each string
      //
      printString(strs, stdout);

      // remove allocated memory
      //
      cleanStringArrayMemory(strs);
      
      // exit gracefully
      //
      return 0;
    }
    
    // error statement with wrong number of arguments
    //
    fprintf(stderr, "Error: incorrect number of arguments\n");
    fprintf(stdout, "Usage: p01.exe <file_to_read>\n");
    return 1;
    
}
