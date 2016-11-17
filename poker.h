#ifndef _POKER_H
#define _POKER_H

#include "baraja.h"

void quitarJokers(carta baraja[], carta nBaraja[]);
int repartirMano(carta baraja[], carta mano[], int n, int *carry, int max);
void imprimirMano(carta mano[]);
void asignarValor(carta baraja[], int length);
void ordenarCartas(carta monton[], int length);
int prioridadTipo(char tipo);
int sacarCarta(carta baraja[], carta mano[], int posicion, int carry, int max);
int cambios(carta baraja[], carta mano[], int *carry, int max);

#endif
