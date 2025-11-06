#!/usr/bin/env python

# File: /data/courses/ece_1111/current/labs/lab_04/ortiz_damien/p04/p04.py

# Version History:
#
# 20250917 Added error checking
# 20250917 Initial file created

#--------------------------------------------------------------------------

# Program will filter any binary file with filter from command line

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

        # Creates a list of all command line arguments
        
        arguments = argv[1:]
        
        # Check if there are enough arguments

        if len(arguments) > 2:
                
                # Alerts the user of improper input quantity before
                # showing the usage of the file
                
                print("Too many input arguments.")
                print("Usage: p04.py <binary_file> <filter>")

                # Exit after errors
                
                sys.exit()
        if len(arguments) < 2:

                # Alerts the user of improper input quantity before
                # showing the usage of the file
                
                print("Not enough input arguments.")
                print("Usage: p04.py <binary_file> <filter>")

                # Exit after errors
                
                sys.exit()

        # Code for when there are the right number of inputs
                
        else:
                # Create empty variables for later use
        
                vectorInput = arguments[1]
                vectorLength = 0
                filteredSignal = []

        # Check if file exists or returns an error for input type

        try:

                # Opens the vector file then converts it into numpy array
                
                with open(vectorInput, "r") as file1:

                        # Reads content of vector file
                        
                        spaceFilledLine = file1.read()

                        # Gets rid of extra white space
                        
                        spaceLessLine = spaceFilledLine.strip()

                        # Checks if the vector is separated by commas or
                        # spaces then creates a list of elements
                        
                        if "," in spaceLessLine:
                                vector = spaceLessLine.split(",")
                        else:
                                vector = spaceLessLine.split("")

                        # Converts each element into a float
                                
                        for i in range(len(vector)):
                                vector[i] = float(vector[i])

                        # Creates array of vector values
                                
                        vector = numpy.array(vector)

                        # Gets the length of the vector to section of the
                        # signal
                        
                        vectorLength = len(vector)

        # Error case when the file is not found
                        
        except FileNotFoundError:

                # Warns user that the file was not found
                
                print("File '%s' not found" % file1)

                # Exit program after error
                
                sys.exit()

        # Error case for when there are type errors
                
        except ValueError:

                # Warns user of non integer data values
                
                print("Non-numerical values use")

                # Exits program after failure
                
                sys.exit()

        # Checks if file exists and for type errors
                
        try:
                # Opens the file to read its content
                
                with open(arguments[0], "rb") as file2:

                        # Creates a list of all bytes within file
                        
                        integers = file2.read()

                        # Empty matrix that will hold every 16-bit integer
                        
                        num = []

                        # Loop converts every 2 bytes into 16-bit integer
                        # then adds the result to the num list
                        
                        for j in range(0, len(integers), 2):
                                if j+1 < len(integers):
                                        num.append(integers[j+1]*256 + integers[j])
                        
                        # Creates a name for an output file based on the
                        # current file name
                                        
                        outputFileName = (arguments[0] + "_filtered")
                        for i in range(0, len(num), vectorLength):
                                section = numpy.array(num[i:i+vectorLength])
                                if len(section) == vectorLength:
                                        filteredSignal = int(numpy.dot(section,vector))

                                        # Creates binary output to be
                                        # sent to output file
                                        
                                        binaryOutput = filteredSignal.to_bytes(2, byteorder='little', signed=False)

                                        # If we are not on the first loop
                                        # simply append to the file
                                        
                                        operator = "ab"

                                        # If we are on the first loop
                                        # write the binary file
                                        
                                        if i ==0:
                                                operator = "wb"

                                # Open the output file then write the
                                # binary output onto it
                                                
                                with open(outputFileName, operator) as outputFile:
                                        outputFile.write(binaryOutput)

                # Alter the user that the signal has been filtered

                print("Signal successfully filtered onto '%s' file."
                      % outputFileName )

        # Errors for when the file does not exist
                                        
        except FileNotFoundError:

                # Warns user that the file was not found
                
                print("File '%s' not found" % file2)

                # Exit program after error
                
                sys.exit()

        # Error case for when there are type errors
                
        except ValueError:

                # Warns user of non integer data values
                
                print("Non-numerical values use")

                # Exits program after failure
                
                sys.exit()

        # exit gracefully
        
        return True

# begin gracefully

if __name__ == '__main__':
    main(sys.argv[0:])

        
# End of file
