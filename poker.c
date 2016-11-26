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
int checarManoPC (jugador hp)
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
        if (hp.mano[i].tipo == COMODIN)
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
            if (hp.mano[i].tipo == hp.mano[j].tipo && hp.mano[i].tipo != COMODIN)
                tipo++;
        }

        if (tipo > tp)
        {
            tp = tipo;
            tipo = 0;
            palo = hp.mano[i].tipo;
        }
    }
    tp++;

    //Datos que comprueban la mano
    printf("Tipo repetido %c en %d\n", palo, tp);
    //--------------------------------------------------------------------
    /*printf("\nEscalera real:\n");
    porcentaje = probarEscaleraReal(hp.mano, hp.cambio, palo, comodines);
    printf("%d\n\n", porcentaje);
    porcentaje = comprobarEscaleraReal(hp.mano, palo, comodines);
    if (porcentaje > 0)
        printf("Hay una escalera real(Carta alta: %d)\n", porcentaje);
    //--------------------------------------------------------------------
    printf("Escalera de color:\n");
    porcentaje = probarEscaleraColor(hp.mano, hp.cambio, palo, comodines);
    printf("%d\n\n", porcentaje);
    porcentaje = comprobarEscaleraColor(hp.mano, palo, comodines);
    if (porcentaje > 0)
        printf("Hay una escalera de color(Carta alta: %d)\n", porcentaje);*/
    //-----------------------------------------------------------
    printf("Trio:\n");
    porcentaje = probarTrio(hp.mano, hp.ventaja, comodines);
    for (i = 0; i < 5; i++)
        printf("%d ", hp.ventaja[i]);
    printf("\n");
    printf("%d para trio\n\n", porcentaje);
    porcentaje = comprobarTrio(hp.mano, comodines);
    if (porcentaje > 0)
        printf("Hay un trio (Carta alta: %d)\n", porcentaje);
    //----------------------------------------------------------
    printf("\nPar(es):\n");
    probarPar(hp.mano, hp.cambio);
    porcentaje = comprobarPares(hp.mano, hp.pares, comodines);
    printf("Pares: %d\n\n", porcentaje);
    if (porcentaje > 0)
        printf("Hay par(es): %d %d\n", hp.pares[0], hp.pares[1]);
    //-----------------------------------------------------------

    //Busca si es posible que pueda realizar una apuesta
    return porcentaje;
}

//Funcion que checa cuantas cartas son necesarias para formar una Escalera Real y regresa las posiciones necesarias también
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

//Checa si la mano posee una escalera real (regresa el valor más alto (14) en caso de existir
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

//Funcion que checa cuantas cartas son necesarias para formar una Escalera de Color y regresa las posiciones también necesarias
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

    //Obtiene el número menor del arreglo (no 0)
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

//Checa si la mano posee una escalera de color (regresa el valor de la carta más alta en caso de existir)
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

    //Obtiene el número menor del arreglo (no 0)
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

    //Regresa la carta más alta
    return ideal[4];
}

//Función que cual es la carta mas alta de la mano (sin contar los comodines) regresando el id de la carta
int cartaMasAlta (carta mano[])
{
    int i;
    int lugar = 0;
    int alta;

    alta = mano[0].valor;
    for (i = 1; i < 5; i++)
    {
        if (mano[i].valor > alta)
        {
           alta = mano[i].valor;
           lugar = i;
        }
    }

    return mano[lugar].id;
}

//En caso de no tener ninguna jugada, checa la carta más alta y reemplaza las demás para buscar formar un par
void probarPar (carta mano[], int posiciones[])
{
    int i;
    int id;

    //Ordena la mano por valor para poder analizarla
    ordenarCartas(mano, 5, 1);

    //Inicializa las cartas a descartar en -1
    inicioDescarte(posiciones);

    //Saca el ID de la carta más alta
    id = cartaMasAlta(mano);

    //Define que carta es la que no se va a cambiar
    for (i = 0; i < 5; i++)
    {
        if (mano[i].id == id)
            posiciones[i] = 0;
    }

    for (i = 0; i < 5; i++)
        printf("%d ", posiciones[i]);
    printf("\n");

    return;
}

