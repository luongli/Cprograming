CC=gcc
CFLAGS= -g
OBJS=adjgraph.o

all: test

test: adjgraph.o
	$(CC) $(CFLAGS) test.c OBJS -o test -Iinc -Llib -lfdr
adjgraph.o:
	$(CC) $(CFLAGS) -c adjgraph.c -o OBJS -Iinc -Llib -lfdr

clean:
	rm -rf *.o test