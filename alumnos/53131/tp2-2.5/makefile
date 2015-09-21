OBJS = main.c hijo.o pipes.o nieto.o repl_str.o
CC = gcc
#DEBUG = -g -Wall -fno-stack-protector 
#CFLAGS = -c $(DEBUG)
CFLAGS = -g -Wall
TARGETS=tp2

all: $(TARGETS)

tp2 : main.c hijo.c pipes.c nieto.c repl_str.c
		$(CC) $(CFLAGS) -o $@ $^  
#tp2 : $(OBJS)
#		$(CC) $(DEBUG) $(OBJS) -o tp2

#main.o : main.c hijo.c
#		$(CC) $(CFLAGS) main.c
#hijo.o : hijo.c hijo.h
#		$(CC) $(CFLAGS) hijo.c
#pipes.o : pipes.c pipes.h
#		$(CC) $(CFLAGS) pipes.c
#nieto.o : nieto.c nieto.h
#		$(CC) $(CFLAGS) nieto.c
#repl_str.o : repl_str.c nieto.h
#		$(CC) $(CFLAGS) repl_str.c;
