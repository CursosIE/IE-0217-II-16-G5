//EmmaDu 
#ifndef CUADRANTE_H
#define CUADRANTE_H

#include <cstdlib>
#include <iostream>
#include "math.h"
#include "string"
#include "stdlib.h"

using namespace std;

class Cuadrante{
public:
	// Atributos:
	int* ci;	//coordenadas inicio
	int* cc;	//coordenadas cierre
	int d;		//dimension

	Cuadrante();	
	Cuadrante(int d);
	virtual ~Cuadrante();
	
	void print();
	Cuadrante* dividir();
};
#endif /* CUADRANTE_H */
