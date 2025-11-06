// file: /data/courses/ece_1111/2025_01_fall/homework/hw_07/ortiz_damien/p02/p02/p02.cc
//
// Version History: 
// 20251009 create initial file

// include files 
//
#include "p02.h"

// Program will read first char of each line
// within file and use the mask entered into
// the command line to do AND, OR, and XOR
// logic

// function to find binary value of input
//
unsigned int charToBinary(char x){

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

// function will convert an integer to its binary value
//
 unsigned int intToBinary(int x){
   int size = sizeof(x);
   
   int sizeOfBinary = 8 * size;
   unsigned int ux = (unsigned int)x;
   char string[sizeOfBinary + 1];

   // loop through number and find binary value
   //
   for (int i = sizeOfBinary-1; i >= 0; i--){

     // bit shifting
     //
     unsigned int bit = (ux >> (sizeOfBinary - 1 - i)) & 1;

     // create string with the necessary 1 or 0
     //
     string[i] = bit ? '1' : '0';
   }
   unsigned int binary = atoi(string);   
   return binary;
}

// function will turn a string representation of hexidecimal
// into string of its binary value
//
 char* hexStringToBinary(char* hex){
   int size = strlen(hex);
   
   int sizeOfBinary = 4 * size;

   // allocated space for the returning string
   //
   char* binary = new char[size * 4 + 1];

   // allocate space for all decimal values
   //
   int* deciValue = new int[strlen(hex)];
   
   int deciVal;

   // use the decimal value of the hexidecimal code to create binary output
   //
   for(int i = 0; i < strlen(hex); i++){
     if (hex[i] >= '0' && hex[i] <= '9') deciVal = hex[i] - '0';
     else if (hex[i] >= 'A' && hex[i] <= 'F') deciVal = 10 + (hex[i] - 'A');
     else if (hex[i] >= 'a' && hex[i] <= 'f') deciVal = 10 + (hex[i] - 'a');
     unsigned int binaryValue = intToBinary(deciVal);
     char tempString[33];
     sprintf(tempString, "%u", binaryValue);
     strcat(binary, tempString);
   }

   //delete allocated memory
   //
   delete[] deciValue;
   return binary;
}

// function will reverse any string 
//
void reverseString(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char tmp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = tmp;
    }
    
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

// function will do logical comparison of bits with And, Or, or Xor logic
//
void compareBits(char* binaryText, char* binaryMask, char* op, char* matchingBits){
    char reversedBinary[strlen(binaryText) +1];
    char reversedMask[strlen(binaryMask) +1];
    strcpy(reversedBinary, binaryText);
    strcpy(reversedMask, binaryMask);
    fprintf(stdout, "%s: ", op);

    // if And is selected
    //
    if (strcmp(op, "And") == 0){

      // will result in 1 or 0 based on logic
      //
      for (size_t i = 0; i < sizeof(reversedMask); i++){
	if (reversedMask[i] == '1' && reversedBinary[i] == '1') {
	  matchingBits[i] = '1';
	} else {
	  matchingBits[i] = '0';
	}
      }
    }

    // if Or is selected
    //
    if (strcmp(op, "Or") == 0){

      // 0 if both are 0 1 if either is 1
      //
      for (size_t i = 0; i < sizeof(reversedMask); i++){
	if (reversedMask[i] == '1' || reversedBinary[i] == '1') {
	  matchingBits[i] = '1';
	} else {
	  matchingBits[i] = '0';
	}
      }

    }

    // if Xor is selected
    //
    if(strcmp(op, "Xor") == 0){
      
      // 0 if both are 0, 1 if only of them is 1
      //
      for (size_t i = 0; i < sizeof(reversedMask); i++){
	 if (binaryText[i] != binaryMask[i]) {
                matchingBits[i] = '1';
            } else {
                matchingBits[i] = '0';
            }
      }
    }

    // give terminator to string
    //
    matchingBits[sizeof(matchingBits)] = '\0';  
    reverseString(matchingBits);
}

// main program
//

int main(int argc, char** argv){

  // check if there are enough arguments
  //
  if (argc == 3){

    // open first file
    //
    FILE* file1 = fopen(argv[1], "r");
  
    size_t maskSize = strlen(argv[2]);
    
    char mask[maskSize+1];
    strcpy(mask, argv[2]);
    
    char line[33];  
    
    char* binaryMask = hexStringToBinary(mask);
    formatFourBit(binaryMask, strlen(binaryMask));
    
    fprintf(stdout, "Mask: %s\n", binaryMask);

    // loop through every line in file
    //
    while (fgets(line, sizeof(line), file1)!=NULL){

      // get binary of each line
      //
      unsigned int binary = charToBinary(line[0]);
      char binaryText[34];
      binaryText[34] = '\0';
      int numChars = sprintf(binaryText, "%u", binary);

      // format binary
      //
      formatFourBit(binaryText, numChars);
    
      fprintf(stdout, "bits: %s\n", binaryText);
      
      char matchingBits[sizeof(binaryText)];

      // and operations
      //
      char op[] = "And";
      compareBits(binaryText, binaryMask, op, matchingBits);
      reverseString(matchingBits);
      int numMaskChar = strlen(matchingBits);
      formatFourBit(matchingBits, numMaskChar);
      fprintf(stdout, "%s\n", matchingBits);

      // or operations
      //
      char op2[] = "Or";
      compareBits(binaryText, binaryMask, op2, matchingBits);
      reverseString(matchingBits);
      numMaskChar = strlen(matchingBits);
      formatFourBit(matchingBits, numMaskChar);
      fprintf(stdout, "%s\n", matchingBits);  

      // xor operations
      //
      char op3[] = "Xor";
      compareBits(binaryText, binaryMask, op3, matchingBits);
      reverseString(matchingBits);
      numMaskChar = strlen(matchingBits);
      formatFourBit(matchingBits, numMaskChar);
      fprintf(stdout, "%s\n", matchingBits);  
    }

    // close the file and delete all allocated memory
    //
    fclose(file1);
    delete[] binaryMask;
    return 0;
  }
  else{

    // tell user there arent the right number of inputs
    //
    fprintf(stdout, "Error: incorrect number of inputs\n");
    fprintf(stdout, "%Usage: p02.exe <file> <mask>");
  }
}
