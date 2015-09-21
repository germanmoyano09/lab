#include "hijo.h"

int main(int argc, char *const argv[]){
	
	int pah[2];
	int hap[2];
	ssize_t leido, escrito;
	char buffer[512];
	memset(buffer, '\0', 512);
	char *salida;
	
	salida = argv[1];
	
	pipe(pah);
	pipe(hap);
	
	int pid = fork();
	if(pid == 0){	
		close (pah[1]);
		close (hap[0]);
		hijo(pah[0], hap[1]);
		return 0;
	}
	
	while((leido = read(STDIN_FILENO, buffer, sizeof buffer))>0){
		if (leido < 0){
			perror("error en read()\n");
			return -1;
		}
		
		escrito = write(pah[1], buffer, sizeof buffer);
		if (escrito < 0){
			perror("error en escrito1()\n");
			return -1;
		}
	
		leido = read (hap[0],buffer, sizeof buffer);
		write(1, buffer, leido);
	}
	
    //printf("La Frase es: %s\n", frase2);
	close(pah[0]);
	close(hap[1]);    
    
	return 0;
}