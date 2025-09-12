#!/usr/bin/env python

# file: homework/hw_02/ortiz_damien/p01/p01.py

#--------------------------------------------------------------------------

#Program will generate a 5x5 matrix that will result in the answer 1.0,
# then it will create a second matrix with the value of 10.0. It will then
# perform basic operations between the matrices and print the output.

#--------------------------------------------------------------------------

#Imports

#--------------------------------------------------------------------------

#Import numpy to get numerical functions such as matrix operations
import numpy as np


#Import sys in order to get system specific parameters
import sys

#--------------------------------------------------------------------------

#Function Code

#--------------------------------------------------------------------------

#Creates main function
def main(argv):

        #Initializes two matrices to be 5x5 with the value of 1 and 5x5
        # with a value of 10
        matrix1 = np.ones((5,5))
        matrix2 = np.full((5,5),10)

        #Performs basic math operations between matrices such as addition,
        # subtraction, multiplication, and division
        mult = matrix1 @ matrix2
        add = matrix1 + matrix2
        subtract = matrix1 - matrix2
        div = matrix1 / matrix2

        #Statements will print out the result of the previous math
        # operations
        print("Multiplication:", mult)
        print("Addition: ", add)
        print("Subtraction:", subtract)
        print("Division: ", div)

        #exit gracefully
        return True
# begin gracefully

if __name__ == '__main__':
    main(sys.argv[0:])

#End of file
