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
	int m=256;
	int n=256;
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
	double **mat3 = (double **) malloc(sizeof(double *)*m);
	for(int i=0; i<m; i++){
        mat3[i] = (double *) malloc(sizeof(double)*n); 
	}
	for(int i=0;i<m;i++){
		for(int j=0; j<n; j++){
            mat3[i][j]=rand()%10;
  			}
		}
	double **mat4 = (double **) malloc(sizeof(double *)*m);
	for(int i=0; i<m; i++){
        mat4[i] = (double *) malloc(sizeof(double)*n); 
	}
	for(int i=0;i<m;i++){
		for(int j=0; j<n; j++){
            mat4[i][j]=rand()%10;
  			}
		}
	Matriz m1(m,n, mat1);
	Matriz m2(m,n, mat2);
//	Matriz m3(m,n, mat3);
//	Matriz m4(m,n, mat4);
	//Matriz m6=m1*m2;
	Matriz m5 = m1.strassen(m2);
	/*cout<<endl<<"Matriz m1:"<<endl;
	~(m1);
	cout<<endl<<"Matriz m2:"<<endl;
	~(m2);
	cout<<endl<<"Matriz m3:"<<endl;
	~(m3);
	cout<<endl<<"Matriz m4:"<<endl;
	~(m4);
	cout<<endl<<"Matriz m*:"<<endl;
	~(m6);*/
	//cout<<endl<<"Matriz bloque:"<<endl;
	~(m5);
	
	
	return 0;
}
