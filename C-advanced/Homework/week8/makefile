CC=gcc
CFLAGS=-g -Wall
LFLAGS=-c

all: testcase1 testcase4

testcase1: digraph.o
	$(CC) $(CFLAGS) testcase1.c digraph.o -o testcase1 -Iinc -Llib -lfdr

testcase4: digraph.o
	$(CC) $(CFLAGS) testcase4.c digraph.o -o testcase4 -Iinc -Llib -lfdr

digraph.o:
	$(CC) $(CFLAGS) $(LFLAGS) digraph.c -o digraph.o -Iinc -Llib -lfdr

clean:
	rm -rf digraph.o testcase1 testcase4