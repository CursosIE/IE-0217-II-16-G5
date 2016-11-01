#ifndef CASINO_H
#define CASINO_H

#include "Portero.h"
#include "Mesa.h"

class Casino {
public:
	//Atributos
	///Portero	
	Portero* P;
	///Mesa 1			
	Mesa* mesa_1;
	///Mesa 2
	Mesa* mesa_2;
	///Mesa 3
	Mesa* mesa_3;
	
	Casino();
	~Casino();
	
	void jugar();

};
#endif /* CASINO_H */
