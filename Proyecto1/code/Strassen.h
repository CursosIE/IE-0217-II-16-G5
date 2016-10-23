//EmmaDu 
#ifndef STRASSEN_H
#define STRASSEN_H

#include "Cuadrante.h"

using namespace std;

class Strassen{

public:
	// Atributos:
	int f;				///filas matriz común
	int c;				///columnas matriz común
	int d;				///dimension
    Cuadrante coord;	///coordenadas de inicio y cierre
    int** cont;			///contenido de la matriz
    
	Strassen();	
	Strassen(int f, int c, int d, int n);
	Strassen(int f, int c);
	Strassen(int d);
	virtual ~Strassen();
	
	int** obtdim(int a, char** entrada);
	int ddn(int** dms);
	int** contx(int f, int c, int n);
	int** contnull(int f, int c);
	int** contnull(int d);
	void fill();
	void modContCero();
    void sobreCont( int** cA, Cuadrante t, Cuadrante a);
    void printContN();
    void printCont();
    void mulNormal(Strassen A, Strassen B);
    void casobase(Strassen A, Strassen B, Cuadrante a, Cuadrante b);
    void mulCuad(Strassen A, Strassen B, Cuadrante a, Cuadrante b);
    void cuadx(Strassen A, Strassen B, Cuadrante a, Cuadrante b, int c);
    void mulSt(Strassen A, Strassen B);
	void eraseN();
	void erase();
};
#endif /* STRASSEN_H */
