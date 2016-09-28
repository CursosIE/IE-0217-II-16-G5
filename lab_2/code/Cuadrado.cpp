// Dunia Barahona. B40806
#include "Cuadrado.h"

Cuadrado::Cuadrado() {		// Método que se llama 'Cuadrado' y pertenece (::) a la clase 'Cuadrado'
	/// @brief El @b constructor es un método que se llama igual que la clase.
}
Cuadrado::Cuadrado(string nombre, string color, double lado) {
    /// @brief Constructor que recibe los atributos como parámetros.
	this->nombre =nombre;
    this->color =color;
    this->lado =lado;		//'this' se refiere a un atributo de la propia clase
}
Cuadrado::~Cuadrado() {
	/// @brief Destructor, sirve para destruir un objeto de la clase.
}
double Cuadrado::area() {
	/// @brief Calcula el área del cuadrado dada la longitud de lado como atributo del objeto.
    /// @return Área del cuadrado.
	double l= this->lado;
	double a= l*l;
	return a;
}
double Cuadrado::pmt() {
	/// @brief Calcula el perímetro del cuadrado dada la longitud de lado como atributo del objeto.
    /// @return Perímetro del cuadrado.	
    double l= this->lado;
	double p= 4*l;
	return p;
}
void Cuadrado::operator ~() {
	/// @brief Sobrecarga del operador @b ~
	///
	/// Imprime los atributos del objeto.
	cout << "Nombre: "<<this->nombre << endl;
	cout << "Color:  "<<this->color << endl;
	cout << "Longitud de lado: "<<this->lado << " cm"<<endl;
}
void Cuadrado::operator !() { 
	/// @brief Sobrecarga del operador @b !
	///
	/// Imprime los valores calculados del área y perímetro del cuadrado.
	cout << "Área:   "<<this->area() <<" cm²"<< endl;
    cout << "Perímetro: "<<this->pmt() <<" cm"<< endl;
    cout << endl;
}
