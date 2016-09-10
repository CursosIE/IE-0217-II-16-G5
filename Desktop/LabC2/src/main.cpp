#include <cstdlib>
#include <iostream>
#include <ctime>
#include "Figura.h"
#include "Triangulo.h"
#include "Circulo.h"
#include "Cuadrado.h"

using namespace std;

int main(int argc, char** argv) {
	Figura f("figurita", "blanco");
	Cuadrado c("Sir cuadrado", "negro", 1);
	Triangulo t("Sir triángulo", "amarillo", 4, 4, 4);
	Circulo cr("Sir circulo", "verde", 1);
	~c;	
	!c;
	~t;
	!t;
	~cr;
	!cr;
}
