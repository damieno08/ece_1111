# file: lecture_05/GNUMakefile
#
# Note that this make file uses "-g" to compile and link "debug".
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
p03.o: p03.cc  Makefile
	gcc -O -c p03.cc -o p03.o

# define a debug target
#
debug:
	gcc -g -o p03.exe p03.cc

# define a target to clean the directory
#
clean:
	rm -f p03.o p03.exe

#
# end of file
