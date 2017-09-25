#ifndef TABLERO_H
#define TABLERO_H

#include "Ficha.h"

using namespace std;
                                       
class Tablero{
	///@class Tablero
public:
    Ficha** tablero;
    ///Tamaño del tablero
    int size;		
    ///Sirve para verificar si alguien ha ganado
    bool ganar;		
	
	Tablero();
	Tablero(int t);
	~Tablero();
	bool ponroja(int a, int b);
	bool ponazul(int a, int b);
	void operator~();
};
#endif /* TABLERO_H */
