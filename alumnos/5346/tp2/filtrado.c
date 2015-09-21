#include "hijo.h"
#include "filtrado.h"
#include "nieto.h"


int filtrado(char *mensaje, int hap){

	char *tok;
	ssize_t leido, escrito;
	char *filtro="mundo";	
	
	tok = strtok(mensaje," ");	
		
	while(tok != NULL){
			
		if(NULL == strstr(tok,filtro)){
			
			char mensajeEspacio[512]=" ";
			strcat (mensajeEspacio, tok);
			
					escrito = write(hap, mensajeEspacio, sizeof mensajeEspacio);
					if (escrito == -1){
						perror("Error al escribir archivo");
						return -1;
					}
				}
					
			tok = strtok(NULL," ");
		
		}
return 0;

}
