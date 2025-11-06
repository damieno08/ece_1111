// file: /data/courses/ece_1111/2025_01_fall/labs/lab_11/ortiz_damien/p03/p03.h

// define header if not already defined
//
#ifndef _p03
#define _p03

// include files
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <ctype.h>

// macro that will compare A and B using comparison logic
//
#define COMPARE(A, B) ( \
    ((A)%2==0 && (B)%2==0) ? ( ((A)<(B)) ? -1 : ((A)>(B)) ? 1 : 0 ) : \
    ((A)%2!=0 && (B)%2!=0) ? ( ((A)<(B)) ? 1  : ((A)>(B)) ? -1 : 0 ) : \
    ( (labs(A) < labs(B)) ? -1 : (labs(A) > labs(B)) ? 1 : 0 ) \
)


#endif

// end of file
