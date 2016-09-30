#include "Figura.h"
#include "Circulo.h"

const double PI  =3.141592653589793238463;
///Constructor de la clase círculo.
Circulo::Circulo(){
}
///Destructor de la clase derivada círculo.
Circulo::~Circulo(){
}
///Constructor sobrecargado de la clase derivada círculo.
Circulo::Circulo(string nombre, string color, double r){
this-> nombre = nombre;
this-> color = color;
this-> r=r;

}

///Función general para cálculo de área de un círculo.
double Circulo::area(){
	double a = PI*pow(this-> r, 2);
	return a;
}

///Función general para cálculo de perímetro de un círculo.
double Circulo::perimetro(){
	double p;
	p = 2*PI*this->r;
	return p;
}

///Desplegador de los datos generales del círculo.
void Circulo::operator~(){
	cout << "Nombre: " << this-> nombre <<endl;
	cout << "Color: " << this-> color <<endl;
	cout << "Longitud del radio " << r <<endl;
	cout<< "\n" << endl;

	}

///Desplegador del área y el perímetro del círculo.
void Circulo::operator!(){
	cout << "Área: " << this-> area() <<endl;
	cout << "Perímetro: " << this-> perimetro() <<endl;
    cout<< "\n" << endl;

	}
