#ifndef PORTERO_H
#define PORTERO_H

#include "LCP.h"

class Portero {
public:
	//Atributos
	int cE;
	int cT;
	double cD;
	int ciclos;
	
	/// Sala de espera de ejecutivos: COLA
	LCP<char>* sala_E;
	/// Sala de espera de trabajadores: COLA	
	LCP<char>* sala_T;
	/// Sala de espera de desempleados: COLA	
	LCP<char>* sala_D;	
	
	Portero();
	~Portero();
	
	void ubicar(char** clientes);
	char llamar_jugador();
};
#endif /* PORTERO_H */
