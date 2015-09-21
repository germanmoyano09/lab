#include "palabras.h"

void obtenerPalabras(char **palabras){

	*palabras = malloc(sizeof(char) * strlen(optarg));
	strncpy(*palabras, optarg, strlen(optarg));
	
}