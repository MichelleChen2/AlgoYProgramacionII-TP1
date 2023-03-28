<div align="right">
<img width="32px" src="img/algo2.svg">
</div>

# TP1

## Repositorio de Michelle Melisa Chen - 105506 - mchen@fi.uba.ar

- Para compilar:

```bash
línea de compilación
```

- Para ejecutar:

```bash
línea de ejecución
```

- Para ejecutar con valgrind:
```bash
línea con valgrind
```
---
##  Funcionamiento

Explicación de cómo funcionan las estructuras desarrolladas en el TP y el funcionamiento general del mismo.

Aclarar en esta parte todas las decisiones que se tomaron al realizar el TP, cosas que no se aclaren en el enunciado, fragmentos de código que necesiten explicación extra, etc.

Incluír **EN TODOS LOS TPS** los diagramas relevantes al problema (mayormente diagramas de memoria para explicar las estructuras, pero se pueden utilizar otros diagramas si es necesario).

### Por ejemplo:

El programa funciona abriendo el archivo pasado como parámetro y leyendolo línea por línea. Por cada línea crea un registro e intenta agregarlo al vector. La función de lectura intenta leer todo el archivo o hasta encontrar el primer error. Devuelve un vector con todos los registros creados.

<div align="center">
<img width="70%" src="img/diagrama1.svg">
</div>

En el archivo `sarasa.c` la función `funcion1` utiliza `realloc` para agrandar la zona de memoria utilizada para conquistar el mundo. El resultado de `realloc` lo guardo en una variable auxiliar para no perder el puntero original en caso de error:

```c
int *vector = realloc(vector_original, (n+1)*sizeof(int));

if(vector == NULL)
    return -1;
vector_original = vector;
```


<div align="center">
<img width="70%" src="img/diagrama2.svg">
</div>

---

## Respuestas a las preguntas teóricas

## --- hospital_t *hospital_crear_desde_archivo (const char *nombre_archivo) ---

El siguiente diagrama ilustra brevemente cómo funciona la función: 

<div align="center">
<img width="70%" src="img/diacrearhospital">
</div>

En la función pido memoria con `malloc` para la variable `hospital` del tamaño de un
`struct _hospital_pkm_t`. Pido memoria también para la variable `**pokemones` en 
`struct _hospital_pkm_t`. Inicializo los otros variables a 0.   

```c
	struct _hospital_pkm_t *hospital =
		malloc(1 * sizeof(struct _hospital_pkm_t));
	hospital->pokemones = malloc(1 * sizeof(pokemon_t *));
	hospital->cantidad_pokemon = 0, hospital->cantidad_entrenadores = 0;
```
<div align="center">
<img width="70%" src="img/hospitalpkm.svg">
</div>