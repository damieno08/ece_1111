# file: /data/courses/ece_1111/2025_01_fall/labs/lab_08/ortiz_damien/p02/p02/Makefile
#
# Note that this make file uses '-g' to compile and link 'debug'.
#


# define a target for the application
#
all: p03.exe


# define a target to link the application
#
p03.exe: p03.o
	g++ -g -O -lm p03.o -o p03.exe
# define targets to compile the source code
#
p03.o: p03.cc p03.h Makefile 
	g++ -O -c p03.cc -o p03.o

# define a debug target
#
debug:
	g++ -g -o p03.cc p03.exe
# define a target to clean the directory
#
clean:
	rm -f p03.o p03.exe
#
# end of file
