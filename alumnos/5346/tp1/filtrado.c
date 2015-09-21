#include "head.h"


int filtrado(char *mensaje, char *salida){

	int op=1, op2;
	char buff[512];
	char *tok;
	ssize_t leido, escrito;
	char *filtro="prohibidas";
	memset(buff, '\0', 512);	
	
	
	if(salida != NULL){
		op2 = open(salida, O_CREAT | O_RDWR | O_APPEND, 0600);
		if (op2 == -1){
			perror("Error al abrir el archivo 2");
			return -1;
		}
	}
	else{
		op2 = 1;
	}		
	
	tok = strtok(mensaje," ");	
		
	while(tok != NULL){
			
		if(NULL == strstr(tok,filtro)){
			
			char mensajeEspacio[512]=" ";
			strcat (mensajeEspacio, tok);
			
					escrito = write(op2, mensajeEspacio, sizeof mensajeEspacio);
					if (escrito == -1){
						perror("Error al escribir archivo");
						return -1;
					}
				}
					
			tok = strtok(NULL," ");
		
		}
		close(op2);
	
/*	if(salida != NULL){
		op = open(salida, O_CREAT | O_RDWR | O_APPEND, 0600);
		if (op == -1){
			perror("Error al abrir el archivo");
			return -1;
		}
		
	}
	else{
		op=1;
	}
	//printf("%s", tok);
	op2 = open(mensaje, O_RDWR, 0600);
	if (op2 == -1){
		perror("Error al abrir el archivo 2");
		return -1;
	
	}
	//	printf("%d\n", op2);
	leido = read(op2, buff, sizeof buff);
	if (leido == -1){
		perror("Error al leer el archivo op2");
		return -1;
	}

	else{
		escrito = write(op, buff, sizeof buff);
		if (escrito == -1){
			perror("Error al escribir archivo");
			return -1;
		}
	}
	close(op2);*/
return 0;

}
