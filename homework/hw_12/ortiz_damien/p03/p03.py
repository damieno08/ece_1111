#!/usr/bin/env python

# file: /data/courses/ece_1111/2025_01_fall/homework/hw_12/ortiz_damien/p03/p03/p03.py
#

# Version History: 
# 20251114 create initial file

# Imports:
#
import sys
import os
import p03_00

# main program
#
def main(argv):

        # check for correct number of args
        #
        if len(argv)==2:
                # create instance of class
                #
                wc = p03_00.WordCounter(argv[1])
                
                # compute the word frequencies
                #
                wc.compute_word_frequencies()
                
                # print our result
                #
                wc.print_frequencies(ascending=True)
        
                # exit gracefully
                #
                return True
        else:
                # give user error messages for incorrect number of arguments
                #
                print("Incorrect number of arguments.")
                print("Usage: p03.py <file>")

                # exit with errors
                #
                return False
                
# begin gracefully
#
if __name__ == '__main__':
	main(sys.argv[0:])
        
# end of file
