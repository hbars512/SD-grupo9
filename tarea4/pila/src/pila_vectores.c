#include <stdlib.h>
#include <stdio.h>

#define MAXPILA 100


struct Pila {
	int dato;
	int topo;
} aPila;



void inicializarPila();
int pilaLlena();



int main() {

	int option;

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
