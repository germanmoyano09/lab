#include "http_worker.h"

void getRuta(char **ruta){
    *ruta = malloc( sizeof( char) * strlen( optarg ));
    strcpy( *ruta, optarg);
}