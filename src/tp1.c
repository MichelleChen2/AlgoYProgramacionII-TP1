#include "tp1.h"

#include "pokemon.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _hospital_pkm_t {
	pokemon_t **pokemones;
	size_t cantidad_pokemon;
	size_t cantidad_entrenadores;
};

char *leer_linea_archivo(FILE *archivo)
{
	size_t c_leidos = 0;
	int caracter = 0; 
	char *vc_linea_leida = malloc(1*sizeof(char));

	for (c_leidos = 1; (caracter = fgetc(archivo)) != '\n' && caracter != EOF; c_leidos++) {
		*(vc_linea_leida + c_leidos) = (char) caracter;
		vc_linea_leida = realloc(vc_linea_leida, (c_leidos + 1)*sizeof(char));

		if (vc_linea_leida == NULL)
			return NULL; 
	} 

	if (c_leidos == 0)
		return NULL; 

	vc_linea_leida[c_leidos] = 0; 
	return vc_linea_leida; 
}


hospital_t *hospital_crear_desde_archivo(const char *nombre_archivo)
{	
	if (nombre_archivo == NULL) 
		return NULL;

	FILE *archivo = fopen(nombre_archivo, "r");

	if (archivo == NULL)
		return NULL; 

	struct _hospital_pkm_t *hospital = malloc(1*sizeof(struct _hospital_pkm_t));
	(hospital->pokemones) = malloc(1*sizeof(pokemon_t *)); 

	pokemon_t *pkm_creado; 
	char *linea;
	size_t cant_pkm; 

	for (cant_pkm = 0; (linea = leer_linea_archivo(archivo)) != NULL; cant_pkm++) {

		pkm_creado = pokemon_crear_desde_string(linea);

		if (pkm_creado == NULL) { 
			free(hospital->pokemones); 
			return NULL; 
		}
		*(hospital->pokemones) = realloc(hospital->pokemones, (cant_pkm + 1)*sizeof(pokemon_t *));
		*(hospital->pokemones + cant_pkm) = pkm_creado;  
	}

	fclose(archivo);
	return hospital;
}

size_t hospital_cantidad_pokemones(hospital_t *hospital)
{
	return 0;
}

size_t hospital_a_cada_pokemon(hospital_t *hospital,
			       bool (*funcion)(pokemon_t *p, void *aux),
			       void *aux)
{
	return 0;
}

int hospital_aceptar_emergencias(hospital_t *hospital,
				 pokemon_t **pokemones_ambulancia,
				 size_t cant_pokes_ambulancia)
{
	return ERROR;
}

pokemon_t *hospital_obtener_pokemon(hospital_t *hospital, size_t prioridad)
{
	return NULL;
}

void hospital_destruir(hospital_t *hospital)
{
	free(hospital); 
}
