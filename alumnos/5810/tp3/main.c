#include <stdio.h>
#include <wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <semaphore.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/time.h>
#include "funhijo.h"

int main(int argc, char **argv) {
    pid_t hijo; sem_t *sem_1, *sem_2; char *mem; int *membits; char cen1[1000]; char buff[1000]; int bits = 0; int opt, countflag = 0; int leido; extern char *optarg; extern int optind, opterr, optopt;

    while ((opt = getopt(argc, argv, "p:h")) != -1) {
        switch (opt) {
            case 'p':
                countflag = 1;
                strncpy(cen1, optarg, strlen(optarg));
                break;
            case 'h':
                write(1, "Uso: ./tp3 -p [PALABRA] \n\n Censura la palabra indicada y las reemplaza por caracteres ? en el texto de entrada\n\n El programa lee la entrada estándar (stdin) por lo que se puede utilizar pipes, \n al estilo 'cat texto.txt | ./tp3 -p palabra'. \n\n Si no se da la palabra a censurar el programa no se ejecuta. \n\n --\n", 313);
                break;
            default:
                write(1, "Uso: ./tp3 -p [PALABRA] \n\n Censura la palabra indicada y las reemplaza por caracteres ? en el texto de entrada\n\n El programa lee la entrada estándar (stdin) por lo que se puede utilizar pipes, \n al estilo 'cat texto.txt | ./tp3 -p palabra'. \n\n Si no se da la palabra a censurar el programa no se ejecuta. \n\n --\n", 313);
                break;
        }
    }
    if (countflag == 1) {
        mem = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
        membits = mmap(NULL, sizeof (int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
        printf("\nCreando semáforos .....\n");
        sem_1 = sem_open("/sem_1", O_CREAT, 0644, 1);
        if (sem_1 == (sem_t *) - 1) { perror("\nError creando semáforo padre"); } else { printf("\nSemáforo del padre creado.\n"); }
        sem_2 = sem_open("/sem_2", O_CREAT, 0644, 0);
        if (sem_2 == (sem_t *) - 1) { perror("\nError creando semáforo hijo"); } else { printf("\nSemáforo del hijo creado.\n"); }
        hijo = fork();
        switch (hijo) {
            case -1:
                printf("\nerror creando el hijo\n");
                exit(0);
            case 0: /* En el hijo */
                funhijo(mem, membits, cen1);
                break;
            default: /*estamos en el padre  */
                sem_wait(sem_1); /* espera que el hijo libere el semáforo */
                while ((leido = read(0, buff, sizeof buff)) > 1) { strncat(mem, buff, leido); bits = bits + leido;  }
                *membits = bits;
                sem_post(sem_2); /* activa al hijo */
        }
        sem_wait(sem_1);
        memset(buff, 0, sizeof (buff));
        leido = 0;
        printf("\033c");
        printf("\nSalida:\n");
        while (leido < bits) {
            strncpy(buff, mem + leido, 1000);
            leido = leido + write(1, buff, sizeof buff);
        }
        printf("\n\n");        
        sem_close(sem_1);
        sem_close(sem_2);
        wait(0);
        sem_unlink("/sem_2");
        sem_unlink("/sem_1");
    }
    return 0;
}
