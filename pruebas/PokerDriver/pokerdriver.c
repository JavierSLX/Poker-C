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
    prueba.mano[0].numero = 9;
    prueba.mano[0].tipo = ESPADA;
    prueba.mano[0].valor = 9;
    prueba.mano[0].color = NEGRO;

    prueba.mano[1].id = 2;
    prueba.mano[1].numero = 7;
    prueba.mano[1].tipo = TREBOL;
    prueba.mano[1].valor = 7;
    prueba.mano[1].color = NEGRO;

    prueba.mano[2].id = 3;
    prueba.mano[2].numero = 11;
    prueba.mano[2].tipo = CORAZON;
    prueba.mano[2].valor = 11;
    prueba.mano[2].color = ROJO;

    prueba.mano[3].id = 4;
    prueba.mano[3].numero = 10;
    prueba.mano[3].tipo = ESPADA;
    prueba.mano[3].valor = 10;
    prueba.mano[3].color = NEGRO;

    prueba.mano[4].id = 12;
    prueba.mano[4].numero = 8;
    prueba.mano[4].tipo = CORAZON;
    prueba.mano[4].valor = 8;
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
    //datos(prueba.mano, 1, prueba.fondo, prueba.apuesta, 0);
    borde(80);

    //Pruebas las manos que pueden ser obtenidas
    //checarManoPC(prueba);
    //checarManoPC(humano);


    liberarMemoria(baraja, 54);
    return;
}

void pruebaAsignarValor(void)
{
    int i;
    carta baraja[54];

    for (i = 0; i < N; i++)
    {
        crearBaraja(baraja);
        barajear(baraja);
        asignarValor(baraja, 54);

        liberarMemoria(baraja, 54);
    }

    printf("Se asigno valores a %d barajas de manera correcta!\n", N);
    return;
}

void pruebaOrdenarCartas(void)
{
    int i;
    carta baraja[54];
    int carry;
    carta mano[5];

    for (i = 0; i < N; i++)
    {
        carry = 0;
        crearBaraja(baraja);
        barajear(baraja);
        repartirMano(baraja, mano, 5, &carry, 54);
        ordenarCartas(mano, 5, i%2);
        liberarMemoria(baraja, 54);
    }

    printf("Se ordenaron %d manos distintas de manera satisfactoria\n", N);
}

void pruebaSacarCarta(void)
{
    int i;
    carta baraja[54];
    carta mano[5];
    int carry;

    for (i = 0; i < N; i++)
    {
        carry = 0;
        crearBaraja(baraja);
        barajear(baraja);
        repartirMano(baraja, mano, 5, &carry, 54);
        //imprimirMano(mano);
        sacarCarta(baraja, mano, 0, &carry, 54);
        //imprimirMano(mano);
        liberarMemoria(baraja, 54);
    }

    printf("Se sacaron %d cartas de manera exitosa!\n", N);

    return;
}

void pruebaCambios(void)
{
    int cont = 0;
    int carry = 0;
    carta baraja[54];
    carta mano[5];

    crearBaraja(baraja);
    barajear(baraja);
    repartirMano(baraja, mano, 5, &carry, 54);

    do
    {
        printf("C: %d\n", carry);
        cambios(baraja, mano, &carry, 54);
        cont++;
        printf("Cont: %d | Carry: %d\n", cont, carry);
        imprimirMano(mano);

    }while(carry < 54);

    printf("Se hicieron %d cambios satisfactorios con un carry de %d\n", cont, carry);
    liberarMemoria(baraja, 54);
    return;
}

void pruebaDatos(void)
{
    int i;
    int carry;
    carta baraja[54];
    jugador prueba;
    jugador pc;

    prueba.numero = 1;
    pc.numero = 2;

    for (i = 0; i < N; i++)
    {
        carry = 0;
        crearBaraja(baraja);
        barajear(baraja);
        asignarValor(baraja, 54);

        repartirMano(baraja, prueba.mano, 5, &carry, 54);
        repartirMano(baraja, pc.mano, 5, &carry, 54);

        datos(prueba, i%2);
        datos(pc, i%2);
        liberarMemoria(baraja, 54);
    }
    return;
}

void pruebaApostar(void)
{
    int total = 0;
    int error = 0;
    jugador prueba;
    jugador pc;

    prueba.numero = 1;
    pc.numero = 2;

    do
    {
        prueba.fondo = FONDO;
        pc.fondo = FONDO;
        prueba.apuesta = 0;
        pc.apuesta = 0;

        printf("Ingresar 0\n");
        error = apostar(&prueba.fondo, &prueba.apuesta, &total, 1, 0);

    }while(prueba.apuesta != 0);
    assert(error == 1);

    do
    {
        prueba.fondo = FONDO;
        pc.fondo = FONDO;
        prueba.apuesta = 0;
        pc.apuesta = 0;

        printf("Ingrese la misma apuesta para jugador como para PC(500)\n");
        error = apostar (&prueba.fondo, &prueba.apuesta, &total, prueba.numero, 0);
        error = apostar (&pc.fondo, &pc.apuesta, &total, pc.numero, 500);

    }while(prueba.apuesta != pc.apuesta || prueba.apuesta >= FONDO);
    assert(total == 1000);
    assert(prueba.apuesta == 500);
    assert(pc.apuesta == 500);
    assert(prueba.fondo == 500);
    assert(pc.fondo == 500);

    do
    {
        prueba.fondo = FONDO;
        prueba.apuesta = 0;
        total = 0;

        printf("Ingrese una cantidad menor que 500\n");
        error = apostar (&prueba.fondo, &prueba.apuesta, &total, prueba.numero, 0);

    }while(prueba.apuesta > 500);
    assert((total + prueba.fondo) == FONDO);

    return;
}

