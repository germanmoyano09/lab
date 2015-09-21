#include "parser.h"

char *parsearFrase(char *palabra,char *palabrasFiltrar[],int cantidad){

	int i;
	int flag = 0;
	
	for (i=0;i<cantidad;i++){

		if  (strncmp(palabra,palabrasFiltrar[i],strlen(palabrasFiltrar[i])) == 0) {
			flag = 1;
		}
			

	if (flag){ 
		palabra = "****";
	}

	}	

	//printf("palabra %s ---- flag %d\n",palabra,flag);
	return palabra;
}