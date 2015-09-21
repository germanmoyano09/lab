#include "funciones.h"
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <semaphore.h>

void hijo(char *ptr, int argc, char **argv){
	int opc;
	char buff[2048];
	char *palabras;
	char *palab;
	extern char *optarg;
	extern int optind, opterr, optopt;
	while((opc = getopt(argc, argv, "p:o"))>0){
		switch(opc){
			case 'p':
				palabras = optarg;
				break;
			default:
				printf("MODO DE USO \n -p palabras separado por comas \n");
				exit(1);
		}
	}	
	
	palab = strtok(palabras,",");
	char *token = palab;
	parser(ptr,sizeof buff,palab);
	while((token = strtok(NULL, ",")) !=NULL){
		parser(ptr,sizeof buff,token);
	}
	return;
}
