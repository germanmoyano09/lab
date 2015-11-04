#include "http_worker.h"

int create_socket(char *puerto, int opt, int optlen){

	struct addrinfo hints, *result, *res;
	int sfd;

	memset(&hints,0,sizeof (struct addrinfo));
	
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;


	if (getaddrinfo(NULL,puerto,&hints,&result) != 0) {
		perror("getaddrinfo() error.");
		exit(EXIT_FAILURE);
	}

	for(res=result;res!=NULL;res=res->ai_next){
		sfd = socket (res->ai_family, res->ai_socktype, res->ai_protocol);	
		if (sfd < 0)
			continue;

		setsockopt(sfd, SOL_SOCKET, SO_REUSEADDR, &opt, optlen);

		if (bind(sfd,res->ai_addr, res->ai_addrlen) != 0){
			perror ("Error en bind (getaddrinfo)\n");
			return -1;
		}		
	}
			

	if (listen (sfd,10) < 0){
		perror("Error en listen (getaddrinfo)");
		return -1;
	}

	freeaddrinfo(res);
	
	return sfd;

} 