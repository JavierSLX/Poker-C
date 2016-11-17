#Proyecto Baraja (Ingeniería de Software)

Documento que recaba todas las descripciones básicas y anotaciones que se han desarrollado, observaciones que se tienen y un apoyo en documentación del mismo proyecto realizado en lenguaje C. Se registran con fechas y observaciones en cada parte del programa.

##Actualizaciones
**16/Nov/16**. Se crearon las funciones (sin probar aún):  
- `int sacarCarta(carta baraja[], carta mano[], int posicion, int carry, int max)`.  
- `int cambios(carta baraja[], carta mano[], int *carry, int max)`.  

**12/Nov/16**. Se crearon las funciones (sin probar aún):  
- `void asignarValor(carta baraja[], int length)`.  
- `void ordenarCartas(carta monton[], int length)`.  
- `int prioridadTipo(char tipo)`.  

**10/Nov/16**. Se realizaron las pruebas de la función `void imprimirMano(carta mano[])`. Los resultados de la prueba se pueden observar en la respectiva carpeta (`/pruebas/poker/imprimirMano`).  

![pIM](./pruebas/poker/imprimirMano/images/pruebaImprimirMano.png)  

**09/Nov/16**. Se realizaron las pruebas de la función `int repartirMano(carta baraja[], carta mano[], int n, int *carry, int max)`. Los resultados de la prueba se pueden observar en la respectiva carpeta (`/pruebas/poker/repartirMano`).  

![dRM](./pruebas/poker/repartirMano/images/driverRepartirMano.png)  

**09/Nov/16**. Se realizaron las pruebas de la función `void quitarJokers(carta baraja[], carta nBaraja[])`. Los resultados de la prueba se pueden observar en la respectiva carpeta (`/pruebas/poker/quitarJokers`).  

![pQJ](./pruebas/poker/quitarJokers/images/pruebaQuitarJokers.png)  

**08/Nov/16**. Se realizaron las pruebas de la función `void barajear (carta baraja[])`. Los resultados de la prueba se pueden observar en la respectiva carpeta (`/pruebas/baraja/barajear`).  

![pBj](./pruebas/baraja/barajear/images/pruebaBarajear.png)  

**08/Nov/16**. Se corrigió el error de liberación de memoria de la función `void barajear (carta baraja[])`.

**05/Nov/16**. Se realizaron las pruebas de la función `int crearBaraja(carta cartas[])`. Los resultados de la prueba se pueden observar en la respectiva carpeta (`/pruebas/baraja/crearBaraja`).  

![pCB](./pruebas/baraja/crearBaraja/images/pruebaCrearBaraja.png)

**05/Nov/16**. Se realizaron las pruebas de la función `void liberarMemoria(carta baraja[], int length)`. Los resultados de la prueba se pueden observar en la respectiva carpeta (`/pruebas/baraja/liberarMemoria`).  

![pLM](./pruebas/baraja/liberarMemoria/images/pruebaLiberarMemoria.png)

**05/Nov/16**. Se realizaron las pruebas de la función `int definirCarta(int id, int num, int value, char type, char* color, carta *elemento)`. Los resultados de la prueba se pueden observar en la respectiva carpeta (`/pruebas/baraja/definirCarta`).  

![dDC](./pruebas/baraja/definirCarta/images/driverDefinirCarta.png)  

**05/Nov/16**. Se modificó y se realizaron las pruebas de la función `void imprimirCaractBaraja(carta baraja[], int length)`. Los resultados de la prueba se pueden observar en la respectiva carpeta (`/pruebas/baraja/imprimirCaractBaraja`).  

![dICB](./pruebas/baraja/imprimirCaractBaraja/images/driverICaractBaraja.png)

**04/Nov/16**. Se modificó y se realizaron las pruebas de la función `void imprimirCaractCarta(carta nombre)` por lo que no se detectaron fallos. Se construyó con anterioridad su respectivo grafo y se calculó su complejidad. Toda esta información puede ser vista en la carpeta `/pruebas/baraja/imprimirCaractCarta`.

