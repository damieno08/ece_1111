#!/usr/bin/env python

# file: homework/hw_02/ortiz_damien/p03/p03.py

#--------------------------------------------------------------------------

#Program will use pandas to read the contents of a csv file then output the
# information onto the terminal.

#--------------------------------------------------------------------------

#Imports

#--------------------------------------------------------------------------

#Imports the pandas library which is used to read data files
import pandas as pd

#Import sys in order to get system specific parameters
import sys

#--------------------------------------------------------------------------

#Function Code

#--------------------------------------------------------------------------
def main(argv):
        #Creates a dataframe which will contain the cell information
        # within the csv
        df = pd.read_csv('x0csvVersion.csv')

        #Prints the contents of the data file onto the terminal
        print(df)
        
        #exit gracefully
        return True
        
# begin gracefully

if __name__ == '__main__':
    main(sys.argv[0:])

#End of file
