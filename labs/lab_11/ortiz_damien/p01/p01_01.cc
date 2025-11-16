// count the number of lines in a file when you want one integer per line
//
int countLines(char* file){

  // open and check if file exists
  //
  FILE* fp = fopen(file, "r");
  if (fp == NULL){
    fprintf(stdout, "The file %s does not exit.\n", file);
    return 0;
  }

  // count number of lines that contain one long integer
  //
  char line[MAX_LINE_LENGTH+1];
  int N = 0;

  // loop through each line checking that only one long integer
  // is found
  //
  while (fgets(line, sizeof(line), fp)){
    int numInLine = 0;
    long num;
    char* ptr = line;
    int offset;

    while (sscanf(ptr, "%ld%n", &num, &offset) == 1) {
      numInLine++;
      ptr += offset; 
    }
    if(numInLine == 1){
      N++;
    }
    else{

      // failure case for more than one number or letter in line
      //
      fprintf(stderr, "Error with file formatting.\n");
      fprintf(stderr, "Each line in test file must be one integer. Ex:\n1\n2\n3\n");

      // close file and return error
      //
      fclose(fp);
      return 0;
      
    }
  }

  // close file and return value
  //
  fclose(fp);
  return N;
}

// will create an array of integers from file
//
signed long* getIntegers(char* file, int lineCount){
  

  // open file and check if it exists
  //
  FILE* fp = fopen(file, "r");
  
  if (fp == NULL){
    fprintf(stdout, "The file %s does not exit.\n", file);
    return nullptr;
  }
  
  // allocate space for the array
  //
  signed long* Integers = new signed long[lineCount];
  
  char line[MAX_LINE_LENGTH+1];

  // put values of integer into array
  //
  int N = 0;
  while (fgets(line, sizeof(line), fp)){
    signed long num;
    if(sscanf(line, "%ld", &num) == 1){
      Integers[N] = num;
    }

    N++;
  }

  // close file and return array
  //
  fclose(fp);
  return Integers;
  
}

