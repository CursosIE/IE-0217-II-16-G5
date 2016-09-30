// Dunia Barahona
#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "Figura.h"

class Triangulo : public Figura{	// Clase 'Triangulo' que hereda publicamente de la clase 'Figura'
	/// @class Triangulo.
	/// @brief Hereda de la clase @link Figura @endlink .
public:
	// hereda los atributos de la clase 'Figura'
	// atributos propios...
    /// @brief Corresponde a la longitud del primer lado del triángulo.
	double lado_1;
	/// @brief Corresponde a la longitud del segundo lado del triángulo.
	double lado_2;
	/// @brief Corresponde a lalongitud del tercer lado del triángulo.
	double lado_3;
	
	// constructores...	
	Triangulo();
	Triangulo(string nombre, string color, double lado_1, double lado_2, double lado_3);
	// destructor...
	virtual ~Triangulo();
	// método propio...
	double semip();
	// hereda los métodos de la clase 'Figura'
	// métodos reimplementados...
	virtual double area();
	virtual double pmt();
	// sobrecarga de operadores...	
    virtual void operator~();
    virtual void operator!();
};
#endif /* TRIANGULO_H */
//archivo de encabezados: es el que.
