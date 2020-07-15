/*
 * pila_vectores.c
 *
 *  Created on: Jul 15, 2020
 *      Author: Grupo 9
 */

#include <stdlib.h>
#include <stdio.h>

#define MAXPILA 100
#define ERRORPILALLENA -1
#define ERRORPILAVACIA -2


struct Pila {
	int dato[MAXPILA];
	int topo;
} aPila;



void inicializarPila();
int pilaLlena();
int empila(int dato);
int pilaVacia();



int main() {

	int option;
	int numero, dat;
		do{
			printf("\n\n ***** MENU PRINCIPAL *****");
			printf("\n 1: Crear la pila.");
			printf("\n 2: Mostrar la pila.");
			printf("\n 3: Insertar elemento.");
			printf("\n 4: Salir.");

			printf("\n\n\tOpcion: ");
			scanf("%d", &option);

			switch(option) {

				case 1: inicializarPila();
						printf("\n\tLa pila ah sido creada.");
						break;
				case 2:
						break;
				case 3:
						printf("Ingresa un numero: ");
						scanf("%i", &dat);
						numero = empila(dat);
						printf("\n\tSe ha insertado el elemento %i exitosamente.", numero);
						break;
				case 4:
						break;
			}

		} while(option != 4);



	return 0;
}


void inicializarPila() {
	aPila.topo = -1;
}

int pilaLlena() {
	return aPila.topo == MAXPILA - 1? 1:0;
}

int pilaVacia() {
	if (aPila.topo == -1) {
		return 1;
	} else {
		return 0;
	}
}

int empila(int d)
{
	if (pilaLlena(aPila)) {
		return ERRORPILALLENA;
	} else {
		aPila.topo = aPila.topo + 1;
		aPila.dato[aPila.topo] = d;
		return aPila.topo;
	}
}
