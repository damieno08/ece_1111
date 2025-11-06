#!/usr/bin/env python

# file: /data/courses/ece_111/current/homework/hw_03/ortiz_damine

#--------------------------------------------------------------------------

# Program will take in files, read through each line, and display how many
# times the word "foo" was used in a line in acase insensitive matter.
# Program will also store help messages for each file input if the --help
# or -h command is used. If a help file does not exist the user will be
# prompted to create one
#--------------------------------------------------------------------------

# Imports

#--------------------------------------------------------------------------

import sys

import os

#--------------------------------------------------------------------------

# Function Code

#--------------------------------------------------------------------------

# Helper file handling function
#

# Function will take in an argument list and create stored helper files
#

def helper(arguments):

        # For loop runs through every argument input
        #
        
        for i in range(len(arguments)):

                # Checks if a helper file already exists within current
                # directory
                #
                
                premadeHelper = ("%s.help" % arguments[i])                
                if os.path.exists(premadeHelper):

                        # If the helper file does exist it will open the
                        # helper file, read each line, then print onto
                        # the terminal
                        
                        with open(premadeHelper, "r") as helperFile:
                                for line in helperFile:
                                        print(line)
                else:
                        # If the helper file doesn't exist the user
                        # will be asked to create it
                        
                        print("Helper file  for %s does not exist."
                              % arguments[i] )
                        creater = input("Would you like to create one"
                                        "[y/n]:" )
                        
                        # If the user says yes they will be prompted to
                        # enter the usage message
                        if creater.lower() == "y":                        
                                usage = input("Enter Usage: ")
                                print()
                                # Program takes usage message and writes it
                                # to help file
                                
                                helperName = arguments[i] + ".help"
                                with open(helperName, "w") as helperFile:
                                        helperFile.write(usage)
                        else:
                                # Prints warning that a helper file
                                # was not created 
                                print("Warning: Help file for %s"
                                      "not created" % arguments[i])
                                print()
                

#--------------------------------------------------------------------------

# Function searches the input file for the input keyword disregarding case
#

def searchContent(file, keyWord):

        # Initializes the number of lines that match as an int
        #
        
        lineMatch = int(0)

        # Loops through each line of the file and store the
        # index of the line
        
        for idx,line in enumerate(file):

                # Creates a temporary variable that is put into logic to
                # see if the keyword is within a line
                #
                
                lineCheck = line.lower()
                if keyWord in lineCheck:

                        # If the keyword is within a line it increases the
                        # count of lines that match
                        #
                        
                        lineMatch += 1                        

                        # Outputs the file, line, and content of the line
                        # that contain the matching keyword
                        #
                        
                        print("file: %s " % file.name)
                        print("line %d: %s" % (idx, line.strip()))
        #Returns the number of matching lines so that the user may use it
        #
        
        return lineMatch
        
# main function
#

def main(argv):

        # Creates a list that stores all command line arguments
        #
        
        argument_list = argv[1:]

        # Sets matching lines total to 0 at start of program
        #
        
        total = 0

        # Sets default keyword to foo
        #

        keyword = "foo"
        
        # Checks if the file exist
        #
        
        try:

                # Loops through every file in argument list
                #

                for i in range(len(argument_list)):

                        # Checks if the user is asking for help file
                        #
                        
                        if "-h" in argument_list:
                                argument_list.remove("-h")

                                # Calls our help function to handle helper
                                # files
                                
                                helper(argument_list)

                                # Ends program after help files are
                                # printed to terminal
                                
                                break
                        elif "--help" in argument_list:
                                argument_list.remove("--help")           
                                helper(argument_list)
                                break
                        else:
                                # If user does not ask for help file
                                # use searchContent to find keyword
                                # within our files after asking user

                                if os.path.exists(argument_list[i]):
                                        if i == 0:
                                                keyword = input("Enter"
                                                        " Keyword:")

                                # Opens each file and closes it even if 
                                # errors occur
                                
                                with open(argument_list[i], "r") as file:

                                        # Updates the match count of
                                        # keyword within file
                                        
                                        total += searchContent(file,
                                                               keyword)
                        # Outputs a statement with the number
                        # of keyword matches within all files
                                
                print("Total lines matched = %d" % total)
        # Error case for when file does not exist
        #
        
        except FileNotFoundError:

                #Tells user that the file they selected doesn't exist
                #
                
                print("File '%s' does not exist" % argument_list[i])
        # exit gracefully
        
        return True

# begin gracefully

if __name__ == '__main__':
    main(sys.argv[0:])

        
#End of file
