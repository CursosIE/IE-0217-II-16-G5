#ifndef CIRCULO_H
#define CIRCULO_H
#include <iostream>
#include "string"
#include "Figura.h"
#include <math.h> 



using namespace std;

class Circulo : public Figura{
public:
    string color;
	string nombre;
	void operator~();
	void operator!();
	double r;
	Circulo();
	Circulo(string nombre, string color, double r);
	virtual double area();
	virtual double perimetro();
	virtual ~Circulo();
};
#endif /* CIRCULO_H */
