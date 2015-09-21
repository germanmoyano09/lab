/**
 * Explique por qué cambia el proceso padre del hijo.
 
    Despues de hacer el fork(), el proceso hijo espera 2 segundos (sleep(2)), durante los cuales el proceso padre
    termina. Al terminar el proceso padre, los procesos hijos son reasignados como hijos del proceso 'init', que
    es el proceso que se ejecuta primero en Linux, después de haberse cargado el kernel, y que tiene el PID 1.
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *const argv[])
{
    printf ("pid proceso %d, y el padre (bash) %d\n", getpid(), getppid());

    if (fork() == 0) {
        printf ("pid proceso hijo %d, y el padre %d\n", getpid(), getppid());
        sleep(2);
        printf ("pid proceso hijo %d, y el padre %d ???\n", getpid(), getppid());
        return 0;
    }

    sleep(1);
    return 0;
}
