CC=gcc
CFLAGS=-g -Wall -pthread
TARGETS=tp3

all: $(TARGETS)

tp3: main.c comparar.c funhijo.c
	$(CC) $(CFLAGS) -o $@ $^


test: tp3
	cat texto.txt | ./tp3 -p hola


clean:
	rm -f $(TARGETS) *~ core*
