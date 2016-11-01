#include "Jugador.h"
#include <iostream>
#include "string"
#include "Carta.h"
#include "Mazo.h"
///Constructor básico de la clase Jugador
Jugador::Jugador(){
}
///Constructor con características de la clase Jugador
Jugador::Jugador(int n){
 this->puntos=0;
 this->activo=false;
 this->numero=n;
}

///Destructor de la clase Jugador
Jugador::~Jugador(){
}

///Método de print para objetos Jugador
void Jugador::operator~(){
	cout<<"El jugador "<<numero<< " posee "<< puntos<<" puntos"<<endl;
}

///Método de la clase jugador para comer carta de un mazo
void Jugador::comer(Mazo &mazo){
	Carta carta=mazo.pop(true);
	this->puntos+=carta.valor;
	}
