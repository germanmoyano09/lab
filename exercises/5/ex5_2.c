#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/syscall.h>


int var = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

pid_t gettid(void) {

    return syscall(SYS_gettid);

}

void * hilo(void *arg) {
    printf("soy el hilo %d, la variables es %d \n", gettid(), var);
    pthread_mutex_lock(&mutex);
    var++;
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

#define MAX_TH 4

int main(int argc, char **argv) {
    
    pthread_t tid[MAX_TH];
    int i = MAX_TH;

    printf("soy el hilo de main mi pid es %d\n", getpid());

    while (i--) {

        if (pthread_create(&tid[i], NULL, hilo, NULL)) {
            perror("pthread_create()");
            return -1;
        }
    }

    for (i = 0; i < MAX_TH; i++) {
        pthread_join(tid[i], NULL);
    }

    printf("La variable sumada es: %d \n", var);
    pthread_exit(NULL);
    return 0;
}
