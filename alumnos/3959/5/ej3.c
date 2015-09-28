//@anaquinpm

#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

const static int MAX_TH=4;
static int nro=0;	//variable global para los threads
			//otra opción sería utilizar malloc para alocar punteros al HEAP
static pthread_mutex_t mtx= PTHREAD_MUTEX_INITIALIZER;

void * threadFunc(void *arg){
	if((pthread_mutex_lock(&mtx))!=0) perror ("MUTEX LOCK FAIL");
	printf ("threadID:  %u\n",*(unsigned int*)arg);
	nro+=1;
	if((pthread_mutex_unlock(&mtx))!=0) perror ("MUTEX UNLOCK FAIL");
	pthread_exit(NULL);
}

int main(int argc, char *argv[]){
	int i = MAX_TH;
	pthread_t th_id[MAX_TH];
	
	printf("mainThId: %u\n",(unsigned int)pthread_self()); //ID del hilo "main" 
	
	while (i--) {
//		cada vez que creamos un thread, se guarda un id único en el arreglo de "th_id" que recorremos con la var "i",
//		Los th_id lo utilizamos en  pthread_join() para esperar que terminen todos lo hilos lanzados.
		if (pthread_create(&th_id[i], NULL, threadFunc,(void *)&th_id[i]) != 0) {
			perror("pthread_create()");
			return -1;
		}
	}
	for (i = 0; i < MAX_TH; i++) {
		pthread_join(th_id[i], NULL);
	}
	printf ("Var Global 'nro':  %d\n",nro);
	pthread_exit(NULL);
	return 0;
}

