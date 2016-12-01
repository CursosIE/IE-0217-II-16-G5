#ifndef FICHA_H
#define FICHA_H

#include <stdio.h> 
#include <iostream>
#include <list>
#include "string"

#include "stdlib.h"   
#include <cstdlib>
#include <unistd.h>

#include <iostream>
#include "string"

#include <vector>
#include "time.h"

using namespace std;
                                       
class Ficha{
	///@class Ficha
public:
	int* pos;
    bool rojo;
    bool azul;
    ///True si sí esta conectado al inicio
    bool* conectainicio;
    ///True si sí esta conectado al final 
    bool* conectafinal;
    ///Listas de espera 
    vector<int*> coneci;
    ///Lista de espera 
    vector<int*> conecf; 
	
	Ficha();
	~Ficha(); 
	void operator~();
};
#endif /* FICHA_H */
