#ifndef MAZO_H
#define MAZO_H

#include <iostream>
#include "string"

using namespace std;
                                       
class Mazo{
	///@class Mazo
public:
    Carta* deck;
    int cantcart;
	Mazo();	// constructor
	Mazo(string nombre, string palo, int valor);
	void barajar();
	Carta pop(bool cond);
	~Mazo(); // destructor
	void operator~();
};
#endif /* MAZO_H */
