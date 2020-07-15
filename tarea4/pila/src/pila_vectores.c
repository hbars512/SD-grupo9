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
void mostrar();



int main() {

	int option;
	int numero, dat;
		do{
			printf("\n\n ***** MENU PRINCIPAL *****");
			printf("\n 1: Crear la pila.");
			printf("\n 2: Mostrar la pila.");
			printf("\n 3: Insertar elemento.");
			printf("\n 4: Desempila");
			printf("\n 5: Salir");
			printf("\n\n\tOpcion: ");
			scanf("%d", &option);
			switch(option) {
				case 1: inicializarPila();
						printf("\n\tLa pila ah sido creada.");
						break;
				case 2:
						mostrar();
						break;
				case 3:
						printf("Ingresa un numero: ");
						scanf("%i", &dat);
						numero = empila(dat);
						printf("\n\tSe ha insertado el elemento %i exitosamente.", aPila.dato[numero]);
						break;
				case 4:
						numero = desempila();
						if(numero == ERRORPILAVACIA) {
							printf("\n\tLa pila está vacía.");
						} else {
							printf("\n\tSe ha desempilado el elemento %i exitosamente.", aPila.dato[numero]);
						}
						break;
				case 5:
						printf("\n\tPrograma terminado");
						return 0;
						break;

			}
		} while(option != 5);
	return 0;
}
void inicializarPila() {
	aPila.topo = -1;
}

int pilaLlena() {
	if (aPila.topo == MAXPILA - 1) {
		return 1;
	}
	return 0;
}

int pilaVacia() {
	if (aPila.topo == -1) {
		return 1;
	}
	return 0;
}

int empila(int d)
{
	if (pilaLlena()) {
		return ERRORPILALLENA;
	} else {
		aPila.topo = aPila.topo + 1;
		aPila.dato[aPila.topo] = d;
		return aPila.topo;
	}
}

int desempila()
{
	if(pilaVacia()){
		return ERRORPILAVACIA;
		}
	aPila.topo = aPila.topo-1;
	return aPila.topo;
}

int topo()
{
	if (pilaVacia()){
		printf("error pila vacia al acceder ");
		return ERRORPILAVACIA;
	}
	return aPila.dato[aPila.topo];
}

void mostrar() {
	int i;
	for(i = 0; i < aPila.topo + 1; i++) {
		printf("%d	", aPila.dato[i]);
	}
}
