#ifndef FILM_H
#define FILM_H

#define FILM_FILE "film.dat"

typedef struct {
	unsigned short id;
	char name[101];
	char category[31];
	unsigned short runningTime;
	char status;
} Film;

typedef struct {
	unsigned short total;
	Film *films;
} FilmList;

void addFilm ( void );
FilmList* getAllFilms();
void freeFilmList( FilmList * );
void renderFilms(FilmList *);

#endif
