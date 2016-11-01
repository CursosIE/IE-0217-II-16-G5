#include "Mesa.h"

/// Constructor
Mesa::Mesa() {
	this->maso= new LCP<int>();			//pila
	this->cartas= new LCP<int>();		//pila
	this->jugadores= new LCP<char>();	//cola
	this->campos= 3;
	this->perdedor="";		//mayor a 21
	this->ganador ="";		//igual a 21 o cerca de 21
}
/// Destructor
Mesa::~Mesa() {
}

int Mesa::esta_llena() {
	///@brief Determina si la mesa esta llena o no
	///@return 1 si sí esta llena
	///@return 0 si no esta llena
	if ((3-jugadores->cn) > 0)	{	// Si sí hay campos disponibles
		return 0;	
	}
	else {
		return 1;
	}
}
////
void Mesa::barajar() {
	///@brief Baraja el maso. Llena de manera aleatoria la cola maso
	if (maso->hn!=NULL) {
		maso->clear();
	}
	for (int i = 0; i < 13; i++) {
		maso->add_head(rand() % 10 + 1);
	}
}
////
int Mesa::dar_carta() {
	///@brief Entrega una carta del maso
	int c= maso->hn->dato;
	maso->rm_head();
	return c;
}
////
void Mesa::repartir(LCP<int>* cartas, int k) {
	///@brief Reparte cartas
	///
	/// Si no tienen cartas se entregan dos, si ya tienen cartas se entrega solo una
	int carta=0;
	barajar();
	if (cartas->hn==NULL)	//si esta vacío: reparte dos carta a cada jugador
	{	
		for (int j = 0; j < k; j++) {
			for (int i = 0; i < 2; i++) {
				carta+= dar_carta();
			}
		cartas->add_tail(carta);
		carta=0;	
		}
	}
	else 	//si ya tiene algo: reparte solo una carta
	{	nodo<int>* temp= cartas->hn;
		int ct=0;
		if (cartas->cn < k) {
			for (int i = cartas->cn; i < k; i++) {
				cartas->add_tail(0);
			}	
		}
		for (int i = 0; i < k; i++) {
			carta= temp->dato + dar_carta();
			cartas->add_tail(carta);
			cartas->rm_head();
			temp= temp->sn;
		}
	}
}
//turno
int Mesa::turno() {
	///@brief En cada turno se reparten cartas y se verifica si algún jugador ganó o si todos continuan jugando
	///@return 0 si todos continuan jugando
	///@return 1 si algún jugador sale
	int se_acaba= 0;	//no
	LCP<char>* ganadores= new LCP<char>();	//temporal
	LCP<char>* perdedores= new LCP<char>();	//temporal

	repartir(cartas, jugadores->cn);
	cout<<endl;
	print_jugada(jugadores, cartas);

	nodo<int>* tempC= cartas->hn;		//crea nodo temporal y guarda en él al nodo cabeza de cartas
	nodo<char>* tempJ= jugadores->hn;	//crea nodo temporal y guarda en él al nodo cabeza de jugadores
	
	while (tempC!=NULL) {				//recorre las cartas que tiene cada jugador
		if (tempC->dato>18 && tempC->dato<22)	// Si la carta del jugador esta entre 19 y 21: Gana 
		{	
			ganadores->add_tail(tempJ->dato);
			ganador+=tempJ->dato;
			ganador+=' ';
			jugadores->rm_e(tempJ->dato);
			//cartas->rm_e(tempC->dato);
			se_acaba= 1;	//sí
		}
		if (tempC->dato>21)		// Si la suma de las cartas del jugador es mayor a 21: Pierde y se va
		{
			perdedores->add_tail(tempJ->dato);
			perdedor+=tempJ->dato;
			perdedor+=' ';
			jugadores->rm_e(tempJ->dato);
			//cartas->rm_e(tempC->dato);
			se_acaba= 1;	//sí
		}
		tempC= tempC->sn;
		tempJ= tempJ->sn;
	}
	////
	if (jugadores->cn == 0)	// vacío.
	{
		if (ganadores->cn >0)
		{
			tempJ= ganadores->hn;	//jugadores = ganadores
			while (tempJ!=NULL) {	
				jugadores->add_tail(tempJ->dato);
				tempJ= tempJ->sn;
			}
			ganadores->clear();
		}
	}
	else 	// si jugadores tiene algo
	{
		if (ganadores->cn >0)
		{
			tempJ= jugadores->hn;	//perdedores = jugadores
			while (tempJ!=NULL) {	
				perdedor+=tempJ->dato;
				perdedor+=' ';
				tempJ= tempJ->sn;
			}
			jugadores->clear();
			
			tempJ= ganadores->hn;	//jugadores = ganadores
			while (tempJ!=NULL) {	
				jugadores->add_tail(tempJ->dato);
				tempJ= tempJ->sn;
			}
			ganadores->clear();
		}
		if (ganadores->cn == 0 && perdedores->cn>0)
		{
			tempJ= jugadores->hn;	//ganadores = jugadores
			while (tempJ!=NULL) {	
				ganador+=tempJ->dato;
				ganador+=' ';
				tempJ= tempJ->sn;
			}
		}
	}
	if (ganador!="")
	{
		cout<<endl<<"Ganó:\t"<<ganador<<endl;
	}
	if (perdedor!="")
	{
		cout<<"Salió:\t"<<perdedor<<endl;
	}
	cout<<"Jugadores: ";
	jugadores->print();
	campos= 3 - jugadores->cn;
	cout<<"Campos:\t"<<campos<<endl;
	ganadores->clear();
	perdedores->clear();
	
	return se_acaba;	
}
//Partida
void Mesa::partida() {
	///@brief La partida inicia con la mesa llena y se acaba hasta que alguien sale de la mesa
	cout<<" //////////////// Inicia partida"<<endl;
	int se_acaba= 0;
	while (se_acaba== 0)
	{
		se_acaba= turno();
	}
	if (se_acaba==1)
	{
		cartas->clear();
		ganador="";
		perdedor="";
		cout<<endl;
	}
}	
////
void Mesa::print_jugada(LCP<char>* jugadores, LCP<int>* cartas) {
	///@brief Imprime jugador y su carta	
	nodo<char>* jt= jugadores->hn;
	nodo<int>* ct= cartas->hn;
		
	if (jugadores->cn==0 || cartas->cn==0){
		cout<<"No hay jugadores"<<endl;
	}
	else {
		while (jt!=NULL) {
			cout<<"Juega "<<jt->dato<<" con "<<ct->dato<<endl;
			jt= jt->sn;		//en el nodo temporal guardo el nodo siguiente del nodo cabeza
			ct= ct->sn;		
		}
	}
}
////
void Mesa::print_maso() {
	///@brief Imprime el maso de cartas	
	nodo<int>* temp= maso->hn;	//crea nodo temporal y guarda en él al nodo cabeza
		
	if (maso->cn==0){
		cout<<"Pila vacía"<<endl;
	}
	else {
		while (temp!=NULL) {
			cout<< "carta: "<<temp->dato <<endl;
			temp= temp->sn;		//en el nodo temporal guardo el nodo siguiente del nodo cabeza
		}
	}
	cout<<endl;
}
