#include "padre.h"


void funcionPadre(char *mem_buff,void *semaforo){


int leido;

char buffer[1024];
memset(buffer,0,sizeof(buffer));


	//printf("PUNTERO: %s\n",puntero);
	while ((leido = read(STDIN_FILENO,buffer,sizeof(buffer))) > 0){
		//result = strtok(buffer,delimitador);
		strncpy(mem_buff,buffer,strlen(buffer));
		//printf("mem_buff Padre %s\n",mem_buff);

		sem_post(semaforo);
		
		wait(NULL); // esperamos a q el hijo termine y mostramos...
		
	
	
			
				
	}//fin while
	sem_wait(semaforo);
	
	write(1,mem_buff,strlen(mem_buff));
    printf ("fin padre\n");
	

}