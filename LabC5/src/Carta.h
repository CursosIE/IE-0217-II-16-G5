#ifndef CARTA_H
#define CARTA_H

#include <iostream>
#include "string"

using namespace std;
                                       
class Carta{
	///@class Carta
public:
	string nombre;
	string palo;
	int valor;
	Carta();	// constructor
	Carta(string nombre, string palo, int valor);
	~Carta(); // destructor
	void operator~();
};
#endif /* CARTA_H */
