#ifndef _MAIN_H_
	#define _MAIN_H_

	#include <unistd.h>
	#include <stdio.h>
	#include <semaphore.h>
	#include <sys/mman.h>
	#include <string.h>
	#include <sys/types.h>
        #include <sys/wait.h>	

	char * replace_filter(char *message, char *filter, char *replace);

#endif	
