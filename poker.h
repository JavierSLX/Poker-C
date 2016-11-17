#ifndef _POKER_H
#define _POKER_H

#include "baraja.h"
#define FONDO1 1000
#define FONDO2 1000
#define FONDO3 1000
#define FONDO4 1000

void quitarJokers(carta baraja[], carta nBaraja[]);
int repartirMano(carta baraja[], carta mano[], int n, int *carry, int max);
void imprimirMano(carta mano[]);
void asignarValor(carta baraja[], int length);
void ordenarCartas(carta monton[], int length);
int prioridadTipo(char tipo);
int sacarCarta(carta baraja[], carta mano[], int posicion, int carry, int max);
int cambios(carta baraja[], carta mano[], int *carry, int max);
void borde(int n);
void datos(carta mano[], int jugador, int fondo, int apuesta, int oculto);
int apostar(int *fondo, int *apuesta, int *total);

#endif
