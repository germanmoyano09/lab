#include "funciones.h"
#include <string.h>

void parser(char *input, int len, char *filtro){
	int i,j,x;
	for(i=0;i<len;i++){
		x=0;
		for(j=0; j<strlen(filtro);j++){
			if(filtro[j] != '\0' && filtro[j] != '\n'){
				if (input[i+j] != filtro[j]){
					x=1;	
				}
			}
		}
		if (x==0){
			for (j=0; j<strlen(filtro); j++){
				if(filtro[j] != '\0' && filtro[j] != '\n'){
					*(input+i+j) = '*';
				}
			}
		}
	}
}
