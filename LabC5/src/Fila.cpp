#include "Fila.h"
#include <iostream>
#include "string"

///Constructor básico de la clase Fila
Fila::Fila(){
}

///Constructor con características de la clase Fila
Fila::Fila(char* fila){
 this->fila = fila;
 char* filo = new char[filen];
 this->filord = filo;
 this->D=0;
 this->E=0;
 this->T=0;
 int i=0;
 int len=0;
 while(fila[i]!='\0'){
 len++;
 i++;
	}
this->filen = len;
}

///Método de la clase fila que crea salas de espera en las cuales agrupa a su contenido según su tipo
void Fila::salas(){
	int i=0;
	int t=0;
	while(i<filen){
	if(fila[i]=='T'){
		t++;
		}
	if(fila[i]=='E'){
		this->E++;
		}
	if(fila[i]=='D'){
		this->D++;
		}
	i++;
	}
	this->T=t;
}

///Método que ordena la fila según la prioridad
void Fila::ord(){
	this->salas();
	D=this->D;
	T=this->T;
	E=this->E;
	float i=0;
	float j=0;
	float k=0;
	int cont=filen-1;
	while(D!=0 || T!=0 || E!=0){
		i+=2;
		j+=1;
		k+=0.5;
		if(i==2 && E!=0){
			filord[cont]= 'E';
			E--;
			cont--;
			i=0;
			}
		if(j==2 && T!=0){
			filord[cont]= 'T';
			T--;
			cont--;
			j=0;
			}
		if(k==2 && D!=0){
			filord[cont]= 'D';
			D--;
			cont--;
			k=0;
			}
		}
	}

///Método que extrae el último elemento de la cola fila ordenada
char Fila::pop(bool cond){
	if(cond && filen!=0){
		this->filen--;
		return this->filord[filen];
	}
}

///Destructor de la clase Fila
Fila::~Fila(){
}

///Método de impresión para la clase Fila
void Fila::operator~(){
		for(int i=0;i<this->filen;i++){
		cout<<this->filord[i]<< ' ';
		}
	cout<<endl;
}

