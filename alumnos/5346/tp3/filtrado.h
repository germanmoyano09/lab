#include <sys/mman.h>
#include <string.h> 
#include <sys/wait.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#ifndef _FILTRADO_H_
	#define _FILTRADO_H_

	typedef struct memoria{
		char texto[512];
		sem_t semaforo;
	}memoria;

	int filtrado(memoria*);
#endif