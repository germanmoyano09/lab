#include <ctype.h>
#include "funciones.h"

void rot13(char *s){
	char *p=s;
//	int upper;
	while(*p){
	//	upper = toupper(*p);
//		write(1, p,1);
		if(*p>='A' && *p<='M') 
			*p+=13;
		else if(*p>='N' && *p<='Z')
			*p-=13;	
		else if(*p>='a' && *p<='m')
			*p+=13;	
		else if(*p>='n' && *p<='z')
			*p-=13;	
//		write(1, p,1);
		++p;
	}
//	return s;
}
