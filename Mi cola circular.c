#include <stdlib.h>
#include <stdio.h>
//#include "colaDinamicaCirculara.h"
//Enrique Emmanuel Rios Chyrnia
//Lugar donde ingresar-> (inicial + ingresados) %TamañoMaximo
//Supongo que al llegar al final osea al quitar 5 elementos voy a terminar reiniciando el contador.

#define MAXTAM 5

typedef struct nodo Nodo;

typedef struct {
	int* datos;
	int posicionInicial;
	int ingresados;

}Cola;

//prototipo de las Operaciones
void crearCola(Cola* cola);
void enQueue(Cola* cola, int entrada);
int deQueue(Cola* cola);
void borrarCola(Cola* cola); //libera todos los nodos de la cola

//acceso a la cola
int frente(Cola* cola);

//metodos de verificacion del estado de la cola
int colaVacia(Cola* cola);

void imprimirCola(Cola* cola);


//Setea en NULL y setea en 0 y reserva espacio tamaño MAXTAM
void crearCola(Cola* cola) {
	cola->datos = (int*)malloc(sizeof(int)*MAXTAM);
	cola->posicionInicial = 0;
	cola->ingresados = 0;
}


int colaVacia(Cola cola) {
	return (cola.ingresados == 0);
}
int colaLlena(Cola cola) {
	return (cola.ingresados == MAXTAM);
}

void enQueue(Cola* cola, int entrada) {

	if (colaLlena(*cola)) {
		printf("\n  Cola llena \n");
		return;
	}

	
	if (colaVacia(*cola)) {
		cola->datos[(cola->posicionInicial + cola->ingresados) % MAXTAM] = entrada;
		cola->ingresados++;

	}
	else {
		cola->datos[(cola->posicionInicial + cola->ingresados) % MAXTAM] = entrada;
		//Ahora el el ultimo apunta al frente.
		cola->ingresados++;

	}


}

int deQueue(Cola* cola) {
	if (colaVacia(*cola)) {
		printf("\n  Cola vacia. \n");
		return;
	}
	int tmp = cola->datos[cola->posicionInicial];
	cola->datos[cola->posicionInicial] = NULL;
	cola->posicionInicial = (cola->posicionInicial + 1) % MAXTAM;
	cola->ingresados--;
	return tmp;
}

void borrarCola(Cola* cola) {
	free(cola);
}


int main() {
	int a, b, c,d,e,f,g;
	a = 5;
	b = 6;
	c = 7;
	d = 8;
	e = 9;//po 5
	f = 10;
	g = 11;
	Cola cola;
	crearCola(&cola);
	enQueue(&cola, a);
	enQueue(&cola, b);
	enQueue(&cola, c);
	enQueue(&cola, d);
	enQueue(&cola, e);
	


	for (int i = 0; i < 4; i++) {
		printf("\n Elemento numero %i --> %i",i, deQueue(&cola));
		
	}

	enQueue(&cola, f);
	enQueue(&cola, g);

	printf("\n Ahora agregamos 2 elementos e imprimimos la posicion inicial -> %i \n", cola.posicionInicial);
	
		printf("\nElemento posicion 5 --> %i", deQueue(&cola));


	printf("\n  imprimimos la posicion inicial -> %i \n", cola.posicionInicial);

	printf("\nElemento posicion 5 --> %i", deQueue(&cola));


	printf("\n  imprimimos la posicion inicial -> %i \n", cola.posicionInicial);
	return 0;
}