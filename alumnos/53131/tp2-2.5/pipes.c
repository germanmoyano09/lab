#include "pipes.h"
#include <unistd.h>


int p_HP[2];
int p_PH[2];

void make_pipes(){
    
    pipe(p_PH);
    pipe(p_HP);            
}

