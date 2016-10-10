#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include "string"
#include "Matriz.h"
#include <ctime>
using namespace std;

/// @mainpage Programación genérica en C++
/// @author Dunia Barahona y Emmanuel Bustos <s4si@hotmail.com>
/// @date 27 de setiembre de 2016
/// @version 1.0
/// @par Descripción
/// Clase emplantillada @link Calculadora @endlink , en la cual se pueden sumar, restar, multiplicar o dividir objetos del
/// tipo @link Fraccion @endlink , @link Polinomio @endlink y @link Matriz @endlink . 
/// Cada clase tiene su respectivo archivo de encabezados.

int main(int argc, char** argv) {
	srand((unsigned int) time (NULL)); 
	double l=0;
	int m=8;
	int n=8;
	double **mat1 = (double **) malloc(sizeof(double *)*m);
	for(int i=0; i<m; i++){
        mat1[i] = (double *) malloc(sizeof(double)*n); 
	}
	for(int i=0;i<m;i++){
		for(int j=0; j<n; j++){
            mat1[i][j]=rand()%10; 
  			}
		}
	double **mat2 = (double **) malloc(sizeof(double *)*m);
	for(int i=0; i<m; i++){
        mat2[i] = (double *) malloc(sizeof(double)*n); 
	}
	for(int i=0;i<m;i++){
		for(int j=0; j<n; j++){
            mat2[i][j]=rand()%10;
  			}
		}
	Matriz m1(m,n, mat1);
	Matriz m2(m,n, mat2);
	Matriz m3(2,2,m1.mat2x2(m2));
	cout<<endl<<"Matriz m1:"<<endl;
	~(m1);
	cout<<endl<<"Matriz m2:"<<endl;
	~(m2);
	cout<<endl<<"Matriz m3:"<<endl;
	~(m1*m2);
	cout<<endl<<"Matriz bloque:"<<endl;
	~(m1.matblock(2));
	
	return 0;
}
