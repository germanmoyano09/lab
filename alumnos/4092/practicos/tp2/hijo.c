#include "funciones.h"
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <signal.h>
#include <string.h>

int i=0;

void manejador(int senal){
	switch(senal){
		case SIGUSR1:
			i=1;
			break;
		case SIGUSR2:
			i=2;
			break;
	}
}

void hijo(int pdesc1[2], int pdesc2[2], int argc, char **argv){
	signal(SIGUSR1, manejador);
	signal(SIGUSR2, manejador);
	int leido, pdesc3[2];
	char buff[10000];
	close(pdesc1[1]);
	close(pdesc2[0]);
	while(i==0){
		printf("Esperando Señal para el proceso %d\n", getpid());
		pause();
	}
	if(i==1){		
		leido = read(pdesc1[0], buff, sizeof buff);
		rot13(buff);
		write(pdesc2[1],buff,leido);
	}
	if(i==2){
		if(pipe(pdesc3) < 0){
			perror("pipe2()");
			return;
		}
		switch(fork()){
			case 0:
				close(pdesc1[0]);
				close(pdesc3[1]);
				nieto(pdesc2, pdesc3, argc, argv);
				return;
			case -1:
				perror("fork()");
				return;
			default: 
				break;
		}
		close(pdesc2[1]);
		close(pdesc3[0]);
		leido = read(pdesc1[0], buff, sizeof buff);
		write(pdesc3[1],buff, leido);
		close(pdesc3[1]);
	}
	return;
}
