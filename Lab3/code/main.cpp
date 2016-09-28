// Dunia Barahona
#include "Fraccion.h"
#include "Polinomio.h"
#include "Matriz.h"
#include "Calculadora.h"

/// @mainpage Programación genérica en C++
/// @author Dunia Barahona <s4si@hotmail.com>
/// @date 27 de setiembre de 2016
/// @version 1.0
/// @par Descripción
/// Clase emplantillada @link Calculadora @endlink, en la cual se pueden sumar, restar, multiplicar o dividir objetos del
/// tipo @link Fraccion @endlink, @link Polinomio @endlink y @link Matriz @endlink.
/// Todas estas clases tiene su respectivo archivo de encabezados y estan implementadas en el @link main @endlink.

int main(int argc, char** argv) {
	/// Llamado a la clase emplantillada @link Calculadora @endlink:
	/// @code
	///Calculadora<Fraccion>* c1= new Calculadora<Fraccion>();
	///Calculadora<Matriz>* c2= new Calculadora<Matriz>();
	///Calculadora<Polinomio>* c3= new Calculadora<Polinomio>();
	/// @endcode
	///
	/// @brief Se suman, restan, multiplican y dividen fracciones, polinomios y matrices.
	Calculadora<Fraccion>* c1= new Calculadora<Fraccion>();
	Calculadora<Matriz>* c2= new Calculadora<Matriz>();
	Calculadora<Polinomio>* c3= new Calculadora<Polinomio>();
	
    Fraccion f1= Fraccion (22.0, 7.0);
	Fraccion f2= Fraccion (40.0, 20.0);
    cout<<endl<<"Fracción f1:\t";
    c1->print(f1);
    cout<<"Fracción f2:\t";
    c1->print(f2);
    cout<<"f1+f2=\t";
    c1->print(c1->add(f1, f2));
    cout<<"f1-f2=\t";
    c1->print(c1->sub(f1, f2));
    cout<<"f1*f2=\t";
    c1->print(c1->mul(f1, f2));
    cout<<"f1/f2=\t";
    c1->print(c1->div(f1, f2));
	
	double a[5] = {38, -65, 0, 0, 27};
	double b[3] = {2, -5, 3};
	Polinomio pa= Polinomio(5, 'x', a);
	Polinomio pb= Polinomio(3, 'x', b);
	cout<<endl<<"Polinomio a:\t";
	c3->print(pa);
	cout<<"Polinomio b:\t";
	c3->print(pb);
    cout<<"a+b=\t";
    c3->print(c3->add(pa, pb));
    cout<<"a-b=\t";
    c3->print(c3->sub(pa, pb));
    cout<<"a*b=\t";
    c3->print(c3->mul(pa, pb));
    cout<<"a/b=\t";
    c3->print(c3->div(pa, pb));
	
	///////////////////////////////
	double l=0;
	int m=4;
	int n=4;
	double **mat1 = (double **) malloc(sizeof(double *)*m);
	for(int i=0; i<m; i++){
        mat1[i] = (double *) malloc(sizeof(double)*n); 
	}
	for(int i=0;i<m;i++){
		for(int j=0; j<n; j++){
            mat1[i][j]=2;
  			}
		}
	double **mat2 = (double **) malloc(sizeof(double *)*m);
	for(int i=0; i<m; i++){
        mat2[i] = (double *) malloc(sizeof(double)*n); 
	}
	for(int i=0;i<m;i++){
		for(int j=0; j<n; j++){
            mat2[i][j]=3;
  			}
		}
	Matriz m1(m,n, mat1);
	Matriz m2(m,n, mat2);
	cout<<endl<<"Matriz m1:"<<endl;
	c2->print(m1);
	cout<<endl<<"Matriz m2:"<<endl;
	c2->print(m2);
	cout<<endl<<"m1+m2:"<<endl;
	c2->print(c2->add(m1, m2));
	cout<<endl<<"m1-m2:"<<endl;
	c2->print(c2->sub(m1, m2));
	cout<<endl<<"m1*m2:"<<endl;
	c2->print(c2->mul(m1, m2));
	cout<<endl<<"m1/m2:"<<endl;
	c2->print(c2->div(m1, m2));
	
	return 0;
}
