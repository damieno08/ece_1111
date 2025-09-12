#!/usr/bin/env python

# file: labs/lab_02/ortiz_damien/factorialFinder.py

#--------------------------------------------------------------------------

#Program finds the factorial of any number entered into
# the terminal and prints the output to the terminal

#--------------------------------------------------------------------------

#Imports

#--------------------------------------------------------------------------

#Import sys in order to get system specific parameters
import sys

#--------------------------------------------------------------------------

#Function Code

#--------------------------------------------------------------------------

#main function
def main(argv):
        
        #The userInput boolean tells the while loop to run when the
        #program is first opened
        userInput = False


        #While loop will allow the user to retry input until they have
        # correctly entered a numerical input
        while  userInput == False:

            #Converts input number into string stored by program
            enteredNumString = input("Enter the number you would like a factorial for: ")

            #Removes empty spaces from string
            spacelessString = enteredNumString.replace(" ", "") 

            #We use the if statement to check for break cases. If a string
            #contains characters that are not a number , the program will
            #output that the input is invalid and ask for the user to retry

            if spacelessString.isdigit():

                #Changes the condition of the while loop in order to stop 
                userInput = True

                #Converts the string into an int if the input is in fact
                # a number
                finalAnswer = int(spacelessString)

                #sets the output to 1 if zero is entered
                if finalAnswer <=0:
                        finalAnswer = 1
                
                for i in range (finalAnswer, 1, -1):

                        #Does the factorial by multiplying the input
                        # number by every number between the input
                        #  and 1
                        finalAnswer = finalAnswer * (i-1)
        #The else statement is used to give an error message when the
        # inputs that contain non-numerical answers are entered        
            else:

                #Prints out the error message letting the user know they
                #entere non-numerical answer       
                print("You did not enter a positive number. Please Try Again.")

        #After all calculations are made prints the factorial of the
        # entered number
        print("The factorial is", finalAnswer)        
        
        # exit gracefully
        
        return True

# begin gracefully

if __name__ == '__main__':
    main(sys.argv[0:])

        
#End of file
