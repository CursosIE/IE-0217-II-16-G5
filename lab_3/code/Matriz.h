// Dunia Barahona

#ifndef MATRIZ_H
#define MATRIZ_H

#include <cstdlib>
#include <iostream>
#include "string"

using namespace std;
                                       
class Matriz{
	///@class Matriz
public:
	///Filas de la matriz
	int m;
	///Columnas de la matriz	
	int n;
	///Coeficientes de la matriz	
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
#endif /* MATRIZ_H */
