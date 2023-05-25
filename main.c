#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Arbol.h"

int main()
{
    int tam = 5;
    ArbolP arboles[tam];

    leerArboles(arboles,tam);

    mostrarArboles(arboles,tam);

    agregarArboles(arboles,tam);
    agregarArboles(arboles,tam);

    mostrarArboles(arboles,tam);
    escribirArboles(arboles,tam);

    return 0;
}
