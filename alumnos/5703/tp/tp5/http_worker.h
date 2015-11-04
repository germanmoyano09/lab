#ifndef _HTTP_WORKER_H_
#define _HTTP_WORKER_H_
	
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <pthread.h>

	#define BUFF 2048

	char *ruta;

	void *http_worker(void *sd_conn);
	
	void getRuta(char **ruta);

	char *getNombre(char *buff);
	
	char *getExtension(char *nombre_archivo );
	
	char *getTipo(char *extension );

	int create_socket(char *puerto,int opt,int optlen);

#endif	