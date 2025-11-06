// file: /data/courses/ece_1111/2025_01_fall/homework/hw_07/ortiz_damien/p01/p01/p01.cc
//
// Version History: 
// 20251009 create initial file

// include files 
//
#include "p01.h"

// Program will read a single character line and
// convert it into the bit value

// function to find binary value of input
//
 unsigned int toBinary(char x){
   int size = sizeof(x);
   
   int sizeOfBinary = 8 * size;
   unsigned char ux = (unsigned char)x;
   char string[sizeOfBinary+1];
   unsigned int binary;

   // create binary value onto the string representing it
   //
   for (int i = sizeOfBinary-1; i >= 0; i--){

     // shift bits
     //
     unsigned int bit = (ux >> (sizeOfBinary - 1 - i)) & 1;

     // put the necessary 1 or 0 in the string
     //
     string[i] = bit ? '1' : '0';
   }
   string[sizeOfBinary] = '\0';
   // convert string to integer
   //
   binary = atoi(string);
   return binary;
}

// function will take in string representation of bits and the number of characters
// then format it to contain a multiple of four bits
//
void formatFourBit(char* binary, int numChars){
  size_t len = strlen(binary);
  int remainder = numChars % 4;
  int diffSize = 0;

  // check if we already have proper formatting
  //
  if (remainder != 0)
    diffSize = 4-remainder;

  // add leading zeros if formatting is not correct
  //
  if (diffSize !=0 ){

    for(int j = 0; j < diffSize; j++){
      for (size_t i = len; i > 0; i--) {
	binary[i] = binary[i - 1];
      }
      
      binary[0] = '0';
      len++;
      binary[len] = '\0';
      
    }
    
  }
}

// main program
//
int main(int argc, char** argv){

  // check for the correct number of arguments
  //
  if (argc ==2){
    // read and open the file argument
    //
    FILE* file1 = fopen(argv[1], "r");

    // tell user if the file used does not exist
    //
    if (file1 == NULL){
      fprintf(stdout, "File does not exist.\n");
      return 1;
    }
  
    // create buffer to store characters
    //
    char line[10];

    // loop through each line finding binary value and printing it
    //
    while (fgets(line, sizeof(line), file1)!=NULL){
      unsigned int binary = toBinary(line[0]);
      char stringBinary[33];
      int numChars = sprintf(stringBinary, "%u", binary);
      formatFourBit(stringBinary, numChars);
      fprintf(stdout, "%c => %s (%d)\n", line[0], stringBinary, line[0]);   
      
    }

    // close file and exit program
    //
    fclose(file1);
    return 0;
  }
  else{

    // if there were not the correct number of arguments then print error statement with the correct usage
    //
    fprintf(stdout, "Incorrect number of arguments.\n");
    fprintf(stdout, "Usage: p01.exe <file>\n");

    // exit program
    //
    return 1;
  }
}
