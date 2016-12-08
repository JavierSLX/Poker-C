#include "barajadriver.h"

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

//Pruebas Unitarias de la funcion
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

        imprimirCaractCarta (elemento);
        printf("\n");
        free(elemento.color);
    }

    return ;
}

//Pruebas Unitarias de la funcion
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

//Funcion imprimirCaractBaraja
//Prueba la funcion N numero de veces
void pruebaICaractBaraja(void)
{
    int azar;
    int i;
    carta baraja[N];
    srand(time(NULL));

    for (i = 0; i < N; i++)
    {
        azar = 1 + rand() % 54;
        baraja[i].id = azar;
        //printf("%d - %d\n", i, 1);

        azar = rand() % 14;
        if (azar == 0)
            azar = -1;
        baraja[i].numero = azar;
        //printf("%d - %d\n", i, 2);

        azar = 1 + rand() % 14;
        baraja[i].valor = azar;
        //printf("%d - %d\n",i, 3);

        azar = rand() % 4;
        switch(azar)
        {
            case 0:
                baraja[i].tipo = 'E';
                break;
            case 1:
                baraja[i].tipo = 'T';
                break;
            case 2:
                baraja[i].tipo = 'C';
                break;
            default:
                baraja[i].tipo = 'R';
        }
        //printf("%d - %d\n",i, 4);

        azar = rand() % 3;
        switch(azar)
        {
            case 0:
                baraja[i].color = malloc(strlen(ROJO) * sizeof(char));
                strcpy(baraja[i].color, ROJO);
                break;
            case 1:
                baraja[i].color = malloc(strlen(NEGRO) * sizeof(char));
                strcpy(baraja[i].color, NEGRO);
                break;
            default:
                baraja[i].color = malloc(strlen(SN) * sizeof(char));
                strcpy(baraja[i].color, SN);
        }
        //printf("%d - %d\n", i, 5);
        printf("Carta %d creada\n", i + 1);
    }

    imprimirCaractBaraja(baraja, N);
    liberarMemoria(baraja, N);
    return ;
}

//Pruebas Unitarias de la funcion
void driverICaractBaraja(void)
{
    carta baraja[54];

    crearBaraja(baraja);
    imprimirCaractBaraja(baraja, 54);
    liberarMemoria(baraja, 54);
    return ;
}

//Funcion definirCarta
//Prueba la funcion N numero de veces
void pruebaDefinirCarta(void)
{
    int id, numero, valor, aT, aC;
    char tipo;
    char *color;
    int error;
    int i;
    carta elemento;
    srand(time(NULL));

    for (i = 0; i < N; i++)
    {
        id = 1 + rand() % 54;

        numero = rand() % 14;
        if (numero == 0)
            numero = -1;

        valor = 1 + rand() % 14;

        aT = rand() % 4;
        switch(aT)
        {
            case 0:
                tipo = 'E';
                break;
            case 1:
                tipo = 'T';
                break;
            case 2:
                tipo = 'C';
                break;
            default:
                tipo = 'R';
        }

        aC = rand() % 3;
        switch(aC)
        {
            case 0:
                color = malloc(strlen(ROJO) * sizeof(char));
                strcpy(color, ROJO);
                break;
            case 1:
                color = malloc(strlen(NEGRO) * sizeof(char));
                strcpy(color, NEGRO);
                break;
            default:
                color = malloc(strlen(SN) * sizeof(char));
                strcpy(color, SN);
        }

        error = definirCarta(id, numero, valor, tipo, color, &elemento);

        if (error == 1)
        {
            printf("Error al asignar memoria\n");
        }
        else
        {
            imprimirCaractCarta (elemento);
            printf("\n");
        }
        free(elemento.color);
        free(color);
    }

    return ;
}

