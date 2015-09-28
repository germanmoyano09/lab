#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "http_worker.h"


int main(int argc, char * const *argv)
{
	int sd, sd_conn;
	int opt = 1, optlen = sizeof(opt);
	socklen_t addrlen;
	struct sockaddr_in srv_addr;
	struct sockaddr_in cli_addr;

    /* TODO: agregar creación y configuración del socket */

	while( (sd_conn = accept(sd, (struct sockaddr *) &cli_addr, &addrlen)) > 0) {
		switch (fork()) {
			case 0: // hijo
				http_worker(sd_conn, (struct sockaddr *) &cli_addr);
				return 0;

			case -1: // error
				break;

			default: // padre
				break;
		}
	}

	return 0;
}

