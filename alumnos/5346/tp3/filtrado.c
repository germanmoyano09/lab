#include "filtrado.h"


int filtrado(memoria *ptr){

	char *tok;
	//ssize_t escrito;
	char *filtro="mundo";
	
	char buffTexto[512];	
	
	memset(buffTexto, 0, sizeof buffTexto);


	tok = strtok(ptr->texto,",");	
		
	while(tok != NULL){
		if(strstr(tok,filtro) != NULL){
			
			strcat(buffTexto,"*");
			strcat(buffTexto,",");
				
					/*escrito = write(ptexto, mensajeEspacio, sizeof mensajeEspacio);
					if (escrito == -1){
						perror("Error al escribir archivo");
						return -1;
					}*/
		}else{
			strcat(buffTexto,tok);
			strcat(buffTexto,",");
		}
				
		tok = strtok(NULL,",");	
	}
	//printf("%s\n", buffTexto);
	//printf("%s\n", ptr->texto);
	ptr->texto[0] = '\0';
	strcat(buffTexto,"\n");
	strcat(ptr->texto,buffTexto);
return 0;

}
