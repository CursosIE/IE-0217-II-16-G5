// Dunia Barahona
#include "Triangulo.h"

Triangulo::Triangulo() {		// Método que se llama 'Triangulo' y pertenece (::) a la clase 'Triangulo'
	/// @brief El @b constructor es un método que se llama igual que la clase.
}
Triangulo::Triangulo(string nombre, string color, double lado_1, double lado_2, double lado_3) {
	/// @brief Constructor que recibe los atributos como parámetros.
	this->nombre =nombre;
    this->color =color;
    this->lado_1 =lado_1;
    this->lado_2 =lado_2;
    this->lado_3 =lado_3;		//'this' se refiere a un atributo de la propia clase
}
Triangulo::~Triangulo() {
	/// @brief Destructor, sirve para destruir un objeto de la clase.
}
double Triangulo::area() {
	/// @brief Calcula el área del triángulo dadas las longitudes de cada uno de sus lados como atributos del objeto.
    /// @return Área del triángulo.
	double s= this->semip();
	double a= this->lado_1;
    double b= this->lado_2;
    double c= this->lado_3;
	double ar= sqrt(s*(s-a)*(s-b)*(s-c));
	return ar;
} 
double Triangulo::semip() {
	/// @brief Calcula el semiperímetro del triángulo dadas las longitudes de cada uno de sus lados como atributos del objeto.
    /// @return Semiperímetro del triángulo.
	double a= this->lado_1;
    double b= this->lado_2;
    double c= this->lado_3;
    double sp= (a+b+c)/2;
    return sp;
}
double Triangulo::pmt() {
	/// @brief Calcula el perímetro del triángulo dadas las longitudes de cada uno de los tres lados como atributos del objeto.
    /// @return Perímetro del triángulo.
	double p= this->lado_1 + this->lado_2 + this->lado_3;
	return p;
}
void Triangulo::operator ~() {
	/// @brief Sobrecarga del operador @b ~
	///
	/// Imprime los atributos del objeto.
	cout << "Nombre: "<<this->nombre << endl;
	cout << "Color:  " <<this->color << endl;
	cout << "Longitud del lado 1: "<<this->lado_1 <<" cm"<< endl;
    cout << "Longitud del lado 2: "<<this->lado_2 <<" cm"<<endl;
    cout << "Longitud del lado 3: "<<this->lado_3 <<" cm"<<endl;
}
void Triangulo::operator !() { 
	/// @brief Sobrecarga del operador @b !
	///
	/// Imprime los valores calculados del área y perímetro del triángulo.   
	cout << "Área:   "<<this->area() <<" cm²"<<endl;
    cout << "Perímetro: "<<this->pmt() <<" cm"<<endl;
    cout << endl;	
}
