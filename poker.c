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
void ordenarCartas(carta monton[], int length, int v)
{
    int i, j;
    carta temp;

    //Ordena las cartas por tipo
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

    //Ordena las cartas por valor o por numero segun se requiera
    if (v > 0)
    {
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
    }
    else
    {
        for (i = 1; i < length; i++)
        {
            for (j = 0; j < length - 1; j++)
            {
                if ((monton[j].numero > monton[j+1].numero) && (monton[j].tipo == monton[j+1].tipo))
                {
                    temp = monton[j];
                    monton[j] = monton[j+1];
                    monton[j+1] = temp;
                }
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

//Inicializa todo el arreglo de descarte a -1
void inicioDescarte(int a[])
{
    int i;

    for (i = 0; i < 5; i++)
        a[i] = -1;

    return;
}

//Checa la mano de la PC y toma la decision de cuanto apuesta y que cartas cambiar
int checarManoPC (carta mano[], int descarte[])
{
    int porcentaje = 0;
    int i, j;
    int tipo = 0;
    int comodines = 0;
    int tp = 0;
    char palo;

    //Busca si hay comodines
    for (i = 0; i < 5; i++)
    {
        if (mano[i].tipo == COMODIN)
        {
            comodines++;
        }
    }
    printf("\nDATOS BASICOS\n");
    printf("Comodines: %d\n", comodines);

    //Busca si la mano tiene cartas del mismo tipo
    tipo = 0;
    for (i = 0; i < 4; i++)
    {
        for (j = i+1; j < 5; j++)
        {
            if (mano[i].tipo == mano[j].tipo && mano[i].tipo != COMODIN)
                tipo++;
        }

        if (tipo > tp)
        {
            tp = tipo;
            tipo = 0;
            palo = mano[i].tipo;
        }
    }
    tp++;

    //Datos que comprueban la mano
    printf("Tipo repetido %c en %d\n", palo, tp);

    //-------------------------------------
    printf("\nEscalera real:\n");
    porcentaje = probarEscaleraReal(mano, descarte, palo, comodines);
    printf("%d\n\n", porcentaje);
    porcentaje = comprobarEscaleraReal(mano, palo, comodines);
    if (porcentaje > 0)
        printf("Hay una escalera real(Carta alta: %d)\n", porcentaje);
    printf("Escalera de color:\n");
    porcentaje = probarEscaleraColor(mano, descarte, palo, comodines);
    printf("%d\n\n", porcentaje);
    porcentaje = comprobarEscaleraColor(mano, palo, comodines);
    if (porcentaje > 0)
        printf("Hay una escalera de color(Carta alta: %d)\n", porcentaje);
    //--------------------------------------

    //Busca si es posible que pueda realizar una apuesta
    return porcentaje;
}

//Funcion que checa cuantas cartas son necesarias para formar una Escalera Real y regresa las posiciones necesarias tambi�n
int probarEscaleraReal (carta mano[], int posiciones[], char palo, int comodines)
{
    int i, j;
    int falta = 0;
    int coincidencia = 0;
    int ideal[5] = {10, 11, 12, 13, 14};
    int orden[5] = {0};
    int com = comodines;

    //Ordena las cartas por valor
    ordenarCartas(mano, 5, 1);

    //Inicializa las cartas a descartar en -1
    inicioDescarte(posiciones);

    //Saca el orden que tiene las cartas del mismo tipo en un arreglo
    for (i = 0; i < 5; i++)
    {
        if (mano[i].tipo == palo)
            orden[i] = mano[i].valor;
    }

    //Busca coincidencias entre el arreglo orden y el ideal
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (orden[i] == ideal[j])
            {
                coincidencia++;
                posiciones[i] = 0;
            }
        }
    }

    //Termina de definir el arreglo de cambios
    for (i = 0; i < 5; i++)
    {
        if (com > 0 && posiciones[i] == -1)
        {
            posiciones[i] = 0;
            com--;
        }
    }

    //Calcula las cartas a cambiar
    coincidencia += comodines;
    falta = 5 - coincidencia;

    //Datos de comprobacion de la funcion
    printf("\nCambios para escalera real:\n");
    for (i = 0; i < 5; i++)
        printf("%d ", posiciones[i]);
    printf("\n");

    return falta;
}

//Checa si la mano posee una escalera real (regresa el valor m�s alto (14) en caso de existir
int comprobarEscaleraReal (carta mano[], char tipo, int comodines)
{
    int i, j;
    int coincidencia = 0;
    int ideal[5] = {10, 11, 12, 13, 14};
    int orden[5] = {0};

    //Ordena las cartas por valor
    ordenarCartas(mano, 5, 1);

    //Saca el orden que tiene las cartas del mismo tipo en un arreglo
    for (i = 0; i < 5; i++)
    {
        if (mano[i].tipo == tipo)
            orden[i] = mano[i].valor;
    }

    //Busca coincidencias entre el arreglo orden y el ideal
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (orden[i] == ideal[j])
            {
                coincidencia++;
            }
        }
    }

    coincidencia += comodines;

    if (coincidencia == 5)
        return 14;
    else
        return 0;
}

