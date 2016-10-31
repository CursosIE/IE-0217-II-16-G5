//EmmaDu 
#include "Cuadrante.h"

Cuadrante::Cuadrante() {
}
///Constructor de un cuadrante
Cuadrante::Cuadrante(int d) {
	int* ci= new int[2];
	ci[0]= 0;
	ci[1]= 0; 
	this->ci= ci;
	int* cc= new int[2];
	cc[0]= d-1;
	cc[1]= d-1;
	this->cc= cc;
	this->d= d;
}
///Destructor
Cuadrante::~Cuadrante() {
}

void Cuadrante::print() {
	///@brief Imprime las coordenadas de inicio y cierre de un cuadrante
	cout<<"Inicia en (fila, columna): "<<this->ci[0]<<"\t"<<this->ci[1]<<endl;
	cout<<"Cierra en (fila, columna): "<<this->cc[0]<<"\t"<<this->cc[1]<<endl;
	cout<<"Es de dimensión: \t"<<this->d<<endl;
	cout<<endl;
}
Cuadrante* Cuadrante::dividir() {
	///@brief Divide un cuadrante en cuatro cuadrantes
	///@return Arreglo que contiene cuatro cuadrantes
	int dim= this->d;
	int d= dim/2;

	Cuadrante* cuad= new Cuadrante[4];

	Cuadrante c1= Cuadrante(d);
	c1.ci[0]= this->ci[0];
	c1.ci[1]= this->ci[1];
	c1.cc[0]= (this->ci[0]) + (d-1);
	c1.cc[1]= (this->ci[1]) + (d-1);

	Cuadrante c2= Cuadrante(d);
	c2.ci[0]= this->ci[0];
	c2.ci[1]= (this->ci[1]) + d;
	c2.cc[0]= (this->ci[0]) + (d-1);
	c2.cc[1]= this->cc[1];

	Cuadrante c3= Cuadrante(d);
	c3.ci[0]= (this->ci[0]) + d;
	c3.ci[1]= this->ci[1];
	c3.cc[0]= this->cc[0];
	c3.cc[1]= (this->ci[1]) + (d-1);

	Cuadrante c4= Cuadrante(d);
	c4.ci[0]= (this->ci[0]) + d;
	c4.ci[1]= (this->ci[1]) + d;
	c4.cc[0]= this->cc[0];
	c4.cc[1]= this->cc[1];

	cuad[0]= c1;
	cuad[1]= c2;
	cuad[2]= c3;
	cuad[3]= c4;

	return cuad;
	
	for (int i = 0; i < 4; i++)
	{
		delete[] cuad[i].ci;
		delete[] cuad[i].cc;
	}
	delete[] cuad;
}
