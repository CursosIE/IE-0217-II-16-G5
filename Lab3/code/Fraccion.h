// Dunia Barahona
#ifndef FRACCION_H
#define FRACCION_H

#include <iostream>
#include "string"

using namespace std;
                                       
class Fraccion {
	///@class Fraccion
public:
	///@brief Numerador de la fracción
	double num;
	///@brief Denominador de la fracción	
	double den;	
	
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
