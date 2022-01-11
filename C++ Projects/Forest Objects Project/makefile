# Makefile assignment #6

OBJS	= main.o
CC		= g++
CCFLAGS	= -Wall -Wextra -pedantic -std=c++11 -g
DEPS	= object.h forest.h

all: main

main: $(OBJS)
	$(CC) $(CCFLAGS) -o main $(OBJS)

main.o:	main.cpp $(DEPS)
	$(CC) $(CCFLAGS) -c main.cpp

# -----
# clean by removing object files.

clean:
	rm $(OBJS)
