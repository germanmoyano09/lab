/*----------------------------------------------------------
 *
 *  * Ejercicio 1) Remover elementos duplicados y ordenar.
 
 ** Fausto Mazzarella (Computación)

 -----------------------------------------------------------*/

#include <stdio.h>
#include <unistd.h>


#define SIZE 14

int rep (int* sample, int* arreglo_aux);
void ordenar (int* arreglo_aux, int cont);

int main (int argc, char **argv){

    int sample[SIZE]= {0,9,8,2,2,2,5,9,5,0,3,2,3,7}; 
    int arreglo_aux[SIZE]={};
    int m,i,  cont;
    
    cont= rep (&sample[0], &arreglo_aux[0]);
    ordenar (&arreglo_aux[0], cont);


    printf ("Original: ");
    for (i=0; i<SIZE; i++){
        printf ("%d - ", sample[i]);

     }   

    printf ("\n\n");

    printf ("Ordenado y sin repetir: ");
    for (m=0; m<cont; m++){
        printf ("%d - ", arreglo_aux[m]);

     }      
    printf ("\n");
    return 0;    
    

}

/*---------------------------------------------------------------------*/

 int rep (int* sample, int* arreglo_aux){
    int i, j, cont=1,  contb=0; 

    (*arreglo_aux)=(*sample); 
    for (i=1; i<SIZE ; i++) 
    { 
        contb=0;
        for (j=0; j<cont; j++)
            { 
               
                if (*(sample+i)==*(arreglo_aux+j))
                    { 
                       
                       contb=1; 
                    }
            
            }
        if (contb==0)
        {
            *(arreglo_aux+cont)=*(sample+i);
            cont=cont+1;
        
        
        }
        
    }                    

    return cont;


}


 void ordenar (int* arreglo_aux, int cont){
    
     int i, j, aux; 

    
    for (i=0; i<cont ; i++) 
    { 
        
        for (j=i+1; j<(cont); j++)
            { 
               
                if (*(arreglo_aux+i)<*(arreglo_aux+j))
                    { 
                       
                       aux=*(arreglo_aux+i);
                       *(arreglo_aux+i)=*(arreglo_aux+j);
                       *(arreglo_aux+j)=aux;
                    }
            
            }
        
    }                    

    


}
