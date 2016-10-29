#include "poker.h"

int main()
{
    int error;
    carta baraja[54];
    //carta sinComodines[52];
    carta mano1[5];
    carta mano2[5];
    int carry = 0;

    //Creacion de baraja y barajear
    error = crearBaraja(baraja);
    barajear(baraja);

    //Quita los comodines y crea una nueva baraja
    //quitarJokers(baraja, sinComodines);

    //Reparte dos manos
    error = repartirMano(baraja, mano1, 5, &carry, 54);
    //imprimirCaractBaraja(mano1, 5);
    imprimirMano(mano1);
    printf("-----------------------------------------------------------\n");
    error = repartirMano(baraja, mano2, 5, &carry, 54);
    //imprimirCaractBaraja(mano2, 5);
    imprimirMano(mano2);

    //Reemplaza las cartas que desea

    liberarMemoria(mano1, 5);
    liberarMemoria(mano2, 5);
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
