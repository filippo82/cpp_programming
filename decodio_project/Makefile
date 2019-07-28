CC      = clang++
CFLAGS  = -std=c++1z -I.
LDFLAGS = 

default: all

all: create_data

create_data: create_data.o
		$(CC) -o $@ $^ $(LDFLAGS)

create_data.o: create_data.cpp
		$(CC) -c $(CFLAGS) $<

.PHONY: clean cleanest

clean:
		rm *.o

cleanest: clean
		rm create_data
