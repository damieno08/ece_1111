// file: /data/courses/ece_1111/2025_01_fall/homework/hw_11/ortiz_damien/p01/p01.cc/
//
// Version History: 
// 20251105 create initial file

// include files 
//
#include "p01.h"

// Program will ___
//

// main program
//

int main(int argc, char** argv){

  int ref_count;
  int hyp_count;
  char** ref_words = lineToWords(argv[1], &ref_count);
  char** hyp_words = lineToWords(argv[2], &hyp_count);  
    
  AlignmentResult result = compute_dp(ref_words, ref_count, hyp_words, hyp_count);
  
  print_alignment(stdout, result);

  cleanUp(ref_words, ref_count);
  cleanUp(hyp_words, hyp_count);

  delete[] result.r_line;
  delete[] result.h_line;
  
return 0;
}
