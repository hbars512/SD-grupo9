/*
 * fila.c
 *
 *  Created on: Jul 15, 2020
 *      Author: Grupo 9
 */

#include <stdio.h>
#define MAXFILA 100
#define ERRORFILALLENA -1
#define ERRORFILAVACIA -2


typedef struct Fila {
  int dato[MAXFILA];
  int tope;
} aFila;

int filaVacia() {
  if (aFila.tope = -1) {
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
    aFila.tope = aFila.tope + 1;
    aFila.datos[aFila.tope] = dato;
    return aFila.tope;
  }
}
