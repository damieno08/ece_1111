// convert list into heap order
//
void heapify(char** strings , int n, int i){
  
    // initialize largest as root
    //
    int largest = i;

    // left index = 2*i + 1
    //
    int l = 2 * i + 1;

    // right index = 2*i + 2
    //
    int r = 2 * i + 2;

    // if left child is larger than root
    //
    if (l < n && strcmp(strings[l], strings[largest]) > 0)
        largest = l;

    // if right child is larger than largest so far
    //
    if (r < n && strcmp(strings[r], strings[largest]) > 0)
        largest = r;

    // if largest is not root
    //
    if (largest != i) {
        char* temp = strings[i];
        strings[i] = strings[largest];
        strings[largest] = temp;

        // recursively heapify the affected sub-tree
	//
        heapify(strings, n, largest);
    }
}

// sorting list using heap
//
void mysort(char** lines, int numLines,char* op){
  for (int i = numLines/2-1; i >= 0; i--){
    
    heapify(lines, numLines, i);
  }
  
  // one by one extract an element from heap
  //
  for (int i = numLines - 1; i > 0; i--) {
    
    // move current root to end
    //
    char* temp = lines[0];
    lines[0] = lines[i];
    lines[i] = temp;
    
    // call max heapify on the reduced heap
    //
    heapify(lines, i, 0);
  }
  
    
  // if descending just reverse the array
  //
  if (!strcmp(op, "-d")){
    for (int i = 0; i < numLines / 2; i++) {
      char* temp = lines[i];
      lines[i] = lines[numLines - 1 - i];
      lines[numLines - 1 - i] = temp;
    }
  }
}

// end of file
