# Make file for twenty-six game program.

OBJS	= main.o matrixImp.o
CC		= g++
CCFLAGS	= -Wall -Wextra -pedantic -std=c++11 -g
DEPS	= matrix.h

all: main

main: $(OBJS)
	$(CC) $(CCFLAGS) -o main $(OBJS)

main.o:	main.cpp $(DEPS)
	$(CC) $(CCFLAGS) -c main.cpp

matrix.o: matrix.cpp $(DEPS)
	$(CC) $(CCFLAGS) -c matrixImp.cpp

# -----
# clean by removing object files.

clean:
	rm $(OBJS)