//Funcion que checa cuantas cartas son necesarias para formar una Escalera de Color y regresa las posiciones tambi�n necesarias
int probarEscaleraColor(carta mano[], int posiciones[], char palo, int comodines)
{
    int i, j;
    int falta = 0;
    int coincidencia = 0;
    int inicio;
    int ideal[5] = {0};
    int orden[5] = {0};
    int com = comodines;

    //Ordena la mano por numero para poder analizarla
    ordenarCartas(mano, 5, 0);

    //Inicializa las cartas a descartar en -1
    inicioDescarte(posiciones);

    //Saca el orden que tiene las cartas del mismo tipo en un arreglo
    for (i = 0; i < 5; i++)
    {
        if (mano[i].tipo == palo)
            orden[i] = mano[i].numero;
    }

    //Obtiene el n�mero menor del arreglo (no 0)
    inicio = 14;
    for (i = 0; i < 5; i++)
    {
        if ((inicio > orden[i]) && (orden[i] != 0))
        {
            inicio = orden[i];
        }
    }

    //Forma el arreglo ideal para formar una escalera
    for (i = 0; i < 5; i++)
    {
        ideal[i] = inicio;
        inicio++;
    }

    //Busca coincidencias entre el arreglo orden y el ideal
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (orden[i] == ideal[j])
            {
                coincidencia++;
                posiciones[i] = 0;
                //printf("%d ", orden[i]);
            }
        }
    }

    //Termina de definir el arreglo de cambios
    for (i = 0; i < 5; i++)
    {
        if (com > 0 && posiciones[i] == -1)
        {
            posiciones[i] = 0;
            com--;
        }
    }

    //Calcula las cartas a cambiar
    coincidencia += comodines;
    falta = 5 - coincidencia;

    //Datos de comprobacion de la funcion
    printf("\nCambios para escalera color:\n");
    for (i = 0; i < 5; i++)
        printf("%d ", posiciones[i]);
    printf("\n");

    return falta;
}

//Checa si la mano posee una escalera de color (regresa el valor de la carta m�s alta en caso de existir)
int comprobarEscaleraColor (carta mano[], char tipo, int comodines)
{
    int i, j;
    int inicio;
    int cont = 0;
    int orden[5] = {0};
    int ideal[5];

    //Ordena la mano por numero para poder analizarla
    ordenarCartas(mano, 5, 0);

    //Saca el orden que tiene las cartas del mismo tipo en un arreglo
    for (i = 0; i < 5; i++)
    {
        if (mano[i].tipo == tipo)
            orden[i] = mano[i].numero;
    }

    //Obtiene el n�mero menor del arreglo (no 0)
    inicio = 14;
    for (i = 0; i < 5; i++)
    {
        if ((inicio > orden[i]) && (orden[i] != 0))
        {
            inicio = orden[i];
        }
    }

    //Forma el arreglo ideal para formar una escalera
    for (i = 0; i < 5; i++)
    {
        ideal[i] = inicio;
        inicio++;
    }

    //Busca coincidencias entre el arreglo orden y el ideal
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (orden[i] == ideal[j])
            {
                cont++;
            }
        }
    }

    if ((cont + comodines) < 5)
        return 0;

    //Regresa la carta m�s alta
    return ideal[4];
}

