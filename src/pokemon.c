#include "pokemon.h"
#include "pokemon_privado.h"
#include <stdio.h>
#include <string.h>

pokemon_t *pokemon_crear_desde_string(const char *string)
{
	if (string == NULL)
		return NULL;

	pokemon_t *nuevo_pkm = malloc(1 * sizeof(pokemon_t));

	if (sscanf(string, "%zu,%[^,],%zu,%[^\n]\n", &(nuevo_pkm->id),
		   nuevo_pkm->nombre, &(nuevo_pkm->salud),
		   nuevo_pkm->nombre_entrenador) < 4) {
		pokemon_destruir(nuevo_pkm);
		return NULL;
	}
	return nuevo_pkm;
}

pokemon_t *pokemon_copiar(pokemon_t *poke)
{
	if (poke == NULL)
		return NULL;

	pokemon_t *poke_copiado = malloc(1 * sizeof(pokemon_t));
	poke_copiado->id = poke->id;
	poke_copiado->salud = poke->salud;
	strcpy(poke_copiado->nombre, poke->nombre);
	strcpy(poke_copiado->nombre_entrenador, poke->nombre_entrenador);
	return poke_copiado;
}

bool pokemon_son_iguales(pokemon_t *pokemon1, pokemon_t *pokemon2)
{
	if (pokemon1 == NULL || pokemon2 == NULL)
		return NULL;

	if (pokemon1->id == pokemon2->id &&
	    pokemon1->salud == pokemon2->salud &&
	    strcmp(pokemon1->nombre, pokemon2->nombre) == 0 &&
	    strcmp(pokemon1->nombre_entrenador, pokemon2->nombre_entrenador) ==
		    0)
		return true;
	return false;
}

char *pokemon_nombre(pokemon_t *pokemon)
{
	if (pokemon == NULL)
		return NULL;
	return pokemon->nombre;
}

char *pokemon_entrenador(pokemon_t *pokemon)
{
	if (pokemon == NULL)
		return NULL;

	return pokemon->nombre_entrenador;
}

size_t pokemon_salud(pokemon_t *pokemon)
{
	return pokemon->salud;
}

size_t pokemon_id(pokemon_t *pokemon)
{
	return pokemon->id;
}

void pokemon_destruir(pokemon_t *pkm)
{
	free(pkm);
}
