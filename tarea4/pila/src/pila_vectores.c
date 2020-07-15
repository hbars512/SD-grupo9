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
int desempila();
int topo();



int main() {

	int option;
	int numero, dat;
		do{
			printf("\n\n ***** MENU PRINCIPAL *****");
			printf("\n 1: Crear la pila.");
			printf("\n 2: Mostrar la pila.");
			printf("\n 3: Insertar elemento.");
			printf("\n 4: Salir.");
			printf("\n 5: Desempila");
			printf("\n 6: topo");
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
				case 5:
						desempila();
						printf("desempila");
				case 6:
						topo();
						printf("topo");

			}
		} while(option != 6);
	return 0;
}
void inicializarPila() {
	aPila.topo = -1;
}

int pilaLlena() {
	return aPila.topo == MAXPILA - 1? 1:0;
}

int pilaVacia() {
	if (aPila.topo = -1) {
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

int desempila()
{
	if(pilaVacia){
		return ERRORPILAVACIA;
		} else{
			aPila.topo = aPila.topo-1;
			return aPila.topo;
		}

}

int topo()
{
	if (pilaVacia){
		printf("error pila vacia al acceder ");
		return ERRORPILAVACIA;

	} else{
		return aPila.dato[aPila.topo];
	}
}


