#ifndef FIGURA_H
#define FIGURA_H
#include <iostream>
#include "string"
#include <math.h> 

using namespace std;

class Figura{
public:
	string color;
	string nombre;
	Figura();
	Figura(string nombre, string color);
	virtual double area();
	virtual double perimetro();
	virtual ~Figura();
	double papa();

};
#endif /* FIGURA_H */
