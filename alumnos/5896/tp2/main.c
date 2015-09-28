#include <stdio.h>
#include <wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include "hijo.h"
#include "parser.h"
#include "nieto.h"
int contador=1;
int main (int argc, char *const argv[])
{
	int operacion=0;
	extern char *optarg;
	extern int optind, opterr, optopt;

	printf("soy %d (main) \n",getpid());		
	int pid,leido;
	char mensaje[100],buff[100];
	if (pipe(hap) < 0) {
		perror("pipe():1");
		return -1;
	}
	if (pipe(pah) < 0) {
		perror("pipe():2");
		return -1;
	}
	if (pipe(han) < 0) {
		perror("pipe():3");
		return -1;
	}
	pid=fork();
	if (pid < 0) {
		perror("fork()");
		return -1;
	}

	while((operacion = getopt( argc, argv, "p")) >= 0){
		switch (operacion){
			case 'p':
				palabra1f = palabras(argv[2],1); 
				palabra2f = palabras(argv[2],2);      
				palabra3f = palabras(argv[2],3);      
				break;
		}

	} 
	//hijo
	if (pid == 0){
		printf("soy  el hijo %d y mi padre es %d estoy esperando la señal!\n",getpid(),getppid());
		if (signal(SIGUSR1, manejador) == SIG_ERR) {
			perror("error en la señal SIGUSR1");
			exit(EXIT_FAILURE);
		}
		if (signal(SIGUSR2, manejador) == SIG_ERR) {
			perror("error en la señal SIGUSR2");
			exit(EXIT_FAILURE);
		}
		for ( ; ; ){
			//pause();
			wait(NULL);
			}
		return 0;
	}

	//padre
	//sleep(2);	
	close(pah[PIPE_RD]);
	close(hap[PIPE_WR]);
	printf("Si la señal es SIGUSR1, al mensaje entrante se le aplicara ROT13\n");  
	printf("Si la señal es SIGUSR2, al mensaje entrante se le filtrara las palabras %s,%s,%s\n",palabra1f,palabra2f,palabra3f);  
	leido=read(STDIN_FILENO,mensaje,sizeof mensaje);
	write(pah[PIPE_WR],mensaje,leido);

	leido = read (hap[PIPE_RD],buff,sizeof buff);
	write(STDOUT_FILENO,buff,leido);

	close(hap[PIPE_RD]);
	close(pah[PIPE_WR]);
	return 0;	
}


