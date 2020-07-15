/*
 * fila.c
 *
 *  Created on: Jul 15, 2020
 *      Author: Grupo 9
 */

#include <stdlib.h>
#include <stdio.h>
#define MAXFILA 100
#define ERRORFILALLENA -1
#define ERRORFILAVACIA -2

struct Fila {
	int dato[MAXFILA];
	int topo;
} aFila;

void inicializarFila();
int filaLlena();
int insertar(int dato);
int filaVacia();
int eliminar();
int desenfilar();
int topo();
void mostrar();

int main() {
	int option;
	int numero, dat;
		do{
			printf("\n\n ***** MENU PRINCIPAL *****");
			printf("\n 1: Crear la fila.");
			printf("\n 2: Mostrar la fila.");
			printf("\n 3: Insertar elemento.");
			printf("\n 4: Eliminar elemento.");
			printf("\n 5: Salir.");

			printf("\n\n\tOpcion: ");
			scanf("%d", &option);
			switch(option) {
				case 1: inicializarFila();
						printf("\n\tLa fila ah sido creada.");
						break;
				case 2: printf("\n\n");
						mostrar();
						break;
				case 3:
						printf("\n\nIngresa un numero: ");
						scanf("%i", &dat);
						numero = insertar(dat);
						printf("\n\tSe ha insertado el elemento %i exitosamente.", numero);
						break;
				case 4:
						printf("\n\nSe elimino el primer elemento de la fila: %d", eliminar());
						break;
			}

		} while(option != 5);
	return 0;
}

int filaVacia() {
	if (aFila.topo == -1) {
		return 1;
	} else {
		return 0;
	}
}

int enfila(int dato)
{
	if (filaLlena(aFila)) {
		return ERRORFILALLENA;
	} else {
		aFila.topo = aFila.topo + 1;
		aFila.dato[aFila.topo] = dato;
		return aFila.topo;
	}
}

void inicializarFila() {
	aFila.topo = -1;
}

int filaLlena() {
	return aFila.topo == MAXFILA - 1? 1:0;
}

int insertar(int d)
{
	if (filaLlena()) {
		return ERRORFILALLENA;
	}
	aFila.topo = aFila.topo + 1;
	aFila.dato[aFila.topo] = d;
	return aFila.topo;
}

int eliminar() {
	//se eliminaria el primer elemento, pero los demas tendrias q "bajar"
	int num = aFila.dato[0];

	int i;

	for(i = 1; i < aFila.topo + 1; i++) {
		aFila.dato[i-1] = aFila.dato[i];
	}
	aFila.topo = aFila.topo - 1;

	return num;
}
void mostrar() {
	int i;
	for(i = 0; i < aFila.topo + 1; i++) {
		printf("%d ", aFila.dato[i]);
	}
}


int desenfilar()
{
	if(filaVacia()){
		return ERRORFILAVACIA;

	}else {
		aFila.topo=aFila.topo-1;
	}
	return aFila.topo;
}
int topo()
{
	if(filaVacia()){
		printf("error Fila vacia al acceder ");
		return ERRORFILAVACIA;
	}else{
		return aFila.dato[aFila.topo];
	}
}
