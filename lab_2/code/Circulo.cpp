// Dunia Barahona. B40806
#include "Circulo.h"

Circulo::Circulo() {		// Función que se llama 'Circulo' y pertenece (::) a la clase 'Circulo'
	/// @brief El @b constructor es una función que se llama igual que la clase.
}
Circulo::Circulo(string nombre, string color, double radio) {
	/// @brief Constructor que recibe los atributos como parámetros.
	this->nombre =nombre;
    this->color =color;
    this->radio =radio;
}
Circulo::~Circulo() {
	/// @brief Destructor, sirve para destruir un objeto de la clase.
}
double Circulo::area() {
    /// @brief Calcula el área del círculo dado su radio como atributo del objeto.
    /// @return Área del círculo.
	double r= this->radio;
	double a= 3.1415*(r*r);
	return a;
}
double Circulo::pmt() {
	/// @brief Calcula el perímetro del círculo dado su radio como atributo del objeto.
    /// @return Perímetro del círculo.
	double r= this->radio;
	double p= 2*3.1415*r;
	return p;
}
void Circulo::operator ~() {
	/// @brief Sobrecarga del operador @b ~
	///
	/// Imprime los atributos del objeto.
	cout << "Nombre: "<<this->nombre << endl;
	cout << "Color:  " <<this->color << endl;
	cout << "Radio:  "<<this->radio << " cm"<<endl;
}
void Circulo::operator !() { 
	/// @brief Sobrecarga del operador @b !
	///
	/// Imprime los valores calculados del área y perímetro del círculo.   
	cout << "Área:   "<<this->area()<< " cm²"<<endl;
    cout << "Perímetro: "<<this->pmt() << " cm"<<endl;
    cout << endl;
}
