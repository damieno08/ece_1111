#include "p01.h"


// create an array of all lines
//
char** lineToWords(char* file, int* num){

  FILE* fp = fopen(file, "r");
  if(!fp){
    fprintf(stdout, "The file '%s' does not exist", file);
    return 0;
  }

  char buffer[MAX_LINE_LENGTH+1];
  
  fgets(buffer, sizeof(buffer), fp);
  for(int i = 0; i < strlen(buffer); i++){

    buffer[i] = tolower(buffer[i]);

  }

  int capacity = 10;

  int ref_count = 0;
  char** words = new char*[capacity];
  
  char* token = strtok(buffer, " \n");
  
  while (token != NULL) {
    
    if (ref_count >= capacity) {
      int new_capacity = capacity * 2;
      char** new_array = new char*[new_capacity];
      for (int i = 0; i < capacity; i++)
	new_array[i] = words[i];
      delete[] words;
      words = new_array;
      capacity = new_capacity;
    }
    
    int len = strlen(token) + 1;
    words[ref_count] = new char[len];
    strcpy(words[ref_count], token);
    ref_count++;
    
    token = strtok(NULL, " \n\t");

 }

  *num = ref_count;
  
  fclose(fp);
  return words;

}

void cleanUp(char** words, int wordCount){
  for (int i = 0; i < wordCount; i++)
    delete[] words[i];  
  delete[] words;

}
