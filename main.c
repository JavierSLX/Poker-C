#include "poker.h"

int main()
{
    int error;
    jugador humano;
    jugador pc1;
    jugador pc2;
    jugador pc3;
    int total = 0;
    int monto;
    carta baraja[54];
    int carry = 0;
    srand(time(NULL));

    //------------------------- *** CONFIGURACIÓN BÁSICA ** ---------------------------------
    //Da los valores de inicio de cada jugador
    humano.numero = 1;
    pc1.numero = 2;
    pc2.numero = 3;
    pc3.numero = 4;
    humano.apuesta = 0;
    humano.fondo = FONDO;
    pc1.apuesta = 0;
    pc1.fondo = FONDO;
    pc2.apuesta = 0;
    pc2.fondo = FONDO;
    pc3.apuesta = 0;
    pc3.fondo = FONDO;

    //------------------------- *** BARAJEA Y REPARTE LAS MANOS ** ---------------------------------
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
    ordenarCartas(pc1.mano, 5, 1);
    ordenarCartas(pc2.mano, 5, 1);
    ordenarCartas(pc3.mano, 5, 1);

    //Imprime el tablero (oculto)
    borde(80);
    datos(humano, 1);
    datos(pc1, 1);
    datos(pc2, 1);
    datos(pc3, 1);
    borde(80);

    //------------------------- *** SE PIDE LA PRIMERA APUESTA ** ---------------------------------

    total = sacarMontoTotal(&humano, &pc1, &pc2, &pc3, 1);

    if (total == -1)
        return 1;

    system("pause");


    //------------------------- *** SE DESTAPA LA MANO DEL HUMANO ** ---------------------------------
    system("cls");
    //Imprime el tablero
    borde(80);
    datos(humano, 0);
    datos(pc1, 1);
    datos(pc2, 1);
    datos(pc3, 1);
    printf("TOTAL = $%d\n\n", total);
    borde(80);

    //Checa las manos de las PC
    checarManoPC(humano);
    checarManoPC(pc1);
    checarManoPC(pc2);
    checarManoPC(pc3);
    /*
    //Se hacen las apuestas
    error = apostar(&humano.fondo, &humano.apuesta, &total, humano.numero, 0);

    if (error > 0)
        return 1;

    //Imprime el tablero
    system("cls");
    borde(80);
    datos(humano, 0);
    datos(pc1, 0);
    datos(pc2, 0);
    datos(pc3, 0);
    printf("\n\t\t\tTOTAL: $%d\n", total);
    borde(80);

    //Se cambian las cartas
    error = cambios(baraja, humano.mano, &carry, 54);
    ordenarCartas(humano.mano, 5, 1);

    //Imprime el tablero
    system("cls");
    borde(80);
    datos(humano, 0);
    datos(pc1, 0);
    datos(pc2, 0);
    datos(pc3, 0);
    printf("\n\t\t\tTOTAL: $%d\n", total);
    borde(80);

    //Aumenta la apuesta
    error = apostar(&humano.fondo, &humano.apuesta, &total, humano.numero, 0);

    if (error > 0)
        return 1;

    //Imprime el tablero
    system("cls");
    borde(80);
    datos(humano, 0);
    datos(pc1, 0);
    datos(pc2, 0);
    datos(pc3, 0);
    printf("\n\t\t\tTOTAL: $%d\n", total);
    borde(80);
    */

    //Libera la memoria de la baraja
    liberarMemoria(baraja, 54);

    return 0;
}
