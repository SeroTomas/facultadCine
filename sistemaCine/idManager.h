#ifndef IDMANAGER_H
#define IDMANAGER_H

#define USUARIO_CODE 0
#define PELICULA_CODE 1
#define FUNCION_CODE 2

struct Id {
	char code;
	short numberId;
};

short idGenerator(char);

#endif
