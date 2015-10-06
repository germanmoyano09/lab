#include "http_worker.h"

char *getTipo(char *extension ){
	char *ext=NULL;

	if (( strncmp("html", extension, 4)) == 0 ){
		ext = "text/html";
	}
	else if ((strncmp("txt", extension, 3)) == 0){
		ext = "text/plain";
	}	
	else if ((strncmp("jpeg", extension, 4)) == 0){
		ext = "image/jpeg";
	}
	else if ((strncmp("jpg", extension,3))==0){
		ext = "image/jpg";
	}	
	else if ((strncmp("png", extension,3))==0){
		ext = "image/png";
	}
	else if ((strncmp("pdf", extension,3))==0){
		ext = "application/pdf";
	}else{
		ext = "error";
	}
		
	return ext;
}