![dICC](./pruebas/baraja/imprimirCaractCarta/images/ruta1.png)

**02/Nov/16**. Se realizaron las pruebas de la estructura y la función `void imprimirElementoCarta (carta nombre, int n)` por lo que no se detectaron fallos. Se construyó con anterioridad su respectivo grafo y se calculó su complejidad. Toda esta información puede ser vista en la carpeta `/pruebas/baraja/imprimirElementoCarta`.

![dIEC](./pruebas/baraja/imprimirElementoCarta/images/driverIElemCart.png)
  
**29/Oct/16**. Se creó el documento README.md para describir características y dar soporte al código. Se comentó parte del código con las características generales de lo que realiza cada función en las librerías. El error aún no se ha corregido, por lo que se ha decidido darle prioridad a su solución antes de continuar para evitar mal funcionamiento del programa más adelante.

**28/Oct/16**. Detectado un error 255 con el compilador Codeblocks al correr n veces el programa, aún no se encuentra la razón de tal debido a que se presenta aparentemente al azar. Se agregan unas imágenes del ya mencionado. 

![Error255](./images/error255_281016.png) 

##Baraja
Librería que contiene las funciones básicas del manejo de los elementos de una baraja en C.

###baraja.h (NO PROBADA ✘)
- `typedef struct {...}carta` **(PROBADA ✔)**. Estructura creada para contener los elementos de id, número, valor, tipo y color de una carta. *ID*, que sirve para darle un valor único a la carta y pueda ser usado en alguna otra parte. *Numero* que da el valor que tiene "físico". *Valor* que es el valor que se le da dependiendo del juego. *Tipo* que es uno de los cuatro que existen (E: Espadas, T: Treboles, C: Corazones y R: Rombos). Y el elemento *color* es asignado con memoria dinámica que puede tener tres (rojo, negro y blanco|sinColor).
- `void imprimirElementoCarta (carta nombre, int n)` **(PROBADA ✔)**. Imprime el elemento específico de una carta. 
- `void imprimirCaractCarta(carta nombre)` **(PROBADA ✔)**. Imprime todas las características de una carta. 
- `void imprimirCaractBaraja(carta baraja[], int length)` **(PROBADA ✔)**. Imprime todas las características de un arreglo de cartas (baraja). 
- `int definirCarta(int id, int num, int value, char type, char* color, carta *elemento)` **(PROBADA ✔)**. Crea una carta con todos los elementos que contiene. 
- `void liberarMemoria(carta baraja[], int length)`**(PROBADA ✔)**.  Libera la memoria de los elementos de un arreglo que usan memoria dinámica. 
- `int crearBaraja(carta baraja[])` **(PROBADA ✔)**. Crea un arreglo de tipo carta (baraja) con todos los tipos de cartas, y los elementos de cada una de ellas.
- `void barajear (carta baraja[])` **(PROBADA ✔)**. Desordena la baraja para que los elementos siempre salgan de manera aleatoria.

###baraja.c

- `void imprimirElementoCarta (carta nombre, int n)`.  
Imprime uno de los distintos elementos sin espacios y sin secuencias de escape. 
	+ **CREADA 27/10/16**. Hay que colocar n para indicar que es lo que se quiere que se imprima (1 = id, 2 = numero, 3 = valor, 4 = tipo y 5 = color). El valor del número es cambiante tomando como -1(comodín) y mostrándolo como N, 1 (As) mostrándolo como A, 11 como J, 12 como Q y 13 como K. Como recibe n los siguientes elementos 1 = id, 2 = numero, 3 = valor, 4 = tipo y 5 = color, falta analizar si se puede realizar de otra manera.
