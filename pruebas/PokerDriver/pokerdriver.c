#include "pokerdriver.h"

void pruebaQuitarJokers(void)
{
    int i;
    carta old[54];
    carta nueva[52];

    for (i = 0; i < N; i++)
    {
        crearBaraja(old);
        barajear(old);
        quitarJokers(old, nueva);
        imprimirCaractBaraja(nueva, 52);
        liberarMemoria(old, 54);
    }

    liberarMemoria(nueva, 52);
    return;
}

void pruebaRepartirMano(void)
{
    int i;
    int fin;
    int error;
    int carry = 0;
    carta mano[M];
    carta baraja[54];

    error = crearBaraja(baraja);
    barajear(baraja);

    if (error > 0)
    {
        printf("Error al crear la baraja\n");
        return;
    }

    for (i = 0; i < N; i++)
    {


        fin = repartirMano(baraja, mano, M, &carry, 54);

        if (fin > 0)
        {
            barajear(baraja);
            carry = 0;
        }
        else
        {
            imprimirCaractBaraja(mano, M);
        }
    }

    liberarMemoria(baraja, 54);
    liberarMemoria(mano, M);
    return;
}

void driverRepartirMano(void)
{
    int i;
    int fin;
    int error;
    int carry = 0;
    carta mano[M];
    carta baraja[54];

    error = crearBaraja(baraja);
    barajear(baraja);

    if (error > 0)
    {
        printf("Error al crear la baraja\n");
        return;
    }

    for (i = 0; ; i++)
    {

        fin = repartirMano(baraja, mano, M, &carry, 54);

        if (fin > 0)
        {
            printf("Tras %d particiones, la baraja no alcanza para dar mas manos\n", 54 / M);
            printf("Carry: %d\n", carry);
            break;
        }
        else
        {
            imprimirCaractBaraja(mano, M);
            printf("Carry: %d\n", carry);
            assert(carry == (M * (i+1)));
            system("cls");
        }
    }

    liberarMemoria(baraja, 54);
    liberarMemoria(mano, M);
    return;
}

void pruebaImprimirMano(void)
{
    int i;
    int fin;
    int error;
    int carry = 0;
    carta mano[5];
    carta baraja[54];

    error = crearBaraja(baraja);
    barajear(baraja);

    if (error > 0)
    {
        printf("Error al crear la baraja\n");
        return;
    }

    for (i = 0; i < N; i++)
    {


        fin = repartirMano(baraja, mano, 5, &carry, 54);

        if (fin > 0)
        {
            barajear(baraja);
            carry = 0;
        }
        else
        {
            imprimirMano(mano);
        }
    }

    liberarMemoria(baraja, 54);
    liberarMemoria(mano, 5);
    return;
}

void pruebaGeneralManos(void)
{
    int error;
    int carry = 0;
    carta baraja[54];
    jugador prueba;
    jugador humano;

    prueba.mano[0].id = 1;
    prueba.mano[0].numero = 2;
    prueba.mano[0].tipo = ESPADA;
    prueba.mano[0].valor = 2;
    prueba.mano[0].color = NEGRO;

    prueba.mano[1].id = 2;
    prueba.mano[1].numero = 1;
    prueba.mano[1].tipo = ESPADA;
    prueba.mano[1].valor = 14;
    prueba.mano[1].color = NEGRO;

    prueba.mano[2].id = 3;
    prueba.mano[2].numero = 1;
    prueba.mano[2].tipo = TREBOL;
    prueba.mano[2].valor = 14;
    prueba.mano[2].color = NEGRO;

    prueba.mano[3].id = 4;
    prueba.mano[3].numero = 1;
    prueba.mano[3].tipo = CORAZON;
    prueba.mano[3].valor = 14;
    prueba.mano[3].color = ROJO;

    prueba.mano[4].id = 12;
    prueba.mano[4].numero = 1;
    prueba.mano[4].tipo = ROMBO;
    prueba.mano[4].valor = 14;
    prueba.mano[4].color = ROJO;

    //Crea la baraja
    error = crearBaraja(baraja);

    if (error > 0)
        return;

    //Barajea el arreglo
    barajear(baraja);

    //Se le asigna valor a las cartas de acuerdo a las reglas del Poker
    asignarValor(baraja, 54);

    //Reparte las manos (de 2 a 4 jugadores)
    error = repartirMano(baraja, humano.mano, 5, &carry, 54);

    //Ordena las cartas
    ordenarCartas(humano.mano, 5, 1);
    ordenarCartas(prueba.mano, 5, 1);

    //Imprime el tablero
    borde(80);
    //datos(humano.mano, 1, humano.fondo, humano.apuesta, 0);
    datos(prueba.mano, 1, prueba.fondo, prueba.apuesta, 0);
    borde(80);

    //Pruebas las manos que pueden ser obtenidas
    checarManoPC(prueba);
    //checarManoPC(humano);


    liberarMemoria(baraja, 54);
    return;
}
