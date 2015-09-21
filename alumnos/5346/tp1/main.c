#include "head.h"

int main(int argc, char *argv[]){

	char buffer[512];
	int leido;
	char *salida;

	salida = argv[1];
	//memset (salida, "\0", 512);
	
	while ((leido = read(STDIN_FILENO, buffer, sizeof buffer)) >0){
	
		//strtok(buffer,);
	
		filtrado(buffer,salida);
		//write(STDOUT_FILENO, leido2, leido);
	}
return 0;
}
