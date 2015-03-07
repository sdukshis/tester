CC = g++
CFLAGS = -Wall -Wextra -std=c++1x
LFLAGS = 

.PNOHY: all clean test

all:tests

tests:test.o
	$(CC) $(LFLAGS) -o $@ $^

test.o: test.cpp tester.h
	$(CC) -c $(CFLAGS) -o $@ $<

test:
	./tests

clean:
	rm -f test.o
	rm -f tests
