#include "http_worker.h"

int main(int argc, char * const *argv){
	int sd, sd_conn, i, option;
	int opt = 1, optlen = sizeof(opt); 
	
	socklen_t addrlen;
	struct sockaddr_in cli_addr;
	addrlen = sizeof(cli_addr);

	char *noComan;
	char *noArg;
	char *puerto = "2020";

	pthread_t tid;
	pthread_attr_t atributos;
	pthread_attr_init(&atributos);
	pthread_attr_setdetachstate(&atributos,PTHREAD_CREATE_DETACHED);

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
					noComan = "ponee -d adelante!!!!!\n";
					write(STDERR_FILENO, noComan, strlen(noComan));
					return -1;
				}

		    default: //mensaje de error si ingresa otro comando
				noComan = "No se reconoce el comando, por favor ejecuta ./tp5 -d <document_root>\n";
				write(STDERR_FILENO, noComan, strlen(noComan));
				return -1;
		}
	}
	
	for (i = optind; i < argc; i++){
    	printf ("Ingrese -d y la ruta del archivo %s\n", argv[i]);
  		return -1;
	}

	sd = create_socket(puerto,opt,optlen);

	while( (sd_conn = accept(sd, (struct sockaddr *) &cli_addr, &addrlen)) > 0) {		
		pthread_create(&tid,&atributos, http_worker, (void *)&sd_conn); 
	} 

	close(sd_conn);	

	return 0;
}