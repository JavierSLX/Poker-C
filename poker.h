#ifndef _POKER_H
#define _POKER_H

#include "baraja.h"

void quitarJokers(carta baraja[], carta nBaraja[]);
int repartirMano(carta baraja[], carta mano[], int n, int *carry, int max);

#endif
