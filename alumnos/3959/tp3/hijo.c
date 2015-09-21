#include <semaphore.h>
#include "func.h"
#include "hijo.h"
#include "srch.h"

int hijo(char * input, sem_t * sp, char * words, sem_t * sp_c){
	int val;
	for(val=-1 ;val<1 ;sem_getvalue(sp_c,&val)){
		sem_wait(sp);
		srch(input,words);
		sem_post(sp_c);
		sem_wait(sp);
	}
	return 0;
}
