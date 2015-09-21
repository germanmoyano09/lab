#include <ctype.h>
#include "funciones.h"

char *rot13(char *s){
	char *p=s;
	int upper;
	while(*p){
		upper = toupper(*p);
		if(upper>='A' && upper<='M') 
			*p+=13;
		else if(upper>='N' && upper<='Z')
			*p-=13;	
		++p;
	}
	return s;
}
