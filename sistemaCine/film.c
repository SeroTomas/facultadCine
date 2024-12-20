#include <stdio.h>
#include <stdlib.h>
#include "idManager.h"
#include "film.h"

void renderFilms(FilmList *filmList){
	for(short i = 0;i < filmList->total ;i++){
		if(filmList->films[i].status){
			printf("ID: %hu \t", filmList->films[i].id);
			printf("Nombre: %s \t", filmList->films[i].name);
			printf("Genero: %s \t", filmList->films[i].category);
			printf("duracion: %hu miutos \t", filmList->films[i].runningTime);
		}
	}
}

void freeFilmList( FilmList *filmList ) {
	if ( filmList->films ) {
		free( filmList->films );
		filmList->films = NULL;
	}
	
	free( filmList );
	filmList = NULL;
}

FilmList* getAllFilms() {

	FILE* file = fopen( FILM_FILE, "rb" );
	unsigned short amount = 0;
	Film* films = NULL;
	FilmList *filmList = NULL;

	if ( file == NULL ) {
		printf( "No hay peliculas en nuestro catalogo.\n" );
		return NULL;
	}

	//busco cuantas peliculas hay
	fseek( file, 0, SEEK_END );
	amount = ftell( file ) / sizeof( Film );
	fseek( file, 0, SEEK_SET );

	//guardo el espacio para esas peliculas
	films = malloc( amount * sizeof( Film ) );
	if ( films == NULL ) {
		printf( "Error al asignar espacio para peliculas\n" );
		fclose( file );
		return NULL;
	}

	fread( films, sizeof( Film ), amount, file );
	fclose( file );

	filmList = malloc( ( sizeof( FilmList ) ) );
	if ( filmList == NULL ) {
		printf( "Error al asignar espacio para la lista de peliculas\n" );
		free( films );
		return NULL;
	}

	filmList->films = films;
	filmList->total = amount;

	return filmList;
};


void addFilm( void ) {

	Film *film = malloc( sizeof( Film ) );
	FILE *file = NULL;

	//introduzco los datos de la pelicula

	printf( "agregar pelicula a nuestro catalogo\n" );

	printf( "Ingrese el nombre de la pelicula:\n" );
	scanf( " %[^\n]100s", film->name );
	fflush( stdin );

	printf( "Ingrese el genero de la pelicula:\n" );
	scanf( " %[^\n]30s", film->category );
	fflush( stdin );

	printf( "Ingrese la duracion en minutos de la pelicula:\n" );
	scanf( "%hu", &film->runningTime );

	film->id = idGenerator(FILM_CODE);

	film->status = 1; // Borrado logico

	// agregar al archivo

	file = fopen( FILM_FILE, "ab" );

	if ( file == NULL ) {
		printf( "Error en el acceso al archivo de peliculas\n" );
	} else {
		fwrite( film, sizeof( Film ), 1, file );
		printf( "La pelicula fue agregada con exito.\n" );
	}

	fclose( file );
	file = NULL;

	free( film );
	film = NULL;
};
