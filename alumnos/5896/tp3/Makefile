CC=gcc
LDLIBS=-pthread -lrt
CFLAGS=-g -Wall
all: $(TARGETS)

tp3: main.c parser.c hijo.c
	$(CC) $(CFLAGS) $(LDLIBS) -o $@ $^


test: tp3
	ls -l | ./tp3


test2: tp3
	ls -l | ./tp3 -p hola,mono,meme


test3: tp3
	cat entrada.txt | ./tp3 -p hola,mono,meme


clean:
	rm -f $(TARGETS) *~ core*
