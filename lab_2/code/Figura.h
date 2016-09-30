// Dunia Barahona
#ifndef FIGURA_H
#define FIGURA_H

#include <cstdlib>
#include <iostream>
#include "math.h"
#include "string"

using namespace std;
class Figura{
	/// @class Figura
	/// @brief Clase base.
public:
	// atributos...
	/// @brief Corresponde al color de la figura.
	string color;
	/// @brief Corresponde al nombre de la figura.
	string nombre;
	// constructores...
	Figura();	
	Figura(string nombre, string color);
	// destructor...
	virtual ~Figura();
	// métodos virtuales...
	virtual double area();
	virtual double pmt();
	// sobrecarga de operadores...
    virtual void operator~();
    virtual void operator!();
};
#endif /* FIGURA_H */
//archivo de encabezados: es el que.
