#include <stdio.h>
#include <stdlib.h>
/* codigos devuelto por funciones de lista */
#define VERDADERO 1
#define FALSO 0
#define ERROR -1
#define TAMANIO_DATO_ALMACENAR 256

struct nodo{
	struct nodo *siguiente;
    int contenido
};
typedef struct nodo Nodo;

struct elementoPila{
    int contenido;
    char *dato;
     struct elementoPila *siguiente;
};
typedef struct elementoPila Elemento;

struct pila{
    Elemento *cima;
    int tamanio;
    int cantidad;
};
typedef struct pila Pila;

Pila* crearPila ();

/* APILAR*/

int apilar (Pila *miPila, char *dato);

/* DESAPILAR*/

Nodo* desapilar (Pila *miPila);

/* si pila vacia*/

int pilaVacia(Pila *miPila);

Elemento obtenerElementoCima(Pila *miPila);
void eliminarElementoCima(Pila *miPila);

int cantidadElementos(Pila *miPila);

int destruirPila(Pila *miPila);