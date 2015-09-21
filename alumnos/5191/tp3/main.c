#include "palabras.h"
#include "padre.h"
#include "hijo.h"


int main(int argc, char **argv){
    
    int opcion; 

    char *palabras = NULL;
            
    //char *ptr1 = NULL;
    void *ptr1 = NULL;
    char *mem_buff;

    sem_t *semaforo1;
    
    
    int memsize = (sizeof(char *) * 1024) + sizeof(sem_t);

    ptr1 = mmap (NULL, memsize, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    //ptr1 = (char *) mmap (NULL, memsize, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
        
    //printf("posicion de memoria ptr1: %p \n", ptr1);
   
    if (*(char *) ptr1  == -1){
        perror ("Error en mmap ptr1\n");
        return -1;
    }

    mem_buff = (char *)(ptr1 + sizeof(sem_t));
    
    semaforo1 = (sem_t *)ptr1;

    //printf("semaforo 1: %p \n", (sem_t *) semaforo1);

    if (sem_init(semaforo1, 1 , 0) < 0){
        perror ("semaforo 1");
        return -1;
    };

   
    while ((opcion = getopt (argc,argv, "p:")) != -1){
        switch (opcion){
            case 'p':
                obtenerPalabras(&palabras);
                break;
        }
    } // fin while
  
        switch(fork()){
            case -1: // error fork
                perror("Error en la creacion de fork(hijo)");
                return -1;

            case 0: // proceso hijo
                
                sem_wait(semaforo1);   
                printf("mem_buff Hijo %s\n",mem_buff);
            
                funcionHijo(mem_buff,semaforo1,palabras);
               // sem_post(semaforo1);
                return 1;
               
         
            default: // proceso padre
                funcionPadre(mem_buff,semaforo1);
                
      
      } // fin switch    

    return 0;
}

