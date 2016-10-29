#include "baraja.h"

void imprimirCaractCarta(carta nombre)
{
    char letra;

    printf("ID: %d\n", nombre.id);

    if (nombre.numero == -1)
        printf("Numero: N\n");
    else if (nombre.numero == 1)
        printf("Numero: A\n");
    else if (nombre.numero <= 10)
        printf("Numero: %d\n", nombre.numero);
    else
    {
        switch(nombre.numero)
        {
            case 11:
                letra = 'J';
                break;
            case 12:
                letra = 'Q';
                break;
            default:
                letra = 'K';
        }
        printf("Numero: %c\n", letra);
    }
    printf("Valor: %d\nTipo: %c\nColor: %s\n\n", nombre.valor, nombre.tipo, nombre.color);

    return ;
}

void imprimirCaractBaraja(carta baraja[], int length)
{
    int i;
    char letra;

    for (i = 0; i < length; i++)
    {
        printf("ID: %d\n", baraja[i].id);

        if (baraja[i].numero == -1)
            printf("Numero: N\n");
        else if (baraja[i].numero == 1)
            printf("Numero: A\n");
        else if (baraja[i].numero <= 10)
            printf("Numero: %d\n", baraja[i].numero);
        else
        {
            switch(baraja[i].numero)
            {
                case 11:
                    letra = 'J';
                    break;
                case 12:
                    letra = 'Q';
                    break;
                default:
                    letra = 'K';
            }
            printf("Numero: %c\n", letra);
        }
        printf("Valor: %d\nTipo: %c\nColor: %s\n\n", baraja[i].valor, baraja[i].tipo, baraja[i].color);
    }

    return ;
}

int definirCarta(int id, int num, int value, char type, char* color, carta *elemento)
{
    elemento->id = id;
    elemento->numero = num;
    elemento->valor = value;
    elemento->tipo = type;
    elemento->color = malloc(strlen(color) * sizeof(char)); //Se asigna dinamicamente la memoria para guardar una cadena

    //Se verifica si se hizo, en caso de hacerlo lo guarda en la memoria
    if(elemento->color == NULL)
    {
        printf("Error al asignar la memoria en id = %d\n", id);
        return 1;
    }
    else
    {
        strcpy(elemento->color, color);
    }

    return 0;
}

void liberarMemoria(carta baraja[], int length)
{
    int i;

    for (i = 0; i < length; i++)
        free(baraja[i].color);
}

int crearBaraja(carta baraja[])
{
    int i, a;
    int error;
    int id = 0;

    //Da un id, un numero, un valor (por lo pronto es 0), un tipo y un color
    for (a = 0; a < 4; a++)
    {
        for (i = 0; i < 13; i++)
        {
            switch(a)
            {
                case 0:
                    error = definirCarta(id+1, i+1, 0, 'E', NEGRO, &baraja[id]);
                    break;
                case 1:
                    error = definirCarta(id+1, i+1, 0, 'T', NEGRO, &baraja[id]);
                    break;
                case 2:
                    error = definirCarta(id+1, i+1, 0, 'C', ROJO, &baraja[id]);
                    break;
                default:
                    error = definirCarta(id+1, i+1, 0, 'R', ROJO, &baraja[id]);

            }

            if (error > 0)
                return 1;

            id++;
        }
    }

    error = definirCarta(53, -1, 0, 'N', "S/C", &baraja[52]);
    error = definirCarta(54, -1, 0, 'N', "S/C", &baraja[53]);

    return 0;
}

void barajear (carta baraja[])
{
    int i;
    int cont = 0;
    int azar;
    srand(time(NULL));
    int temp[54];
    carta prov[54];

    for (i = 0; i < 54; i++)
    {
        temp[i] = -1;
    }

    //Crea un arreglo de numeros al azar
    for (i = 0; i < 54; )
    {
        azar = rand() % 54;

        if (temp[azar] == -1)
        {
            temp[azar] = cont;
            cont++;
            i++;
        }
    }

    //Imprimir
    /*for (i = 0; i < 54; i++)
    {
        printf("%d\n", temp[i]);
    }*/

    //Crea la nueva baraja

    for (i = 0; i < 54; i++)
    {
        prov[temp[i]] = baraja[i];
    }

    for (i = 0; i < 54; i++)
    {
        baraja[i] = prov[i];
    }

    //liberarMemoria(prov, 54);
    return ;
}
