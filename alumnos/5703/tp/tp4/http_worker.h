#ifndef _HTTP_WORKER_H_
	#define _HTTP_WORKER_H_
	
	#include <signal.h>
	#include <string.h>
	#include <stdlib.h>
	#include <unistd.h>
	#include <stdio.h>
	#include <sys/socket.h>
	#include <netinet/in.h>
	#include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>

	#define BUFF 2048

	void http_worker(int sd_connm, struct sockaddr * cli_addr, char *ruta);
	
	void getRuta(char **ruta);

	char *getNombre(char *buff);
	
	char *getExtension(char *nombre_archivo );
	
	char *getTipo(char *extension );


#endif	