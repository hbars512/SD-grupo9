/*
 * 008_pe.c
 *
 *  ESTE PROGRAMA CREA, MUESTRA E INSERTA VALORES EN UNA LISTA
 *  CIRCULAR DOBLEMENTE ENLAZADA DE FORMA ORDENADA
 *
 *  Created on: Jul 8, 2020
 *      Author: grupo 9
 */


#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


struct node {
	int data;
	struct node *next;
	struct node *prev;
};

struct node *start = NULL;
struct node *crearListaCircular(struct node*);
struct node *mostrar(struct node*);
struct node *ordenarValores(struct node*);
struct node *insertar(struct node*);


int main() {


	int op = 0;


	do {

		printf("******** MENU *********");
		printf("\n1. Crear una lista.");
		printf("\n2. Mostrar la lista.");
		printf("\n3. Insertar elemento.");
		printf("\n4. Ordenas valores.");
		printf("\n5. Salir.");

		printf("\n\n\tOpcion: ");
		scanf("%d", &op);

		switch(op) {
			case 1: start = crearListaCircular(start);
					printf("\n\nSe creo la lista\n\n.");
					break;

			case 2: mostrar(start);
					break;

			case 3: insertar(start);
					//ordenarValores(start);
					break;

			case 4: ordenarValores(start);
					printf("\n\nSe ordeno los valores de la lista.\n\n.");
					break;

			case 5: printf("Salir.");
		}


	} while(op != 5);


	return 0;
}



struct node *crearListaCircular(struct node *start) {

	struct node *nuevoNodo, *ptr;
	int num;

	printf("\nIngrese -1 para salir.");
	printf("\nIngrese un elemento: ");
	scanf("%d", &num);

	while(num != -1) {

		if(start == NULL) {
			nuevoNodo = (struct node*)malloc(sizeof(struct node));
			nuevoNodo->prev = NULL;
			nuevoNodo->next = start;
			nuevoNodo->data = num;
			start = nuevoNodo;
		}
		else {
			nuevoNodo = (struct node*)malloc(sizeof(struct node));
			nuevoNodo->data = num;
			ptr = start;

			while(ptr->next != start && ptr->next != NULL) {
				ptr = ptr->next;
			}

			nuevoNodo -> prev = ptr;
			ptr -> next = nuevoNodo;
			nuevoNodo -> next = start;
			start -> prev = nuevoNodo;


		}

		printf("\nIngrese un elemento: ");
		scanf("%d", &num);

	}

	return start;
}

struct node *mostrar(struct node *start) {
	struct node *ptr;
	ptr = start;


	printf("\n");
	while(ptr->next != start && ptr->next != NULL) {
		printf("\t%d", ptr->data);
		ptr = ptr->next;
	}

	printf("\t %d \n\n", ptr->data);

	return start;
}

struct node *ordenarValores(struct node *start) {

	struct node *ptr;
	ptr = start;

	//contamos cuantos elementos hay
	int tam = 1;
	while(ptr->next != start && ptr->next != NULL) {
		tam++;
		ptr = ptr->next;
	}
	//printf("\n\nEl tamaño es %d\n\n", tam);

	//ALMACENAMOS LOS VALORES EN UN ARREGLO
	int i = 0, j = 0;
	int arreglo[tam];
	while(i < tam) {
		arreglo[i] = ptr->data;
		ptr = ptr->next;
		i++;
	}


	//ORDENAMOS POR METODO BURBUJA LOS VALORES DEL ARREGLO
	for(i = 0; i < tam - 1; i++) {
		for(j = 0; j < tam - 1; j++) {
			if(arreglo[j] > arreglo[j+1]) {
				int aux = arreglo[j];
				arreglo[j] = arreglo[j+1];
				arreglo[j+1] = aux;
			}
		}
	}

	//ASIGNAMOS LOS VALORES EN ORDEN A LA LISTA
	i = 0;
	ptr = start;
	while(i < tam) {
		ptr->data = arreglo[i];
		ptr = ptr->next;
		i++;
	}


	return start;
}

struct node *insertar(struct node *start) {
	struct node *nuevoNodo, *ptr;
	int num;

	printf("\nIngrese -1 para salir.");
	printf("\nIngrese un elemento: ");
	scanf("%d", &num);

	while(num != -1) {

		nuevoNodo = (struct node*)malloc(sizeof(struct node));
		nuevoNodo->data = num;
		ptr = start;

		while(ptr->next != start && ptr->next != NULL) {
			ptr = ptr->next;
		}

		nuevoNodo -> prev = ptr;
		ptr -> next = nuevoNodo;
		nuevoNodo -> next = start;
		start -> prev = nuevoNodo;

		printf("\nIngrese un elemento: ");
		scanf("%d", &num);
	}


	return start;
}
