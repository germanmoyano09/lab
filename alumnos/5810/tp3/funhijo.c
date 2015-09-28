#include <semaphore.h>
#include <string.h>
#include <sys/stat.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>


#include "comparar.h"
#include "funhijo.h"

void funhijo(char * mem, int * membits, char * cen1) {

    char * aux = (char*) calloc(1000, sizeof (char));
    char * token;
    char * result;
    char * strptr = (char*) calloc(1000, sizeof (char));

    sem_t *sem_1, *sem_2;

    int bits = 0;

    char delim[] = " \t\r\n\f";

    sem_1 = sem_open("/sem_1", O_RDWR);
    if (sem_1 == (sem_t *) - 1) {
        perror("\nError leyendo semáforo padre");
    } else {
        printf("\nSemáforo del padre leido.\n");
    }

    sem_2 = sem_open("/sem_2", O_RDWR);
    if (sem_2 == (sem_t *) - 1) {
        perror("\nError leyendo semáforo hijo");
    } else {
        printf("\nSemáforo del hijo leido.\n");
    }

    sem_wait(sem_2); /* espera que el padre libere el semáforo */

    printf("\nSoy el hijo con PID:%d\n\n", getpid());


    printf("\nSoy el hijo y empiezo a leer la memoria compartida.....\n");

    bits = *membits;

    strncpy(aux, mem, bits);

    for (token = strtok(aux, delim); token; token = strtok(NULL, delim)) {

        result = comparar(token, cen1);
        strncat(strptr, result, strlen(token));
        strncat(strptr, " ", 1);

    }
    strncat(strptr, "\0", 1);
    printf("\nSoy el hijo y termino de procesar el texto.....\n");


    //    printf("\n %s \n", strptr);

    strncpy(mem, strptr, bits);

    free(aux);
    free(strptr);

    printf("\nSoy el hijo y termino.....\n");
    
    sem_post(sem_1); /* activa al padre */

    exit(0);
}

