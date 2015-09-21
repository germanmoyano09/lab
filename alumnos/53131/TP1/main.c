#include "filtrar.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

int main (int argc, char **argv){
      int tm, index;
      char c;
      char error[37]="La opción -o requiere un argumento\n";
      char error2[26]="Esa opción no es válida\n";

      tm=leer();
       
      while ((c= getopt (argc, argv, "ho:")) != -1){
            switch (c)
            {
                case 'h':
                    printf ("Ayuda: \n");
                    return 0;
                break;
                case 'o':
                    filtro (tm, 2, optarg);
                    return 0;
                break;
                case '?':
                    if (optopt == 'o'){
                          write (2, error, sizeof (error));} 
                        else if ( isprint (optopt)){
                            write (2, error2, sizeof (error2));}
                         else{
                             write (2, error2, sizeof (error2));}
                    return -1;
                break;
                
            
            }   
      
      }                                 
         
         
      if (optind==argc==1)
        {
           filtro (tm, 1, "");
           return 0;
        }
     for (index = optind; index < argc; index++)
         printf ("Argumento no váido %s\n", argv[index]);
  
 
      
      
      
      }



