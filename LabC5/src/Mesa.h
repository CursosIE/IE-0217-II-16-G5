#ifndef MESA_H
#define MESA_H

#include <iostream>
#include "string"
#include "Jugador.h"
#include "Fila.h"

using namespace std;
                                       
class Mesa{
	///@class Mesa
public:
	int espaciosdisp;
	int numero;
	Jugador Jugador1;
    Jugador Jugador2;
    Jugador Jugador3;
	Mesa();	// constructor
	Mesa(int numero);
	~Mesa(); // destructor
	void operator~();
	void partida(Fila &fila);
};
#endif /* MESA_H */
