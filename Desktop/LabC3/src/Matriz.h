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
	~Matriz(); // destructor
	
	Matriz operator+(const Matriz f2);
	Matriz operator-(const Matriz f2);
	Matriz operator*(const Matriz f2);
	Matriz operator/(const Matriz f2);
	void operator~();
};
//en el main ud llama a add con dos objetos del tpo: fraccion, matriz, polinomio
#endif /* MATRIZ_H */
