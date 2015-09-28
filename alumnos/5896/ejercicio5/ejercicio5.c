#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/types.h>

int global=0;
void * saludo(void * nro){
	int n = *(int *)nro;
	printf("Hola mundo, soy el hilo nro %d\n",n);
	global = global + 10;	
	printf(" global %d\n",global);
	pthread_exit(NULL);
}
#define MAX_TH 4

int main() {
	printf("Soy  main y mi pid es %d\n", getpid());
	printf(" variable global antes de ejecucion de hilos %d\n",global);
	

	pthread_t tid[MAX_TH];
	int t[5],i;
	for (i=0; i < MAX_TH; i++){
		t[i]= i;
		pthread_create(&(tid[i]) ,NULL, saludo ,(void *)&(t[i]));
	}

	for (i=0; i < MAX_TH; i++){
		pthread_join(tid[i] , NULL );
	}

	
	printf("Soy  main y mi pid es %d\n", getpid());
	printf(" variable global despues de ejecucion de hilos %d\n",global);
	pthread_exit(NULL);
	return 0;
}
/*La funcion pthread_create para pasar argumentos a los hilos, ese necesario que sea 
puntero void. Por eso se nesecita realizar un casteo y utilizar la dirección de memora de la variable i.
Un puntero a void tiene la ventaja  de poder apuntar a cualquier otro tipo de puntero.
Utilizando casteo en los hilos logramos que apunte a una variable int. Siendo así el ID de cada hilo.*/ 
