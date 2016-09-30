#include "Figura.h"
#include "Cuadrado.h"

const double PI  =3.141592653589793238463;
///Constructor de la clase cuadrado.
Cuadrado::Cuadrado(){
}
///Destructor de la clase derivada cuadrado.
Cuadrado::~Cuadrado(){
}
///Constructor sobrecargado de la clase derivada cuadrado.
Cuadrado::Cuadrado(string nombre, string color, double l){
this-> nombre = nombre;
this-> color = color;
this-> l=l;

}

///Función general para cálculo de área de un cuadrado.
double Cuadrado::area(){
	double a = pow(this-> l, 2);
	return a;
}

///Función general para cálculo de perímetro de un cuadrado.
double Cuadrado::perimetro(){
	double p;
	p = 4*this->l;
	return p;
}

///Desplegador de los datos generales del cuadrado.
void Cuadrado::operator~(){
	cout << "Nombre: " << this-> nombre <<endl;
	cout << "Color: " << this-> color <<endl;
	cout << "Longitud del lado " << l <<endl;
	cout<< "\n" << endl;
	}

///Desplegador del área y el perímetro del cuadrado.
void Cuadrado::operator!(){
	cout << "Área: " << this-> area() <<endl;
	cout << "Perímetro: " << this-> perimetro() <<endl;
	cout<< "\n" << endl;

	}
