// file: /data/courses/ece_1111/2025_01_fall/homework/hw_06/ortiz_damien/p01/p01/p01.cc
//
// Version History: 
// 20251005 create initial file

// Program will show the limitations of data representations for each
// data type
//

// include files
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// main file
//
int main(int argc, char** argv){

  // create unsigned char increasing integer value from 0 to 99999
  // printing the char and long representation
  //
  unsigned char c = 0;

  for (long i = 0; i < 99999; i++) {
    fprintf(stdout, "c = %c (%ld)\n", c, (long)c);
    c++;
  }

  // create unsigned short integer increasing value from 0 to 99999
  // printing the char and long representation
  //
  unsigned short int integer = 0;

  for (long i = 0; i < 99999; i++) {
    fprintf(stdout, "int = %c (%ld)\n", integer, (long)integer);
    integer++;
  }

  // create unsigned integer increasing value from 0 to 99999
  // printing the char and long representation
  //
  unsigned int unsignedInteger = 0;

  for (long i = 0; i < 99999; i++) {
    fprintf(stdout, "unsigned int = %c (%ld)\n", unsignedInteger, (long)unsignedInteger);
    unsignedInteger++;
  }

  // create unsigned long increasing value from 0 to 99999
  // printing the char and long representation
  //
  unsigned long longInteger = 0;

  for (long i = 0; i < 99999; i++) {
    fprintf(stdout, "long = %c (%ld)\n", (char)longInteger, (long)longInteger);
    longInteger++;
  }

  // create signed char increasing value from -99999 to 99999
  // printing the char and long representation
  //
  signed char signedChar = -99999;
  for (long i = -99999; i < 99999; i++){
    fprintf(stdout, "signed Char = %c (%ld)\n", signedChar, (long)signedChar);
    signedChar++;
  }

  // create unsigned short int increasing value from -99999 to 99999
  // printing the char and long representation
  //
  unsigned short int unsignedShortInt = -99999;
  for (long i = -99999; i < 99999; i++){
    fprintf(stdout, "unsigned short int = %c (%ld)\n", unsignedShortInt, (long)unsignedShortInt);
    unsignedShortInt++;
  }

  // create signed short int increasing value from -99999 to 99999
  // printing the char and long representation
  //
  signed short int signedShortInt = -99999;
  for (long i = -99999; i < 99999; i++){
    fprintf(stdout, "signed short int = %c (%ld)\n", signedShortInt, (long)signedShortInt);
    signedShortInt++;
  }
  

  // create int increasing value from -99999 to 99999
  // printing the char and long representation
  //
  int negativeToPos = -99999;
  for (long i = -99999; i < 99999; i++){
    fprintf(stdout, "int = %c (%ld)\n",  negativeToPos, (long)negativeToPos);
     negativeToPos++;
  }

  // create long increasing value from -99999 to 99999
  // printing the char and long representation
  //
  long negativeToPosLong = -99999;
  for (long i = -99999; i < 99999; i++){
    fprintf(stdout, "long = %c (%ld)\n",  negativeToPosLong, (long)negativeToPosLong);
     negativeToPosLong++;
  }

  // exit gracefully
  //
  return 0;
}
