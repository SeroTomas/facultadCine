#ifndef IDMANAGER_H
#define IDMANAGER_H

#define USER_CODE 0
#define FILM_CODE 1
#define FUNCTION_CODE 2

struct Id {
	char code;
	short numberId;
};

short idGenerator(char);

#endif
