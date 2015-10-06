#ifndef _MAIN_H_
	#define _MAIN_H_

	#include <unistd.h>
	#include <stdio.h>
	#include <semaphore.h>
	#include <sys/mman.h>
	#include <string.h>
	#include <sys/types.h>
    #include <sys/wait.h>	
	
	#define MAX 5120	

	char * replace_filter(char *message, char *filter, char *replace);

	typedef struct {
	    char buf_est[MAX];
	    sem_t ph;
	    sem_t hp;
	}tp3;

#endif	
