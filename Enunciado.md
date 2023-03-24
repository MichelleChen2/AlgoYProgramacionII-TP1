<div align="right">
<img width="32px" src="img/algo2.svg">
</div>

## TP1

Ya que desarrollaste el TP0, ahora vamos a ir un paso mas allá. Vamos a agarrar el código del TP0 y vamos a cambiar algunas cosas.

- Ahora las estructuras del hospital y los pokemones son privadas. Esto significa que, por ejemplo, desde `tp1.c` no vas a poder acceder a los elementos de la estructura `pokemon`.  Para acceder a la información vas a tener que usar las funciones provistas por `pokemon.h`.
- Se agrega lectura de archivos. Se incluyen algunos archivos de ejemplo para que veas el formato.
- Los pokemon ahora se almacenan como un vector de punteros. Recordá liberar cada uno de los pokemon al destruir el hospital.
- Recordá que (como se dijo en clase) no se permite el uso de `qsort`.
- Para simplificar vamos a suponer que las líneas de los archivos a leer no tienen mas de 30 caracteres.

No te olvides de incluir en el informe todas las suposiciones que hayas tomado (cosas que no queden claras en el enunciado por ejemplo) y diagramas de memoria explicando cómo se almacenan los datos.
