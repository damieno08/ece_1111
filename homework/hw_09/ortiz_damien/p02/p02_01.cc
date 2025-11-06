// selection sorting algorithm
//
void mysort(char** lines, int numLines, char* op){

  // ascending order loop
  //
  if (!strcmp(op, "-a")||!strcmp(op, "-u")){

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
      // check if they want unique sorting
      //
      if (!strcmp(op, "-u")) {
	int uniqueCount = 0;
	
	for (int i = 0; i < numLines; i++) {
	  
	  // skip over any duplicates
	  //
	  int j = i + 1;
	  while (j < numLines && strcmp(lines[i], lines[j]) == 0) {
	  free(lines[j]); 
	  j++;
	  }
	  
	  // keep only one copy
	  //
	  lines[uniqueCount++] = lines[i];
	  
	  // move to the next new value
	  //
	  i = j - 1;
	}
	
	// mark the rest of the array as NULL
	for (int i = uniqueCount; i < numLines; i++) {
	  lines[i] = NULL;
	}
	
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
