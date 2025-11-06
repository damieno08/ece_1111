# file: /data/courses/ece_1111/2025_01_fall/labs/lab_09/ortiz_damien/Makefile/
#
# Note that this make file uses '-g' to compile and link 'debug'.
#


# define a target for the application
#
all: p01.exe


# define a target to link the application
#
p01.exe: p01.o
	gcc -O -lm p01.o -o p01.exe
# define targets to compile the source code
#
p01.o: p01.cc p01.h Makefile
	gcc -O -c p01.cc -o p01.o

# define a debug target
#
debug:
	gcc -g p01.cc -o p01.debug
# define a target to clean the directory
#
clean:
	rm -f p01.o p01.exe
#
# end of file
