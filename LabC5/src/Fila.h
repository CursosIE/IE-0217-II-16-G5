#ifndef FILA_H
#define FILA_H

#include <iostream>
#include "string"

using namespace std;
                                       
class Fila {
	///@class Fila
public:
	char* fila;
	char* filord;
	int filen;
	int E;
	int T;
	int D;	
	
	Fila();	// constructor
	Fila(char* fila);
	~Fila(); // destructor
	void salas();
	void ord();
	void operator~();
	char pop(bool cond);
};
#endif /* FILA_H */
