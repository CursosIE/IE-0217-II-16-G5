#ifndef NODO_H
#define NODO_H

#include "string"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

template <typename DT>	//DT (datatype): tipo de dato, es el que se reemplaza

class nodo { /// Lista enlazada
public:
	
	//Una lista enlazada tiene un conjunto de nodos.
	//Los nodos almacenan 2 tipos de información: El dato que contienen y un puntero al siguiente nodo en la lista.
    //El último nodo de la lista tiene como siguiente nodo el valor NULL.
	//En el caso de las listas el acceso es secuencial, es decir, para acceder a un elemento del conjunto debemos 
	//de recorrer uno por uno los elementos hasta llegar al solicitado.
    
    
    //Atributos
	//DT* dato;	//puntero: contenido
	/// Contenido
	DT dato;
	/// Puntero: siguiente nodo	
	nodo* sn;	

    /// Constructor por defecto
    nodo() {
		this->dato= -1;
		this->sn= NULL;
	}
	/// Constructor por parámetro: Recibe elemento de tipo DT llamado dato
	nodo(DT dato) {		
		this->dato= dato;
		this->sn= NULL;
	}
	/// Destructor
	~nodo() {	
	}
	
	void print()	{
		///@brief Imprime un nodo
		if (this->sn==NULL) {
			cout<< this->dato <<endl;
		}
		else {
			cout<< this->dato << "-> ";
		}
	}
	//
	void erase() {
		///@brief Se elimina ese nodo	
		delete this->sn;
		delete this;
	}
};
#endif /* NODO_H */
