#include "nieto.h"
#include "hijo.h"
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
		//	printf (" palabra1 de la funcion palabras: %s \n",p);
		return p;
	}
	if(cont==2){
		p=palabra2;
		//	printf (" palabra2 de la funcion palabras: %s \n",p);
		return p;
	}
	if(cont==3){
		p=palabra3;
		//	printf (" palabra3 de la funcion palabras: %s \n",p);
		return p;
	}
	return NULL;
}






void filtrar()
{
	//	printf (" palabra1: %s \n",palabra1f); 
	//	printf (" palabra2: %s \n",palabra2f);
	//	printf (" palabra3: %s \n",palabra3f);

	int m,n,p;
	char filtrado[1024];
	char *token;
	memset(filtrado, 0, sizeof filtrado);

	token = strtok(buff, " \n\t");
	m = strcmp(token,palabra1f);
	n = strcmp(token,palabra2f);
	p = strcmp(token,palabra3f);
	if (m==0 || n==0 || p==0) {
		token="****";
	}
	strcat(filtrado,token);
	strcat(filtrado," ");
	while( (token = strtok( NULL, " \n\t" )) != NULL ){
		m = strcmp(token,palabra1f);
		n = strcmp(token,palabra2f);
		p = strcmp(token,palabra3f);
		if (m==0 || n==0 || p==0){
			token="****";
		}
		strcat(filtrado,token);
		strcat(filtrado," ");
	}




	write(hap[PIPE_WR],filtrado,strlen(filtrado));//envio al abuelo
	close(han[PIPE_RD]);
	close(hap[PIPE_WR]);

}

void ROT13(){
	//fin de aplicado de ROT13 y enviando al padre
	int c;
	int e;
	int j;
	for (j = 0;j<leido;j++){
		c=buff[j];

		{
			if(c >='A' && c <='Z')
			{
				if((e = c + 13) <= 'Z')
					buff[j]=e;
				else
				{
					e = c - 13;
					buff[j]=e;
				}
			}
			else if(c >='a' && c <='z')
			{
				if((e= c + 13) <= 'z')
					buff[j]=e;
				else
				{
					e = c - 13;
					buff[j]=e;
				}
			}
			else
				buff[j]=c;
		}
	}


	write(hap[PIPE_WR],buff,leido);//envio al padre

	close(hap[PIPE_WR]);
	close(pah[PIPE_RD]);


}
