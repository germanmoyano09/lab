#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include "filtrar.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void filtro (int tm, int dest, char* destino){
    
    int leido, fd, fdd;
    char ch[100];
    char new[50];
    char new2[7]="???????";
    char *p;
    char *st=malloc (tm);
    char *st_MAY=malloc (tm);
    FILE *fp;

    fp= fopen ("./palabras.txt", "r");             
     
    fd= open ("./temp", O_RDONLY , 0644);
    
    while ((leido=read (fd, ch, sizeof (ch)))>0)
        {
             st=strncat (st, ch, leido);
        }
     while (fscanf (fp, "%s", new)==1)
        {
            st=repl_str (st, new, new2); 
        }
    
    switch (dest)
    {
        case 1:
            printf ("%s", st);
        break;
        
        case 2:
            fdd=open (destino, O_RDWR | O_CREAT | O_TRUNC, 0777);
            lseek (fdd, 0, SEEK_SET); 
            write (fdd, st, tm);
            printf ("Mensaje guardado en %s\n",destino );
            close (fdd);
        break;
    }

    
}
