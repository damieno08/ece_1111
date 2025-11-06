// file: /data/courses/ece_1111/2025_01_fall/labs/lab_08/ortiz_damien/p01/p01.cc
//

// Version History: 
// 20251013 create initial file

// include files
//
#include "p01.h"

// Program will read a file then 
// print its line number alongside its value
// ex) 27: this is text
//

// main program
//
int main(int argc, char** argv){
    
    int x = 5;
    printf("Hello FUze");
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
        int lineNum = 0;

        // read each line until we reach the end of the file
        //
        while(fgets(line, sizeof(line), fp) != NULL){
        
            // change the line number
            //
            lineNum++;
      
            // look for newline character and terminate string there
            //
            line[strcspn(line, "\n")] = '\0';

            // allocate space for string containing line and copy it 
            // to the temporary string
            //
            int len = strlen(line);
            char* tmp_string = new char[len+1];
            strcpy(tmp_string,line);

            // print out the line number and line value
            //
            fprintf(stdout, "%d: %s\n", lineNum,line);
            
            // delete allocated space 
            //
            delete[] tmp_string;
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
