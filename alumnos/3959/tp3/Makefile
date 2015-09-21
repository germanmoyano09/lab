CFLAGS= -g -Wall
LDLIBS=-lrt -pthread
CC:=gcc
TARGETS= tp3

all: clean $(TARGETS)
tp3: main.c hijo.c srch.c
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

.PHONY:test
test:	
	cat mensaje.txt | ./tp3 -p hola,como,con

.PHONY:test2
test2:
	ls -l | ./tp3 -p hijo,srch,anakin


.PHONY: clean
clean:
	rm -f *.o *~ $(TARGETS)
