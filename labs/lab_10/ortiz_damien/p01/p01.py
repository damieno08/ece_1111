#!/usr/bin/env python

# file: /data/courses/ece_1111/2025_01_fall/labs/lab_10/ortiz_damien/p01/p01.py
#

# Version History: 
# 20251028 create initial file
#

#--------------------------------------------------------------------------

# Timing comparison

#--------------------------------------------------------------------------

# C:
# real    0m0.256s
# user    0m0.227s
# sys     0m0.015s

# Python:
# real    0m0.809s
# user    0m1.407s
# sys     0m0.059s

# Grep: 
# real    0m0.025s
# user    0m0.014s
# sys     0m0.007s

#--------------------------------------------------------------------------

# Program will act like the python version of the linux grep command 

#--------------------------------------------------------------------------

# Imports

#--------------------------------------------------------------------------

import sys
import os
import numpy as np

#--------------------------------------------------------------------------

#Function Code

#--------------------------------------------------------------------------

# function will take in inputfile, text to match, and window size then
# print matching lines
#
def matchLines(inputFile, searchText, numLines):

        # check if file exists and print error if not
        #
        try :
                # open file in read mode
                #
                with open(inputFile, "r") as file:

                        # variable will check if file has a match
                        #
                        match = False
                        
                        # create window
                        #
                        windowSize = 2 * numLines + 1
                        
                        # create empty array to fill
                        #
                        lines = [""] * windowSize  # initialize window
                        
                        # loop through each line in file
                        #
                        for i, line in enumerate(file):
                                
                                # shift window left
                                #
                                for j in range(windowSize - 1):
                                        lines[j] = lines[j + 1]
                                
                                # add new line at end
                                #
                                lines[-1] = line
                                
                                # check for match in middle of window
                                #
                                if searchText in lines[int(len(lines)/2)]:
                                        match = True
                                        print("".join(lines))
                                        
                        # shift window left
                        #
                        for j in range(windowSize - numLines):
                                lines[j] = lines[j + numLines]
                                
                        # add new line at end
                        #
                        lines[-1] = ""
                        
                        # check for match in middle of window
                        #
                        if searchText in lines[int(len(lines)/2)]:
                                match = True
                                print("".join(lines))
                                
                # tell user match doesnt exist
                #
                if not match:
                        print("File does not have any matches")
                        
        # when the file doesn't exist tell user and exit
        #
        except FileNotFoundError:
                
                print("File '%s' does not exist" % inputFile)
                return
                                                                
# main program
#
def main(argv):

        # check number of arguments
        #
        if len(argv) >= 4:

                # make new argument list without program name
                #
                argvList = argv[1:]

                # check if arguments contains -w
                #
                try:

                        searchIndex = argvList.index("-w")+1;
                        
                        # find word after -w is within argument list
                        #                        
                        searchText = argvList[searchIndex].upper()
                        argvList.remove(argvList[searchIndex])
                        argvList.remove("-w")
                        
                # exit if not
                #
                except ValueError:
                        print("Proper search was not present in command")
                        return False

                numLineText = "1"

                # check if arguments contains -n
                #
                try:
                        # find number of lines to print after match
                        #
                        numLineText = argvList[argvList.index("-n")+1]
                        numLines = int(numLineText)
                        argvList.remove(numLineText)
                        argvList.remove("-n")

                        if numLines < 1:
                                print("Error: N must be positive integer")
                                return False

                # n is 1 if there is no -n argument
                #
                except ValueError:
                        if not numLineText.isdigit() :
                                print("Error: N must be positive integer")
                                return False

                        numLines = 1

                # loop through each listed file searching for match
                #
                for i in range(len(argvList)):
                        matchLines(argvList[i], searchText, numLines)
                        
	        # exit gracefully
                #
                return True

                        
        # show error message
        #
        else:
                print("Usage: p01 <file> <pattern>")

                # exit with errors
                #
                return False
                 


# begin gracefully
#
if __name__ == '__main__':
	main(sys.argv[0:])
        
# end of file
