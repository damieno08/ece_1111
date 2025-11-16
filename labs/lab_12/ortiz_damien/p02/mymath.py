#!/usr/bin/env python

# file: /data/courses/ece_1111/2025_01_fall/labs/lab_12/ortiz_damien/p02/mymath/mymath.py
#

# Version History: 
# 20251111 create initial file

# Imports:
#
import mat_00
import sys
import os
import numpy as np

# main program
#
def main(argv):

        # create set of possible operations
        #
        s = set(["addition", "subtraction", "multiplication"])

        # check number of arguments is correct
        #
        if len(argv) == 5:

                # check that we called for an operation
                #
                if "-o" in argv[1] or "-operation" in argv[1]:

                        # check that operation is valid
                        #
                        if argv[2] in s:

                                # create our two matrices
                                #
                                mat1 = mat_00.MyMatrix()
                                mat2 = mat_00.MyMatrix()

                                # try to open files and perform operations
                                # 
                                if mat1.read(argv[3]):
                                        if mat2.read(argv[4]):

                                                # print matrices if all successful
                                                #
                                                mat3 = mat_00.performOp(argv[2], mat1, mat2)
                                                print("First matrix:")
                                                mat1.display()
                                                print("Second matrix:")
                                                mat2.display()
                                                print("Result matrix:")
                                                mat3.display()

                        else:
                                # tells user when there is a problem with operation
                                #
                                print("Invalid operation")
                                print("Usage: mymath.py -o <operation> <matrix_file> <matrix_file>")                                        
                else:
                        # tells user when there is a problem with option
                        #
                        print("Invalid options")
                        print("Usage: mymath.py -o <operation> <matrix_file> <matrix_file>")
                
                # exit gracefully
                #
                return True
        else:
                # tell user when wrong number of arguments
                #
                print("Incorrect number of arguments.")
                print("Usage: mymath.py -o <operation> <matrix_file> <matrix_file>")

                # exit with errors
                #
                return False
                      
                      
# begin gracefully

if __name__ == '__main__':
	main(sys.argv[0:])
        
# end of file
