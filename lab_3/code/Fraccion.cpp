// Dunia Barahona
#include "Fraccion.h"

Fraccion::Fraccion() 
{	///@brief El @b constructor es una función que se llama igual que la clase	
}
Fraccion::Fraccion(double num, double den) 
{	///@brief Constructor que recibe los atributos como parámetros
	this->num =num;
	this->den =den;
}
Fraccion::~Fraccion() 
{	///@brief Destructor, sirve para destruir un objeto de la clase
}	
Fraccion Fraccion::operator+(const Fraccion f2) 
{	///@brief Sobrecarga del operador @b +
	///
	///Método que pertenece a la clase Fraccion y devuelve un bjeto de tipo Fraccion 
	///@param f2 objeto de tipo Fraccion
    ///@return Suma de las fracciones dadas
	Fraccion fadd;
    //this se refiere al objeto con el que estoy llamando al metodo (f1+) f1 es this
	fadd.num= (this->num * f2.den)+(f2.num * this->den);
	fadd.den= (this->den * f2.den);
	return fadd;
}
Fraccion Fraccion::operator-(const Fraccion f2) 
{	///@brief Sobrecarga del operador @b -
	///
	///Método que pertenece a la clase Fraccion y devuelve un bjeto de tipo Fraccion 
	///@param f2 objeto de tipo Fraccion
    ///@return Resta de las fracciones dadas
	Fraccion fsub;
	fsub.num= (this->num * f2.den)-(f2.num * this->den);
	fsub.den= (this->den * f2.den);
	return fsub;
}
Fraccion Fraccion::operator*(const Fraccion f2) 
{	///@brief Sobrecarga del operador @b *
	///
	///Método que pertenece a la clase Fraccion y devuelve un bjeto de tipo Fraccion 
	///@param f2 objeto de tipo Fraccion
    ///@return Multiplicación de las fracciones dadas
	Fraccion fmul;
	fmul.num= this->num * f2.num;
	fmul.den= this->den * f2.den;
	return fmul;
}
Fraccion Fraccion::operator/(const Fraccion f2) 
{	///@brief Sobrecarga del operador @b /
	///
	///Método que pertenece a la clase Fraccion y devuelve un bjeto de tipo Fraccion 
	///@param f2 objeto de tipo Fraccion
    ///@return División de las fracciones dadas
	Fraccion fdiv;
	fdiv.num= this->num * f2.den;
	fdiv.den= this->den * f2.num;
	return fdiv;
}
void Fraccion::operator~() 
{	///@brief Sobrecarga del operador @b ~
	///
	///Método que pertenece a la clase Fraccion
	///
    ///Imprime la fracción especificada
	cout<< this->num<< "/"<< this->den<< endl;
	//this se refiere al objeto con el que llamo esta función. (~f1) f1 es this
}
