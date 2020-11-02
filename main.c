#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"


#define VERDADERO 1
#define FALSO 0
#define TAMANIO_DATO_ALMACENAR 256

int seleccionarMenu();
void menuCrearPila(Pila *miPila);
void menuPilaVacia(Pila *miPila);
void menuNuemroElementos(Pila *miPila);
void menuApilado(Pila *miPila);
void menuDesapilado(Pila *miPila);
void menuMostrarElementoCima(Pila *miPila);
void menuDestruirPila(Pila *miPila);
void pausa();

int main() {

    Pila miPila;

    int menuSeleccionado = 0;

    do {

        menuSeleccionado = seleccionarMenu();
        switch (menuSeleccionado) {
            case 1:
                menuCrearPila(&miPila);
                pausa();
                break;
            case 2:
                menuPilaVacia(&miPila);
                pausa();
                break;
            case 3:
                menuNuemroElementos(&miPila);
                pausa();
                break;
            case 4:
                menuApilado(&miPila);
                pausa();
                break;
            case 5:
                menuMostrarElementoCima(&miPila);
                pausa();
                break;
            case 6:
                menuDesapilado(&miPila);
                pausa();
                break;
            case 7:
                menuDestruirPila(&miPila);
                pausa();
                break;
            case 8:
                printf("Gracias por usar este soft..");
                break;
            default:
                break;
        }
    } while (!(menuSeleccionado == 8));
}

int seleccionarMenu() {

    int menuSeleccionado;

    system("clear");
    printf("\t\t\tSISTEMA DE MANEJO DE PILAS\n\n");
    printf("\t\t1 Crear la Pila\n");
    printf("\t\t2 Verificar pila vacia\n");
    printf("\t\t3 Determinar la cantidad de elementos de la pila\n");
    printf("\t\t4 Agregar un elemento en la cima de la pila\n");
    printf("\t\t5 Obtener el elemento de la cima de la pila\n");
    printf("\t\t6 Eliminar el elemento de la cima de la pila\n");
    printf("\t\t7 Destruir una pila\n");
    printf("\t\t8 Salir \n\n\n");
    printf("Seleccione menu: ");
    scanf("%i", &menuSeleccionado);
    printf("\n");

    return menuSeleccionado;
}

void menuCrearPila(Pila *miPila) {

    if ((miPila = (Pila *) malloc(sizeof (Pila))) == NULL) {
        printf("Cantidad de memoria insuficiente para crear la pila.\n");
    } else {
        crearPila(miPila);
        printf("La pila fue creada con exito.\n");
    }

}

void menuPilaVacia(Pila *miPila) {

    if (pilaVacia(miPila) == VERDADERO) {
        printf("La pila esta vacia.\n");
    } else {
        printf("La pila NO esta vacia.\n");
    }
}

void menuNuemroElementos(Pila *miPila) {

    if (cantidadElementos(miPila) < 0) {
        printf("La pila no presenta elemento.\n");
    } else {
        printf("La cantidad de elemento de la pila es: %i \n", cantidadElementos(miPila));
    }
}

void menuApilado(Pila *miPila) {

    char datoAlmacenar[TAMANIO_DATO_ALMACENAR];

    printf("Ingrese dato a almacenar: ");
    scanf("%s", datoAlmacenar);
    printf("\n");

    apilar(miPila, datoAlmacenar);
}

void menuDesapilado(Pila *miPila) {

    if (desapilar(miPila) == VERDADERO) {
        printf("Desapilado con exito.\n");
    } else {
        printf("Fallo al desapilar.\n");
    }
}

void menuMostrarElementoCima(Pila *miPila) {

    Elemento cima = obtenerElementoCima(miPila);
    printf("El dato almacenado en la cima es: %s\n", cima.dato);
}

void menuDestruirPila(Pila *miPila) {

    destruirPila(miPila);
    if (pilaVacia(miPila) == VERDADERO) {
        printf("La pila a sido eliminada con exito.\n");
    } else {
        printf("No se pudo destruir la pila.\n");
    }
}


