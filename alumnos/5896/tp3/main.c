#include <semaphore.h>
#include <wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include "parser.h"
#include "hijo.h"

int main(int argc, char **argv)
{
	char mensaje[100],buff[100];
	//	char *orgmensaje;
	int pid;
	int leido;
	int fd, fdo;
	int operacion;
	extern char *optarg;
	extern int optind, opterr, optopt;
	void *psem;
	leido=0;
	operacion=0;
	char *orgmensaje;
	sem_t *semaforo;
	char *msgfiltrado;
	psem = mmap(NULL,sizeof(sem_t), PROT_READ | PROT_WRITE, 
			MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	semaforo=(sem_t*)psem;
	while((operacion = getopt( argc, argv, "p")) >= 0){
		switch (operacion){
			case 'p':
				palabra1f = palabras(argv[2],1); 
				palabra2f = palabras(argv[2],2);      
				palabra3f = palabras(argv[2],3);      
				break;
		}	
	}
	//texto utilizado para mapear a memoria compartida
	fd = open("salida.txt",O_RDWR|O_CREAT,0777);
	if(fd<0){       
		perror("open()");
		return -1;
	}
	while(
			(leido=read(STDIN_FILENO,buff,sizeof buff)) > 0){	
		write(fd,buff,leido);
	}
	fdo=open("salida.txt", O_RDWR);
	sem_init(semaforo,1,1);
	sem_wait(semaforo);
	while(
			(leido= read(fdo,mensaje,sizeof mensaje)) > 0){
		//mapeo el archivo a memoria
		//	sem_init(semaforo,1,1);
		//	sem_wait(semaforo);
		orgmensaje=mmap(NULL, 1024, PROT_READ | PROT_WRITE, MAP_SHARED, fdo, 0);
		//	sem_post(semaforo);
	}
	//hijo
	pid = fork();
	if(pid == 0){
		sem_wait(semaforo);
		//memset(filtrado, 0, sizeof filtrado);
		//strcpy(mensajeafiltrar,orgmensaje);
		msgfiltrado = hijo(orgmensaje);
		strcpy(orgmensaje,msgfiltrado);
		sem_post(semaforo);
		return 0;
	}

	sem_post(semaforo);
	wait(NULL);
	printf("soy el padre %d y el mensaje filtrado es el sigiente:\n\n%s\n\n",getpid(),orgmensaje);
	return 0;
}




