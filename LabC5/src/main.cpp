#include <iostream>
#include "string"
#include "Fila.h"
#include "Carta.h"
#include "Mazo.h"
#include "Jugador.h"
#include "Mesa.h"
#include "stdlib.h"   
#include <cstdlib>
#include <unistd.h>
using namespace std;
int main(int argc, char** argv) {
	Fila A= Fila(argv[1]);
	A.ord();
	cout<< A.T <<endl;
	Mesa Mesa1(1);
	Mesa Mesa2(2);
	Mesa Mesa3(3);
	while(A.filen!=0){
 	Mesa1.partida(A);
 	usleep(1000000); //Delay añadido para evitar errores con la semilla de función random
 	Mesa2.partida(A);
 	usleep(1000000);
 	Mesa3.partida(A);
 	usleep(1000000);
 	}
 	
 	while(Mesa1.espaciosdisp!=3){
 	Mesa1.partida(A);
 	usleep(1000000);
 	}
 	
 	while(Mesa2.espaciosdisp!=3){
 	Mesa2.partida(A);
 	usleep(1000000);
 	}
 	
 	while(Mesa3.espaciosdisp!=3){
 	Mesa3.partida(A);
 	usleep(1000000);
 	}
 	
 	if(Mesa1.espaciosdisp==3 && Mesa1.espaciosdisp==3 && Mesa1.espaciosdisp==3 && A.filen==0){
		cout<<"Casino vacío"<<endl;
		}
 	
	return 0;
	}
