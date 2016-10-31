#include "Carta.h"
#include <iostream>
#include "string"
#include "Mazo.h"
#include <cstdlib>
#include "time.h"
///Constructor básico de clase Mazo
Mazo::Mazo(){
	this->cantcart=52;
	this->deck = new Carta[52];
    this->deck[0]=Carta("As", "Picas", 11);
	this->deck[1]=Carta("Dos", "Picas", 2);
	this->deck[2]=Carta("Tres", "Picas", 3);
	this->deck[3]=Carta("Cuatro", "Picas", 4);
	this->deck[4]=Carta("Cinco", "Picas", 5);
	this->deck[5]=Carta("Seis", "Picas", 6);
	this->deck[6]=Carta("Siete", "Picas", 7);
	this->deck[7]=Carta("Ocho", "Picas", 8);
	this->deck[8]=Carta("Nueve", "Picas", 9);
	this->deck[9]=Carta("Diez", "Picas", 10);
	this->deck[10]=Carta("J", "Picas", 10);
	this->deck[11]=Carta("Q", "Picas", 10);
	this->deck[12]=Carta("K", "Picas", 10);
	
	this->deck[13]=Carta("As", "Diamantes", 11);
	this->deck[14]=Carta("Dos", "Diamantes", 2);
	this->deck[15]=Carta("Tres", "Diamantes", 3);
	this->deck[16]=Carta("Cuatro", "Diamantes", 4);
	this->deck[17]=Carta("Cinco", "Diamantes", 5);
	this->deck[18]=Carta("Seis", "Diamantes", 6);
	this->deck[19]=Carta("Siente", "Diamantes", 7);
	this->deck[20]=Carta("Ocho", "Diamantes", 8);
	this->deck[21]=Carta("Nueve", "Diamantes", 9);
	this->deck[22]=Carta("Diez", "Diamantes", 10);
	this->deck[23]=Carta("J", "Diamantes", 10);
	this->deck[24]=Carta("Q", "Diamantes", 10);
	this->deck[25]=Carta("K", "Diamantes", 10);
	
	this->deck[26]=Carta("As", "Corazones", 11);
	this->deck[27]=Carta("Dos", "Corazones", 2);
	this->deck[28]=Carta("Tres", "Corazones", 3);
	this->deck[29]=Carta("Cuatro", "Corazones", 4);
	this->deck[30]=Carta("Cinco", "Corazones", 5);
	this->deck[31]=Carta("Seis", "Corazones", 6);
	this->deck[32]=Carta("Siete", "Corazones", 7);
	this->deck[33]=Carta("Ocho", "Corazones", 8);
	this->deck[34]=Carta("Nueve", "Corazones", 9);
	this->deck[35]=Carta("Diez", "Corazones", 10);
	this->deck[36]=Carta("J", "Corazones", 10);
	this->deck[37]=Carta("Q", "Corazones", 10);
	this->deck[38]=Carta("K", "Corazones", 10);
	
	this->deck[39]=Carta("As", "Trébol", 11);
	this->deck[40]=Carta("Dos", "Trébol", 2);
	this->deck[41]=Carta("Tres", "Trébol", 3);
	this->deck[42]=Carta("Cuatro", "Trébol", 4);
	this->deck[43]=Carta("Cinco", "Trébol", 5);
	this->deck[44]=Carta("Seis", "Trébol", 6);
	this->deck[45]=Carta("Siete", "Trébol", 7);
	this->deck[46]=Carta("Ocho", "Trébol", 8);
	this->deck[47]=Carta("Nueve", "Trébol", 9);
	this->deck[48]=Carta("Diez", "Trébol", 10);
	this->deck[49]=Carta("J", "Trébol", 10);
	this->deck[50]=Carta("Q", "Trébol", 10);
	this->deck[51]=Carta("K", "Trébol", 10);
	
}

///Destructor de la clase mazo
Mazo::~Mazo(){
}

///Método que de forma aleatoria ordena a las cartas del objeto mazo
void Mazo::barajar(){
	srand(time(0));
	Carta cartemp;
	int m;
	int n;
	for(int i=0; i<300; i++){
		m=rand()%(cantcart);
		n=rand()%(cantcart);
		cartemp=this->deck[m];
		this->deck[m]=this->deck[n];
		this->deck[n]=cartemp;
		}
	}

///Método que hace un pop al mazo, removiendo la carta que está arriba en el strack
Carta Mazo::pop(bool cond){
	if(cond && cantcart!=0){
		this->cantcart--;
		return this->deck[cantcart];
	}
}

///Método de print para la clase mazo
void Mazo::operator~(){
	for(int i=0; i<cantcart; i++){
		~deck[i];
		}
}
