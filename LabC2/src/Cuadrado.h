#ifndef CUADRADO_H
#define CUADRADO_H
#include <iostream>
#include "string"
#include "Figura.h"
#include <math.h> 



using namespace std;

class Cuadrado : public Figura{
public:
    string color;
	string nombre;
	void operator~();
	void operator!();
	double l;
	Cuadrado();
	Cuadrado(string nombre, string color, double l);
	virtual double area();
	virtual double perimetro();
	virtual ~Cuadrado();
};
#endif /* CUADRADO_H */
