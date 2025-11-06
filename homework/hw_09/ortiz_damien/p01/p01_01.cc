// bubble sorting algorithm
//
void mysort(char** lines, int numLines, char* op){
  
  // loop if we have ascending order
  //
  if (!strcmp(op, "-a") || !strcmp(op, "-u")){

    // swap smallest row to front
    //
    for(int i = 0; i < numLines-1; i++){
      
      for (int j = 0; j < numLines - i - 1; j++) {
	
	if (strcmp(lines[j], lines[j+1]) > 0){
	  
	  char* temp = lines[j];
	  lines[j] = lines[j + 1];
	  lines[j + 1] = temp;
	}
      }
    }

    // check if user asked for unique sorting
    //
    if (!strcmp(op, "-u")) {
    int uniqueCount = 0;

    for (int i = 0; i < numLines; i++) {
        // skip over any duplicates
        int j = i + 1;
        while (j < numLines && strcmp(lines[i], lines[j]) == 0) {
            free(lines[j]); // free duplicate memory
            j++;
        }

        // keep only one copy
        lines[uniqueCount++] = lines[i];

        // move to the next *new* value
        i = j - 1;
    }

    // mark the rest of the array as NULL
    for (int i = uniqueCount; i < numLines; i++) {
        lines[i] = NULL;
    }

}

    
  }

  // loop if we have descending order
  //
  else if (!strcmp(op, "-d")){

    // swap smallest row to front
    //
    for(int i = 0; i < numLines-1; i++){

      for (int j = 0; j < numLines - i - 1; j++) {

	if (strcmp(lines[j], lines[j+1]) < 0){	  
	  char* temp = lines[j];
	  lines[j] = lines[j + 1];
	  lines[j + 1] = temp;
	}
      }
    }
  } else{
    fprintf(stderr, "Invalid sorting option.\n");

  } 
}

// end of file
