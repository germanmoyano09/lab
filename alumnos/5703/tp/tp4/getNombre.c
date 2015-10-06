#include "http_worker.h"

char *getNombre(char *buff){	
	char *nombre = NULL;

	nombre = strtok(buff, "/");
	nombre = strtok(NULL, " ");
	
	return nombre;
}