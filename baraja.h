#ifndef _BARAJA_H
#define _BARAJA_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ROJO "rojo"
#define NEGRO "negro"
#define SN "blanco"

typedef struct
{
    int id;
    int numero;
    int valor;
    char tipo;
    char *color;

}carta;

void imprimirElementoCarta (carta nombre, int n);
void imprimirCaractCarta(carta nombre);
void imprimirCaractBaraja(carta baraja[], int length);
int definirCarta(int id, int num, int value, char type, char* color, carta *elemento);
void liberarMemoria(carta baraja[], int length);
int crearBaraja(carta cartas[]);
void barajear (carta baraja[]);

#endif
