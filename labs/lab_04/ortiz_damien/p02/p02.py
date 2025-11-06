#!/usr/bin/env python

# File: /data/courses/ece_1111/current/labs/lab_04/ortiz_damien/p02/p02.py

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

# main function
def main(argv):

        # Set the error count to zero

        error = 0

        # Sets size mismatch errors to false on startup

        sizeMisMatch = False
        
        # Creates list of command line arguments excluding the program
        
        argList = argv[1:]

        # Creates blank answer matrix to be filled
        
        matrix = []
        vector = []

        # Checks if there are too many

        if len(argList) >2:
                print("Too many input arguments")
                print("Usage: p02.py <matrix_file> <vector_file>")
                
                sys.exit()
        
        # Checks if there are too little inputs

        if len(argList) <2:
                print("Not enough input arguments")
                sys.exit()
        
        
        # Checks if the matrix file exists
        
        try:                       
                
                # Opens the file containing the first matrix
        
                with open(argList[0], "r") as file:

                        # Goes through every line in the file
                        # checking index and its value
                        
                        for line in file:

                                # Removes excess whitespace from
                                # each line

                                line = line.strip()

                                # Logic checks if the elements are
                                # separated by commas or spaces
                                # then split them into lists
                                
                                if "," in line:
                        
                                        line = line.split(",")
                                else:
                                        line = line.split()
                                                
                                # Loop converts every
                                # element into float
                                        
                                for i in range(len(line)):

                                        # Check if only numbers
                                        # are used

                                        line[i] = float(line[i])
                                                
                                        # Adds the float to our matrix 
                                        
                                matrix.append(line)
                                        
        # Error case for file not existing
                                
        except FileNotFoundError:                

                # Writes error message stating that a file does not exist
                
                print("The file '%s' does not exist" % argList[0])

                sys.exit()
                
        # Error case where non-numerical files are used

        except ValueError:

                # Tells user they used wrong values and exits
                
                print("Non-numerical value used")

                
                sys.exit()
                
        # Checks if the file exists
                
        try:

                # Opens vector file
                        
                with open(argList[1], "r") as file2:

                        # Reads every line within vector file
                                
                        lines = file2.readlines()

                        # Checks that we have a vector not matrix
                                
                        if len(lines) ==1:
                                line = lines[0]
                                line = line.strip()

                                # Formats the text for use
                                        
                                if "," in line:
                                        
                                        line = line.split(",")
                                else:
                                        line = line.split()
                                        for i in range(len(line)):
                                                line[i] = float(line[i])
                                # Create vector using numpy
                                        
                                vector = numpy.array(line)
                        else:
                                # Tells user they input wrong file type
                                
                                print("Second entry is not a"
                                              " vector")

                                # Exits the program
                                
                                sys.exit()
                                
        # Error case for file does not exist
                                
        except FileNotFoundError:

                # Gives the user an error message if file does not exist
                
                print("The file '%s' does not exist" % argList[1])

                # Exits after error

                sys.exit()

        # Error case where non-numerical files are used

        except ValueError:

                # Tells user they used the wrong type of value
                
                print("Non-numerical value used")

                # Exits program after failure
                
                sys.exit()


        # Checks if the matrix and vector have compatible sizes
                
        for i in range(len(matrix)):                        
                        
                if len(matrix[i]) != len(vector):
                        sizeMisMatch = True

        # If there is a size mismatch the user is told
                                
        if sizeMisMatch :
                print("Error: incompatible size")
                sys.exit()

        # If there are compatible sizes computes and prints answer
                
        else:
                # Does dot product of matrix and vector
                        
                answer = numpy.dot(matrix,vector)

                # Prints formatted input matrix
                        
                print("Input matrix: ")
                for row in matrix:
                        print(row)

                # Prints input vector
                                
                print("Input vector:")
                print(vector)
                print("Result:")
        
                # Print the result of dot product
                        
                print(answer)

        # exit gracefully
        
        return True

# begin gracefully

if __name__ == '__main__':
    main(sys.argv[0:])

        
#End of file
