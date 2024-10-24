#include <stdio.h>
#include <stdlib.h>
#include "idManager.h"

int main(void) {
	
	short usuario, pelicula, funcion;
	
	usuario = idGenerator(USUARIO_CODE);
	pelicula = idGenerator(PELICULA_CODE);
	funcion = idGenerator(FUNCION_CODE);
	
	printf("Usuario id nro: %hd\n pelicula id: %hd\n funcion id: %hd\n", usuario, pelicula, funcion);
	
	return 0;
}


