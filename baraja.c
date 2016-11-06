#include "baraja.h"

//Valores de n: 1 = id, 2 = numero, 3 = valor, 4 = tipo y 5 = color. Imprime el valor sin espacios ni secuencias de escape
void imprimirElementoCarta (carta nombre, int n)
{
    switch(n)
    {
        case 1:
            printf("%d", nombre.id);
            break;
        case 2:
            if (nombre.numero == -1)
                printf("N");
            else if (nombre.numero == 1)
                printf("A");
            else if (nombre.numero > 1 && nombre.numero <= 10)
                printf("%d", nombre.numero);
            else
            {
                switch(nombre.numero)
                {
                    case 11:
                        printf("J");
                        break;
                    case 12:
                        printf("Q");
                        break;
                    default:
                        printf("K");
                }
            }
            break;
        case 3:
            printf("%d", nombre.valor);
            break;
        case 4:
            printf("%c", nombre.tipo);
            break;
        default:
            printf("%s", nombre.color);
    }

    return ;
}

//Imprime las características de un elemento tipo carta
void imprimirCaractCarta(carta nombre)
{
    printf("ID: ");
    imprimirElementoCarta (nombre, 1);
    printf("\n");
    printf("Numero: ");
    imprimirElementoCarta (nombre, 2);
    printf("\n");
    printf("Valor: ");
    imprimirElementoCarta (nombre, 3);
    printf("\n");
    printf("Tipo: ");
    imprimirElementoCarta (nombre, 4);
    printf("\n");
    printf("Color: ");
    imprimirElementoCarta (nombre, 5);
    printf("\n");

    return ;
}

//Imprime las caracteristicas de un arreglo tipo carta (una baraja)
void imprimirCaractBaraja(carta baraja[], int length)
{
    int i;

    for (i = 0; i < length; i++)
    {
        imprimirCaractCarta(baraja[i]);
        printf("\n");
    }

    return ;
}

//Se crea una carta con sus distintos tipos de caracteristicas (regresa un 1 solamente si hubo error al asignar memoria)
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

//Libera la memoria usada en los elementos carta (en este caso libera lo de todo un arreglo)
void liberarMemoria(carta baraja[], int length)
{
    int i;

    for (i = 0; i < length; i++)
        free(baraja[i].color);
}

//Crea todas las caracteristicas que contiene una baraja inglesa (54 cartas) y sus distintos elementos
//(regresa 1 solamente si hay error de asignación de memoria).
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

    error = definirCarta(53, -1, 0, 'N', SN, &baraja[52]);
    error = definirCarta(54, -1, 0, 'N', SN, &baraja[53]);

    return 0;
}

//Desordena el arreglo para que las cartas puedan salir siempre en un orden distinto
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

    return ;
}
