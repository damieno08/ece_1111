// file: /data/courses/ece_1111/current/labs/lab_10/ortiz_damien/p02/p02_01.cc
//

// all functions will process command line to be used for file I/O
// with circular buffer

// include files
//
#include "p02.h"

// functions will parse text from command line
//
char** getFileList(char** argv, int argc, Buffer& buff, int* num){

  bool found1 = false;
  bool found2 = false;

  char* searchText;
  int numLines;
  int wordIndex;
  int lineIndex;

  // loop through each argument
  //
  for (int i = 1; i < argc; i++ ){

    // define search word if present
    //
    if(strstr(argv[i],"-w")){

      searchText = argv[i+1];
      wordIndex = i+1;
      
      found1 = true;
      
    }

    // define window size if present
    //
    else if(strstr(argv[i], "-n")){

      numLines = atoi(argv[i+1]);
      lineIndex = i +1;
      found2 = true;
      
    }

  }
  
  // define all buffer values if found and exit if no search word is present
  //
  if(found1){
    buff.searchText = searchText;
    
    if(found2){

      // check that N is a positive value
      //
      if(numLines >= 1){
	
	buff.N = numLines;
      } else{

	fprintf(stderr, "Error: N must be a positive numerical value\n");
	return nullptr;

      }
      
    } else{
      buff.N = 1;
      lineIndex = wordIndex;
    }
    
  } else{
    
    fprintf(stderr, "No search word in arguments\n");
    return nullptr;
    
  }

  // get number of files
  //
  int numFiles = argc - (int)fmax(lineIndex, wordIndex)-1;
  
  // create file list we will return
  //
  char** fileList = new char*[numFiles];

  // copy arguments past search and line number
  //
  memcpy(fileList, argv + (int)fmax(lineIndex, wordIndex)+1, numFiles*sizeof(char*));

  *num = numFiles;
  
  // return list of files
  //
  return fileList;     
  
}

