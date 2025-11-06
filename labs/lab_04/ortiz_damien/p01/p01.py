#!/usr/bin/env python

# File: /data/courses/ece_1111/current/labs/lab_04/ortiz_damien/p01/p01.py

# Version History:
#
# 20250916 Created error checking 
# 20250916 Added vector multiplication for two vectors
# 20250915 Initial program created    

#--------------------------------------------------------------------------

# Program will multiply vector inputs and add constant within the
# command line

#--------------------------------------------------------------------------

# Imports

#--------------------------------------------------------------------------

import sys
import os
import numpy as np

#--------------------------------------------------------------------------

# Function Code

#--------------------------------------------------------------------------

# Float checker
#

# Checks if the input variable is a float

def is_float(s):

    # Will return True if the variable is a float and does not cause errors
    
    try:

        # Does parse float in order to see if error occurs
        
        float(s)

        # Returns true if the variable is a float
        
        return True

    # Code for when error is present
    
    except ValueError:

        # Returns false if the variable is not a float
        
        return False

# File to vector function
#

def vectorAddition(filePath, constant):

    # Create empty variable for later use

    numList = []
    z = 0
    index = 0
    breakNow = False

    # Set up error checking for when the file does not exist
    
    try:
        
        # Open the file and read it
        
        with open(filePath, "r") as file:

            # Loop through every line within the file and keep its index

            for idx, line in enumerate(file):

                # Create index variable that will count the number of lines
                
                    index = idx

                    # Remove unnecessary white space from strings
                    
                    line = line.strip()

                    if "," in line:
                        
                        # Split each vector into lists by their commas
                    
                        numbers = line.split(",")

                    else:

                        # Split each vector by space between them
                        
                        line.split()

                    #Loop through each element turning it into a float
                    
                    for i in range(len(numbers)):
                            if is_float(numbers[i]):
                                    numbers[i] = float(numbers[i])
                            else:

                                # Error statement when there is
                                # a non-numerical element
                                
                                print("Errors with non-numerical answers")
                                breakNow == True

                                # Breaks the loop if there is an error
                                
                                break
                            
                    # Stops program when error for non-numerical occurs
                            
                    if breakNow == True:
                        break

                    # Creates numpy array of all vectors
                    
                    numList.append(np.array(numbers,dtype = float))

            # Checks for when there are not enough vectors
                    
            if len(numList) > 1:

                # Checks for when vectors are not the same size
                
                if len(numList[0]) != len(numList[1]):
                    print("Vectors are not the same"
                          " size")
                else:

                    # Computes the dot product of the vectors
                    
                    z = np.sum(np.prod(numList, axis=0)) + constant

                    # Checks if there are too many vectors in the file
                    
                    if index >= 2:

                        # Error statement for too many vectors
                        
                        print("Too many vectors")
                        print("Usage: p01.py <vector_file>")

                    # Checks for an appropriate amount of vectors
                        
                    elif index == 1:

                        # Prints formatted output
                        
                        print("x = %s" % numList[0])
                        print("y = %s" % numList[1])
                        print("z = %.4f" % z)

                    # Checks for when there are not enough vectors
                        
                    else:

                        # Error statement for not enough vectors
                        
                        print("Not enough vectors within file")
                        print("Usage: p01.py <vector_file>")
    # Error catching for when the file does not exist
    
    except FileNotFoundError:

        # Error statement for file that doesn't exist
        
            print("%s does not exist" % filePath)

    # Error case where non-numerical files are used
    
    except ValueError:

        # Warning and exit when non-numerical values are used
        
        print("Non numerical values were used")
        sys.exit()

    # Exit the function
            
    return True


# main function

def main(argv):       
    try:

        
        # Removes program name from argument list
        
        argv = argv[1:]
        
        # Checks if there are enough many arguments on command line

        if len(argv) == 2:

            # Turn first argument into file name
    
            fileName = argv[0]
        
            # Tries to turn second argument into float
        
            try:
                constant = float(argv[1])
            
                # Computes dot product plus a constant if the second
                # argument is a float
        
                x = vectorAddition(fileName, constant)

                # Error for when second argument is not a float
        
            except ValueError :

                # Error statement for second argument is not a float
        
                print("Error second command should be constant")
                print("Usage: p01.py <vector_file> <constant>")

                # Code for when there aren't enough arguments
            
        elif len(argv) < 2:

            # Error statement for not enough inputs

            print("Not enough arguments")
            
            # Code for when there are too many arguments
            
        else:

            # Error statement for too many arguments

            print("Too many input arguments")

    except FileNotFoundError:
        print("Entered a file that does not exist")
    # exit gracefully
        
    return True

# begin gracefully

if __name__ == '__main__':
    main(sys.argv[0:])
        
# End of file
