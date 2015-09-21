#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <ctype.h>
#include "hijo.h"
#include "pipes.h"
#include "nieto.h"

 
#define WR 1
#define RD 0
 
void usr1();
void usr2();


void hijo ()
{

    signal (SIGUSR1,usr1); 
    signal (SIGUSR2,usr2);
    
    pause();

    
    
}  
        
void usr2 (){

        int id_nieto, status;
        
        switch (id_nieto=fork()){
            case 0:
                nieto();
                return 0;
            break;
            
            case -1:
                perror ("fork(): ");
            break;
            
            default:    
             
                wait (&status);
                return 0;
                /*   l=read (p_PH[RD], buff, sizeof(buff));
                write (p_HN[WR], buff, l);
                l2=read (p_NH[RD], buff, l); 
                wait (&status);
                write (p_HP[WR], buff, l2);
               */
            break;     
        } 

    } 
void usr1 (){

    
    close (p_PH[WR]);
    close (p_HP[RD]);
    char cadena[1000];
    int i=0, c, l;
     
    l=read (p_PH[RD], cadena, sizeof (cadena));
    
        
        while (cadena[i] != '\0') {        //comienza el bucle para analizar los caracteres de la cadena[] hasta llegar a \0
                c = cadena[i];              //introduce el carácter de la posición actual de la cadena en la variable c
        
                if (c >= 'A' && c < 'N') {                //compara c con A y N
                        cadena[i] = c + 13;               //si es igual o mayor que A y menor que N, se realiza un desplazamiento sumándole 13
                } else if (c >= 'N' && c <= 'Z') {        //compara c con N y Z
                        cadena[i] = c - 13;               //si es igual o mayor que N e igual o menor que Z, se realiza un desplazamiento restándole 13
                } else if (c >= 'a' && c < 'n') {         //compara c con a y n
                        cadena[i] = c + 13;               //si es igual o mayor que a y menor que n, se realiza un desplazamiento sumándole 13
                } else if (c >= 'n' && c <= 'z') {        //compara c con n y z
                        cadena[i] = c - 13;               //si es igual o mayor que n e igual o menor que z, se realiza un desplazamiento restándole 13
                }
 
                i++;        //incrementa la variable i en uno para poder analizar el siguiente carácter
        }
    write (p_HP[WR], cadena, l);
}                                        
    
       

