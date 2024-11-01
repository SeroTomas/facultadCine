#include <stdio.h>
#include <stdlib.h>

#include "film.h"

int main(void) {
	
	FilmList *peliculas = NULL;
	
	peliculas = getAllFilms();
	
	renderFilms(peliculas);
	
	return 0;
}
