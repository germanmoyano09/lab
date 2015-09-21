CC=gcc
CFLAGS=-g -Wall
TARGETS=tp3
LDLIBS=-pthread

all: $(TARGETS)

tp3: main.c hijo.c parser.c
	$(CC) $(CFLAGS) $(LDLIBS) -o $@ $^


test: tp3
	./tp3 -p franco


test2: tp3
	ls -l | ./tp3 -p hola,mono,franco


test3: tp3
	cat enunciado.txt | ./tp3 -p hola,mono,meme,Desarrollar,proceso,Entrega


clean:
	rm -f $(TARGETS) *~ core*


