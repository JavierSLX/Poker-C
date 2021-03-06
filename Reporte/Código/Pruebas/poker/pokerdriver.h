#ifndef _POKERDRIVER_H
#define _POKERDRIVER_H

#include "../../poker.h"
#include <assert.h>
#define N 10000
#define M 5

void pruebaQuitarJokers(void);
void pruebaRepartirMano(void);
void driverRepartirMano(void);
void pruebaImprimirMano(void);
void pruebaGeneralManos(void);
void pruebaAsignarValor(void);
void pruebaOrdenarCartas(void);
void pruebaSacarCarta(void);
void pruebaCambios(void);
void pruebaDatos(void);
void pruebaApostar(void);
void imprimirManoArc(carta mano[], FILE *f);
void pruebaCartaMasAlta(void);
void pruebaComprobarPares (void);
void pruebaComprobarTrio (void);
void pruebaComprobarEscalera(void);
void pruebaComprobarColor(void);
void pruebaComprobarFullHouse(void);
void pruebaComprobarPoker(void);
void pruebaComprobarEscaleraColor(void);
void pruebaComprobarEscaleraReal(void);
void pruebaRegistro(void);
void pruebaChecarMano(void);

#endif
