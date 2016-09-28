// Dunia Barahona. B40806
#include "Figura.h"

Figura::Figura() {		// Constructor vacío.
	/// @brief El @b constructor es una función que se llama igual que la clase.
}
Figura::Figura(string nombre, string color) {
	/// @brief Constructor que recibe los atributos como parámetros.
	this->nombre = nombre;
    this->color = color;		//'this' se refiere a un atributo de la propia clase
}
Figura::~Figura() {
	/// @brief Destructor, sirve para destruir un objeto de la clase.
}
double Figura::area() {
	/// @brief Función virtual que se reimplementa en las clases derivadas según cada caso.
    /// @return Área de la figura.
	cout << "Método para calcular el área de la figura "<<this->nombre <<" debe implementarse en clases derivadas." << endl;
	return 0.0;
}
double Figura::pmt() {
	/// @brief Función virtual que se reimplementa en las clases derivadas según cada caso.
    /// @return Perímetro de la figura.
	cout << "Método para calcular el perímetro de la figura "<<this->nombre <<" debe implementarse en clases derivadas." << endl;
	return 0.0;
}
void Figura::operator ~() {
	/// @brief Sobrecarga del operador @b ~
	///
	/// Imprime los atributos del objeto.
	cout << "Nombre: "<< this->nombre << endl;
	cout << "Color:  " <<this->color << endl;
}
void Figura::operator !() {
	/// @brief Sobrecarga del operador @b !
	///
	/// Imprime el mensaje correspondiente de los métodos @link area @endlink y @link pmt @endlink .
	cout << "Área:   "<< this->area() << endl;
    cout << "Perímetro: "<< this->pmt() << endl;
    cout << endl;
}
