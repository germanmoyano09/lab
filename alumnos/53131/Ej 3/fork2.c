/**
 * ¿Qué valor tiene la variable "saldo" al finalizar los dos procesos? 
 *
 *      Tendrá el valor 900. 
        

        Al ejecutar la función fork(), ésta devolverá el PID del hijo al padre y un 0 al hijo, como 
 *      se lee en el manual de fork():
 *
 *          "RETURN VALUE
                On success, the PID of the child process is returned in the parent, an
                0  is returned in the child."

        El proceso hijo es idéntico en código y datos del proceso padre, pero los espacios de memoria no son los mismos, por lo que hay aquí en realidad dos 
        variables 'saldo' que son modificadas: la del padre y la del hijo.
        Así, sólo en el proceso hijo se cumplirá la condición del if, y se ejecutará la línea de código 'saldo = saldo + 100' en la variable 'saldo' del hijo.
        La variable 'saldo' del padre se altera en la línea 'saldo=saldo-100', lo que equivale a 1000-100=900. Si mostraramos la variable 'saldo' del hijo antes de
        que finalice (return 0), valdría 1100.
       
 *
 *
 *
 * ¿Depende del orden de ejecución?

        No. La variable 'saldo' del proceso padre será siempre 900, independientemente de si se le restan 100 antes o después del fork(). Esto se debe
        a que el proceso padre no entra en el if, y por ende no le suma 100 a su variable 'saldo'. El proceso hijo sí lo hace, y después finaliza.








*/
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int pid;
    int saldo = 1000;
    
    pid = fork();
    if (pid == 0) {
        saldo = saldo + 100;
        return 0;
    }

    saldo = saldo - 100;   

        

    return 0;
}

