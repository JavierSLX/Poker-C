#include "baraja.h"
#define N 10000

void pruebaIElemCart(void);
void driverIElemCart(void);
void pruebaICaractCarta(void);
void driverICaractCarta(void);

int main()
{
    //pruebaIElemCart();
    //driverIElemCart();
    //pruebaICaractCarta();
    //driverICaractCarta();
    return 0;
}

//Funcion imprimirElementoCarta
//Prueba la funcion N numero de veces
void pruebaIElemCart(void)
{
    int azar;
    int i;
    carta elemento;
    srand(time(NULL));

    for (i = 0; i < N; i++)
    {
        azar = 1 + rand() % 54;
        elemento.id = azar;

        azar = rand() % 14;
        if (azar == 0)
            azar = -1;
        elemento.numero = azar;

        azar = 1 + rand() % 14;
        elemento.valor = azar;

        azar = rand() % 4;
        switch(azar)
        {
            case 0:
                elemento.tipo = 'E';
                break;
            case 1:
                elemento.tipo = 'T';
                break;
            case 2:
                elemento.tipo = 'C';
                break;
            default:
                elemento.tipo = 'R';
        }

        azar = rand() % 3;
        switch(azar)
        {
            case 0:
                elemento.color = malloc(strlen(ROJO) * sizeof(char));
                strcpy(elemento.color, ROJO);
                break;
            case 1:
                elemento.color = malloc(strlen(NEGRO) * sizeof(char));
                strcpy(elemento.color, NEGRO);
                break;
            default:
                elemento.color = malloc(strlen(SN) * sizeof(char));
                strcpy(elemento.color, SN);
        }

        azar = 1 + rand() % 5;
        imprimirElementoCarta (elemento, azar);
        printf("\n");
        free(elemento.color);
    }


    return ;
}

void driverIElemCart(void)
{
    carta elemento;
    elemento.id = 9;
    elemento.numero = 10;
    elemento.valor = 14;
    elemento.tipo = 'T';
    elemento.color = malloc(strlen(NEGRO) * sizeof(char));
    strcpy(elemento.color, NEGRO);

    //Ruta 1 (1, 2, 15)
    printf("%d = ", elemento.id);
    imprimirElementoCarta(elemento, 1);
    printf("\n");

    //Ruta 2 (1, 3, 4, 15)
    elemento.numero = -1;
    printf("%d = ", elemento.numero);
    imprimirElementoCarta(elemento, 2);
    printf("\n");

    //Ruta 3 (1, 3, 4, 5, 15)
    elemento.numero = 1;
    printf("%d = ", elemento.numero);
    imprimirElementoCarta(elemento, 2);
    printf("\n");

    //Ruta 4 (1, 3, 4, 5, 6, 7, 15)
    printf("%d = ", elemento.numero);
    imprimirElementoCarta(elemento, 2);
    printf("\n");

    //Ruta 5 (NO VALIDA)

    //Ruta 6 (1, 3, 4, 5, 6, 7, 8, 11, 15)
    elemento.numero = 13;
    printf("%d = ", elemento.numero);
    imprimirElementoCarta(elemento, 2);
    printf("\n");

    //Ruta 7 (1, 3, 4, 5, 6, 7, 8, 10, 15)
    elemento.numero = 12;
    printf("%d = ", elemento.numero);
    imprimirElementoCarta(elemento, 2);
    printf("\n");

    //Ruta 8 (1, 3, 4, 5, 6, 7, 8, 9, 15)
    elemento.numero = 11;
    printf("%d = ", elemento.numero);
    imprimirElementoCarta(elemento, 2);
    printf("\n");

    //Ruta 9 (1, 12, 15)
    printf("%d = ", elemento.valor);
    imprimirElementoCarta(elemento, 3);
    printf("\n");

    //Ruta 10 (1, 13, 15)
    printf("%c = ", elemento.tipo);
    imprimirElementoCarta(elemento, 4);
    printf("\n");

    //Ruta 11 (1, 14, 15)
    printf("%s = ", elemento.color);
    imprimirElementoCarta(elemento, 5);
    printf("\n");

    free (elemento.color);
    return ;
}

//Funcion imprimirCaractCarta
//Prueba la funcion N numero de veces
void pruebaICaractCarta(void)
{
    int azar;
    int i;
    carta elemento;
    srand(time(NULL));

    for (i = 0; i < N; i++)
    {
        azar = 1 + rand() % 54;
        elemento.id = azar;

        azar = rand() % 14;
        if (azar == 0)
            azar = -1;
        elemento.numero = azar;

        azar = 1 + rand() % 14;
        elemento.valor = azar;

        azar = rand() % 4;
        switch(azar)
        {
            case 0:
                elemento.tipo = 'E';
                break;
            case 1:
                elemento.tipo = 'T';
                break;
            case 2:
                elemento.tipo = 'C';
                break;
            default:
                elemento.tipo = 'R';
        }

        azar = rand() % 3;
        switch(azar)
        {
            case 0:
                elemento.color = malloc(strlen(ROJO) * sizeof(char));
                strcpy(elemento.color, ROJO);
                break;
            case 1:
                elemento.color = malloc(strlen(NEGRO) * sizeof(char));
                strcpy(elemento.color, NEGRO);
                break;
            default:
                elemento.color = malloc(strlen(SN) * sizeof(char));
                strcpy(elemento.color, SN);
        }

        azar = 1 + rand() % 5;
        imprimirCaractCarta (elemento);
        printf("\n");
        free(elemento.color);
    }

    return ;
}

void driverICaractCarta(void)
{
    carta elemento;
    elemento.id = 10;
    elemento.numero = 1;
    elemento.valor = 8;
    elemento.tipo = 'N';
    elemento.color = malloc(strlen(SN) * sizeof(char));
    strcpy(elemento.color, SN);

    //Valores de la carta
    printf("ID: %d, Numero: %d, Valor: %d, Tipo: %c, Color: %s\n\n",
           elemento.id, elemento.numero, elemento.valor, elemento.tipo, elemento.color);

    //Valores de la carta en funcion
    imprimirCaractCarta(elemento);

    free(elemento.color);
    return;
}

