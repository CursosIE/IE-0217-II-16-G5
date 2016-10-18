#include "Strassen.h"
#include "Cuadrante.h"

int main(int argc, char** argv) {

	Strassen* ini = new Strassen();	//inicializar
	
	int** dim;
	dim= ini->obtdim(argc, argv);	//obtener dimensiones matrices

    int d=ini->ddn(dim);	//dimension correcta
	delete[] dim;
	
	
	Strassen A= Strassen(d, 3);
	//cout<<"Matriz A"<<endl;
	//A.printCont();
	Strassen B= Strassen(d, 2);
    //cout<<endl<<"Matriz B"<<endl;
	//B.printCont();
    
    //multiplicación convencional
	Strassen C= Strassen(d);	//Crea matriz resultante C
	C.mulNormal(A,B);
	cout<<endl;
	cout<<"Multiplicación convencional"<<endl;
	C.printCont();	
	cout<<endl<<"Done"<<endl;
	cout<<endl;
	
	////multiplicación Strassen
	cout<<"//////////"<<endl;
	cout<<"Multiplicación Strassen"<<endl;
	ini->mulSt(A, B);
    A.printCont();
    cout<<endl<<"Done"<<endl<<endl;
    /////////////////////////
    
	delete ini;

	return 0;
}
