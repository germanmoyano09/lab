#include "hijo.h"
#include "nieto.h"
#include "filtrado.h"

char bufferHijo[512];

int hijo(int pah, int hap){

	int han[2];
	pipe (han);
	memset(bufferHijo, '\0', 512);
	memset(bufferMayuscula, '\0', 512);
	
	leido_pipe = read(pah, bufferHijo, sizeof bufferHijo);
	if (leido_pipe ==-1){
		perror("Error al leer en bufferHijo");
		return -1;
	}
	escrito_pipe2 = write(han[1], bufferHijo, sizeof bufferHijo);
	if (escrito_pipe2 ==-1){
		perror("Error al escribir en bufferHijo2");
		return -1;
	}
	
	int pid2 = fork();
	if(pid2 == 0){
		close(han[1]);
		nieto(han[0], hap);
		return 0;
	}
	
		signal(SIGUSR1, mayuscula);	
		pause();
		//pause();
		
	escrito_pipe = write(hap, bufferMayuscula, sizeof bufferMayuscula);
	if (escrito_pipe ==-1){
		perror("Error al escribir en bufferHijo");
		return -1;
	}
		
		
}


void mayuscula(int signum){
    
    if (signum == SIGUSR1){
        printf("Received SIGUSR1!\n");
        //printf("bufferHijo: %s\n", bufferHijo);
        
    	for (int i=0; bufferHijo[i] != '\0'; i++){
   			bufferMayuscula[i] = toupper (bufferHijo[i]);
   		}
    }
}