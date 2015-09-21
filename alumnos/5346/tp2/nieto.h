#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <ctype.h>
#include <signal.h>

#ifndef _NIETO_H_
     #define _NIETO_H_

	ssize_t escrito_pipe, leido_pipe;
	char bufferHijo[512];
	char bufferMayuscula[512];
	int hap;
	
  int nieto(int, int);
  void manejador(int signum);

#endif