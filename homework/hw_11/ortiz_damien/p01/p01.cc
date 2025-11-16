// file: /data/courses/ece_1111/2025_01_fall/homework/hw_11/ortiz_damien/p01/p01.cc/
//
// Version History: 
// 20251105 create initial file

// include files 
//
#include "p01.h"

// Program will align strings and calculate errors between them
//

// main program
//
int main(int argc, char** argv) {

  // check if there are enough arguments and exit if not
  //
  if (argc < 3) {
    printf("Usage: %s ref.txt hyp.txt\n", argv[0]);
    return 1;
  }
  
  // read lines from files
  //
  FILE* f_ref = fopen(argv[1], "r");
  FILE* f_hyp = fopen(argv[2], "r");
  if (!f_ref || !f_hyp) {
    printf("Error opening files\n");
    return 1;
  }
  char ref_line[MAX_LINE_LENGTH], hyp_line[MAX_LINE_LENGTH];
  fgets(ref_line, 1024, f_ref);
  fgets(hyp_line, 1024, f_hyp);
  fclose(f_ref);
  fclose(f_hyp);

  // check where lines match/missalign
  //
  int ref_count, hyp_count;
  char** ref_words = lineToWords(ref_line, &ref_count);
  char** hyp_words = lineToWords(hyp_line, &hyp_count);
  
  compute_dp(ref_words, ref_count, hyp_words, hyp_count);
  
  // clean up original word arrays
  //
  cleanUp(ref_words, ref_count);
  cleanUp(hyp_words, hyp_count);
  
  return 0;
}
