#include "pila.h"

Pila* crearPila(){
	Pila *miPila = NULL;							/* creo un apuntador de tipo pila */
	miPila = malloc(sizeof(Pila));				/* reservo memoria y al apuntador lo hago apuntar al sector de memoria */
	miPila->cima = NULL;
	miPila->cantidad = 0;
	return miPila;								/* devuelvo el apuntador apuntando al sector de memoria reservado*/
}

int pilaVacia(Pila *miPila) {
	if (miPila->cima == NULL && miPila->cantidad == 0)
	{
		return VERDADERO;
	}
	return FALSO;
}

int cantidadElementos(Pila *miPila){
	return miPila->cantidad;
}


int apilar(Pila *miPila, char *dato){

	Elemento *nuevo_elemento;
    if ((nuevo_elemento = (Nodo *) malloc(sizeof (Nodo))) == NULL) {
        return -1;
    }
    
    if ((nuevo_elemento->dato = (char *) malloc(sizeof (char) * TAMANIO_DATO_ALMACENAR)) == NULL) {
        return -1;
    }

    strcpy(nuevo_elemento->dato, dato);
    nuevo_elemento->siguiente = miPila->cima;
    miPila->cima = nuevo_elemento;
    miPila->tamanio++;
}

Nodo* desapilar(Pila *miPila){

	Nodo *temporalNodo = NULL;					/* creo un apuntador a un nodo*/
	
	if(pilaVacia(miPila) == FALSO){							/* si la pila existe */
		temporalNodo = miPila->cima;				/* al apuntador nodo lo hago apuntar al nodo de la cima de la pila */
		miPila->cima = temporalNodo->siguiente;	/* al puntero de la cima lo hago apuntar al segundo de la cima */
		temporalNodo->siguiente = NULL;				/* desvinculo el nodo a desapilar totalmente de la pila */
		miPila->cantidad--;						/* decremento la cantidad de nodos de la lista */ 
	}

	return temporalNodo;						/* devuelvo el apuntador al nodo */
}

Elemento obtenerElementoCima(Pila *miPila){

    Elemento cimaPila;

    cimaPila = *(miPila->cima);
    return cimaPila;    
}

void eliminarElementoCima(Pila *miPila){
    Elemento *cimaPila = NULL;

    cimaPila = (miPila->cima);
    free(cimaPila);
}

int destruirPila(Pila *miPila){
	Nodo *temp = NULL;
	
	if (!pilaVacia(miPila)) /* se verifica que la pila contiene elementos */
	{
		temp = desapilar(miPila); /* se desapila y guarda el nodo desapilada*/
		while (temp != NULL)/* se repte mientras hallan nodos*/
		{
			free(temp);/* se libera la memoria ocupada por el nodo desapilado */
			temp = desapilar(miPila);/*  se desapila y guarda el posible nodo de la pila*/
		}
		return VERDADERO;/* si concluye correctamente se devuelve el codigo 1*/
	}
	return FALSO;/* si la pila estaba vacia se se retorna el codigo 0 */
}
