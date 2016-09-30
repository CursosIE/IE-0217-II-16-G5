#include <stdio.h>
#include <stdlib.h>

/**
 * @file
 * @author  Dunia Barahona <s4si@hotmail.com>
 * @version 1.0
 *
 * @section DESCRIPCIÓN
 *
 * Este es un programa escrito en C que toma de la línea de comandos una lista de 
 * números reales e imprime en pantalla el resultado de la suma de dichos números.
 */

/**
 * @param cant argumento de tipo entero, es la cantidad de elementos que recibe.
 * @param **ents un puntero de constantes, son los valores recibidos.
 * @return el resultado de la suma de dichos números.
 */       
int sum(int cant, char **ents){ 
	int i=0;
	double bolsita=0;			
	for(i; i<cant; i++){
		bolsita += atof(ents[i]);
	}
	int temp= ("%i", bolsita);
	printf("%i\n", temp);
	return 0;
}

/**
 * Esta es la función principal.
 * @param argc es la cantidad de elementos que recibe.
 * @param **argv son los valores recibidos.
 */  
int main(int argc, char **argv) {	
	sum(argc, argv);
}
