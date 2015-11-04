CC = gcc
CFLAGS = -g -Wall
TARGETS = tp5

all: $(TARGETS)

tp5: main.c http_worker.c getRuta.c getNombre.c getExtension.c getTipo.c create_socket.c
	$(CC) $(CFLAGS) -o $@ $^ -pthread

clean:
	rm -f $(TARGETS) *~ core*
