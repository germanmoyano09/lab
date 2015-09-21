#include <unistd.h>
#include <sys/mman.h>
#include <string.h>
#include "func.h"
#include "srch.h"

int srch(char * input, char * words){		//input es el *dato
	char *str1;				//puntero para el TOKEN
	int i,pt=0,chk=0;
        char *palabras[10];
	char relleno[]="********************";			//asteriscos
	int n_palabras=0;
	char point[BUF_SIZE];			//para recobrar separadores
	char out_buff[BUF_SIZE]; 		//buffer de la salida filtrada
	char cp_words[256];

	memset(out_buff,0,sizeof out_buff);
	memset(point,0,sizeof point);
	memset(cp_words,0,sizeof cp_words);
	strcpy(&point[0],input);			//input se destruye cuando pasa por strtok, asi que la copio
	strcpy(&cp_words[0],words);
	


	for(i=0,str1=strtok(cp_words,",");str1!=NULL;str1=strtok(NULL,","),i++){	//parseo las palabras a filtrar
		palabras[i]=str1;
	}
	n_palabras=i; 					//guardo las cantidad de palabras a filtrar

	for(str1=strtok(input," \n\t,.");str1!=NULL;str1=strtok(NULL," \n\t,."),chk=0){ //strtok el 2° arg son delimitadores
		for(i=0;i<n_palabras;i++){
			if(((strcmp(str1,palabras[i]))==0)&&chk==0){		//comparo cada palabra para ver si las imprimo
				chk=1;
			}
		}
		for( ;str1[0]!=point[pt];pt++){				//for para recobrar el separador de la cadena original
			strncat(out_buff,&point[pt],1);			
		}
		pt=pt+(strlen(str1));					//puntero para dejar marcado el siguiente separador
			
		if(chk!=1){ strcat(out_buff,str1); }			//si no esta filtrada la agrego al buff de salida
		else { strncat(out_buff,relleno,strlen(str1)); }	//agrego asteriscos para remplazar la palabra

	}
	strcpy(input,out_buff);
	msync(input,strlen(input), MS_ASYNC);
 	return 0;
}
