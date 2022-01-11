

OBJS	= reverse.o
CC		= g++
CCFLAGS	= -Wall -Wextra -pedantic -std=c++11 -g
DEPS	= linkedStack.h linkedQueue.h

all: main

main: $(OBJS)
	$(CC) $(CCFLAGS) -o reverse $(OBJS)

reverse.o: reverse.cpp $(DEPS)
	$(CC) $(CCFLAGS) -c reverse.cpp

# -----
# clean by removing object files.

clean:
	rm $(OBJS)

