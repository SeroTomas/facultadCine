#include <stdio.h>
#include <stdlib.h>


#define USUARIO_CODE 0
#define PELICULA_CODE 1
#define FUNCION_CODE 2


struct Id {
	char code;
	short numberId;
};

short idGenerator(char);


int main(void) {
	
	short usuario, pelicula, funcion;
	
	usuario = idGenerator(USUARIO_CODE);
	pelicula = idGenerator(PELICULA_CODE);
	funcion = idGenerator(FUNCION_CODE);
	
	printf("Usuario id nro: %hd\n pelicula id: %hd\n funcion id: %hd\n", usuario, pelicula, funcion);
	
	return 0;
}

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
		
		id = malloc(3*sizeof(struct Id));
		
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
		
		id->numberId++; 
		utilId = id->numberId;
		
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
