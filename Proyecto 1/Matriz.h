#ifndef MATRIZ_H
#define MATRIZ_H

//#include "Calculadora.h"
#include <iostream>
#include "string"

using namespace std;
                                       
class Matriz{
public:	
	int m;	//filas de la matriz
	int n;	//columnas de la matriz
	double **matrix;
	
	Matriz();	// constructor
	Matriz(int m, int n, double** matriz);
	Matriz(Matriz m1, Matriz m2, Matriz m3, Matriz m4, int m);
	~Matriz(); // destructor
	
	Matriz operator+(const Matriz f2);
	Matriz operator-(const Matriz f2);
	Matriz operator*(const Matriz f2);
	Matriz operator/(const Matriz f2);
	void operator~();
	//funciones por crear!!!
	Matriz mat2x2(const Matriz f2);
	Matriz matTxt(FILE f); //Dunia, crear función para leer matrices de archivos de texto
	void matverify(); //Dunia, crear función que verifique que las condiciones son las adecuadas para la multiplicación y llene las filas y columnas de ceros necesarias
	Matriz matblock(int b); //función que subdivide la matriz en bloques
	Matriz strassen(const Matriz m2);
};
//en el main ud llama a add con dos objetos del tpo: fraccion, matriz, polinomio
#endif /* MATRIZ_H */
