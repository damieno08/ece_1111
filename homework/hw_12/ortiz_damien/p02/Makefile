# file: /data/courses/ece_1111/2025_01_fall/homework/hw_12/ortiz_damien/p02/Makefile/
#
# Note that this make file uses '-g' to compile and link 'debug'.
#


# define a target for the application
#
all: p02.exe


# define a target to link the application
#
p02.exe: p02.o
	g++ -O -lm p02.o p02_00.cc -o p02.exe
# define targets to compile the source code
#
p02.o: p02.cc p02.h Makefile p02_00.cc
	g++ -O -c p02.cc -o p02.o
p02_00.o: p02.cc p02.h Makefile p02_00.cc
	g++ -O -c p02_00.cc -o p02_00.o

# define a debug target
#
debug:
	g++ -g p02.cc -o p02.debug
# define a target to clean the directory
#
clean:
	rm -f p02.o p02.exe
#
# end of file
