#!/usr/bin/env python


# file: labs/lab_02/ortiz_damien/helloworld.py

#--------------------------------------------------------------------------

#Program will print "hello world" onto the terminal

#--------------------------------------------------------------------------

#Imports

#--------------------------------------------------------------------------

#Import sys in order to get system specific parameters
import sys

#--------------------------------------------------------------------------

#Function Code

#--------------------------------------------------------------------------

#Creates main function
def main(argv):

        #Prints hello world onto the console
        print("hello world")

        return True
        
# begin gracefully

if __name__ == '__main__':
    main(sys.argv[0:])

#End of file
