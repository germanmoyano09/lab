#include "hijo.h"
#include "parser.h"


void funcionHijo(char *mem_buff,void *semaforo, char *palabras){

	
	int cantidad = 0; // palabras
	//int espacio = 0;

	char delimitador[] = " \n";
	char delimitador2[] = ",";
	char buffer[1024];
	memset(buffer,0,sizeof(buffer));

	char buffer2[1024];
	memset(buffer2,0,sizeof(buffer2));

	char buffer3[1024];
	memset(buffer3,0,sizeof(buffer3));

	char *result = NULL;

	char buf[10];
	memset(buf,0,sizeof(buf));

	//char *palabra = NULL;

	char *palabrasFiltrar[20] ={};
	char *palabrasTmp = NULL;
	char *dimension = NULL;
	char *frase = NULL;

	strncpy(buffer2,mem_buff,strlen(mem_buff));
	palabrasTmp = palabras;

		dimension = strtok(palabrasTmp,delimitador2);

		while (dimension != NULL){
			palabrasFiltrar[cantidad] = dimension;

			dimension = strtok(NULL,delimitador2);
			cantidad++;
		}

	

		result = strtok(buffer2,delimitador);
				
		while (result != NULL){

			//palabra = strcpy(buf,result);
			//printf("BUUUU %s\n",palabra);
			
			frase = parsearFrase(result,palabrasFiltrar,cantidad);	

			result = strtok(NULL,delimitador);
			

			memset(buf,0,sizeof(buf));

			strncat(buffer3,frase,strlen(frase)); // agrego cada palabra para luego formar el texto filtrado
			//espacio = (int)strlen(frase);
			strncat(buffer3," ",1);
			
			//printf("frase %s\n",buffer3);
	        /*if (strncmp(frase,"****",4) == 0){ // hacemos un espacio
				strncat(buffer3," ",1);
				printf ("OK\n");
			}else {
				printf ("NO OK\n");
			}*/
			
			
		
		} // fin while
			//printf("buf3 %s\n",buffer3);
			strncpy(mem_buff,buffer3,strlen(buffer3));

			sem_post(semaforo);
	
}