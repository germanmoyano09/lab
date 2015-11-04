#include "http_worker.h"

char *getExtension(char *nombre_archivo ){
	char *ext = NULL;
	char nombre_archivo_aux[256];
	
	memset(nombre_archivo_aux,0,sizeof(nombre_archivo_aux));

	strncpy(nombre_archivo_aux, nombre_archivo, strlen(nombre_archivo));

	ext = strtok(nombre_archivo_aux, ".");
	ext = strtok( NULL, " ");
		
	return ext;
}