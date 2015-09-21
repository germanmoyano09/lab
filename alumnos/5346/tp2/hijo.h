#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <ctype.h>
#include <signal.h>

#ifndef _HIJO_H_
     #define _HIJO_H_

	ssize_t escrito_pipe, escrito_pipe2, leido_pipe;
	char bufferMayuscula[512];
	int pah;
	int hap;
		
  int hijo(int, int);
  void mayuscula(int signum);

#endif
