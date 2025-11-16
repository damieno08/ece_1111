# file: /data/courses/ece_1111/2025_01_fall/labs/lab_12/ortiz_damien/p01/Makefile/
#
# Note that this make file uses '-g' to compile and link 'debug'.
#


# define a target for the application
#
all: mymath.exe


# define a target to link the application
#
mymath.exe: mymath.o
	g++ -O -lm mymath.o -o mymath.exe
# define targets to compile the source code
#
mymath.o: mymath.cc mymatrix.h Makefile mat_00.cc
	g++ -O -c mymath.cc -o mymath.o

# define a debug target
#
debug:
	g++ -g mymath.cc -o mymath.debug
# define a target to clean the directory
#
clean:
	rm -f mymath.o mymath.exe
#
# end of file
