/**
 * Indique y justifique la cantidad  de procesos creados en el siguiente programa. 
 *
 * ¿Cómo sería la jerarquía de los procesos creados?
 */

/*
    El programa creará 8 procesos, contando el programa mismo. Esto se debe a que cada vez
    que se ejecuta fork(), todos los procesos del programa, y el programa mismo, crean un hijo.
    
    Entonces, si suponemos que el primer proceso creado es el 4915 (el programa), al hacer fork() 
    se crea el proceso 4916; al ejecutar fork() nuevamente, tanto el proceso 4915 como el 4916
    crean un proceso hijo--> el 4917 (hijo de 4916) y el 4919 (hijo de 4916). Así sucede también
    con el tercer fork(), creandose 4 procesos más, uno por cada proceso existente.
    La jerarquía, en este ejemplo, queda de la siguiente manera:
                        4915
             ____________|_________________
            |            |                 |
          4917          4916              4918
                _________|____________
               |         |            |
              4922      4919        4920  
                         |
                        4921
 
 */

#include <stdio.h>
#include <unistd.h>

int main(void)
{
    fork();
    fork();
    fork();
    
    printf(" [x] proceso nro %d y nro %d \n", getpid(), getppid());
    
    sleep(1);

    return 0;



}  




