#include "parser.h"
#include "hijo.h"

char *hijo(char *shm_dir){
	char mensajeafiltrar[1024];
	char filtrado[1024];
	//char palabra[1024]="hola";
	char *token;
	int m,n,p;//,i;

	memset(filtrado, 0, sizeof filtrado);
	//char palabra[1024]="hola";
	strcpy(mensajeafiltrar,shm_dir);

	//empieza el filtrado
	token = strtok(mensajeafiltrar, " \t");
	m = strcmp(token,palabra1f);
	n = strcmp(token,palabra2f);
	p = strcmp(token,palabra3f);
	if (m==0 || n==0 || p==0) {
		token="****";
	}  
	strcat(filtrado,token);
	strcat(filtrado," ");
	while( (token = strtok( NULL, " \t" )) != NULL ){
		m = strcmp(token,palabra1f);
		n = strcmp(token,palabra2f);
		p = strcmp(token,palabra3f);
		if (m==0 || n==0 || p==0){
			token="****";
		}
		strcat(filtrado,token);
		strcat(filtrado," ");
	}
	char *pfiltrado=filtrado;
	printf("soy %d  hijo de %d  mostrando el mensaje original:\n\n%s\n\n",getpid(),getppid(),shm_dir);
	//	printf("%s soy el hijo %d de %d \n",filtrado,getpid(),getppid());
	//	printf("%s soy el hijo %d de %d a travez del puntero \n",pfiltrado,getpid(),getppid());

	//sobrescribo el mensaje filtrado a la memoria compartida
	//strcpy(orgmensaje,pfiltrado);	

	return pfiltrado; 




}
