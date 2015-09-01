CC=gcc
CFLAGS = -g -Wall -pthread
TARGETS = tp3

all: $(TARGETS)

tp3: main.c filter.c
	$(CC) $(CFLAGS) -o $@ $^

test: tp3
	ls -l | ./tp3


test2: tp3
	ls -l | ./tp3 -p hola,mono,meme


test3: tp3
	cat mensaje.txt | ./tp3 -p hola,mono,meme


clean:
	rm -f $(TARGETS) *~ core*
