#!/usr/bin/env python

# File: /data/courses/ece_1111/current/labs/lab_04/ortiz_damien/p03/p03.py

# Version History:
#
# 20250917 Add error checking
# 20250916 Create initial program

#--------------------------------------------------------------------------

# Program will multiply a matrix by a vector

#--------------------------------------------------------------------------

# Imports

#--------------------------------------------------------------------------

import sys
import os
import numpy
#--------------------------------------------------------------------------

# Function Code

#--------------------------------------------------------------------------

# Function that turns a file into a matrix
def fileToMatrix(filePath):

        # Empty answer matrix
        
        matrix = []

        # For loop will convert each line of the matrix into numpy matrix
        # of floats 
        
        for line in filePath:
                line = line.strip()
                if "," in line:
                        line = line.split(",")
                else:
                        line = line.split()
                for i in range(len(line)):
                        line[i] = float(line[i])
                matrix.append(line)

        # Returns numpy matrix of input file
                
        return numpy.array(matrix)

# main function

def main(argv):

        # Makes list of command line arguments excluding program name
        
        argList = argv[1:]

        # Create empty matrices for calculations
        
        matrix1 = []
        matrix2 = []

        # Set the error for incompatible sizes to false
        
        sizeWrong = False

        # Warns the user if there aren't enough inputs and shows proper
        # usage
        
        if len(argList) < 2:
               print("Not enough input arguments")
               print("Usage: p03.py <matrix_file> <matrix_file>")

               # Closes program after error message
               
               sys.exit()
        elif len(argList) >2:

                # Tells user there are too many arguments, shows
                # proper usage, and exits
                
                print("Too many input arguments")
                print("Usage: p03.py <matrix_file> <matrix_file>")
                sys.exit()

        # Tests if the file exists
               
        try:

                # Opens file containing first matrix
                
                with open(argList[0], "r") as file:

                        # Calls the function to make matrix usable
                        
                        matrix1 = fileToMatrix(file)

        # Error case for when file does not exist
                        
        except FileNotFoundError:
                print("File '%s' not found." % argList[0])
                sys.exit()

        # Error case for when file contains non-numerical answers
                
        except ValueError:
                print("Error: Non-numerical files have been used")
                sys.exit()

        # Tests if the file exists
                
        try:

                # Opens file containing first matrix
                
                with open(argList[1], "r") as file2:

                        # Calls function to make matrix usable
                        
                        matrix2 = fileToMatrix(file2)
                        
        # Error case for when file does not exist
                        
        except FileNotFoundError:
                print("File '%s' not found." % argList[1])
                sys.exit()

        # Error case for when file contains non-numerical answers
                
        except ValueError:
                print("Error: Non-numerical files have been used")
                sys.exit()

        # Checks if matrix dimensions are compatible
                
        if matrix1.shape[1] != matrix2.shape[0]:
                sizeWrong = True

        # Prints error then exits if matrix dimensions are incompatible
                
        if sizeWrong:
                print("Matrix dimensions do not match")
                sys.exit()

        # Code when all conditions are properly met
                
        else:
                # Computes the matrix multiplication 
                
                answer = numpy.dot(matrix1,matrix2)

                # Prints the formatted first input matrix
                
                print("First matrix: ")
                for row in matrix1:
                        print(row)

                # Prints the formatted second input matrix

                print("Second matrix:")
                for row in matrix2:
                        print(row)

                # Prints our final result
                        
                print("Result:")        
                print(answer)
                
        # exit gracefully
        
        return True

# begin gracefully

if __name__ == '__main__':
    main(sys.argv[0:])

        
#End of file
