#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

struct ArbolEst;
typedef struct ArbolEst* ArbolP;

ArbolP cargarArbolPT();
ArbolP cargarArbolPP(char es[30], int e, float a);

//inicializoArreglo
void leerArboles(ArbolP as[], int t);

void mostrarArbol(ArbolP arb);
void mostrarArboles(ArbolP as[], int t);

void agregarArboles(ArbolP as[], int t);

void escribirArboles(ArbolP as[], int t);

#endif // ARBOL_H_INCLUDED
