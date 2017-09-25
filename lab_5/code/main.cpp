// Dunia Barahona

#include "Mesa.h"
#include "Portero.h"
#include "Casino.h"

/// @mainpage Lista y Colas en C++
/// @author Dunia Barahona <s4si@hotmail.com>
/// @date 1 de noviembre de 2016
/// @version 1.0
/// @par Descripción
/// Simulación del funcionamiento de un casino mediante las clases @link nodo @endlink, @link LCP @endlink, @link Mesa @endlink,
/// @link Portero @endlink y @link Casino @endlink.
/// Todas estas clases tiene su respectivo archivo de encabezados y estan implementadas en el @link main @endlink.

int main(int argc, char** argv) {

	Casino* casa= new Casino();
	
	cout<<endl<<"CASINO ABRE"<<endl;
	cout<<endl<<"Salas de espera: "<<endl;
	casa->P->ubicar(argv);	//Inicio: Ubicar clientes en salas de espera
	cout<<endl;
	
	casa->jugar();

    cout<<"CASINO CIERRA"<<endl<<endl;
  
	return 0;
}
