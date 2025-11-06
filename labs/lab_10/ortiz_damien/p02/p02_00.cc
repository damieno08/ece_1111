// file: /data/courses/ece_1111/current/labs/lab_10/ortiz_damien/p02/p02_00.cc
//

// all functions will be used to manipulate buffer for file processing


// include our header
//
#include "p02.h"

// create circular buffer struct
//
struct Buffer{
  int windowSize;
  int N;
  char* searchText;
  char** window;
  int head;
  int count;
};


// initialize the buffer and window size
//
void initBuffer(Buffer& buff) {
    buff.windowSize = 2 * buff.N + 1;
    buff.head = 0;
    buff.count = 0;    

    // allocate memory to store the window
    //
    buff.window = new char*[buff.windowSize];
    for (int i = 0; i < buff.windowSize; i++) {
        buff.window[i] = new char[MAXIMUM_LINE_LENGTH];
        buff.window[i][0] = '\0';
    }
}


// delete memory for buffer window
//
void freeBuffer(Buffer& buff) {
    for (int i = 0; i < buff.windowSize; i++) {
        delete[] buff.window[i];
    }
    delete[] buff.window;
}


// write a line to the buffer and move the head
//
void writeLine(Buffer& buff, char* string){

  strcpy(buff.window[buff.head], string);
  buff.head = (buff.head+1) % buff.windowSize;

  // increase the count until we are full
  //
  if (buff.count < buff.windowSize)
    buff.count++;
}


// print buffer if match is contained
//
void printWindow(Buffer& buff){

  // find oldest index and print starting there
  //
  int oldestIndex = (buff.head - buff.count + buff.windowSize) % buff.windowSize;
  for (int i = 0; i < buff.count; i++) {
    int index = (oldestIndex + i) % buff.windowSize;
    printf("%s", buff.window[index]);
  }
  fprintf(stdout, "\n");
}


// find out if the search word is within the line
//
int containsWord(const char* line, const char* word) {
    int lineLen = strlen(line);
    int wordLen = strlen(word);
    int i, j;

    // loop through each char checking if their lowercase forms match
    //
    for (i = 0; i <= lineLen - wordLen; i++) {
        int match = 1;
        for (j = 0; j < wordLen; j++) {
            if (tolower((unsigned char)line[i + j]) != tolower((unsigned char)word[j])) {
                match = 0;
                break;
            }
        }

	// return 1 if found and 0 if not found
	//
        if (match) return 1; 
    }
    return 0;
}

// open a file and use buffer to read it
//
void readFile(FILE* fp, Buffer& buff){

  char line[MAXIMUM_LINE_LENGTH+1];

  bool foundMatch = false;

  // loop through each line of the file checking for matches
  //
  while (fgets(line, sizeof(line), fp) != NULL){
    
    writeLine(buff, line);

    int oldestIndex = (buff.head - buff.count + buff.windowSize) % buff.windowSize;
    int middleIndex = (oldestIndex + buff.count / 2) % buff.windowSize;

    // if match found print the window
    //
    if (containsWord(buff.window[middleIndex], buff.searchText)) {

      printWindow(buff);
      foundMatch = true;

    }
  }
  
  // go through one last time at end of file to make last line
  // center of buffer  
  //
  char blank[] = "";
  for(int i =0 ; i < buff.N; i++){
    writeLine(buff, blank);
  }
  int oldestIndex = (buff.head - buff.count + buff.windowSize) % buff.windowSize;
  int middleIndex = (oldestIndex + buff.count / 2) % buff.windowSize;

  if (containsWord(buff.window[middleIndex], buff.searchText)) {
    printWindow(buff);
    foundMatch = true;
  }

  // if there is no match in entire file tell user
  //
  if (!foundMatch){

    fprintf(stdout, "No matches within file.\n");
    
  }

}


