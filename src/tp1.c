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
	size_t cant_c_leidos = 0;
	int caracter = 0; 
	char *vc_linea_leida = malloc(1*sizeof(char));

	while ((caracter = fgetc(archivo)) != '\n' && caracter != EOF) {
		vc_linea_leida[cant_c_leidos] = (char) caracter;
		cant_c_leidos++;
		vc_linea_leida = realloc(vc_linea_leida, (cant_c_leidos + 1)*sizeof(char));

		if (vc_linea_leida == NULL) {
			return NULL; 
		}
	} 

	if (cant_c_leidos == 0) {
		free(vc_linea_leida); 
		return NULL;
	} 

	vc_linea_leida[cant_c_leidos] = 0; 
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
	hospital->pokemones = malloc(1*sizeof(pokemon_t *)); 
	hospital->cantidad_pokemon = 0, hospital->cantidad_entrenadores = 0; 

	pokemon_t *pkm_creado = NULL; 
	char *linea;
	size_t cant_pkm; 

	for (cant_pkm = 0; (linea = leer_linea_archivo(archivo)) != NULL; cant_pkm++) {

		pkm_creado = pokemon_crear_desde_string(linea);

		if (pkm_creado == NULL) 
			return NULL; 
		
		hospital->pokemones = realloc(hospital->pokemones, (cant_pkm + 1)*sizeof(pokemon_t *));
		hospital->pokemones[cant_pkm] = pkm_creado; 
		hospital->cantidad_pokemon += 1;
		hospital->cantidad_entrenadores += 1; 
	}

	if (linea == NULL) {
		free(pkm_creado); 
		return NULL;
	} 
	free(pkm_creado); 
	return hospital;
}

size_t hospital_cantidad_pokemones(hospital_t *hospital)
{
	if (hospital == NULL)
		return 0; 
	return hospital->cantidad_pokemon;
}

size_t hospital_a_cada_pokemon(hospital_t *hospital,
			       bool (*funcion)(pokemon_t *p, void *aux),
			       void *aux)
{
	if (hospital == NULL || funcion == NULL)
		return 0; 

	size_t invocaciones = 0, pokemon = 0;
	
	while (funcion(hospital->pokemones[pokemon], aux)) {
		pokemon++;
		invocaciones++;
	}
	return invocaciones;
}



int hospital_aceptar_emergencias(hospital_t *hospital,
				 pokemon_t **pokemones_ambulancia,
				 size_t cant_pokes_ambulancia)
{
	if (hospital == NULL || pokemones_ambulancia == NULL)
		return ERROR; 

	if (cant_pokes_ambulancia == 0)
		return EXITO;

	pokemon_t **hospital_aux = realloc(hospital->pokemones, (hospital->cantidad_pokemon + cant_pokes_ambulancia)*sizeof(pokemon_t *));
	if (hospital_aux == NULL) {
		return ERROR; 
	}

	hospital->pokemones = hospital_aux; 
	size_t n_pokemon = 0; 
	while (n_pokemon < cant_pokes_ambulancia) {
		hospital->pokemones[hospital->cantidad_pokemon + n_pokemon] = pokemones_ambulancia[n_pokemon];
		n_pokemon++;
	}
	hospital->cantidad_pokemon += cant_pokes_ambulancia; 

	size_t longitud = hospital->cantidad_pokemon, i, j;
	for (i = 0; i < (longitud - 1); i++) {
		j = i; 
		while (j > 0 && pokemon_salud(hospital->pokemones[j - 1]) > pokemon_salud(hospital->pokemones[j])) {
			pokemon_t *pkm_aux = hospital->pokemones[j]; 
			hospital->pokemones[j] = hospital->pokemones[j-1]; 
			hospital->pokemones[j-1] = pkm_aux; 
		}
	}	
	return EXITO;
}

pokemon_t *hospital_obtener_pokemon(hospital_t *hospital, size_t prioridad)
{
	if (hospital == NULL)
		return NULL; 

	for (size_t i = 0; i < hospital->cantidad_pokemon; i++) {
		if (i == prioridad)
			return hospital->pokemones[i];
	}
	return NULL;
}

void hospital_destruir(hospital_t *hospital)
{
	if (hospital == NULL)
		return; 

	for (size_t i = 0; i < hospital->cantidad_pokemon; i++) 
		pokemon_destruir(hospital->pokemones[i]);
	
	free(hospital->pokemones);
	free(hospital); 
}
