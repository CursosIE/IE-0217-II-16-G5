//EmmaDu 
#ifndef STRASSEN_H
#define STRASSEN_H

#include "Cuadrante.h"

using namespace std;

class Strassen{

public:
	// Atributos:
	int d;				//dimension
    Cuadrante coord;	//coordenadas de inicio y cierre
    int** cont;			//contenido de la matriz
    
	Strassen();	
	Strassen(int d);
	Strassen(int d, int n);
	virtual ~Strassen();
	
	int** obtdim(int a, char** entrada);
	int ddn(int** dms);
	int** contx(int n);
	int** contCero();
	void modContCero();
    void sobreCont( int** cA, Cuadrante t, Cuadrante a);
    void printCont();
    void mulNormal(Strassen A, Strassen B);
    void casobase(Strassen A, Strassen B, Cuadrante a, Cuadrante b);
    void mulCuad(Strassen A, Strassen B, Cuadrante a, Cuadrante b);
    void cuadx(Strassen A, Strassen B, Cuadrante a, Cuadrante b, int c);
    void mulSt(Strassen A, Strassen B);
	void deleteRows(int fi, int fc);
	void operator+=(Strassen C);
};
#endif /* STRASSEN_H */
