// Dunia Barahona
#ifndef POLINOMIO_H
#define POLINOMIO_H

#include <iostream>
#include "string"

using namespace std;

class Polinomio {
	///@class Polinomio
public:
	///Tamaño del polinomio
	int tam;
	///Variable del polinomio	
	char var;
	///Coeficientes numéricos del polinomio	
	double* coef;	
	
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
