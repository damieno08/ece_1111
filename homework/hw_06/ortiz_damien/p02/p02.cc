// file: /data/courses/ece_1111/2025_01_fall/homework/hw_06/ortiz_damien/p02/p02/p02.cc
//
// Version History: 
// 20251005 create initial file

// Program will demonstrate computational accuracey using floats and doubles

// include files 
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char** argv){

  // create float version of pi
  //
  float my_pi = M_PI;

  // add pi squared a preset amount of times then divide it by the number of times we looped
  //
  float sum = 0;
  int loopCount =  99999;
  
  for (int i ; i < loopCount; i++){

    sum += M_PI*M_PI;
    
  }
  
  float ans1 = sum/loopCount;

  // calculate and prin the percentage difference between the calculated and theoretical values  
  //
  float percentageDiff1 = abs((ans1 - M_PI*M_PI)/(M_PI*M_PI)*100);
  
  fprintf(stdout, "The percentage difference is %15.10f\n", percentageDiff1);

  // add pi squared a preset amount of times then divide it by the number of times we looped
  //
  double sum2 = 0;
  
  for (int i ; i < loopCount; i++){

    sum2 += M_PI*M_PI;
    
  }
  
  double ans2 = sum2/loopCount;

  // calculate and prin the percentage difference between the calculated and theoretical values  
  //
  float percentageDiff2 = abs((ans2 - M_PI*M_PI)/(M_PI*M_PI)*100);
  
  fprintf(stdout, "The percentage difference is %15.10f\n", percentageDiff2);

  // exit gracefully
  //
  return 0;
}
