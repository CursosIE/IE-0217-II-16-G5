// Dunia Barahona. B40806
#include "Figura.h"
#include "Circulo.h"
#include "Cuadrado.h"
#include "Triangulo.h"

/// @mainpage Herencia, poliformísmo y sobrecargas en C++
/// @author Dunia Barahona <s4si@hotmail.com>
/// @date 11 de setiembre de 2016
/// @version 1.0
/// @par Descripción
/// Serie de clases que modelan figuras geométricas. La clase base se llama Figura y las derivadas son Circulo, Cuadrado
/// y Triangulo; cada una tiene su respectivo archivo de encabezados. Todas estas clases estan implementadas en el @link main @endlink .

int main(int argc, char** argv) {
	/// Crea objeto @b F de tipo @link Figura @endlink y usa el constructor para inicializarlo.
	/// @code
	/// Figura F;
	/// F = Figura("Cualquiera", "rojo");
	/// @endcode
	///
	/// Crea objeto @b cc de tipo @link Circulo @endlink y usa el constructor para inicializarlo.
	/// @code Circulo cc= Circulo("Círculo", "azul", 4.2); @endcode
	/// 
	/// Crea objeto @b cd de tipo @link Cuadrado @endlink y usa el constructor para inicializarlo.
	/// @code Cuadrado cd= Cuadrado("Cuadrado", "verde", 13.5); @endcode
	///
	/// Crea objeto @b t de tipo @link Triangulo @endlink y usa el constructor para inicializarlo.
	/// @code Triangulo t= Triangulo("Triángulo", "amarillo", 11, 7.5, 11); @endcode

	Figura F;	// crea instancia: objeto de tipo 'Figura' llamado 'F' 
	F = Figura("cualquiera", "rojo");	// constructor
    ~F;
	!F;
	Circulo cc= Circulo("círculo", "azul", 4.2);	// crea objeto de tipo Circulo llamado 'cc' y lo inicializa
    ~cc;
    !cc;
	Cuadrado cd= Cuadrado("cuadrado", "verde", 13.5);
    ~cd;
    !cd;
	Triangulo t= Triangulo("triángulo", "amarillo", 11, 7.5, 11);
	~t;
	!t;

    return 0;
}
