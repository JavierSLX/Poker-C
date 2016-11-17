#include "poker.h"

int main()
{
    int error;
    int apuesta1 = 0;
    int apuesta2 = 0;
    int apuesta3 = 0;
    int apuesta4 = 0;
    int total = 0;
    carta baraja[54];
    carta mano1[5];
    carta mano2[5];
    carta mano3[5];
    carta mano4[5];
    int fondo1 = FONDO1;
    int fondo2 = FONDO2;
    int fondo3 = FONDO3;
    int fondo4 = FONDO4;
    int carry = 0;

    //Crea la baraja
    error = crearBaraja(baraja);

    if (error > 0)
        return 1;

    //Barajea el arreglo
    barajear(baraja);

    //Reparte las manos (de 2 a 4 jugadores)
    error = repartirMano(baraja, mano1, 5, &carry, 54);

    if (error > 0)
        return 1;

    error = repartirMano(baraja, mano2, 5, &carry, 54);

    if (error > 0)
        return 1;

    error = repartirMano(baraja, mano3, 5, &carry, 54);

    if (error > 0)
        return 1;

    error = repartirMano(baraja, mano4, 5, &carry, 54);

    if (error > 0)
        return 1;

    //Ordena las cartas
    ordenarCartas(mano1, 5);
    ordenarCartas(mano2, 5);
    ordenarCartas(mano3, 5);
    ordenarCartas(mano4, 5);

    //Imprime el tablero
    borde(80);
    datos(mano1, 1, fondo1, apuesta1, 0);
    datos(mano2, 2, fondo2, apuesta2, 0);
    datos(mano3, 3, fondo3, apuesta3, 0);
    datos(mano4, 4, fondo4, apuesta4, 0);
    printf("\n\t\t\tTOTAL: $%d\n", total);
    borde(80);

    //Se hacen las apuestas
    error = apostar(&fondo1, &apuesta1, &total);

    if (error > 0)
        return 1;

    //Imprime el tablero
    system("cls");
    borde(80);
    datos(mano1, 1, fondo1, apuesta1, 0);
    datos(mano2, 2, fondo2, apuesta2, 0);
    datos(mano3, 3, fondo3, apuesta3, 0);
    datos(mano4, 4, fondo4, apuesta4, 0);
    printf("\n\t\t\tTOTAL: $%d\n", total);
    borde(80);

    //Se cambian las cartas
    error = cambios(baraja, mano1, &carry, 54);
    ordenarCartas(mano1, 5);

    //Imprime el tablero
    system("cls");
    borde(80);
    datos(mano1, 1, fondo1, apuesta1, 0);
    datos(mano2, 2, fondo2, apuesta2, 0);
    datos(mano3, 3, fondo3, apuesta3, 0);
    datos(mano4, 4, fondo4, apuesta4, 0);
    printf("\n\t\t\tTOTAL: $%d\n", total);
    borde(80);

    //Aumenta la apuesta
    error = apostar(&fondo1, &apuesta1, &total);

    if (error > 0)
        return 1;

    //Imprime el tablero
    system("cls");
    borde(80);
    datos(mano1, 1, fondo1, apuesta1, 0);
    datos(mano2, 2, fondo2, apuesta2, 0);
    datos(mano3, 3, fondo3, apuesta3, 0);
    datos(mano4, 4, fondo4, apuesta4, 0);
    printf("\n\t\t\tTOTAL: $%d\n", total);
    borde(80);

    //Libera la memoria de la baraja
    liberarMemoria(baraja, 54);

    return 0;
}
