#include "poker.h"

int main()
{
    int error;
    int vacio;
    carta baraja[54];
    carta mano1[5];
    carta mano2[5];
    int carry = 0;

    error = crearBaraja(baraja);
    if(error > 0)
    {
        printf("Error al crear la baraja\n");
    }
    else
    {
        barajear(baraja);
        asignarValor(baraja, 54);

        vacio = repartirMano(baraja, mano1, 5, &carry, 54);
        if (vacio == 0)
        {
            vacio = repartirMano(baraja, mano2, 5, &carry, 54);

            if (vacio == 0)
            {
                ordenarCartas(mano1, 5);
                ordenarCartas(mano2, 5);
                imprimirMano(mano1);
                printf("-------------------\n\n");
                //imprimirMano(mano2);
                printf("\n\n");
                cambios(baraja, mano1, &carry, 54);
                imprimirMano(mano1);
                printf("-------------------\n\n");
                ordenarCartas(mano1, 5);
                imprimirMano(mano1);
                printf("carry: %d\n", carry);
            }
            else
            {
                printf("Cartas insuficientes\n");
            }
        }
    }

    liberarMemoria(baraja, 54);

    return 0;
}

/*Asignación de memoria dinamica
char *memoria;

//Se asigna dinamicamente la memoria para guardar una cadena
memoria = malloc(strlen(NEGRO) * sizeof(char));

//Se verifica si se hizo, en caso de hacerlo lo guarda en la memoria
if(memoria == NULL)
{
    printf("Error al asignar la memoria\n");
}
else
{
    strcpy(memoria, NEGRO);
}

free(memoria);
*/
