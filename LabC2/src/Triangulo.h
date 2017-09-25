#ifndef TRIANGULO_H
#define TRIANGULO_H
#include <iostream>
#include "string"
#include "Figura.h"
#include <math.h> 



using namespace std;

class Triangulo : public Figura{
public:
    string color;
	string nombre;
	void operator~();
	void operator!();
	double l1;
	double l2;
	double l3;
	double s;
	Triangulo();
	Triangulo(string nombre, string color, double l1, double l2, double l3);
	virtual double area();
	virtual double perimetro();
	virtual ~Triangulo();
};
#endif /* TRIANGULO_H */
