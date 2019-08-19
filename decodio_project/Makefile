CC      = clang++
CFLAGS  = -std=c++1z -I.
LDFLAGS = 

default: all

all: wave

wavetools.o: wavetools.cpp
		$(CC) -c $(CFLAGS) $<

utils.o: utils.cpp
		$(CC) -c $(CFLAGS) $<

wave.o: wave.cpp
		$(CC) -c $(CFLAGS) $<

wave: wave.o wavetools.o utils.o
		$(CC) $(LDFLAGS) -o $@ $^

.PHONY: clean cleanest

clean:
		rm *.o

cleanest: clean
		rm create_data
