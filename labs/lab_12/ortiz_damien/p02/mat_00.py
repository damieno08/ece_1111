#!/usr/bin/env python

# file: /data/courses/ece_1111/2025_01_fall/labs/lab_12/ortiz_damien/p02/mymath/mat_00.py
#
# Version History: 
# 20251111 create initial file

# Imports:
#
import sys
import os
import numpy as np

# functions
#      
class MyMatrix():

    # constructor for class with default 1x1
    #
    def __init__(self, rows=1, cols=1):
        self.rows = rows
        self.cols = cols
        self.matrix = None

    # function to read data values from file into matrix
    #
    def read(self, file):

        tempMat = []
        with open(file, "r") as f:
            firstRun = True
            for line in f:            
                row = [float(x) for x in line.strip().split()]
                tempMat.append(row)
                if firstRun:
                    colCount = len(row)
                    firstRun = False
                elif len(row) != colCount:
                    print("Matrix has inconsistent size.")
                    return False
                self.cols = colCount
        self.rows = len(tempMat)
        self.matrix = np.array(tempMat)
        return True

    # displays matrix to filepointer
    #
    def display(self, file=sys.stdout):
        for row in self.matrix:
            for element in row:
                file.write(str(element) + " ")
            file.write("\n")
        file.write("\n")
        return True

    # rewrite operator to add elements
    #
    def __add__(self, other):
        if not isinstance(other, MyMatrix):
            raise TypeError("Can only add MyMatrix to MyMatrix")
        
        if self.matrix.shape != other.matrix.shape:
            raise ValueError("Matrix sizes must match for addition")
        
        result = MyMatrix(self.rows, self.cols)
        result.matrix = self.matrix + other.matrix
        return result
    
    # rewrite operator to subtract elements
    #
    def __sub__(self, other):
        if not isinstance(other, MyMatrix):
            raise TypeError("Can only add MyMatrix to MyMatrix")
        
        if self.matrix.shape != other.matrix.shape:
            raise ValueError("Matrix sizes must match for addition")
        
        result = MyMatrix(self.rows, self.cols)
        result.matrix = self.matrix - other.matrix
        return result
    
    # rewrite operator to perform matrix multiplication
    #
    def __mul__(self, other):
        if not isinstance(other, MyMatrix):
            raise TypeError("Can only add MyMatrix to MyMatrix")
        
        if self.cols != other.rows:
            raise ValueError("Matrix sizes must match for multiplication")
        
        result = MyMatrix(self.rows, other.cols)
        result.matrix = self.matrix @ other.matrix
        return result

# function to do operation to two matrix objects
#
def performOp(op, self, other):

    result = MyMatrix()
    if op == "addition":
        result = self+other

    if op == "subtraction":
        result = self-other

    if op == "multiplication":
        result = self*other
    return result

# exit gracefully
