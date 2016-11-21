#include "poker.h"

int main()
{
    int error;
    jugador humano;
    jugador pc1;
    jugador pc2;
    jugador pc3;
    int total = 0;
    carta baraja[54];
    int carry = 0;

    //Da los valores de inicio de cada jugador
    humano.apuesta = 0;
    humano.fondo = FONDO;
    pc1.apuesta = 0;
    pc1.fondo = FONDO;
    pc2.apuesta = 0;
    pc2.fondo = FONDO;
    pc3.apuesta = 0;
    pc3.fondo = FONDO;

    //Crea la baraja
    error = crearBaraja(baraja);

    if (error > 0)
        return 1;

    //Barajea el arreglo
    barajear(baraja);

    //Se le asigna valor a las cartas de acuerdo a las reglas del Poker
    asignarValor(baraja, 54);

    //Reparte las manos (de 2 a 4 jugadores)
    error = repartirMano(baraja, humano.mano, 5, &carry, 54);

    if (error > 0)
        return 1;

    error = repartirMano(baraja, pc1.mano, 5, &carry, 54);

    if (error > 0)
        return 1;

    error = repartirMano(baraja, pc2.mano, 5, &carry, 54);

    if (error > 0)
        return 1;

    error = repartirMano(baraja, pc3.mano, 5, &carry, 54);

    if (error > 0)
        return 1;

    //Ordena las cartas
    ordenarCartas(humano.mano, 5, 1);
    /*ordenarCartas(pc1.mano, 5, 1);
    ordenarCartas(pc2.mano, 5, 1);
    ordenarCartas(pc3.mano, 5, 1);*/

    //Imprime el tablero
    borde(80);
    datos(humano.mano, 1, humano.fondo, humano.apuesta, 0);
    /*datos(pc1.mano, 2, pc1.fondo, pc1.apuesta, 0);
    checarManoPC(pc1.mano, pc1.cambio);
    datos(pc2.mano, 3, pc2.fondo, pc2.apuesta, 0);
    datos(pc3.mano, 4, pc3.fondo, pc3.apuesta, 0);
    printf("\n\t\t\tTOTAL: $%d\n", total);*/
    borde(80);

    /*//Se hacen las apuestas
    error = apostar(&humano.fondo, &humano.apuesta, &total);

    if (error > 0)
        return 1;

    //Imprime el tablero
    system("cls");
    borde(80);
    datos(humano.mano, 1, humano.fondo, humano.apuesta, 0);
    datos(pc1.mano, 2, pc1.fondo, pc1.apuesta, 0);
    datos(pc2.mano, 3, pc2.fondo, pc2.apuesta, 0);
    datos(pc3.mano, 4, pc3.fondo, pc3.apuesta, 0);
    printf("\n\t\t\tTOTAL: $%d\n", total);
    borde(80);

    //Se cambian las cartas
    error = cambios(baraja, humano.mano, &carry, 54);
    ordenarCartas(humano.mano, 5, 1);

    //Imprime el tablero
    system("cls");
    borde(80);
    datos(humano.mano, 1, humano.fondo, humano.apuesta, 0);
    datos(pc1.mano, 2, pc1.fondo, pc1.apuesta, 0);
    datos(pc2.mano, 3, pc2.fondo, pc2.apuesta, 0);
    datos(pc3.mano, 4, pc3.fondo, pc3.apuesta, 0);
    printf("\n\t\t\tTOTAL: $%d\n", total);
    borde(80);

    //Aumenta la apuesta
    error = apostar(&humano.fondo, &humano.apuesta, &total);

    if (error > 0)
        return 1;

    //Imprime el tablero
    system("cls");
    borde(80);
    datos(humano.mano, 1, humano.fondo, humano.apuesta, 0);
    datos(pc1.mano, 2, pc1.fondo, pc1.apuesta, 0);
    datos(pc2.mano, 3, pc2.fondo, pc2.apuesta, 0);
    datos(pc3.mano, 4, pc3.fondo, pc3.apuesta, 0);
    printf("\n\t\t\tTOTAL: $%d\n", total);
    borde(80);*/

    //Libera la memoria de la baraja
    liberarMemoria(baraja, 54);

    return 0;
}
