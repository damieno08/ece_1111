// bubble sorting algorithm
//
void mysort(char** lines, int numLines, char* op){
  
  // loop if we have ascending order
  //
  if (!strcmp(op, "-a")){

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
