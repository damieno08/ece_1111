#!/usr/bin/env python

# file: homework/hw_02/ortiz_damien/p02/p02.py

#--------------------------------------------------------------------------

#Program will read the basic data within an excel file print int it to the
# terminal.

#--------------------------------------------------------------------------

#Imports

#--------------------------------------------------------------------------

#Imports to get data file reading library
import pandas as pd

#Import sys in order to get system specific parameters
import sys

#--------------------------------------------------------------------------

#Function Code

#--------------------------------------------------------------------------
def main(argv):
        #Creates a data frame which contains the basic cell information of the
        # excel file
        df = pd.read_excel('x0.xlsx')

        #Displays the data in the data frame printing the output to the terminal
        print(df)

        #exit gracefully
        return True


# begin gracefully

if __name__ == '__main__':
    main(sys.argv[0:])

#End of file
