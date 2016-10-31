#include "Carta.h"
#include <iostream>
#include "string"
 ///Constructor básico de la clase Carta
Carta::Carta(){
}

///Constructor con características de la clase Carta
Carta::Carta(string nombre, string palo, int valor){
 this->nombre = nombre;
 this->palo=palo;
 this->valor=valor;
}

///Destructor de la clase Carta
Carta::~Carta(){
}

///Método de print para la clase Carta
void Carta::operator~(){
		cout<< this->nombre << " de " << this->palo << " con valor de " << this->valor << endl;
}
