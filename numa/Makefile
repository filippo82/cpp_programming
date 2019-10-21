CC      = icpc
CFLAGS  = -std=c++17 -qopenmp -I.
LDFLAGS = -parallel

default: all

all: test0

test0: test0.o
		$(CC) -o $@ $^ $(LDFLAGS)

test0.o: test0.cpp
		$(CC) -c $(CFLAGS) $<

.PHONY: clean cleanest

clean:
		rm *.o

cleanest: clean
		rm simple1
