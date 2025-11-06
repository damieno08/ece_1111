// file: /data/courses/ece_1111/2025_01_fall/homework/hw_08/ortiz_damien/p01/p01.cc/
//

// Version History: 
// 20251015 create initial file
// 20251019 create mass comments

// include files 
//
#include "p01.h"

// Program will take in two matrix files and compute their product, sum,
// difference, or determinant 
//

// main program
//
int main(int argc, char** argv){

  // check how many arguments there are
  //
  if (argc <= 5 && argc >= 4){

    // check if an operator was selected
    //
    if (!strcmp(argv[1], "-o") || !strcmp(argv[1], "--operation")){

      char* operation= argv[2];

      // compute entered operation or tell user if operator is invalid
      //
      computeOperation(argv, operation, argc);
      
      // exit gracefully
      //
      return 0;
    }

    // code for having help and usage
    //
  } else if(argc == 2){

    char buffer[MAXIMUM_LINE_LENGTH+1];

    // reads the helper file
    //
    if (!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help")){
      
      FILE* helpFile =  fopen("helpFile.txt", "r");
      while(fgets(buffer, sizeof(buffer), helpFile)){

	fprintf(stdout, "%s", buffer);

      }
      fclose(helpFile);
      return 0;
      
    }

    //reads the usage file
    //
    if (!strcmp(argv[1], "-u") || !strcmp(argv[1], "--usage")){
      
      FILE* usageFile =  fopen("usageFile.txt", "r");
      while(fgets(buffer, sizeof(buffer), usageFile)){
	
	fprintf(stdout, "%s", buffer);
	
      }
      fclose(usageFile);
      return 0;
      
    }
  }


  // tell the user they incorrectly used program
  //
  fprintf(stderr, "Incorrect use.\n");
  fprintf(stdout, "Please call the following command for the usage file:\n");
  fprintf(stdout, "p01.exe -u\n");

  // exit with errors
  //
  return 1;
  
}

// end of file
