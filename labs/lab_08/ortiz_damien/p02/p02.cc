// file: /data/courses/ece_1111/2025_01_fall/labs/lab_08/ortiz_damien/p02/p02.cc
//

// Version History: 
// 20251013 create initial file

// include files
//
#include "p02.h"

// Program will read a file then 
// print its line number alongside its value
// ex) 27: this is text
//

// main program
//
int main(int argc, char** argv){
    
    // check if there are correct number of arguments
    //
    if ( argc == 2){
    
        // open file and check if it exists
        //
        FILE* fp = fopen(argv[1], "r");
        
        // tell user the file doesn't exist
        //
        if(fp == (FILE*)NULL){
            fprintf(stderr, "File %s does not exist.\n", argv[1]);
            return 1;
        }

        // allocate space for line and line number
        //
        char line[MAX_LINE_LENGTH+1];
        int N = 0;

        // find number of lines
        //
        while(fgets(line, sizeof(line), fp) != NULL){
        
            N++;
      
        }

        // create array of strings size of lines in file
        //
        char* strs[N];

        // rewind pointer to start of file
        //
        rewind(fp);

        // count which line we are on for indexing
        //
        int lineNum = 0;

        // read the value of each line
        //
        while(fgets(line, sizeof(line), fp) != NULL){

            // increment line number
            //
            lineNum++;

            // remove excess space after newline character
            //
            line[strcspn(line, "\n")] = '\0';

            // creates a string the size of the line inside array of strings
            //
            int len = strlen(line);
            strs[lineNum] = new char[len+1];

            // puts value into the new allocated string
            //
            strcpy(strs[lineNum], line);
            
        }

        // loops through each index of string list putting value and line number
        // 
        for (int i = 1; i <= N; i++){
            fprintf(stdout, "%d: %s\n", i, strs[i]);

            // delete allocated memory after use
            //
            delete[] strs[i];
        }

        // close file and exit program
        //
        fclose(fp);
        return 0;
}
    // error statement with wrong number of arguments
    //
    fprintf(stderr, "Error: incorrect number of arguments\n");
    fprintf(stdout, "Usage: p01.exe <file_to_read>");
    return 1;
}
