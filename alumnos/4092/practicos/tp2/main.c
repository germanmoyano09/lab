#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"

int main(int argc, char **argv){
	int leido,pdesc1[2],pdesc2[2];
	char buff[10000];
	if(pipe(pdesc1) < 0){
		perror("pipe1()");
		return -1;
	}
	if(pipe(pdesc2) < 0){
		perror("pipe2()");
		return -1;
	}
	switch (fork()){
		case 0:
			hijo(pdesc1,pdesc2, argc, argv);
			return 0;
		case -1:
			perror("fork()");
			return -1;
		default:
			break;
	}
	close(pdesc1[0]);
	close(pdesc2[1]);
	memset(buff, 0, sizeof buff); 
	leido = read(0, buff, sizeof buff);
		write(pdesc1[1], buff, leido);
		leido = read(pdesc2[0], buff, sizeof buff);
		write(1, buff, leido);
	
	close (pdesc1[1]);
	return 0;
}
