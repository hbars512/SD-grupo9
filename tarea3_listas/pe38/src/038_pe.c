/*
 * 038_pe.c
 *
 *  Created on: Jul 8, 2020
 *      Author: grupo 9
 */


#include <stdio.h>
#include <malloc.h>
typedef struct nodo{
	int dato;
	struct nodo* siguiente;
} nodo;


nodo* primero = NULL;
nodo* ultimo = NULL;

void insertarNodo();
void eliminarNodo();
void desplegarLista();


int main(){
	int opcionMenu = 0;
	do{
		printf("\n--------------------------------");
		printf("\n 1. Insertar  ");
		printf("\n 2. Eliminar primer nodo ");
		printf("\n 3. Desplegar  ");
		printf("\n 4. Salir      ");
		printf("\n --------------------------------");
		printf("\n\n Escoja una Opcion: ");

		scanf("%d", &opcionMenu);
		switch(opcionMenu){
			case 1:
				printf("\n\n INSERTA NODO EN LA LISTA \n\n");
				insertarNodo();
				break;
			case 2:
				printf("\n\n ELIMINAR UN NODO DE LA LISTA \n\n");
				eliminarNodo();
				break;
			case 3:
				printf("\n\n DESPLEGAR LISTA DE NODOS \n\n");
				desplegarLista();
				break;
			case 4:
				printf("\n\n Programa finalizado... \n\n");
				eliminarNodo();
				break;
			default:
				printf("\n\n Opcion No Valida \n\n");
		}
	}while(opcionMenu != 4);
	return 0;
}


void insertarNodo(){
	nodo* nuevo = (nodo*) malloc(sizeof(nodo));
	printf(" Ingrese el dato que contendra el nuevo Nodo: ");
	scanf("%d",&nuevo->dato);

	if(primero==NULL){
		primero = nuevo;
		primero->siguiente = primero;
		ultimo = primero;
	}else{
		ultimo->siguiente = nuevo;
		nuevo->siguiente = primero;
		ultimo = nuevo;
	}
	printf("\n Nodo ingresado con exito\n\n");
}


void eliminarNodo(){
	nodo* actual = (nodo*)malloc(sizeof(nodo));
	actual = primero;
	nodo* anterior = (nodo*)malloc(sizeof(nodo));
	anterior = NULL;
	int encontrado = 0;

	if(primero!=NULL){

		if(actual==primero){
		primero = primero->siguiente;
		ultimo->siguiente = primero;
		}
		printf("\n Nodo Eliminado\n\n");
		encontrado = 1;
	}
		anterior = actual;
		actual = actual->siguiente;


		if(encontrado==0){
			printf("\n Nodo no Encontrado\n\n");
		}else{
			free(anterior);
		}

}

void desplegarLista(){
	nodo* actual = (nodo*)malloc(sizeof(nodo));
	actual = primero;
	if(primero!=NULL){
		do{
			printf("\n %d", actual->dato);
			actual = actual->siguiente;
		}while(actual!=primero);
	}else{
		printf("\n La lista se encuentra vaci\n\n");
	}
}
