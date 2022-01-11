CC = g++
CFLAGS= -Wall -Wextra -pedantic -std=c++11 -g
DEPS = rBuffer.h
OBJS = main.o
OUT = ast7

all: $(OUT)

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) 

$(OUT): $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm $(OBJS) $(OUT)
	