- `void imprimirCaractCarta(carta nombre)`.  
Imprime TODAS las características de una carta para pruebas del programador. 
	+ **CREADA 27/10/16**. El valor de número es cambiante tomando como -1(comodín) y mostrándolo como N, 1 (As) mostrándolo como A, 11 como J, 12 como Q y 13 como K.
	+ **MODIFICADA 04/11/16**. Se simplificó la función mandando llamar `void imprimirElementoCarta (carta nombre, int n)` para imprimir cada elemento.
- `void imprimirCaractBaraja(carta baraja[], int length)`.  
Imprime TODAS las características de cada carta contenida en el arreglo.  
	+ **CREADA 27/10/16**. Se requiere el largo del arreglo para ver el límite dentro de un ciclo *for* que realiza la impresión de las cartas. Desconozco si se puede realizar sin que el programador tenga que ingresarlo como parámetro.
	+ **MODIFICADA 05/11/16**. Se simplificó la función mandando llamar `void imprimirCaractCarta(carta nombre)` para imprimir cada carta contenida en el arreglo (baraja).
- `int definirCarta(int id, int num, int value, char type, char* color, carta *elemento)`.  
Crea una carta a partir de todos los elementos que contiene.
	+ **CREADA 27/10/16**. Es necesario colocar todos y cada uno de los parámetros que requiere la función. El color se asigna por memoria dinámica, a lo que regresa 1 la función cuando no se pudo asignarle para tal objetivo. Un parámetro es un apuntador a donde se encuentra la carta que se le darán tales valores.  
- `void liberarMemoria(carta baraja[], int length)`.  
Libera la memoria usada en *color* de cada elemento del arreglo.
	+ **CREADA 27/10/16**. En este caso, recibe un arreglo de tipo carta y el largo de este. Libera memoria de cada uno de los elementos ayudado con un ciclo *for*.
- `int crearBaraja(carta baraja[])`.   
Crea un arreglo de tipo carta (baraja) con todos los tipos de cartas.
	+ **CREADA 27/10/16**. Se da como valor fijo del arreglo 54 elementos, 13 cartas de los 4 tipos distintos que existen, más dos comodines. Como no se pudo colocar los símbolos de cada tipo de carta estos se representan con E = Espadas, T = Tréboles, C = Corazones y R = Rombos. Aquí los comodines poseen un valor númerico de -1 (N). Regresa el valor de 1 en caso de que no se haya podido asignar la memoria.  
- `void barajear (carta baraja[])`.  
Desordena el arreglo para que usando el azar pueda alterar el orden.
	+ **CREADA 27/10/16**. Usa la funcion `rand()` para realizar la tarea indicada además de crear otro arreglo de tipo carta para poder reemplazar el orden sin alterar la baraja original. ***NOTA: No fue posible liberar memoria de un arreglo tipo carta creado para dar soporte para desordenar las cartas. Crea un error al correr el programa. Checar tal error***.
	+ **MODIFICADA 08/11/16**. Se corrigió el error de liberación de memoria de la función.
	

##Poker
Librería de C que contiene todas las reglas y características de este juego. Se apoya en las funciones hechas en `baraja.h`.

###poker.h (NO PROBADA ✘)
- `void quitarJokers(carta baraja[], carta nBaraja[])` **(PROBADA ✔)**. Quita dos elementos carta del arreglo y crea una nueva baraja sin ellos. 
- `int repartirMano(carta baraja[], carta mano[], int n, int *carry, int max)` **(PROBADA ✔)**. Toma del arreglo baraja cinco cartas para darle a cada jugador.
- `void imprimirMano(carta mano[])` **(PROBADA ✔)**. Imprime la mano que tiene el jugador.  
- `void asignarValor(carta baraja[], int length)` **(NO PROBADA ✘)**. Define el valor de las cartas a este juego en específico.  
- `void ordenarCartas(carta monton[], int length)` **(NO PROBADA ✘)**. Ordena las cartas de acuerdo al tipo y al valor de la carta para hacer un poco más visible la mano.  
- `int prioridadTipo(char tipo)` **(NO PROBADA ✘)**. Auxilia a la función `void ordenarCartas(carta monton[], int length)`. 
- `int sacarCarta(carta baraja[], carta mano[], int posicion, int carry, int max)` **(NO PROBADA ✘)**. Permite sacar una carta de la baraja y la reemplaza por la carta que se le indique.  
- `int cambios(carta baraja[], carta mano[], int *carry, int max)` **(NO PROBADA ✘)**. Realiza los cambios de cartas de los jugadores.  

