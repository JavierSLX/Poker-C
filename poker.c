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

    if (*carry + n > max)
        return 1;

    for (i = *carry; i < *carry + n; i++)
    {
        mano[cont] = baraja[i];
        cont++;
    }

    *carry += n;
    return 0;
}

//Imprime la mano del jugador (hecha solamente para que la vea el usuario)
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

    printf("\n\n");

    return;
}

//Asigna el valor a la carta
void asignarValor(carta baraja[], int length)
{
    int i;

    for (i = 0; i < length; i++)
    {
        if (baraja[i].numero == 1)
        {
            baraja[i].valor = 14;
        }
        else
        {
            baraja[i].valor = baraja[i].numero;
        }
    }
    return;
}

//Ordena la mano de forma ascendente y por tipo
void ordenarCartas(carta monton[], int length)
{
    int i, j;
    carta temp;

    for (i = 1; i < length; i++)
    {
        for (j = 0; j < length - 1; j++)
        {
            if (prioridadTipo(monton[j].tipo) > prioridadTipo(monton[j+1].tipo))
            {
                temp = monton[j];
                monton[j] = monton[j+1];
                monton[j+1] = temp;
            }
        }
    }

    for (i = 1; i < length; i++)
    {
        for (j = 0; j < length - 1; j++)
        {
            if ((monton[j].valor > monton[j+1].valor) && (monton[j].tipo == monton[j+1].tipo))
            {
                temp = monton[j];
                monton[j] = monton[j+1];
                monton[j+1] = temp;
            }
        }
    }

    return;
}

//Saca la prioridad de ordenamiento de los tipos de carta
int prioridadTipo (char tipo)
{
    int valor;

    switch (tipo)
    {
        case ESPADA:
            valor = 2;
            break;
        case TREBOL:
            valor = 3;
            break;
        case CORAZON:
            valor = 4;
            break;
        case ROMBO:
            valor = 5;
            break;
        default:
            valor = 1;
    }

    return valor;
}

//Reemplaza una carta por otra que se saca de la baraja
int sacarCarta(carta baraja[], carta mano[], int posicion, int carry, int max)
{
    if (carry + 1 > max)
        return 1;

    mano[posicion] = baraja[carry];

    carry++;

    return 0;
}

//Realiza los cambios de cartas que el jugador necesita
int cambios(carta baraja[], carta mano[], int *carry, int max)
{
    int i, j;
    int cont = 0;
    int n;
    int p;
    int *memory = NULL;
    int error;

    do
    {
        printf("\nCuantas cartas quiere cambiar: ");
        scanf("%d", &n);

        if (n < 0)
            printf("Eso es imposible\n");

        if (n > 5)
            printf("Solo es permitido cambiar como maximo 5 cartas\n");

    }while (n < 0 || n > 5);

    if (n != 0)
    {
        memory = malloc (n * sizeof(int));

        for (i = 0; i < n; i++)
        {
            do
            {
                do
                {
                    printf("Que carta quiere cambiar?(1-5): ");
                    scanf("%d", &p);

                    if (p < 1 || p > 5)
                    printf("Tal carta no existe, elija una correcta\n");

                }while(p < 1 || p > 5);

                for (j = 0; j < n; j++)
                {
                    if (*(memory + j) == p)
                    {
                        printf("Esa carta acaba de recibirla\n");
                        break;
                    }
                }

            }while (*(memory + j) == p);

            *(memory + cont) = p;
            cont++;

            printf("\nCambio carta (%d): ", p);
            imprimirElementoCarta(mano[p-1], 2);
            printf(" %c %s -----> ", mano[p-1].tipo, mano[p-1].color);

            error = sacarCarta(baraja, mano, p-1, *carry, max);

            if (error > 0)
                return 1;

            *carry += 1;

            imprimirElementoCarta(mano[p-1], 2);
            printf(" %c %s\t\n\n", mano[p-1].tipo, mano[p-1].color);
        }

        free(memory);
    }

    return 0;
}

//Imprime un borde
void borde(int n)
{
    int i;

    for (i = 0; i < n; i++)
        printf("%c", 205);

    printf("\n");
    return;
}

//Imprime los datos basicos de un jugador
void datos(carta mano[], int jugador, int fondo, int apuesta, int oculto)
{
    int i;

    if (jugador == 1)
    {
        printf("--> JUGADOR <--\n");
    }
    else
    {
        printf("--> PC%d <--\n", jugador-1);
    }

    if (oculto > 0)
    {
        for (i = 0; i < 5; i++)
            printf("Carta %d\t\t", i+1);

        printf("\n");
        for (i = 0; i < 5; i++)
           printf("* * ****\t");

        printf("\n\nFondo: $%d\n", fondo);
        printf("Apuesta: $%d\n\n", apuesta);
    }
    else
    {
        imprimirMano(mano);
        printf("Fondo: $%d\n", fondo);
        printf("Apuesta: $%d\n\n", apuesta);
    }

    return;
}

//Pregunta al usuario cuanto quiere apostar (regresa 1 si el jugador decide retirarse)
int apostar(int *fondo, int *apuesta, int *total)
{
    int cantidad;

    do
    {
        printf("\nCuando quiere apostar (0 = retirarse): ");
        scanf("%d", &cantidad);

        if (cantidad == 0)
            return 1;

        if (cantidad > *fondo)
            printf("\nNo tiene suficiente dinero para apostar\n");

    }while(cantidad > *fondo);

    *fondo -= cantidad;
    *total += cantidad;
    *apuesta += cantidad;

    return 0;
}

