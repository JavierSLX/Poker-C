##Diseño
###baraja.c
`void imprimirCaractBaraja(carta baraja[], int length)`.  

**05/11/16**. Se diseñó su grafo para poder calcular la complejidad de la función y poder realizar las pruebas unitarias de la función.  

![GrafoFuncion](./images/grafoICaractBaraja.png)  

Los elementos que representan los nodos son los siguientes:  
1. ***i = 0***. Inicializa la variable i a 0.  
2. ***for (i < N)***. Comienza un ciclo de tipo for con la condición anterior.  
3. ***printf, i++***. Imprime la carta e incrementa uno en i.  
4. ***return***. Finaliza la función. 

####Complejidad ciclomática del grafo
Aplicando la fórmulas se obtiene lo siguiente:  
- *Número de regiones*. Se obtienen 2 regiones distintas incluyendo la exterior.  
- *V(G) = E - N + 2*. Aplicando la fórmula, se obtiene que el número de aristas(E) es de 4 y el de nodos (N) de 4, así que aplicando la fórmula nos da V(G) = 4 - 4 + 2 = 2.  
A lo que se deduce que 2 son las pruebas mínimas para recorrer todo el grafo.

####Rutas posibles del grafo
Las siguientes son las rutas posibles que serán analizadas en las pruebas unitarias de la función:  
1. 1, 2, 3, ..., 4.  
2. 1, 2, 4. 

En este caso sólo 1 es una ruta válida, ya que la ruta 2, aunque en el grafo se presenta como una ruta recorrible, en la lógica de la función construida no es posible acceder (tal caso es cuando el arreglo posee 0 elementos, cosa no posible).

##Pruebas
###driver_baraja.c
**CREADO 05/10/16**. Se usó el archivo driver_baraja.c para realizar las distintas pruebas de las funciones, entre ellas las pruebas unitarias.  

- **05/10/16**. Se probó la función con 10,000 cartas creadas generadas con tipos de datos al azar, en un inicio se localizó un pequeño error en el código que daba error al correr la prueba. Se corrigió, y se observó que tras 45 segundos aproximadamente, la prueba obtiene un resultado ***EXITOSO ✔***.  

![pruebaIEC](./images/pruebaICaractBaraja1.png)  

![pruebaIEC](./images/pruebaICaractBaraja2.png)  

- **05/10/16**. Pruebas unitarias de la función con resultado ***EXITOSO ✔***.

####Ruta 1: 1, 2, 3, ..., 4.  

![pruebaIEC](./images/driverICaractBaraja.png)