// Dunia Barahona
#include "Polinomio.h"

Polinomio::Polinomio() {	
	///@brief Constructor simple
}
Polinomio::Polinomio(int tam, char var, double* coef) {
	///@brief Constructor con atributos
	this->tam= tam;
	this->var= var;
	double* temp= new double[tam];
	for (int i= 0; i< tam; i++)
	{
		temp[i]= coef[tam-1-i];
	}
	//les da vuelta, queda vector donde la posición es el exponente
	this->coef= temp;
	//delete[] temp;
}
Polinomio::~Polinomio() {	
	///@brief Destructor
}
Polinomio Polinomio::operator+(Polinomio p2) 
{   ///@brief Sobrecarga del operador @b +
	///
	///Método que pertenece a la clase Polinomio y que devuelve un objeto de tipo Polinomio 
	///@param p2 objeto de tipo Polinomio
    ///@return Suma de los polinomios dados
    Polinomio pm, pM, padd;
    if (this->tam > p2.tam)
	{
		pm= p2;
		pM.tam= this->tam;
		pM.var= this->var;
		pM.coef= this->coef;
	}
	else
	{
		pM= p2;
		pm.tam= this->tam;
		pm.var= this->var;
		pm.coef= this->coef;
	}
	double* temp= new double[pM.tam];
	for (int i = 0; i < pm.tam; i++)
	{
		temp[i]= this->coef[i] + p2.coef[i];
	}
	for (int i = 0; i < (pM.tam-pm.tam); i++)
	{
		temp[pm.tam+i]= pM.coef[pm.tam+i];
	}
	padd.coef= temp;
	padd.tam= pM.tam;
	padd.var= this->var;
	return padd;
	delete[] temp;	
}
Polinomio Polinomio::operator-(Polinomio p2) 
{   ///@brief Sobrecarga del operador @b -
	///
	///Método que pertenece a la clase Polinomio y que devuelve un objeto de tipo Polinomio 
	///@param p2 objeto de tipo Polinomio
    ///@return Resta de los polinomios dados
    Polinomio pm, pM, psub;
    if (this->tam > p2.tam)
	{
		pm= p2;
		pM.tam= this->tam;
		pM.var= this->var;
		pM.coef= this->coef;
	}
	else
	{
		pM= p2;
		pm.tam= this->tam;
		pm.var= this->var;
		pm.coef= this->coef;
	}
	double* temp= new double[pM.tam];
	for (int i = 0; i < pm.tam; i++)
	{
		temp[i]= this->coef[i] - p2.coef[i];
	}
	for (int i = 0; i < (pM.tam-pm.tam); i++)
	{
		if (this->tam > p2.tam) {
			temp[pm.tam+i]= pM.coef[pm.tam+i];
		}
		else {
			temp[pm.tam+i]= (-1)*pM.coef[pm.tam+i];
		}
	}
	psub.coef= temp;
	psub.tam= pM.tam;
	psub.var= this->var;
	return psub;
	delete[] temp;	
}
Polinomio Polinomio::operator*(Polinomio p2) 
{   ///@brief Sobrecarga del operador @b *
	///
	///Método que pertenece a la clase Polinomio y que devuelve un objeto de tipo Polinomio 
	///@param p2 objeto de tipo Polinomio
    ///@return Multiplicación de los polinomios dados
    Polinomio pmul;
	pmul.tam= this->tam*p2.tam;
	pmul.var= this->var;
	int i=0, tp=0;
	double* temp= new double[pmul.tam];
	for (int a = 0; a < this->tam; a++)
	{
		for (int b = 0; b < p2.tam; b++)
		{
			tp= this->coef[a] * p2.coef[b];
			i= a+b;
			temp[i]+= tp;
		}
	}
	pmul.coef= temp;
	return pmul;
	delete[] temp;
}
Polinomio Polinomio::operator/(Polinomio p2) 
{   ///@brief Sobrecarga del operador @b /
	///
	///Método que pertenece a la clase Polinomio y que devuelve un objeto de tipo Polinomio 
	///@param p2 objeto de tipo Polinomio
    ///@return División de los polinomios dados
	int tamdiv=(this->tam-p2.tam)+1, j=1;
	double* div= new double[tamdiv];
	double* cociente= new double[tamdiv];
	Polinomio pdiv, pb, pc, pd;
	pdiv.coef= div;
	pdiv.var= this->var;
	pdiv.tam= tamdiv;
	pb.coef= this->coef;
	pb.var= this->var;
	pb.tam= this->tam;
	for (int i =tamdiv-1; i >=0; i--)
	{   
		for (int k = 0; k < tamdiv; k++)
		{
			div[k]=0;
		}
		div[i]= pb.coef[pb.tam-j]/p2.coef[p2.tam-1];
		cociente[i]= div[i];
		pdiv.coef= div;
		pc= pdiv*p2;
		pd= pb-pc;
		pb.coef= pd.coef;
		j++;
	}
	pdiv.coef= cociente;
	return pdiv;
	delete[] div;
	delete[] cociente;
}
void Polinomio::operator~() 
{	///@brief Sobrecarga del operador @b ~
	///
	///Método que pertenece a la clase Polinomio
	///
    ///Imprime el polinomio especificado
	int cont=0;
	int a= this->tam-1;
	while (this->coef[a]==0)
	{
		cont++;
		a--;
	}
	for (int i= this->tam-1-cont; i>=0 ; i--)
	{
		if (i==0)
		{
			if (this->coef[i]!=0)
			{
				cout<<this->coef[i];
			}
		}
		if (i>0)
		{
			if (this->coef[i]==-1)
			{
				cout<<'-';
			}
			if (this->coef[i]!=0&&this->coef[i]!=1&&this->coef[i]!=-1)
			{
				cout<<this->coef[i];
			}
			if (this->coef[i]!=0)
			{
				cout<<this->var;
			}
			if ((i!=1)&&(this->coef[i]!=0))
			{
				cout<<'^'<<i;
			}
			if (this->coef[i-1]>0)
			{
				cout<<'+';
			}
		}
		if (i==0)
		{
			cout<<endl;
		}
	}
}	   
