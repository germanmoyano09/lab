#include "main.h"
#include "global.h"

typedef struct {
    char buf_est[MAX];
    sem_t ph;
    sem_t hp;
}tp3;

int main(int argc, char **argv){
    int i;
    char *noArg;
   
    tp3 *mitp3 = NULL; 
    mitp3 = mmap(NULL, sizeof(tp3), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);

    signal(SIGCHLD,SIG_IGN);

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
            sem_wait(&(mitp3->hp));
          
            char remp[100];
            int re;
           
            for(i = 1; i < argc; i++){
                memset(remp,'\0',sizeof(remp));
                for(re=0; re< strlen(argv[i]) ;re++){
                    strcat(remp, "*");
                }
                strcpy(mitp3->buf_est, replace_filter(mitp3->buf_est, argv[i], remp));
            }    
            sem_post(&(mitp3->ph)); 
            return 0;
        case -1: // error
            perror("fork(): ");
            return 1;
        default: // padre
            sem_wait(&(mitp3->ph));
                read(STDIN_FILENO, mitp3->buf_est , sizeof(mitp3->buf_est));
            sem_post(&(mitp3->hp));
        
            sem_wait(&(mitp3->ph));
                write(STDOUT_FILENO, mitp3->buf_est, sizeof(mitp3->buf_est));
            sem_post(&(mitp3->hp));
            break;
    }

    return 0;
}

