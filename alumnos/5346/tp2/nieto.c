#include "nieto.h"
#include "filtrado.h"

char bufferNieto[512];
char bufferFiltrado[512];

int nieto(int han, int hap){
	
	leido_pipe = read(han, bufferNieto, sizeof bufferNieto);
	if (leido_pipe ==-1){
		perror("Error al leer en bufferNieto");
		return -1;
	
	}
	
	signal(SIGUSR2, manejador);
	pause();	
	
}



void manejador(int signum){
    
    if (signum == SIGUSR2){
        printf("Received SIGUSR2!\n");
        //printf("bufferNieto: %s\n", bufferNieto);
        
   		filtrado(bufferNieto, hap);
    }
}