//Checa cuantos pares contiene la mano, los registra en un arreglo pedido en un parámetro y regresa la cantidad de pares que tiene
int comprobarPares (carta mano[], int pares[], int comodines)
{
    int n = 0;
    int i, j;
    int par = 0;
    int numero;

    //Inicia el arreglo pares en 0
    for (i = 0; i < 2; i++)
        pares[i] = 0;

    //Busca el primer par
    if (comodines > 0)
    {
        numero = cartaMasAlta(mano);
        for (i = 0; i < 5; i++)
            if (numero == mano[i].id)
                pares[0] = mano[i].valor;
        n++;
    }
    else
    {
        for (i = 0; i < 5; i++)
        {
            for (j = 0; j < 5; j++)
            {
                if (mano[i].valor == mano[j].valor)
                    par++;

                if (par >= 2)
                {
                    pares[0] = mano[i].valor;
                    n++;
                    break;
                }
            }

            if (par >= 2)
                break;
            else
                par = 0;
        }
    }

    //Busca el segundo par en la mano
    par = 0;
    for (i = 0; i < 5; i++)
    {
        if (mano[i].valor == pares[0])
            continue;

        for (j = 0; j < 5; j++)
        {
            if (mano[i].valor == mano[j].valor)
                par++;

            if (par >= 2)
            {
                pares[1] = mano[i].valor;
                n++;
                break;
            }
        }

        if (par >= 2)
            break;
        else
            par = 0;
    }

    return n;
}

//Comprueba que cartas hay que cambiar en caso de que sea posible formar un trío (regresa las cartas que hacen falta para formarlo)
int probarTrio (carta mano[], int posiciones[], int comodines)
{
    int i, j;
    int alta;
    int valor = 0;
    int trio = 0;
    int pares[2] = {0};
    int par;

    //Ordena la mano por valor para poder analizarla
    ordenarCartas(mano, 5, 1);

    //Inicializa las cartas a descartar en -1
    inicioDescarte(posiciones);

    //Checa cuando hay comodines
    if (comodines > 1)
    {
        alta = cartaMasAlta(mano);
        for (i = 0; i < 5; i++)
        {
            if (mano[i].id == alta || mano[i].valor == -1)
                posiciones[i] = 0;
        }

        return 0;
    }
    else if (comodines == 1)
    {
        par = comprobarPares(mano, pares, 0);
        if (par > 0)
        {
            for (i = 0; i < 5; i++)
            {
                if (mano[i].valor == pares[0] || mano[i].valor == -1)
                {
                    posiciones[i] = 0;
                }
            }
            return 0;
        }
        else
        {
            alta = cartaMasAlta(mano);
            for (i = 0; i < 5; i++)
            {
                if (mano[i].id == alta || mano[i].valor == -1)
                {
                    posiciones[i] = 0;
                }
            }
            return 1;
        }
    }
    //Checa cuando no hay comodines
    else
    {
        par = comprobarPares(mano, pares, 0);
        if (par > 0)
        {
            for (i = 0; i < 5; i++)
            {
                if (mano[i].valor == pares[0] || mano[i].valor == -1)
                {
                    posiciones[i] = 0;
                }
            }
            return 1;
        }
        else
        {
            for (i = 0; i < 5; i++)
            {
                trio = 0;
                for (j = 0; j < 5; j++)
                {
                    if (mano[i].valor == mano[j].valor)
                    {
                        trio++;
                    }
                }

                if (trio > 2)
                {
                    valor = mano[i].valor;
                    break;
                }
            }

            for (i = 0; i < 5; i++)
            {
                if (mano[i].valor == valor)
                {
                    posiciones[i] = 0;
                }
            }

            if (valor > 0)
                return 0;
        }
    }

    return 3;
}

//Checa si existe un trio en la mano y regresa su valor en caso de existir
int comprobarTrio (carta mano[], int comodines)
{
    int i, j;
    int valor = 0;
    int id;
    int par;
    int trio = 0;
    int pares[2] = {0};

    switch(comodines)
    {
        case 2:
            id = cartaMasAlta(mano);
            for (i = 0; i < 5; i++)
                if (mano[i].id == id)
                    valor = mano[i].valor;
            break;
        case 1:
            par = comprobarPares(mano, pares, 0);

            if (par > 0)
                valor = pares[0];
            break;
        default:
            for (i = 0; i < 5; i++)
            {
                trio = 0;
                for (j = 0; j < 5; j++)
                {
                    if (mano[i].valor == mano[j].valor)
                        trio++;
                }

                if (trio > 2)
                {
                    valor = mano[i].valor;
                    break;
                }
            }
    }

    return valor;
}

