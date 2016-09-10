#include "Triangulo.h"
#include "Figura.h"

///Constructor de la clase triángulo.
Triangulo::Triangulo(){
}
///Destructor de la clase derivada triángulo.
Triangulo::~Triangulo(){
}
///Constructor sobrecargado de la clase derivada triángulo.
Triangulo::Triangulo(string nombre, string color, double l1, double l2, double l3){
this-> nombre = nombre;
this-> color = color;
this-> l1= l1;
this-> l2= l2;
this-> l3= l3;
this-> s= (l1+l2+l3)/2;

}

///Función general para cálculo de área de un triangulo.
double Triangulo::area(){
	double sp = this->s;
	double la1 = this-> l1;
	double la2 = this-> l2;
	double la3 = this-> l3;
	double a= sqrt(sp*(sp-la1)*(sp-la2)*(sp-la3));
	return a;
}

///Función general para cálculo de perímetro de un triangulo.
double Triangulo::perimetro(){
	double p;
	p = this-> l1 + this-> l2 + this-> l3;
	return p;
}

///Desplegador de los datos generales del triángulo.
void Triangulo::operator~(){
	cout << "Nombre: " << this-> nombre <<endl;
	cout << "Color: " << this-> color <<endl;
	cout << "Longitud de los lados " << this-> l1 << ", " << this-> l2 << ", " << this-> l3 <<endl;
	cout<< "\n" << endl;

	}
///Desplegador del área y el perímetro del triángulo.
void Triangulo::operator!(){
	cout << "Área: " << this-> area() <<endl;
	cout << "Perímetro: " << this-> perimetro() <<endl;
	cout<< "\n" << endl;

	}
