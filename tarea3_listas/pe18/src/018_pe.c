/*
 * 018_pe.c
 *
 * Este programa crea una lista enlazada, la muestra, inserta elementos
 * e imprime el valor maximo y minimo que esta lista contiene
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
};


struct node *start = NULL;
struct node *crearLista(struct node*);
struct node *mostrar(struct node*);
struct node *insertar(struct node*);
struct node *imprimirMinMax(struct node*);


int main(int argc, char *argv[]) {


	int option;

	do{
		printf("\n\n ***** MENU PRINCIPAL *****");
		printf("\n 1: Crear la lista.");
		printf("\n 2: Mostrar la lista.");
		printf("\n 3: Insertar elemento.");
		printf("\n 4: Obtener el menor y mayor elemento.");
		printf("\n 5: Salir.");

		printf("\n\n\tOpcion: ");
		scanf("%d", &option);

		switch(option) {

			case 1: start = crearLista(start);
					printf("\n\tLa lista ah sido creada.");
					break;
			case 2: mostrar(start);
					break;
			case 3: insertar(start);
					break;
			case 4: imprimirMinMax(start);
					break;
		}

	} while(option != 5);

	return 0;
}


struct node *crearLista(struct node *start) {
	struct node *ptr, *nuevoNodo;
	int num;

	printf("\n\tIngrese -1 para salir.");
	printf("\n\tIngrese un elemento: ");
	scanf("%d", &num);

	while(num != -1) {

		nuevoNodo = (struct node*)malloc(sizeof(struct node));
		nuevoNodo->data = num;

		if(start == NULL) {
			nuevoNodo->next = NULL;
			start = nuevoNodo;
		}
		else {
			ptr = start;

			while(ptr->next != NULL) {
				ptr = ptr->next;
			}

			ptr->next = nuevoNodo;
			nuevoNodo->next = NULL;

		}

		printf("\n\tIngrese un elemento: ");
		scanf("%d", &num);

	}

	return start;
}

struct node *mostrar(struct node *start) {
	struct node *ptr;

	printf("%d", start->data);
	ptr = start;


	while(ptr->next != NULL) {
		printf("\t%d", ptr->data);
		ptr = ptr->next;
	}
	printf("\t%d", ptr->data);

	return start;
}


struct node *insertar(struct node *start) {

	struct node *ptr, *nuevoNodo;

	printf("\n\tIngrese -1 para salir.");
	printf("\n\tIngrese un elemento: ");
	int num;
	scanf("%d", &num);

	while(num != -1) {

		nuevoNodo = (struct node*)malloc(sizeof(struct node));
		nuevoNodo->data = num;

		ptr = start;

		while(ptr->next != NULL) {
			ptr = ptr->next;
		}

		ptr->next = nuevoNodo;
		nuevoNodo->next = NULL;

		printf("\n\tIngrese un elemento: ");
		scanf("%d", &num);

	}

	return start;
}


struct node *imprimirMinMax(struct node *start) {
	int min = start->data;
	int max = start->data;

	struct node *ptr = start;

	while(ptr->next != NULL) {

		if(min > ptr->data) {
			min = ptr->data;
		}
		if(max < ptr->data) {
			max = ptr->data;
		}

		ptr = ptr->next;
	}

	if(min > ptr->data) {
		min = ptr->data;
	}
	if(max < ptr->data) {
		max = ptr->data;
	}

	printf("\nEl valor minimo es: %d", min);
	printf("\nEl valor maximo es: %d", max);

	return start;
}
