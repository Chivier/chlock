CC=gcc
CXX=g++
CFLAGS=-I. -g
INCLUDES=..
testc = ccode.o
testcpp = cppcode.o

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS) -I$(INCLUDES)

testc:
	gcc ccode.c -o testc -g

testcpp:
	g++ cppcode.cpp -o testcpp -g

all: testc testcpp

.PHONY: clean

clean:
	rm -rf testc testcpp
