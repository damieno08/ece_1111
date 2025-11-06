#include "p02.h"

// count the number of lines in a file
//
int countLines(char* file){
    FILE* fp = fopen(file, "r");
    if (fp == NULL){
        fprintf(stdout, "The file %s does not exit.\n", file);
        return -1;
    }

    char line[MAX_LINE_LENGTH+1];
    int N = 0;
    while (fgets(line, sizeof(line), fp)){
        N++;
    }
    fclose(fp);
    return N;
}

// return an array of strings containing each line
//
char** getLineText(char* file){
    int N = countLines(file);
    FILE* fp = fopen(file, "r");
    if (fp == NULL){
        fprintf(stdout, "The file %s does not exit.\n", file);
        return nullptr;
    }
    char line[MAX_LINE_LENGTH+1];
    char** strings = (char**)malloc((N+1) * sizeof(char*));

    int lineNum = 0;
    while (fgets(line, sizeof(line), fp)){
        line[strcspn(line, "\n")] = '\0';
        int len = strlen(line);
	strings[lineNum] = (char*)malloc(sizeof(char)*(len+1));
        strcpy(strings[lineNum], line); 
        lineNum++;
    }
    strings[N] = nullptr;
    fclose(fp);
    return strings;
}

// loop through string array and print values
//
void printString(char** stringArray, FILE* file){
    
  for (int i = 0; stringArray[i] != nullptr; i++) {
      fprintf(file, "%d: %s\n", (i+1),stringArray[i]);
    }
}

// loop through and delete allocated memory for all strings
//
void cleanStringArrayMemory(char** strs){
  
  for (int i = 0; strs[i] != nullptr; i++){
      free(strs[i]);
    }
    free(strs);
}

// end of file
