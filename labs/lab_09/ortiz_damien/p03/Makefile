# file: /data/courses/ece_1111/2025_01_fall/labs/lab_09/ortiz_damien/p03/Makefile/
#
# Note that this make file uses '-g' to compile and link 'debug'.
#


# define a target for the application
#
all: p03.exe


# define a target to link the application
#
p03.exe: p03.o
	gcc -O -lm p03.o -o p03.exe
# define targets to compile the source code
#
p03.o: p03.cc p03.h Makefile
	gcc -O -c p03.cc -o p03.o

# define a debug target
#
debug:
	gcc -g p03.cc -o p03.debug
# define a target to clean the directory
#
clean:
	rm -f p03.o p03.exe
#
# end of file
