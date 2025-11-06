#!/usr/bin/env python3

import sys
import os
import time

def main():
    # Get program name
    program_name = os.path.basename(sys.argv[0])
    
    # Print output
    print(program_name)
    print("today's date is:", time.ctime())
    print("hello world")
    print("today's date is: 2025-09-04")
    print("the program name is:", program_name)

       
if __name__ == "__main__":
    main()

    
