#include "func.h"

int srch(char *input, int fd_o){
	char *str1;				//puntero para el TOKEN
	int i,pt=0,chk=0;
	char out_buff[1024]; 			//buffer de la salida filtrada
        char *palabras[]={"hola","como"};	//palabras a buscar
	char point[1024];			//para recobrar separadores
	char relleno[20];

	memset(out_buff,0,sizeof out_buff);
	memset(point,0,sizeof point);
	memset(relleno,'*',sizeof relleno);
	strcpy(&point[0],input);		//input se destruye cuando para por strtok, asi que la copio

	for(str1=strtok(input," \n\t,.");str1!=NULL;str1=strtok(NULL," \n\t,."),chk=0){ 	//en strtok el 2° argumento son los delimitadores
		for(i=0;i<2;i++){
			if(((strcmp(str1,palabras[i]))==0)&&chk==0){	//comparo cada palabra para ver si las imprimo
			//	printf("palabra filtrada:%s\n",palabras[i]);
				chk=1;

			}
		}
		for( ;str1[0]!=point[pt];pt++){				//for para recobrar el separador de la cadena original
			strncat(out_buff,&point[pt],1);			
		}
		pt=pt+(strlen(str1));					//puntero para dejar marcado el siguiente separador
			
		if(chk!=1){strcat(out_buff,str1);}			//si no esta filtrada la agrego al buff de salida
		else {strncat(out_buff,relleno,strlen(str1));}
	}
	write (fd_o,out_buff,sizeof out_buff);
	return 0;
}
