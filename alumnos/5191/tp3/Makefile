CC = gcc
CFLAGS= -g -Wall
TARGETS = tp3
all: $(TARGETS)

# objetivo: dependencias
#	reglas ( tab )
tp3: main.c padre.c palabras.c hijo.c parser.c
	$(CC) $(CFLAGS) -o $@ $^ -lrt -pthread

test: tp3
	ls -l | ./tp3

test2: tp3
	ls -l | ./tp3 -p hola,mono,meme

test3: tp3
	cat mensaje.txt | ./tp3 -p hola,mono,meme	

clean:
	rm -fv $(TARGETS) *.o *~
