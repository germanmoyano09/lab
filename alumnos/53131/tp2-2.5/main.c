#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "hijo.h"
#include "pipes.h" 

#define WR 1
#define RD 0

int main (int argc, char **argv)
{
    char buff [1000], c, *d;
    int leido,leido2, id,status, fp;
    make_pipes();  

    switch(id=fork()){ //creo el hijo.
        case 0:
             hijo ();
             return 0;
        break;
        case -1:
            perror ("Error al crear P_hijo: ");
            return 1;
        default:        
                close (p_PH[RD]);
                close (p_HP[WR]);
                
                while ((c= getopt (argc, argv, "p")) != -1){
                    leido=read (0, buff, sizeof (buff));
                    if (c=='p')
                        {   
                            d=strtok (argv[2], ",");
                            fp=open("./palabras.txt",O_RDWR| O_CREAT, 0777);
                            while (d!=NULL){
                                lseek(fp, 0, SEEK_END);
                                write (fp,d, strlen(d));
                                write (fp, "\n", 1);                                  
                                d=strtok (NULL, ",");
                            } 
                        }
                } 
         
                if (optind == 1){ 
                    printf ("No hay argumento\n");           
                    return 0;
                    }
                write (p_PH[WR], buff, leido);
                wait (&status);
                leido2=read (p_HP[RD], buff, leido); 
                write (1, buff, leido2);  
                write (1, "\n", 1);                                  
                
        break;
        } 
    return 0;
     
}

      

  
 
      