###poker.c
- `void quitarJokers(carta baraja[], carta nBaraja[])`.  
Quita dos elementos carta del arreglo y crea una nueva baraja sin ellos.
	+ **CREADA 27/10/16**. La función busca en un ciclo *for* las cartas con numero -1, las que no tienen tal valor lo asignan al nuevo arreglo. Es importante mencionar que para que la función trabaje de la manera adecuada, el arreglo del primer parámetro debe de tener un largo de 54 elementos y el segundo de 52. *La función aún no se usa, pero se creo para colocar más adelante la opción de jugar sin comodines*.
- `int repartirMano(carta baraja[], carta mano[], int n, int *carry, int max)`.  
Se toma de una arreglo llamado baraja, elementos para conformar una mano.
	+ **CREADA 27/10/16**. La función toma de un arreglo baraja, una mano de 5 elementos para poder jugar. Se necesita además de estos dos elementos antes mencionados, n que es la cantidad de cartas que se tomará, un carry que lleva la cuenta de manera externa de la posición del arreglo baraja donde ya se tomaron las cartas, y el límite del arreglo baraja para comparar si aún existen cartas por tomar. Si se evalua el caso de ya no haber cartas para jugar, la función regresa un 1.
- `void imprimirMano(carta mano[])`  
Imprime los elementos que el jugador tiene como visibles para poder jugar.
	+ **CREADA 27/10/16**. La función se apoya de la la función `imprimirElementoCarta (...)` para imprimir el número de la carta. Se hace énfasis que como sólo imprime los elementos que el jugador debe conocer, estos se limitan al número de carta, tipo y color. Ordenadas de tal manera que fueron extraídas de la baraja. ***NOTA: A partir de que se usaba esta función se presentó un error 255 en el compilador, pero se desconoce si es por las funciones que aquí se usan o por la anterior que reparte la mano***.  
- `void asignarValor(carta baraja[], int length)`.  
Define el valor de las cartas a este juego en específico.  
	+ **CREADA 12/11/16**. Como el juego de poker su valor de cartas es único, se le asigna un valor distinto, en su mayoría toma el valor de su número, excepto el As (que en lugar de valor 1 toma valor 14) y el de comodín que toma el valor -1, dando a entender en futuras funciones que puede ser cambiado de acuerdo a la ventaja del jugador.  
- `void ordenarCartas(carta monton[], int length)`.  
Ordena las cartas de acuerdo al tipo y al valor de la carta para hacer un poco más visible la mano.  
	+ **CREADA 12/11/16**. Se usa un ordenamiento de tipo burbuja, al comienzo de la función le da prioridad a los tipos (ordenando primero comodines, espadas, tréboles, corazones y rombos respectivamente) y en la segunda parte ordena dependiendo de su valor de cada tipo.  
- `int prioridadTipo(char tipo)`.  
Auxilia a la función `void ordenarCartas(carta monton[], int length)`.  
	+ **CREADA 12/11/16**. Ayuda a la función anterior dándole a cada tipo un valor para poder ordenar de una cierta manera. Esta función puede ser cambiada para que el orden de la mano pueda ser distinta.  
- `int sacarCarta(carta baraja[], carta mano[], int posicion, int carry, int max)`.  
Permite sacar una carta de la baraja y la reemplaza por la carta que se le indique.  
	+ **CREADA 16/11/16**. La función trabaja de la siguiente manera: Del arreglo baraja obtiene la carta donde está actualmente el valor de carry y la coloca en el arreglo mano en la posición donde se le indica, reemplazando así una carta por una nueva.  
