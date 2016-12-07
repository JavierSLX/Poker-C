#include "poker.h"

int main()
{
    int i;
    int me;
    int re;
    int error;
    int total;
    int n;
    int monto;
    int temp;
    int cont;
    int carry;
    int posicion;
    char nombre[10];
    carta baraja[54];
    jugador humano;
    jugador pc1;
    jugador pc2;
    jugador pc3;

    do
    {
        me = menu();
        humano.fondo = FONDO;
        switch(me)
        {
            case 1:
                //------------------------- *** CONFIGURACIÓN BÁSICA ** ---------------------------------
                //Da los valores de inicio de cada jugador
                humano.numero = 1;
                pc1.numero = 2;
                pc2.numero = 3;
                pc3.numero = 4;
                pc1.fondo = FONDO * 100;
                pc2.fondo = FONDO * 100;
                pc3.fondo = FONDO * 100;

                do
                {
                    humano.apuesta = 0;
                    pc1.apuesta = 0;
                    pc2.apuesta = 0;
                    pc3.apuesta = 0;
                    carry = 0;
                    total = 0;
                    system("cls");

                    //------------------------- *** BARAJEA Y REPARTE LAS MANOS ** ---------------------------------
                    //Crea la baraja
                    error = crearBaraja(baraja);

                    if (error > 0)
                    {
                        printf("ERROR. Desborde de baraja\n");
                        break;
                    }

                    //Barajea el arreglo
                    barajear(baraja);

                    //Se le asigna valor a las cartas de acuerdo a las reglas del Poker
                    asignarValor(baraja, 54);

                    //Reparte las manos (de 2 a 4 jugadores)
                    error = repartirMano(baraja, humano.mano, 5, &carry, 54);

                    if (error > 0)
                    {
                        printf("ERROR. Desborde de baraja\n");
                        break;
                    }

                    error = repartirMano(baraja, pc1.mano, 5, &carry, 54);

                    if (error > 0)
                    {
                        printf("ERROR. Desborde de baraja\n");
                        break;
                    }

                    error = repartirMano(baraja, pc2.mano, 5, &carry, 54);

                    if (error > 0)
                    {
                        printf("ERROR. Desborde de baraja\n");
                        break;
                    }

                    error = repartirMano(baraja, pc3.mano, 5, &carry, 54);

                    if (error > 0)
                    {
                        printf("ERROR. Desborde de baraja\n");
                        break;
                    }

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

                    printf("\n### SE ABREN LAS APUESTAS ###\n");
                    n = sacarMontoTotal(&humano, &pc1, &pc2, &pc3, 0, 1);

                    if (n == -1)
                        break;

                    total += n;

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

                    //------------------------- *** SE HACE EL PRIMER CAMBIO DE CARTAS DE LA MANO DEL JUGADOR *** ---------------------------------

                    printf("\n### PRIMERA RONDA DE CAMBIOS ###\n");

                    error = cambios(baraja, humano.mano, &carry, 54);
                    if(error > 1)
                    {
                        printf("ERROR. Desborde de baraja\n");
                        break;
                    }

                    //------------------------- *** SE HACEN LOS PRIMEROS CAMBIOS DE CARTAS DE LAS MANOS DE LOS DEMÁS *** ---------------------------------

                    monto = checarMano(&pc1);
                    temp = checarMano(&pc2);

                    if (temp > monto)
                        monto = temp;

                    temp = checarMano(&pc3);
                    if (temp > monto)
                        monto = temp;

                    //Cuenta las cartas a cambiar, manda el mensaje a pantalla y hace los cambios
                    cont = sacarCambios(pc1.cambio);
                    printf("El jugador 2 cambia %d carta(s)\n", cont);
                    for (i = 0; i < 5; i++)
                    {
                        if (pc1.cambio[i] == -1)
                        {
                            error = sacarCarta(baraja, pc1.mano, i, &carry, 54);

                            if (error > 0)
                                return 1;
                        }
                    }

                    cont = sacarCambios(pc2.cambio);
                    printf("El jugador 3 cambia %d carta(s)\n", cont);
                    for (i = 0; i < 5; i++)
                    {
                        if (pc2.cambio[i] == -1)
                        {
                            error = sacarCarta(baraja, pc2.mano, i, &carry, 54);

                            if (error > 0)
                                return 1;
                        }
                    }

                    cont = sacarCambios(pc3.cambio);
                    printf("El jugador 4 cambia %d carta(s)\n", cont);
                    for (i = 0; i < 5; i++)
                    {
                        if (pc3.cambio[i] == -1)
                        {
                            error = sacarCarta(baraja, pc3.mano, i, &carry, 54);

                            if (error > 0)
                                return 1;
                        }
                    }

                    system("pause");
                    system("cls");

                    //Ordena las cartas
                    ordenarCartas(humano.mano, 5, 1);
                    ordenarCartas(pc1.mano, 5, 1);
                    ordenarCartas(pc2.mano, 5, 1);
                    ordenarCartas(pc3.mano, 5, 1);

                    //Imprime el tablero
                    borde(80);
                    datos(humano, 0);
                    datos(pc1, 1);
                    datos(pc2, 1);
                    datos(pc3, 1);
                    printf("TOTAL = $%d\n\n", total);
                    borde(80);

                    //------------------------- *** SE HACE LA SEGUNDA RONDA DE APUESTAS *** ---------------------------------

                    printf("\n### SEGUNDA RONDA DE APUESTAS ###\n");

                    n = sacarMontoTotal(&humano, &pc1, &pc2, &pc3, monto, 2);

                    if (n == -1)
                        break;

                    total += n;

                    system("pause");
                    system("cls");

                    //Imprime el tablero
                    borde(80);
                    datos(humano, 0);
                    datos(pc1, 1);
                    datos(pc2, 1);
                    datos(pc3, 1);
                    printf("TOTAL = $%d\n\n", total);
                    borde(80);

                    //------------------------- *** SE HACE EL ULTIMO CAMBIO DE CARTAS DE LA MANO DEL JUGADOR *** ---------------------------------

                    printf("\n### ULTIMA RONDA DE CAMBIOS ###\n");
                    error = cambios(baraja, humano.mano, &carry, 54);

                    if (error > 0)
                    {
                        printf("ERROR. Desborde de baraja\n");
                        break;
                    }

                    //------------------------- *** SE HACEN LOS ULTIMOS CAMBIOS DE CARTAS DE LAS MANOS DE LOS DEMÁS *** ---------------------------------

                    monto = checarMano(&pc1);
                    temp = checarMano(&pc2);

                    if (temp > monto)
                        monto = temp;

                    temp = checarMano(&pc3);
                    if (temp > monto)
                        monto = temp;

                    //Cuenta las cartas a cambiar, manda el mensaje a pantalla y hace los cambios
                    cont = sacarCambios(pc1.cambio);
                    printf("El jugador 2 cambia %d carta(s)\n", cont);
                    for (i = 0; i < 5; i++)
                    {
                        if (pc1.cambio[i] == -1)
                        {
                            error = sacarCarta(baraja, pc1.mano, i, &carry, 54);

                            if (error > 0)
                                return 1;
                        }
                    }

                    cont = sacarCambios(pc2.cambio);
                    printf("El jugador 3 cambia %d carta(s)\n", cont);
                    for (i = 0; i < 5; i++)
                    {
                        if (pc2.cambio[i] == -1)
                        {
                            error = sacarCarta(baraja, pc2.mano, i, &carry, 54);

                            if (error > 0)
                                return 1;
                        }
                    }

                    cont = sacarCambios(pc3.cambio);
                    printf("El jugador 4 cambia %d carta(s)\n", cont);
                    for (i = 0; i < 5; i++)
                    {
                        if (pc3.cambio[i] == -1)
                        {
                            error = sacarCarta(baraja, pc3.mano, i, &carry, 54);

                            if (error > 0)
                                return 1;
                        }
                    }

                    system("pause");
                    system("cls");

                    //Ordena las cartas
                    ordenarCartas(humano.mano, 5, 1);
                    ordenarCartas(pc1.mano, 5, 1);
                    ordenarCartas(pc2.mano, 5, 1);
                    ordenarCartas(pc3.mano, 5, 1);

                    //Imprime el tablero
                    borde(80);
                    datos(humano, 0);
                    datos(pc1, 1);
                    datos(pc2, 1);
                    datos(pc3, 1);
                    printf("TOTAL = $%d\n\n", total);
                    borde(80);

                    //------------------------- *** SE HACE LA ULTIMA RONDA DE APUESTAS *** ---------------------------------
                    printf("\n### ULTIMA RONDA DE APUESTAS ###\n");

                    n = sacarMontoTotal(&humano, &pc1, &pc2, &pc3, monto, 3);

                    if (n == -1)
                        break;

                    total += n;

                    system("pause");
                    system("cls");

                    //Imprime el tablero
                    borde(80);
                    datos(humano, 0);
                    datos(pc1, 1);
                    datos(pc2, 1);
                    datos(pc3, 1);
                    printf("TOTAL = $%d\n\n", total);
                    borde(80);

                    //------------------------- *** SE DESTAPAN LAS MANOS Y SE CHECA QUIEN ES EL GANADOR *** ---------------------------------
                    checarMano(&humano);
                    checarMano(&pc1);
                    checarMano(&pc2);
                    checarMano(&pc3);
                    printf("\nHORA DEL DESTAPE!\n");
                    system("pause");

                    //------------------------- *** SE IMPRIME LA JUGADA DE LA MANO DEL JUGADOR *** ---------------------------------
                    system("cls");
                    //Imprime el tablero
                    borde(80);
                    datos(humano, 0);
                    datos(pc1, 1);
                    datos(pc2, 1);
                    datos(pc3, 1);
                    printf("TOTAL = $%d\n\n", total);
                    borde(80);

                    printf("\n### DESTAPES! ###\n");
                    printf("\nJUGADOR:\n");
                    mensajeManoJugada(humano.jugada, humano.ventaja);
                    system("pause");

                    //------------------------- *** SE IMPRIME LA JUGADA DE LA MANO PC1 *** ---------------------------------
                    system("cls");
                    //Imprime el tablero
                    borde(80);
                    datos(humano, 0);
                    datos(pc1, 0);
                    datos(pc2, 1);
                    datos(pc3, 1);
                    printf("TOTAL = $%d\n\n", total);
                    borde(80);

                    printf("\n### DESTAPES! ###\n");
                    printf("\nJUGADOR:\n");
                    mensajeManoJugada(humano.jugada, humano.ventaja);
                    printf("\nPC1:\n");
                    mensajeManoJugada(pc1.jugada, pc1.ventaja);
                    system("pause");

                    //------------------------- *** SE IMPRIME LA JUGADA DE LA MANO DE PC2 *** ---------------------------------
                    system("cls");
                    //Imprime el tablero
                    borde(80);
                    datos(humano, 0);
                    datos(pc1, 0);
                    datos(pc2, 0);
                    datos(pc3, 1);
                    printf("TOTAL = $%d\n\n", total);
                    borde(80);

                    printf("\n### DESTAPES! ###\n");
                    printf("\nJUGADOR:\n");
                    mensajeManoJugada(humano.jugada, humano.ventaja);
                    printf("\nPC1:\n");
                    mensajeManoJugada(pc1.jugada, pc1.ventaja);
                    printf("\nPC2:\n");
                    mensajeManoJugada(pc2.jugada, pc2.ventaja);
                    system("pause");

                    //------------------------- *** SE IMPRIME LA JUGADA DE LA MANO DE PC3 *** ---------------------------------
                    system("cls");
                    //Imprime el tablero
                    borde(80);
                    datos(humano, 0);
                    datos(pc1, 0);
                    datos(pc2, 0);
                    datos(pc3, 0);
                    printf("TOTAL = $%d\n\n", total);
                    borde(80);

                    printf("\n### DESTAPES! ###\n");
                    printf("\nJUGADOR:\n");
                    mensajeManoJugada(humano.jugada, humano.ventaja);
                    printf("\nPC1:\n");
                    mensajeManoJugada(pc1.jugada, pc1.ventaja);
                    printf("\nPC2:\n");
                    mensajeManoJugada(pc2.jugada, pc2.ventaja);
                    printf("\nPC3:\n");
                    mensajeManoJugada(pc3.jugada, pc3.ventaja);
                    system("pause");

                    //------------------------- *** IMPRIME QUIEN GANÓ *** ---------------------------------

                    system("cls");
                    //Imprime el tablero
                    borde(80);
                    datos(humano, 0);
                    datos(pc1, 0);
                    datos(pc2, 0);
                    datos(pc3, 0);
                    printf("TOTAL = $%d\n\n", total);
                    borde(80);

                    printf("\n### PREMIACION ###\n");
                    switch(analizarGanador(humano, pc1, pc2, pc3))
                    {
                        case 1:
                            printf("\nJUGADOR GANADOR!\n");
                            mensajeManoJugada(humano.jugada, humano.ventaja);
                            printf("Obtiene $%d\n", total);
                            humano.fondo += total;
                            break;
                        case 2:
                            printf("\nPC1 GANADOR!\n");
                            mensajeManoJugada(pc1.jugada, pc1.ventaja);
                            printf("Obtiene $%d\n", total);
                            pc1.fondo += total;
                            break;
                        case 3:
                            printf("\nPC2 GANADOR!\n");
                            mensajeManoJugada(pc2.jugada, pc2.ventaja);
                            printf("Obtiene $%d\n", total);
                            pc2.fondo += total;
                            break;
                        default:
                            printf("\nPC3 GANADOR!\n");
                            mensajeManoJugada(pc3.jugada, pc3.ventaja);
                            printf("Obtiene $%d\n", total);
                            pc3.fondo += total;
                    }

                    //Libera la memoria de la baraja
                    liberarMemoria(baraja, 54);

                    //Pregunta al usuario si quiere seguir jugando
                    do
                    {
                        printf("\nQuiere seguir jugando(1=Si/2=No): ");
                        scanf("%d", &re);

                        if (re < 1 || re > 2)
                            printf("Opcion no registrada\n");

                    }while(re < 1 || re > 2);
                }while(re == 1);

                break;
            case 2:
                mostrarMarcadores();
                break;
            default:
               me = 3;
        }

         posicion = checarRegistro(humano.fondo);

        if (posicion >= 0)
        {
            printf("\n\nFelicidades! Puedes ingresar tu nombre a los marcadores\nNombre: ");
            fflush(stdin);
            gets(nombre);
            fflush(stdin);

            nuevoRegistro(nombre, humano.fondo, posicion);
            printf("\nRegistro completo\n\n");
            system("pause");
        }

    }while(me >= 1 && me <= 2);

    return 0;
}