//Pruebas Unitarias de la funcion
void driverDefinirCarta(void)
{
    int id, numero, valor, aT, aC;
    int i;
    char tipo;
    char *color;
    int error;
    carta original;
    carta copia;
    srand(time(NULL));

    id = 1 + rand() % 54;
    copia.id = id;
    //printf("ID = %d\n", copia.id);

    numero = rand() % 14;
    if (numero == 0)
        numero = -1;
    copia.numero = numero;
    //printf("Numero = %d\n", copia.numero);

    valor = 1 + rand() % 14;
    copia.valor = valor;
    //printf("Valor = %d\n", copia.valor);

    aT = rand() % 4;
    switch(aT)
    {
        case 0:
            tipo = 'E';
            break;
        case 1:
            tipo = 'T';
            break;
        case 2:
            tipo = 'C';
            break;
        default:
            tipo = 'R';
    }
    copia.tipo = tipo;
    //printf("Tipo = %c\n", copia.tipo);

    aC = rand() % 3;
    switch(aC)
    {
        case 0:
            color = malloc(strlen(ROJO) * sizeof(char));
            strcpy(color, ROJO);
            break;
        case 1:
            color = malloc(strlen(NEGRO) * sizeof(char));
            strcpy(color, NEGRO);
            break;
        default:
            color = malloc(strlen(SN) * sizeof(char));
            strcpy(color, SN);
    }
    copia.color = color;
    //printf("Color = %s\n", copia.color);

    imprimirCaractCarta(copia);
    printf("\n");
    error = definirCarta(id, numero, valor, tipo, color, &original);

    if (error == 1)
    {
        printf("Error al asignar memoria\n");
    }
    else
    {
        assert(original.id == copia.id);
        assert(original.numero == copia.numero);
        assert(original.valor == copia.valor);
        assert(original.tipo == copia.tipo);

        for (i = 0; i < strlen(original.color); i++)
            assert(*(original.color + i) == *(copia.color + i));

        imprimirCaractCarta(original);
    }

    free(color);
    //free(original.color);
    //free(copia.color);
    return;
}

//Funcion liberarMemoria
//Prueba la funcion N numero de veces
void pruebaLiberarMemoria(void)
{
    int id, numero, valor, aT, aC;
    char tipo;
    char *color;
    int error;
    int i;
    carta arreglo[N];
    srand(time(NULL));

    for (i = 0; i < N; i++)
    {
        id = 1 + rand() % 54;

        numero = rand() % 14;
        if (numero == 0)
            numero = -1;

        valor = 1 + rand() % 14;

        aT = rand() % 4;
        switch(aT)
        {
            case 0:
                tipo = 'E';
                break;
            case 1:
                tipo = 'T';
                break;
            case 2:
                tipo = 'C';
                break;
            default:
                tipo = 'R';
        }

        aC = rand() % 3;
        switch(aC)
        {
            case 0:
                color = malloc(strlen(ROJO) * sizeof(char));
                strcpy(color, ROJO);
                break;
            case 1:
                color = malloc(strlen(NEGRO) * sizeof(char));
                strcpy(color, NEGRO);
                break;
            default:
                color = malloc(strlen(SN) * sizeof(char));
                strcpy(color, SN);
        }

        error = definirCarta(id, numero, valor, tipo, color, &arreglo[i]);

        if (error == 1)
        {
            printf("Error al asignar memoria\n");
        }
        else
        {
            imprimirCaractCarta (arreglo[i]);
            printf("\n");
        }

        //printf("%s\n", arreglo[i].color);
        free(color);

    }

    liberarMemoria(arreglo, N);
    printf("Liberacion de memoria de %d elementos exitoso!\n", N);
    return;
}

//Funcion crearBaraja
//Prueba la funcion creando 100 arreglos barajas
void pruebaCrearBaraja(void)
{
    int i;
    int error;
    carta baraja[54];

    for (i = 0; i < 100; i++)
    {
        error = crearBaraja(baraja);

        if (error > 0)
            printf("Error al crear la baraja\n");
        else
            imprimirCaractBaraja(baraja, 54);

        liberarMemoria(baraja, 54);
    }

    return;
}

//Funcion barajear
//Prueba la funcion barajeando 100 barajas
void pruebaBarajear(void)
{
    int i;
    int error;
    carta baraja[54];

    for (i = 0; i < 100; i++)
    {
        error = crearBaraja(baraja);

        if (error > 0)
        {
            printf("Error al crear la baraja\n");
            return;
        }
        else
        {
            barajear(baraja);
            imprimirCaractBaraja(baraja, 54);
        }
    }

    return;
}


