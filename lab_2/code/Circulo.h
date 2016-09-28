// Dunia Barahona. B40806
#ifndef CIRCULO_H
#define CIRCULO_H

#include "Figura.h"

class Circulo : public Figura{	// Clase 'Circulo' que hereda publicamente de la clase 'Figura'
	/// @class Circulo.
	/// @brief Hereda de la clase @link Figura @endlink .
public:
	// hereda los atributos de la clase 'Figura'
	// atributo propio...
	/// @brief Corresponde al radio del círculo.
	double radio;
	// constructores...	
	Circulo();
	Circulo(string nombre, string color, double radio);
	// destructor...
	virtual ~Circulo();
	// hereda los métodos de la clase 'Figura'
	// métodos reimplementados...
	virtual double area();
	virtual double pmt();
	// sobrecarga de operadores...	
    virtual void operator~();
    virtual void operator!();
};
#endif /* CIRCULO_H */
//archivo de encabezados: es el que.
