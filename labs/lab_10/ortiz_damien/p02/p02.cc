// file: /data/courses/ece_1111/2025_01_fall/labs/lab_10/ortiz_damien/p02/p02.cc/
//

// Version History: 
// 20251028 create initial file
// 20251029 create functions for circular buffer 
// 20251030 create functions for parsing command line

// include files 
//
#include "p02.h"

// Program will copy linux grep command in C

// main program
//
int main(int argc, char** argv) {

  // check if there are correct number of arguments
  //
  if (argc >= 4){
        
    struct Buffer buff;

    int numFiles = 0;
    
    // put all necessary values in buffer then create a file list
    //
    char** fileList = getFileList(argv, argc, buff, &numFiles);

    // if there is an error like -w not being in arguments exit program;
    // will also check that if N is entered it is positive numerical value
    //
    if(!fileList){

      return 1;
      
    }

    

    // loop through each file using circular buffer to find matches
    //
    for(int i = 0; i < numFiles; i ++){
      
      initBuffer(buff);
      
      FILE* fp = fopen(fileList[i], "r");

      // check that files exist
      //
      if(!fp){
	fprintf(stderr, "The file '%s' does not exist.\n", fileList[i]);
	return 1;
      }
      fprintf(stdout, "%s:\n", fileList[i]);
      readFile(fp, buff);
      freeBuffer(buff);
    }

    // delete allocated memory for fileList pointer
    //
    delete[] fileList;

    // exit gracefully
    //
    return 0;
  }

  // error case with not enough arguments
  //
  fprintf(stderr, "Not enough arguments.\n");
  fprintf(stdout, "Usage: p02.exe -w <searchWord> -n <number of lines around match> file(s)\n");

  // exit with errors
  //
  return 1;

  
}

// end of file



