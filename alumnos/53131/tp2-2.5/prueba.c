#include <stdio.h>
#include <stdlib.h>
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
int main (int argc, char**argv){
	char buff [150], c;
	int l, fp, i=0;
	//l=read (0, buff, sizeof (buff));
	//write (1, buff, l);
	
    while ((c= getopt (argc, argv, "p:")) != -1){
                   
        l=read (0, buff, sizeof (buff));
        
        if (c=='p')
            {   
             fp=open("./palabras.txt",O_RDWR| O_CREAT | O_TRUNC, 0777);
            printf ("%s\n", argv[i+1]);
                while (argv[i+2]!=NULL){
                        lseek (fp, 0, SEEK_END); 
                        write (fp, argv[i+2],15 );
                        i=i+1; 
                            } 
            }
                }                                      

    return 0;

}
