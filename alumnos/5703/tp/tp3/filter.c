#include "editMessage.h"

char * replace_filter(char *message, char *filter, char *replace){
	char *buffer;
  	char *p;
	
	if(!(p = strstr(message, filter)))
		return message;
	
	buffer = (char*)malloc(strlen(message)+strlen(replace)-strlen(filter));

	strncpy(buffer, message, p-message);

	sprintf(buffer+(p-message), "%s%s", replace, p+strlen(filter));

	return replace_filter(buffer, filter, replace);
	
}
