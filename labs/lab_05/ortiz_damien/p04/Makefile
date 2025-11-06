# file: /data/courses/ece_1111/current/labs/lab_04/ortiz_damien/p04
#
# Note that this make file uses "-g" to compile and link "debug".
#

# define a target for the application
#
all: p04.exe

# define a target to link the application
#
p04.exe: p04.o
	gcc -O -lm p04.o -o p04.exe

# define targets to compile the source code
#
p04.o: p04.cc Makefile
	gcc -O -c p04.cc -o p04.o

# define a debug target
#
debug:
	gcc -g -o p04.exe p04.cc

# define a target to clean the directory
#
clean:
	rm -f p04.o p04.exe

#
# end of file