- `int cambios(carta baraja[], carta mano[], int *carry, int max)`.  
Realiza los cambios de cartas de los jugadores.  
	+ **CREADA 16/11/16**. La función obtiene los elementos básicos, y le pide al jugador cuantas cartas va a cambiar. En este caso, sólo puede cambiar mínimo 1 carta y máximo 3, de las cuales le va pidiendo una a una que le vaya indicando que carta va a cambiar. Regresa un 1 en caso de que no se puedan hacer los cambios pedidos.  

##Principal

###main.c
- **CREADO 27/10/16**. Se probaron las funciones de manera básica para notar su funcionamiento, aún no se detectan dos de los posibles errores que el compilador arrojó, errores lógicos dados por el programador al parecer.

##Pruebas
***ERRORES CORREGIDOS: 3***  

- **10/11/16**. Se usó el archivo *driver_poker.c* para realizar las distintas pruebas de la función `void imprimirMano(carta mano[])`. Los resultados de la prueba se pueden observar en la respectiva carpeta (`/pruebas/poker/imprimirMano`).  

- **09/11/16**. Se usó el archivo *driver_poker.c* para realizar las distintas pruebas de la función `int repartirMano(carta baraja[], carta mano[], int n, int *carry, int max)`. Los resultados de la prueba se pueden observar en la respectiva carpeta (`/pruebas/poker/repartirMano`).   

- **09/11/16**. Se usó el archivo *driver_poker.c* para realizar las distintas pruebas de la función `void quitarJokers(carta baraja[], carta nBaraja[])`. Los resultados de la prueba se pueden observar en la respectiva carpeta (`/pruebas/poker/quitarJokers`).  

- **09/11/16**. Se creó el *driver_poker.c* para realizar las pruebas de la librería poker.h.

- **08/11/16**. Se usó el archivo *driver_baraja.c* para realizar las distintas pruebas de la función `void barajear (carta baraja[])`. Los resultados de la prueba se pueden observar en la respectiva carpeta (`/pruebas/baraja/barajear`). 

- **05/11/16**. Se usó el archivo *driver_baraja.c* para realizar las distintas pruebas de la función `int crearBaraja(carta cartas[])`. Los resultados de la prueba se pueden observar en la respectiva carpeta (`/pruebas/baraja/crearBaraja`).  

- **05/11/16**. Se usó el archivo *driver_baraja.c* para realizar las distintas pruebas de la función `void liberarMemoria(carta baraja[], int length)`. Los resultados de la prueba se pueden observar en la respectiva carpeta (`/pruebas/baraja/liberarMemoria`). 

- **05/11/16**. Se usó el archivo *driver_baraja.c* para realizar las distintas pruebas de la función `int definirCarta(int id, int num, int value, char type, char* color, carta *elemento)`. Los resultados de la prueba se pueden observar en la respectiva carpeta (`/pruebas/baraja/definirCarta`).  

- **05/11/16**. Se usó el archivo *driver_baraja.c* para realizar las distintas pruebas de la función `void imprimirCaractBaraja(carta baraja[], int length)`. Los resultados de la prueba se pueden observar en la respectiva carpeta (`/pruebas/baraja/imprimirCaractBaraja`).  

- **04/11/16**. Se usó el archivo *driver_baraja.c* para realizar las distintas pruebas de la función `void imprimirCaractCarta(carta nombre)`. Los resultados de la prueba se pueden observar en la respectiva carpeta (`/pruebas/baraja/imprimirCaractCarta`).  

- **02/11/16**. Se usó el archivo *driver_baraja.c* para realizar las distintas pruebas de la función `void imprimirElementoCarta (carta nombre, int n)`. Los resultados de la prueba se pueden observar en la respectiva carpeta (`/pruebas/baraja/imprimirElementoCarta`).  
 
- **02/11/16**. Se creó el *driver_baraja.c* para realizar las pruebas de la librería baraja.h.