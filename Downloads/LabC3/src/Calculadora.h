//Clase emplantillada
#ifndef CALCULADORA_H
#define CALCULADORA_H

#include <cstdlib>
#include <iostream>
#include "string"
#include "Fraccion.h"
#include "Polinomio.h"
#include "Matriz.h"

template <typename data>	//data puede ser objeto de tipo: Fracción, polinomio o matriz. 
class Calculadora {
public:	
	Calculadora() {
		/// Constructor de la clase Calculadora.
	}
	~Calculadora() {
		/// Destructor de la clase Calculadora.
	}
	data add(data d1, const data d2) {
		/// Método suma de la clase Calculadora.
		data d= d1+d2;
		return d;
	}
	data sub(data d1, const data d2) {
		/// Método resta de la clase Calculadora.
		data d= d1-d2;
		return d;
	}
	data mul(data d1, const data d2) {
		/// Método multiplicación de la clase Calculadora.
		data d= d1*d2;
		return d;
	}
	data div(data d1, const data d2) {
		/// Método división de la clase Calculadora.
		data d= d1/d2;
		return d;
	}
	void print(data d) {
		/// Método que imprime.
		~d;
	}
};
#endif /* CALCULADORA_H */
// las otras clases si tienen .cpp. Solo plantilla no.
