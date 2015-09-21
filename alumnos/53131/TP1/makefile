OBJS = main.o leer.o filtro.o repl_str.o
CC = gcc
DEBUG = -g -Wall
CFLAGS = -c $(DEBUG)


tp1 : $(OBJS)
		$(CC) $(DEBUG) $(OBJS) -o tp1
main.o : main.c leer.c filtro.c filtrar.h
		$(CC) $(CFLAGS) main.c
leer.o : leer.c filtrar.h
		$(CC) $(CFLAGS) leer.c
filtro.o : filtro.c filtrar.h
		$(CC) $(CFLAGS) filtro.c 
repl_str.o : repl_str.c filtrar.h
		$(CC) $(CFLAGS) repl_str.c
