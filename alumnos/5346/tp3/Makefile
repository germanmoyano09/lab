CC=gcc
CFLAGS=-Wall
TARGETS=tp3
LDLIBS=-pthread

# el $@ reemplaza todos los objetivos y el $^ reemplaza todas las dependencias
#objetivo: dependencias
#       reglas

all: $(TARGETS)

tp3: main.c filtrado.c
	 $(CC) $(CFLAGS) $(LDLIBS) -o  $@ $^

test: tp3
	./tp3 -o salida.txt
#	cat news-* |./tp3 -o salida.txt
clean:
	 rm -fv $(TARGETS) *.txt *~ 
