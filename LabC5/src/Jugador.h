#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
#include "string"
#include "Carta.h"
#include "Mazo.h"

using namespace std;
                                       
class Jugador{
	///@class Jugador
public:
	int puntos;
	int numero;
	bool activo;
	Jugador();	// constructor
	Jugador(int n);
	~Jugador(); // destructor
	void comer(Mazo &mazo);
	void operator~();
};
#endif /* JUGADOR_H */
