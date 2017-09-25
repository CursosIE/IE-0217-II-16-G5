#include "Fraccion.h"

Fraccion::Fraccion() 
{	
	// Constructor.
}
Fraccion::Fraccion(double num, double den) 
{
	this->num =num;
	this->den =den;
}
Fraccion::~Fraccion() 
{	
	// Destructor.
}
	
Fraccion Fraccion::operator+(const Fraccion f2) 
{
	//Método que sobrecarga el operador "+", que pertenece a la clase Fraccion y que devuelve un objeto de tipo Fraccion
	//Recibe objeto de tipo Fraccion
	Fraccion fadd;
    //this se refiere al objeto con el que estoy llamando al metodo (f1+) f1 es this
	fadd.num= (this->num * f2.den)+(f2.num * this->den);
	fadd.den= (this->den * f2.den);
	return fadd;
}
Fraccion Fraccion::operator-(const Fraccion f2) 
{
	//Método que sobrecarga el operador "-", que pertenece a la clase Fraccion y que devuelve un objeto de tipo Fraccion
	Fraccion fsub;
	fsub.num= (this->num * f2.den)-(f2.num * this->den);
	fsub.den= (this->den * f2.den);
	return fsub;
}
Fraccion Fraccion::operator*(const Fraccion f2) 
{
	Fraccion fmul;
	fmul.num= this->num * f2.num;
	fmul.den= this->den * f2.den;
	return fmul;
}
Fraccion Fraccion::operator/(const Fraccion f2) 
{
	Fraccion fdiv;
	fdiv.num= this->num * f2.den;
	fdiv.den= this->den * f2.num;
	return fdiv;
}
void Fraccion::operator~() 
{
	//Método que sobrecarga el operador "~", que pertenece a la clase Fraccion y que no devuelve nada
	cout<< this->num<< "/"<< this->den<< endl;
	//this se refiere al objeto con el que llamo esta función. (~f1) f1 es this
}
