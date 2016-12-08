##Diseño
###poker.c
`int comprobarPares (carta mano[], int pares[], int posiciones[], int comodines)`. 

**03/12/16**. Se diseñó su grafo para poder calcular la complejidad de la función y poder realizar las pruebas unitarias de la función.  

![GrafoCP](./images/grafoComprobarPares.png)  

Los elementos que representan los nodos son los siguientes:  
1. ***i = 0***. Inicializa el contador a 0.  
2. ***if (par)***. Checa si encuentra un par en la mano.  
3. ***i++***. Incrementa el contador.  
4. ***if (par)***. Checa y asigna si hay otro par en la mano.  
5. ***return***. Termina la función.  

####Complejidad ciclomática del grafo
Aplicando la fórmulas se obtiene lo siguiente:  
- *Número de regiones*. Se obtienen 4 regiones distintas incluyendo la exterior.  
- *V(G) = E - N + 2*. Aplicando la fórmula, se obtiene que el número de aristas(E) es de 7 y el de nodos (N) de 5, así que aplicando la fórmula nos da V(G) = 7 - 5 + 2 = 4.  
A lo que se deduce que 4 son las pruebas mínimas para recorrer todo el grafo.  


##Pruebas
###driver_poker.c
**CREADO 03/12/16**. Se usó el archivo driver_poker.c para realizar las distintas pruebas de las funciones, entre ellas las pruebas unitarias.  

- **03/12/16**. Se probó la función hasta encontrar mínimo un par, lo que al final se obtuvo un resultado ***EXITOSO ✔***.  

![pruebaCP](./images/pruebaComprobarPares.png) 