#include "http_worker.h"

int main(int argc, char * const *argv){
	int sd, sd_conn;
	int opt = 1, optlen = sizeof(opt); 
	socklen_t addrlen;
	struct sockaddr_in srv_addr;
	struct sockaddr_in cli_addr;

	int i;

	int option;
	char *ruta = NULL;
	char *noComan;
	char *noArg;

	signal(SIGCHLD,SIG_IGN);

    sd = socket(AF_INET, SOCK_STREAM, 0);

    srv_addr.sin_family = AF_INET;
	srv_addr.sin_port = htons(2020);
	srv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	
	setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, &opt, optlen);

	addrlen = sizeof srv_addr;
	
	if (bind(sd, (const struct sockaddr *) &srv_addr, addrlen) < 0){
		perror("bind()");
		return 1;
	}
	if (listen(sd, 10) < 0) {
		perror("listen()");
		return 1;
	}


	if(argc < 2){
        noArg = "Ingrese la ruta de los archivos.\n";
        write(STDOUT_FILENO, noArg, strlen(noArg));
        return -1;
    }

    
	while ((option = getopt(argc, argv, "d:")) >= 0 ){ //Manejo argumentos
		switch (option){
            case 'd': //ruta de los archivos
				getRuta(&ruta);
				break;

			case '?':
				if (optopt != 'd'){
					noComan = "poneeee -d adelante!!!!!\n";
					write(STDERR_FILENO, noComan, strlen(noComan));
					return -1;
				}

		    default: //mensaje de error si ingresa otro comando
				noComan = "No se reconoce el comando, por favor ejecuta ./tp4 -d <document_root>\n";
				write(STDERR_FILENO, noComan, strlen(noComan));
				return -1;
		}
	}
	
	//printf("optind: %d\n", optind);
	//printf("argc  : %d\n", argc);
	
	for (i = optind; i < argc; i++){
    	printf ("Ingrese -d y la ruta del archivo %s\n", argv[i]);
  		return -1;
	}


	while( (sd_conn = accept(sd, (struct sockaddr *) &cli_addr, &addrlen)) > 0) {
		switch (fork()) {
			case 0: // hijo
				http_worker(sd_conn, (struct sockaddr *) &cli_addr, ruta);
				return 0;

			case -1: // error
				break;

			default: // padre
				break;
		}
		close(sd_conn);
	}

	return 0;
}