#include "Portero.h"

/// Constructor por defecto
Portero::Portero() {
	this->cE= 0;
	this->cT= 0;
	this->cD= 0.0;
	this->ciclos= 0;

	this->sala_E= new LCP<char>();
	this->sala_T= new LCP<char>();
	this->sala_D= new LCP<char>();

}
/// Destructor
Portero::~Portero() {
}
//
void Portero::ubicar(char** clientes) {
    ///@brief Ubica clientes en salas respectivas
	int i=0;
    while (clientes[1][i]!='\0')
	{
		if (clientes[1][i]=='E')
		{
			sala_E->add_tail(clientes[1][i]);
		}
		else if (clientes[1][i]=='T')
		{
			sala_T->add_tail(clientes[1][i]);
		}
		else if (clientes[1][i]=='D')
		{
			sala_D->add_tail(clientes[1][i]);
		}
		i++;
	}
	sala_E->print();
	sala_T->print();
	sala_D->print();
}
//
char Portero::llamar_jugador() {
	///@brief Devuelve jugador que será enviado a la mesa
	///@return 'n' si no salió ningún jugador
	///@return 'o' si ya no hay más clientes en salas de espera
	int clientes= sala_E->cn + sala_T->cn + sala_D->cn;
	char jugador;	
	if (clientes>0)	//si sí hay clientes esperando su turno
	{	
		if (cE<2) {
			if (sala_E->hn==NULL) {			// Si la lista esta vacía, es decir el nodo cabeza es NULL entonces
				cE++;						// no hay más ejecutivos
				jugador='n';						
			}
			else {
				jugador='E';
				sala_E->rm_head();
				cE++;
			}
		}
		else {
			if (cT<1) {
				if (sala_T->hn==NULL) {		// Si la lista esta vacía, es decir el nodo cabeza es NULL entonces
					cT++;					// no hay más trabajadores
					jugador='n';						
				}
				else {
					jugador='T';
					sala_T->rm_head();
					cT++;
				}
			}
			else {
				if (sala_D->hn==NULL) {			// Si la lista esta vacía, es decir el nodo cabeza es NULL entonces
					cD++;						// no hay más Desempleados
					jugador='n';						
				}
				else {
					cD+=0.5;
					if (cD==1) {
						jugador='D';
						sala_D->rm_head();
					}
					else {
						jugador='n';
					}
				}
			}
		}
		ciclos++;
		if (ciclos==4 && cE==2 && cT==1) {	
			cE=0;
			cT=0;
			ciclos=0;
			if (cD==1) {
				cD=0;
			}
		}
	}
	else
	{
		cout<<"No hay más clientes"<<endl;
		jugador='o';
	}
	return jugador;
}
