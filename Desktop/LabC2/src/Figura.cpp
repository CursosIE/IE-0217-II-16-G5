#include "Figura.h"

///Constructor de la clase figura.
Figura::Figura(){
}
///Desstructor de la clase figura.
Figura::~Figura(){
}

///Constructor sobrecargado de la clase figura
Figura::Figura(string nombre, string color){
this-> nombre = nombre;
this-> color = color;
}
///Función general para cálculo de área de una figura.
double Figura::area(){
	cout << "Implementar en subclases de figuras" << endl;
	return 0;
}
///Función general para cálculo de perímetro de una figura.

double Figura::perimetro(){
	cout << "Implementar en subclases de figuras" << endl;
	return 0;
}


