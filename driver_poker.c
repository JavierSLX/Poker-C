#include "poker.h"
#include <assert.h>
#define N 10000

void pruebaQuitarJokers(void);

int main()
{
    pruebaQuitarJokers();
    return 0;
}

void pruebaQuitarJokers(void)
{
    int i;
    carta old[54];
    carta nueva[52];

    for (i = 0; i < N; i++)
    {
        crearBaraja(old);
        barajear(old);
        quitarJokers(old, nueva);
        imprimirCaractBaraja(nueva, 52);
        liberarMemoria(old, 54);
    }

    liberarMemoria(nueva, 52);
    return;
}

