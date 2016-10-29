#include "poker.h"

//Quita los comodines de la baraja
void quitarJokers(carta baraja[], carta nBaraja[])
{
    int i;
    int cont = 0;

    for (i = 0; i < 54; i++)
        if (baraja[i].numero != -1)
        {
            nBaraja[cont] = baraja[i];
            cont++;
        }

    return ;
}

//Regresa un 1 en caso de no haber mas cartas para repartir
int repartirMano(carta baraja[], carta mano[], int n, int *carry, int max)
{
    int i;
    int cont = 0;

    //printf("Carry de entrada %d\n", *carry);
    if (*carry + n > max - 1)
        return 1;

    for (i = *carry; i < *carry + n; i++)
    {
        //printf("cont: %d carry: %d\n", cont, i);
        mano[cont] = baraja[i];
        cont++;
    }

    *carry += n;
    //printf("Carry de salida %d\n", *carry);
    return 0;
}


void imprimirMano(carta mano[])
{
    int i;

    for (i = 0; i < 5; i++)
        printf("Carta %d\t\t", i+1);

    printf("\n");
    for (i = 0; i < 5; i++)
    {
        imprimirElementoCarta(mano[i], 2);
        printf(" %c %s\t", mano[i].tipo, mano[i].color);
    }

    printf("\n");

    return;
}
