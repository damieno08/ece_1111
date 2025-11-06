// selection sorting algorithm
//
void mysort(char** lines, int numLines, char* op){

  // ascending order loop
  //
  if (!strcmp(op, "-a")){

    for (int i = 0; i < numLines-1; i++){

      int min_idx = i;
      
      for (int j = i+1; j< numLines; j++){

	if (strcmp(lines[j], lines[min_idx]) < 0) {

	  min_idx = j;

	}

      }                

      char* temp = lines[i];
      lines[i] = lines[min_idx];
      lines[min_idx] = temp;
    }
  }

  // descending order loop
  //
  else if (!strcmp(op, "-d")){
   for (int i = 0; i < numLines-1; i++){

      int max_idx = i;
      
      for (int j = i+1; j< numLines; j++){

	if (strcmp(lines[j], lines[max_idx]) > 0){

	  max_idx = j;

	}

      }

      
      
    

    char* temp = lines[i];
    lines[i] = lines[max_idx];
    lines[max_idx] = temp;
   }
  }

  // error with operator statement
  //
  else{

    fprintf(stderr, "Invalid sorting operation.\n");
    
  }
}

// end of file
