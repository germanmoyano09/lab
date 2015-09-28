CFLAGS= -g -Wall
LDLIBS=-lrt -pthread
CC:=gcc
TARGETS= hilos 

all: clean $(TARGETS)
hilos: ej3.c
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

.PHONY: clean
clean:
	rm -f *.o *~ $(TARGETS)
