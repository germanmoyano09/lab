/**
 * Explique el estado de los procesos hijos de este código.
 
        Los procesos en linux son representados por una estructura de datos llamada 'task_struct'; cada estructura
        'task_struct' es apuntada por un puntero en el vector 'task'. Al crear un proceso hijo, se le asigna a este 
        una estructura task_struct. Si este proceso hijo termina y el proceso padre está en estado de espera (esperando 
        por un evento o un recurso; en este caso el proceso padre espera una entrada de teclado-->getcher()), o "Sleeping",
        entonces el proceso hijo termina pero le queda aun asignada una estructura task_struct. Es tarea del proceso
        padre limpiar el proceso hijo, liberando así la memoria reservada para la estructura que tenía asignada.

        Si agregamos una función wait() en el programa antes de getchar(), el proceso padre espera hasta que el 
        proceso hijo cambie de estado (R->T).
 
 
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *const argv[])
{
    int status;
    int status2;
    if (fork() == 0) {
         return 0;
    }
    if (fork() == 0) {
        return 0;
    }
    printf("En otra pantalla ejecutar \"ps f\". Cualquier tecla para terminar \n");
    wait(&status);
    wait (&status2);
    printf ("status: %d \n", status);
    getchar();
    return 0;
}

