// file: /data/courses/ece_1111/2025_01_fall/homework/hw_08/ortiz_damien/p02/p02.cc/
//
// Version History: 
// 20251015 create initial file
// 20251019 change formatting to use functions

// include files 
//
#include "p02.h"

// Program will read 16 bit binary integers, place them into vectors, then
// add the vectors and print the result

// main program
//

int main(int argc, char** argv){  


  // check if there are correct number of arguments
  //
  if (argc == 3){

    // open first file and return an error if it doesn't exist
    //
    FILE* firstVectorFile = fopen(argv[1], "rb");
    if(!firstVectorFile){
      fprintf(stderr, "First vector file does not exist.\n");
      return 1;
    }

    // find the list of binary integers, size of the file, and number of elements
    //
    long fileSize1;
    int numberOfElements1;
    
    unsigned short* binaryList1 = createBinaryList(&fileSize1, &numberOfElements1, firstVectorFile);

    // open second file and return an error if it doesn't exist
    //
    FILE* secondVectorFile = fopen(argv[2], "rb");
    if(!secondVectorFile){
      fprintf(stderr, "Second vector file does not exist.\n");
      return 1;
    }    

    // find the list of binary integers, size of the file, and number of elements
    //
    long fileSize2;
    int numberOfElements2;

    unsigned short* binaryList2 = createBinaryList(&fileSize2, &numberOfElements2, secondVectorFile);


    // check that vectors are same size
    //
    if (numberOfElements1 != numberOfElements2){
      
      // return error if they are not the same size
      //
      fprintf(stderr, "Vector dimensions do not match.\n");
      return 1;
    }


    // create the result matrix and compute its values
    //
    unsigned short* result = new unsigned short[numberOfElements1];
        
    for (int i = 0; i < numberOfElements1; i++){
      
      result[i] = binaryList1[i] + binaryList2[i];
      fprintf(stdout, "%d + %d = %d\n", binaryList1[i], binaryList2[i],result[i]);
    }
    
    // delete all allocated memory
    //
    delete[] binaryList1;
    delete[] binaryList2;
    delete[] result;

    // exit gracefully
    //
    return 0;
  }
  
  // tell user there aren't enough arguments
  //
  fprintf(stderr, "Error: not enough arguments.\n");
  fprintf(stdout, "Usage: p01.exe <binaryFile1> <binaryFile2>\n");
  
  // exit with errors
  //
  return 1;
}

// end of file
