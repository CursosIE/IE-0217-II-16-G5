#ifndef POLINOMIO_H
#define POLINOMIO_H

//#include "Calculadora.h"
#include <iostream>
#include "string"

using namespace std;

class Polinomio {
public:	
	int tam;	//tamaño del polinomio
	char var;	//variable del polinomio
	double* coef;	//coeficientes numéricos del polinomio
	
	Polinomio();
	Polinomio(int tam, char var, double* coef);
	~Polinomio();
	
	Polinomio operator+(const Polinomio p2);
	Polinomio operator-(const Polinomio p2);
	Polinomio operator*(const Polinomio p2);
	Polinomio operator/(const Polinomio p2);
	void operator~();
};
#endif /* POLINOMIO_H */
