CC      = clang++
CFLAGS  = -std=c++1z -I.
LDFLAGS = 

default: all

all: simple1

simple1: simple1.o
		$(CC) -o $@ $^ $(LDFLAGS)

simple1.o: simple1.cpp
		$(CC) -c $(CFLAGS) $<

.PHONY: clean cleanest

clean:
		rm *.o

cleanest: clean
		rm simple1
