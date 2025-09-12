#!/usr/bin/env python 


#Imports

from datetime import datetime
import sys
import os

#Main function
def main(argv):
    # Print current date and time
    now = datetime.now()
    formatted_now = now.strftime("%Y-%m-%d %H:%M:%S")
    print("Current date and time:", formatted_now)

    # Get the path to this file
    this_file = os.path.abspath(__file__)

    # Count the number of lines in this Python file
    with open(this_file, 'r') as f:
        num_lines = len(f.readlines())

    print(f"Number of lines in this file: {num_lines}")
    return True


# begin gracefully

if __name__ == '__main__':
    main(sys.argv[0:])


#End of file
