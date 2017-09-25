#ifndef LCP_H
#define LCP_H

#include "nodo.h"

//Lista con punteros
template <typename DT>	//DT (datatype): tipo de dato, es el que se reemplaza

class LCP {	//lista enlazada
public:
	
	//Atributos
	/// Cantidad de nodos
	int cn;
	/// head: puntero de tipo nodo emplantillado			
	nodo<DT>* hn;	
	 
    /// Constructor por defecto
    LCP() {
		cn= 0;
		this->hn= NULL;
	}
	
	/// Destructor
    ~LCP() {
	}

    void add_head(DT dato) {
		///@brief Inserta dato al inicio de la lista
		nodo<DT>* nuevo_nodo= new nodo<DT> (dato);	//puntero nuevo_nodo de tipo nodo emplantillado, llama a constructor
		nodo<DT>* temp= hn;		//puntero temp de tipo nodo emplantillado, donde guarda al nodo cabeza de la lista
		
		if (hn==NULL) {			// si la lista esta vacía, es decir el nodo cabeza es NULL entonces
			hn = nuevo_nodo;	// el nodo cabeza pasa a ser el nuevo nodo creado
		}
		else {                      // si el nodo cabeza es distinto de NULL entonces
			nuevo_nodo->sn = hn;	// nuevo_nodo apunta al nodo cabeza
			hn = nuevo_nodo;		// el nodo cabeza es ahora el nuevo nodo creado
		}
		cn++;
	}
    
    void add_tail(DT dato) {
		///@brief Inserta dato al final de la lista
		nodo<DT>* nuevo_nodo= new nodo<DT> (dato);	//puntero nuevo_nodo de tipo nodo emplantillado, llama a constructor
		
		if (hn==NULL) {			// si la lista esta vacía, es decir el nodo cabeza es NULL entonces
			hn = nuevo_nodo;	// el nodo cabeza pasa a ser el nuevo nodo creado
		}
		else {	
			nodo<DT>* temp= hn;		//puntero temp de tipo nodo emplantillado, donde guarda al nodo cabeza de la lista
			//// encuentra último nodo: tail de la lista //////
			while (temp->sn!=NULL) {
				temp= temp->sn;
			}
			///////////////////////////////////////////////////
			temp->sn= nuevo_nodo;	//último nodo apunte al nuevo nodo. Nuevo nodo apunta a NULL por default
		}
		cn++;
	}
	
    nodo<DT>* find_e(DT esp, int opc) {	//recibe dato tipo DT, devuelve objeto tipo nodo emplantillado  
        ///@brief Encuentra un elemento en específico
		///@return Si opc es 0 devuelve nodo anterior al nodo con el elemento específico
		///@return Si opc es 1 devuelve nodo que con el elemento específico
		nodo<DT>* temp= hn;		//crea nodo temporal y guarda en él al nodo cabeza
		nodo<DT>* n_ant;		//nodo anterior
		nodo<DT>* n_esp;		//nodo específico
		int cont= 0;
		
		if (hn->dato==esp)
		{   n_ant=NULL;
			n_esp= hn;
		}
		else {
			while (temp!=NULL) {	//recorre toda la lista. Hasta llegar al último nodo que apunta a NULL
				
				if (temp->sn!=NULL) {
					n_ant= temp;
					n_esp= temp->sn;
				}	
				if (n_esp->dato==esp) {
					temp= NULL;
				}
				else {
					temp= temp->sn;
					cont++;
				}
			}
			if (cont==cn) {
				n_ant=NULL;
				n_esp=NULL;
				
				if (esp!='o')
				{
					cout<<esp<<" no está en la lista"<<endl;
				}
			}
		}
		if (opc==0) {
			return n_ant;
		}
		else {
			return n_esp;
		}
		delete temp;
		delete n_ant;
		delete n_esp;
	}
	
    void rm_head() {
        ///@brief Elimina primer elemento de la lista
		if (hn==NULL) {			// si la lista esta vacía, es decir el nodo cabeza es NULL entonces
			cout<<"Lista vacía"<<endl;
		}
		else {					// si el nodo cabeza es distinto de NULL entonces
			hn= hn->sn;         // el nodo cabeza ahora será el nodo siguiente
		}
		cn--;
		//¿como liberar memoria del elemento que estoy eliminando?
	}
	
    void rm_tail() {
		///@brief Elimina último elemento de la lista
        if (cn==0) {
			cout<<"Lista vacía"<<endl;
		}
		else {
			nodo<DT>* tempPRE;		
			nodo<DT>* temp= hn;		//puntero temp de tipo nodo emplantillado, donde guarda al nodo cabeza de la lista
			//// encuentra último nodo: tail de la lista //////
			while (temp->sn!=NULL) {
				tempPRE= temp;
				temp= temp->sn;
			}
			///////////////////////////////////////////////////
			tempPRE->sn= NULL;
			delete temp;
			cn--;
		}
	}	
	
	void rm_e(DT esp) {
        ///@brief Elimina un elemento en específico
        nodo<DT>* n_esp= this->find_e(esp, 1);		//específico
        if (n_esp!=NULL) {
			nodo<DT>* temp= this->find_e(esp, 0);	//anterior
			
			if (temp==NULL) {
				this->rm_head();
			}
			else {
				temp->sn= n_esp->sn;
				delete n_esp;
				cn--;
			}
		}
		//¿como liberar memoria del elemento que estoy eliminando?
	}
	
	//Limpiar lista 
    void clear() {
        ///@brief Elimina todos los elementos de la lista. Vacía de elemtos la estructura.
        nodo<DT>* temp= hn;		//crea nodo temporal y guarda en él al nodo cabeza

		while (temp!=NULL) {
			if (temp->sn==NULL) {
				hn= temp;
				hn= NULL;
				cn--;
			}
			else {
				hn= temp;
				delete hn;
				cn--;
			}
			temp= temp->sn;		//en el nodo temporal guardo el nodo siguiente del nodo cabeza
		}
	}

	void print() {
		///@brief Imprime elementos de la lista
		nodo<DT>* temp= hn;		//crea nodo temporal y guarda en él al nodo cabeza
		
		if (this->cn==0){
			cout<<"Lista vacía"<<endl;
		}
		else {
			while (temp!=NULL) {
				if (temp->sn==NULL) {
					cout<< temp->dato;
				}
				else {
					cout<< temp->dato << "-> ";
				}
				temp= temp->sn;		//en el nodo temporal guardo el nodo siguiente del nodo cabeza
			}
			cout<<endl;
		}
	}
	
	void find_rm(DT dato) {
		///@brief Encuentra todos los elementos iguales al dato dado y lo elimina de la lista	
		nodo<DT>* temp= hn;		
			while (temp->sn!=NULL) {
				if (temp->dato == dato)
				{
					rm_e(dato);
				}
				temp= temp->sn;
			}
			if (temp->dato == dato && temp->sn==NULL) {
				rm_tail();
			}
	}	
	
private:

};

#endif /* LCP_H */
//Trabajo con punteros de un tipo de dato. En este caso el dato es del tipo nodo (objeto)
//Nodo esta emplantillado. El atributo dato de un objeto nodo esta emplantillado, por eso se debe específicar cual es.
