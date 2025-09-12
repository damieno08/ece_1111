#!/usr/bin/env python
 
# file: labs/lab_01//myprog.py
## revision history:jackson
#
# 20230827 (JP): first version
#
# This is a Python program version of myscript.py
#------------------------------------------------------------------------------

# import system modules
#
import os
import sys

#------------------------------------------------------------------------------
 #
# global variables are listed here
#
#------------------------------------------------------------------------------

#------------------------------------------------------------------------------
#
# functions are listed here
#
#------------------------------------------------------------------------------

# function: main
# 
def main(argv):

    # print hello world
    #
    print("hello world")

    # set a variable
    #
    sum = float(27.0)

    # print its value
    #
    print("sum = %f" % (sum))

    # display an informational message
    #
    print("... it has been a pleasure doing business %s ..." % ("today"))

    # exit gracefully
    #
    return True

# begin gracefully
#
if __name__ == '__main__':
    main(sys.argv[0:])
