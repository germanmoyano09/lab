CC = gcc
CFLAGS = -g -Wall
TARGETS = tp4

all: $(TARGETS)

tp4: main.c http_worker.c getRuta.c getNombre.c getExtension.c getTipo.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGETS) *~ core*