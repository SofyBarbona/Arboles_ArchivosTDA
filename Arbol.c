#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Arbol.h"
struct ArbolEst{
    char especie[30];
    int edad;
    float altura;

};
int contarArboles(ArbolP as[]){
    FILE * archivo = fopen("arboles.txt","r");

    int i=0;
    while(!feof(archivo)){
        char datos[100];
        fgets(datos,100,archivo);
        i++;
    }

    fclose(archivo);
    return i;
}
void escribirArboles(ArbolP as[], int t){
    FILE* archivo = fopen("arboles.txt","a");

    int cantArb = contarArboles(as);
    for(int i=cantArb;i<t;i++){
        fprintf(archivo,"\n%s+%d+%f",as[i]->especie,as[i]->edad,as[i]->altura);
    }
}

int buscarPos(ArbolP as[], int t, int buscar){
    int pos = -2;

    for(int i=0;i<t;i++){
        if(as[i]->edad==buscar){
            pos = i;
            i = t+1;
        }
    }

    return pos;
}
void agregarArboles(ArbolP as[], int t){
    int posVa = buscarPos(as,t,-1);

    if(posVa != -2){
        as[posVa] = cargarArbolPT();
    }else{
        printf("\nNo hay posiciones vacias\n");
    }
}

void mostrarArboles(ArbolP as[], int t){
    for(int i=0;i<t;i++){
        mostrarArbol(as[i]);
    }
}
void mostrarArbol(ArbolP arb){
    printf("\nEspecie: %s\n",arb->especie);
    printf("Edad: %d\n",arb->edad);
    printf("Altura: %f\n",arb->altura);
}


ArbolP transformarTxtArbol(char d[100]){
    ArbolP arb = malloc(sizeof(struct ArbolEst));

    int posDel1 = -1;
    int posDel2 = -1;

    for(int i=0;i<100;i++){ //POS DEL PRIMER DELIMITADOR
        if(d[i]=='+'){
            posDel1 = i;
            i = 101;
        }
    }

    for(int i=posDel1+1;i<100;i++){  //POS DEL SEGUNDO DELIMITADOR
        if(d[i]=='+'){
            posDel2 = i;
            i = 101;
        }
    }

    ///Creo auxiliares y le asigno cada dato
    char auxEsp[30]= "";
    char auxEd[30] = "";
    char auxAl[30] = "";

    for(int i=0; i<posDel1; i++){
        auxEsp[i] = d[i];
    }
    for(int i=posDel1+1; i<posDel2; i++){
        auxEd[i-(posDel1+1)] = d[i];
    }
    for(int i=posDel2+1;i<posDel2+30;i++){
        auxAl[i-(posDel2+1)] = d[i];
    }

    ///Asigno valores a los atributos de la estructura
    strcpy(arb->especie,auxEsp);
    arb->edad=atoi(auxEd);
    arb->altura=atof(auxAl);

    return arb;
}
void inicializarArboles(ArbolP as[], int t){
    for(int i=0;i<t;i++){
        as[i] = cargarArbolPP("zzzzzz",-1,-1);
    }
}
void leerArboles(ArbolP as[], int t){
    FILE * archivo = fopen("arboles.txt","r");

    inicializarArboles(as,t);

    int i=0;
    while(!feof(archivo)){
        char datos[100];
        fgets(datos,100,archivo);

        as[i] = transformarTxtArbol(datos);
        i++;
    }

    fclose(archivo);
}

ArbolP cargarArbolPP(char es[30], int e, float a){
    ArbolP arb = malloc(sizeof(struct ArbolEst));

    strcpy(arb->especie,es);
    arb->edad = e;
    arb->altura = a;

    return arb;
}
ArbolP cargarArbolPT(){
    ArbolP arb = malloc(sizeof(struct ArbolEst));

    printf("\nIngrese la especie del arbol\n");
    fflush(stdin);
    gets(arb->especie);

    printf("Ingrese la edad\n");
    scanf("%d",&arb->edad);

    printf("Ingrese la altura\n");
    scanf("%f",&arb->altura);

    return arb;
}
