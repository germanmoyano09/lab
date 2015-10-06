#include "main.h"

int main(int argc, char **argv){
    char *noArg;
    tp3 *mitp3 = NULL; 
    int leido;
    mitp3 = mmap(NULL, sizeof(tp3), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);

    signal(SIGCHLD,SIG_IGN); //si llega señal del hijo lo ignoro 

    if ((sem_init(&(mitp3->ph),1,1) | (sem_init(&(mitp3->hp),1,0))) < 0){  
        perror("sem");
        return -1;
    }
    if(argc < 2){
        noArg = "Ingrese al menos una palabra para filtrar.\n";
        write(STDOUT_FILENO, noArg, strlen(noArg));
        return -1;
    }
    switch (fork()) {
        case 0: // hijo
            while(1){
	            sem_wait(&(mitp3->hp));
	          	char remp[MAX];
	            int re,i;
	           
	            for(i = 1; i < argc; i++){
	                memset(remp,'\0',sizeof(remp));
	                for(re=0; re< strlen(argv[i]) ;re++){
	                    strncat(remp, "*",1);
	                }
	                strcpy(mitp3->buf_est, replace_filter(mitp3->buf_est, argv[i], remp));
	            }    
	            sem_post(&(mitp3->ph)); 
	            //return 0;
	        }
        case -1: // error
            perror("fork(): ");
            return 1;
        default: // padre
            sem_wait(&(mitp3->ph));
              
            while ((leido = read(STDIN_FILENO, mitp3->buf_est , sizeof(mitp3->buf_est))) > 0){
	           
	            sem_post(&(mitp3->hp));
	        
	            sem_wait(&(mitp3->ph));
	                write(STDOUT_FILENO, mitp3->buf_est, sizeof(mitp3->buf_est));
	                memset(mitp3->buf_est,'\0',sizeof(mitp3->buf_est));
	            //sem_post(&(mitp3->hp));
             }

            break;
    }
    return 0;
}
