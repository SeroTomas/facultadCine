#include <stdio.h>
#include <stdlib.h>
#include "idManager.h"


short idGenerator(char idCode){
	
	FILE *file = fopen("ids.dat","rb+");
	struct Id *id;
	short utilId;
	char flag = 0;
	char position = 0;
	
	if(file == NULL){
		
		printf("El archivo no existe\n");
		printf("generando primer archivo\n");
		
		file = fopen("ids.dat", "wb+");
		
		if(file == NULL){
			printf("falla en la creacion del archivo ID\n");
			return 0;
		}
		
		//creo espacio en memoria para las 3 estructuras
		id = malloc(3 * sizeof(struct Id));
		
		//asigno los espacios
		for(short i = 0;i<3;i++){
			id[i].code = i;
			id[i].numberId = 0;
		}
		
		fwrite(id, sizeof(struct Id), 3, file);
		printf("archivo vacio creado\n");
		
		rewind(file);
		
		free(id);
		id = NULL;
	}
	
	//reservar espacio para una estructura
	id = malloc(sizeof(struct Id));
	
	position = ftell(file);
	
	fread(id, sizeof(struct Id), 1, file);
	
	while(!feof(file) && !flag){
		if(idCode == id->code){
			flag = 1;
		}else{
			position = ftell(file);
			fread(id, sizeof(struct Id), 1, file);
		}
	}
	
	if(flag){
		
		id->numberId++; //puntero
		utilId = id->numberId; // valor
		
		fseek(file,position,SEEK_SET);
		fwrite(id, sizeof(struct Id), 1, file);
		
		fclose(file);
		free(id);
		id = NULL;
		
		return utilId;
		
	}else{
		printf("Ocurrio un error en la busqueda del ID a generar.");
		return 0;
	}
	
}
