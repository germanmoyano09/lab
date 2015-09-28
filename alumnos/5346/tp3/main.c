#include "filtrado.h"

int main(int argc, char **argv){
	
	int c, i, escrito;
	struct memoria* ptr;
	
	ptr = (struct memoria *) mmap(NULL, sizeof ptr, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANON, -1,0);
		
	if(*(char*)ptr == -1){
		perror("mmap");
		return -1;
	}
	
	ptr->texto[0] = '\0';
	
	while((c=getopt(argc,argv,"p")) != -1){
		switch(c){
			case 'p':
				
				for(i=0;i<argc;i++){
					if(strstr(argv[i],"-p")){
						
						strcat(ptr->texto,argv[i+1]);
					}		
				}
			break;		
		}
	}	
	
	//strcat(ptr->texto,argv[1]);
	
	if (sem_init(&(ptr->semaforo), 1, 0) < 0){
		perror("sem");
		return -1;
	}

	switch(fork()) {
		case 0://hijo
			//sem_wait(&(ptr->semaforo));

			filtrado(ptr);	
			
			sem_post(&(ptr->semaforo));
			return 0;
		case -1: //err
			perror("fork()");
			return -1;
		
		default: // padre	
		break;
	
	}
	//printf("%s\n", ptr->texto);

	//wait(NULL);// espera q terminen los demas procesos en este caso el proceso hijo
	
	sem_wait(&(ptr->semaforo));
	
	//printf("%s\n", ptr->texto);
	escrito = write(STDOUT_FILENO, ptr->texto, 512);
	if (escrito < 0 ){
		perror ("escrito");
		return -1;
	}

	sem_post(&(ptr->semaforo));
	return 0;
}
