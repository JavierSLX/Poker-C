#include "poker.h"
#include <assert.h>
#define N 10000
#define M 5

void pruebaQuitarJokers(void);
void pruebaRepartirMano(void);
void driverRepartirMano(void);
void pruebaImprimirMano(void);

/*int main()
{
    pruebaQuitarJokers();
    pruebaRepartirMano();
    driverRepartirMano();
    pruebaImprimirMano();
    return 0;
}*/

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

