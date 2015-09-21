#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <ctype.h>
#include "hijo.h"
#include "pipes.h"
#include "nieto.h"
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>


#define WR 1
#define RD 0 


void nieto ()
{


    close (p_PH[WR]);
    close (p_HP[RD]);

    int leido=0, fp, cont=0;
    char ch[1000];
    char new[50];
    char new2[5]="?????";
    char *st=malloc (1000);
    FILE* fs;

    fp=open("./palabras.txt",O_RDWR| O_CREAT, 0777);

    fs=fdopen (fp, "r");   
   
    leido=read (p_PH[RD], ch, sizeof (ch));
    st=ch;
    
     while (fscanf (fs, "%s", new)==1){           
            
            st=repl_str (st, new, new2);
            cont=cont+1; 
     }  
     
    write (p_HP[WR], st, (leido+(cont*5))); 
    fclose (fs);
    free (st);
}
  
