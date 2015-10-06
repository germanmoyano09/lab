#include "http_worker.h"

void http_worker(int sd_conn, struct sockaddr * cli_addr, char *ruta){
	int leido;
	char buff[BUFF];
	long longitud;

	char *nombre_archivo = NULL;
	char *extension;
	char *tipo_archivo;

	int fd1;
	int leido2;
	char buff2[BUFF];

	if (( leido = read(sd_conn, buff, sizeof(buff))) > 0 ) {
			
		printf ("-----------------------------------------------------------\n");
		printf ("%s\n",buff);
		printf ("-----------------------------------------------------------\n");
		
		nombre_archivo = getNombre(buff);
		printf("Archivo   : %s\n", nombre_archivo);

		extension = getExtension(nombre_archivo);
		printf("Extension : %s\n", extension );

		tipo_archivo = getTipo(extension);
		printf("Mime type : %s\n", tipo_archivo);

		printf("=============================================================\n");		
		printf("=============================================================\n");

		strcat(ruta,nombre_archivo);

		if ((fd1 = open( ruta, O_RDONLY)) != -1){
			while ((leido2 = read(fd1, buff2, sizeof(buff2))) > 0){
				longitud = longitud + leido2;
			}	
			close (fd1);
		}
	}

	char *estado=NULL;
	int fd;
	int leido3;
	char cabecera[BUFF];
	char *version = "HTTP/1.1";
	char buffer2[BUFF];
	
	if (( strncmp("error", tipo_archivo, 4)) == 0 ){
		estado = "500 Extension de archivo no reconocida\n";
		write(sd_conn, estado, strlen(estado));
	} else if (( fd = open( ruta, O_RDONLY)) < 0){
		estado = "404 NOT FOUND\n";
		write(sd_conn, estado, strlen(estado));
	} 
	else {
		estado = "200 OK";

		leido3 = snprintf(cabecera, sizeof cabecera, "%s %s\nContent-Length: %ld\nContent-Type: %s\n\n", version, estado, longitud, tipo_archivo);
		write(sd_conn, cabecera, leido3);

		while((leido3 = read(fd, buffer2, sizeof buffer2)) > 0){
			write(sd_conn, buffer2, leido3);
			memset(buffer2, 0, sizeof buffer2);
		}
			
	}
	
	close(fd);
	close(sd_conn);
}