#ifndef _PADRE_H_
#define _PADRE_H_

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <sys/types.h>
	#include <ctype.h>
	#include <unistd.h>
	#include <sys/stat.h>
	#include <fcntl.h>
	#include <errno.h>
	#include <sys/wait.h>
	#include <semaphore.h>
	#include <sys/mman.h>
	
		
		void funcionPadre(char *mem_buff,void *semaforo);
		
				
		
  
#endif
