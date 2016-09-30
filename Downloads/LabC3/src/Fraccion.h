#ifndef FRACCION_H
#define FRACCION_H

#include "Calculadora.h"
#include <iostream>
#include "string"

using namespace std;
                                       
class Fraccion {
public:	
	double num;	//numerador de la fracción
	double den;	//denominador de la fracción
	
	Fraccion();	// constructor
	Fraccion(double n, double d);
	~Fraccion(); // destructor
	
	Fraccion operator+(const Fraccion f2);
	Fraccion operator-(const Fraccion f2);
	Fraccion operator*(const Fraccion f2);
	Fraccion operator/(const Fraccion f2);
	void operator~();
};
//en el main ud llama a add con dos objetos del tpo: fraccion, matriz, polinomio
#endif /* FRACCION_H */
