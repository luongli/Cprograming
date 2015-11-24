CC=gcc
CFLAGS=-g -Wall
LFLAGS=-c

all: testcase1 testcase3

testcase1: digraph.o
	$(CC) $(CFLAGS) testcase1.c digraph.o -o testcase1 -Iinc -Llib -lfdr

testcase3: digraph.o
	$(CC) $(CFLAGS) testcase3.c digraph.o -o testcase3 -Iinc -Llib -lfdr

digraph.o:
	$(CC) $(CFLAGS) $(LFLAGS) digraph.c -o digraph.o -Iinc -Llib -lfdr

clean:
	rm -rf digraph.o testcase1