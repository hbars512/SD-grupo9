/*
 * pila_vectores.c
 *
 *  Created on: Jul 15, 2020
 *      Author: Grupo 9
 */

#include <stdio.h>
#define MAXPILA 100
#define ERRORPILALLENA -1
#define ERRORPILAVACIA -2


typedef struct Pila {
  int datos[MAXPILA];
  int tope;
} tPila;

int pilaVacia(tPila *aPila) {
  if (aPila->tope = -1) {
    return 1;
  } else {
    return 0;
  }
}

int empila(tPila *aPila, int dato)
{
  if (pilaLlena(aPila)) {
    return ERRORPILALLENA;
  } else {
    aPila->tope = aPila->tope + 1;
    aPila->datos[aPila->tope] = dato;
    return aPila->tope;
  }
}
