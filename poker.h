#ifndef _POKER_H
#define _POKER_H

#include "baraja.h"
#define FONDO 1000

typedef struct
{
    carta mano[5];
    int apuesta;
    int fondo;
    int cambio[5];
    int pares[2];
    int ventaja[13];

}jugador;

void quitarJokers(carta baraja[], carta nBaraja[]);
int repartirMano(carta baraja[], carta mano[], int n, int *carry, int max);
void imprimirMano(carta mano[]);
void asignarValor(carta baraja[], int length);
void ordenarCartas(carta monton[], int length, int v);
int prioridadTipo(char tipo);
int sacarCarta(carta baraja[], carta mano[], int posicion, int carry, int max);
int cambios(carta baraja[], carta mano[], int *carry, int max);
void borde(int n);
void datos(carta mano[], int jugador, int fondo, int apuesta, int oculto);
int apostar(int *fondo, int *apuesta, int *total);
void inicioDescarte(int a[]);

int probarEscaleraReal (carta mano[], int posiciones[], char palo, int comodines);
int comprobarEscaleraReal (carta mano[], char tipo, int comodines);
int probarEscaleraColor(carta mano[], int posiciones[], char palo, int comodines);
int comprobarEscaleraColor (carta mano[], char tipo, int comodines);
int checarManoPC (jugador hp);

int cartaMasAlta (carta mano[]);
void probarPar (carta mano[], int posiciones[]);
int comprobarPares (carta mano[], int pares[], int comodines);
int probarTrio (carta mano[], int posiciones[], int comodines);
int comprobarTrio (carta mano[], int comodines);
int comprobarPoker (carta mano[], int comodines);
int probarPoker (carta mano[], int posiciones[], int comodines);
int comprobarFullHouse (carta mano[], int comodines);
int probarFullHouse (carta mano[], int posiciones[], int comodines);


#endif
