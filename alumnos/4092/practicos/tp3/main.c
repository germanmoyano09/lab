#include "funciones.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <string.h>
#include <semaphore.h>

int main(int argc, char **argv){
	char *ptr;
	sem_t *sem1=NULL, *sem2=NULL;
	ptr = mmap(NULL,  sizeof(char) * 2048, PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS,-1,0);
	sem1 = mmap(NULL, sizeof(sem_t), PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS,-1,0);
	sem2 = mmap(NULL, sizeof(sem_t), PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS,-1,0);
//	sem = (sem_t *)ptr + sizeof(char) * 1024;
	sem_init(sem1,1,0);
	sem_init(sem2,1,0);	
    	switch (fork()) {
    		case 0: // hijo
			sem_wait(sem1);
			hijo(ptr,argc, argv);       
			sem_post(sem2); 
        		return 0;      
    		case -1: // error
        		perror("fork(): ");
        		return -1;
    		default: // padre
        		break;
    	}
	memset(ptr, 0, sizeof(char) * 2048);
	read(0, ptr, sizeof(char) * 2048);
	sem_post(sem1);
	sem_wait(sem2);
	write(1, ptr, sizeof(char) * 2048);	
	return 0;
}

