// Dunia Barahona
#ifndef CUADRADO_H
#define CUADRADO_H

#include "Figura.h"

class Cuadrado : public Figura {	// Clase 'Cuadrado' que hereda publicamente de la clase 'Figura'
	/// @class Cuadrado
	/// @brief Hereda de la clase @link Figura @endlink .
public:
	// hereda los atributos de la clase 'Figura'
	// atributo propio...
	/// @brief Corresponde a la longitud de lado del cuadrado.
	double lado;
	// constructores...	
	Cuadrado();
	Cuadrado(string nombre, string color, double lado);
	// destructor...
	virtual ~Cuadrado();
	// hereda los métodos de la clase 'Figura'
	// métodos reimplementados...
	virtual double area();
	virtual double pmt();
	// sobrecarga de operadores...	
    virtual void operator~();
    virtual void operator!();
};
#endif /* CUADRADO_H */
//archivo de encabezados: es el que.
