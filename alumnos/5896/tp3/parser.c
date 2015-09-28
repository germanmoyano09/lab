#include "parser.h"


char palabra1[50];
char palabra2[50];
char palabra3[50];

int k=1;
char  *palabras(char *palabras, int cont){
	char *ptr;
	char *p;
	char* s2 = ",";


	ptr = strtok( palabras, s2 );    // Primera llamada => Primer token
	strcpy(palabra1,ptr);

	while( (ptr = strtok( NULL, s2 )) != NULL ){    // Posteriores llamadas

		k++;
		if(k==2){
			strcpy(palabra2,ptr);
		}

		if(k==3){
			strcpy(palabra3,ptr);
		}

	}

	if(cont==1){
		p=palabra1;
			printf (" palabra1 de la funcion palabras: %s \n",p);
		return p;
	}
	if(cont==2){
		p=palabra2;
			printf (" palabra2 de la funcion palabras: %s \n",p);
		return p;
	}
	if(cont==3){
		p=palabra3;
			printf (" palabra3 de la funcion palabras: %s \n",p);
		return p;
	}
	return NULL;
}






