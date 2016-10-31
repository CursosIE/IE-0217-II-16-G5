#include "Strassen.h"
#include "Cuadrante.h"
#include "time.h"

/// @mainpage Algoritmo de Strassen
/// @author Dunia Barahona <s4si@hotmail.com>
/// @author Emmanuel Bustos 
/// @date 21 de octubre de 2016
/// @version 1.0
/// @par Descripción
/// Implementación del algoritmo de Strassen para multiplicación de matrices en C++, mediante la clase @link Cuadrante @endlink y la clase @link Strassen @endlink.

int main(int argc, char** argv) {
 
    int option= atoi(argv[3]);
    
    if (option==1)	//multiplicación normal imprimiendo matrices y resultado
	{
		Strassen* ini = new Strassen();	//inicializar
		int** dim;
		dim= ini->obtdim(3, argv);	//obtener dimensiones matrices
		
		if (dim[0][1] != dim[1][0])
		{
			cout<<endl<<"ERROR: "<<endl;
			cout<<"El número de filas de la matriz A debe ser igual al número de columnas de la matriz B"<<endl<<endl;
			delete[] dim[0];
			delete[] dim[1];
			delete[] dim;
			delete ini;
		}
		else
		{
			int d=ini->ddn(dim);	//dimension correcta
			Strassen A= Strassen(dim[0][0], dim[0][1], d, 3);
			cout<<endl<<"Matriz A:"<<endl;
			A.printContN();
	
			Strassen B= Strassen(dim[1][0], dim[1][1], d, 3);
			cout<<endl<<"Matriz B:"<<endl;
			B.printContN();
		
			Strassen C= Strassen(dim[0][0], dim[1][1]);

			delete[] dim[0];
			delete[] dim[1];
			delete[] dim;
			
			cout<<endl<<"Resultado Convencional:"<<endl;
			
			clock_t start=clock();
			C.mulNormal(A,B);
			clock_t end=clock();
			
			C.printContN();
			cout<<endl<<"LISTO"<<endl;
			cout<<"Tiempo: "<< (double)(end-start)/CLOCKS_PER_SEC<<"s"<<endl<<endl;
			cout<<endl;
			
			delete ini;
			
			A.eraseN();
			B.eraseN();
			for (int i = 0; i < C.f ; i++)
			{
				delete[] C.cont[i];
			}	
		}
	}
	else if (option==2)	//multiplicación Strassen imprimiendo matrices y resultado
	{
		Strassen* ini = new Strassen();	//inicializar
		int** dim;
		dim= ini->obtdim(3, argv);	//obtener dimensiones matrices
		int d=ini->ddn(dim);	//dimension correcta
		
		Strassen A= Strassen(dim[0][0], dim[0][1], d, 3);
		Strassen B= Strassen(dim[1][0], dim[1][1], d, 3);
		
		delete[] dim[0];
		delete[] dim[1];
		delete[] dim;
		
		A.fill();
		cout<<endl<<"Matriz A:"<<endl;
		A.printCont();
		B.fill();
		cout<<endl<<"Matriz B:"<<endl;
		B.printCont();
        
        cout<<endl<<"Resultado Strassen:"<<endl;
        clock_t start=clock();
		ini->mulSt(A, B);
        clock_t end=clock();

		A.printCont();
		cout<<endl<<"LISTO"<<endl;
		cout<<"Tiempo: "<< (double)(end-start)/CLOCKS_PER_SEC<<"s"<<endl<<endl;
		cout<<endl;
		
		delete ini;
		A.erase();
		B.erase();
	}
	else if (option==3)	//comparar resultado multiplicación convencional y Strassen
	{
		Strassen* ini = new Strassen();	//inicializar
		int** dim;
		dim= ini->obtdim(3, argv);	//obtener dimensiones matrices
		
		if (dim[0][1] != dim[1][0])
		{
			cout<<endl<<"ERROR: "<<endl;
			cout<<"El número de filas de la matriz A debe ser igual al número de columnas de la matriz B"<<endl<<endl;
			delete[] dim[0];
			delete[] dim[1];
			delete[] dim;
			delete ini;
		}
		else
		{
			int d=ini->ddn(dim);	//dimension correcta
			Strassen A= Strassen(dim[0][0], dim[0][1], d, 3);
			Strassen B= Strassen(dim[1][0], dim[1][1], d, 3);
			
			Strassen C= Strassen(dim[0][0], dim[1][1]);

			delete[] dim[0];
			delete[] dim[1];
			delete[] dim;
			
			cout<<endl<<"Multiplicación convencional:"<<endl;
			clock_t startN=clock();
			C.mulNormal(A,B);
			clock_t endN=clock();
			C.printContN();
			cout<<endl<<"LISTO"<<endl;
			cout<<"Tiempo: "<< (double)(endN-startN)/CLOCKS_PER_SEC<<"s"<<endl<<endl;
			
			for (int i = 0; i < C.f ; i++)
			{
				delete[] C.cont[i];
			}
			
			A.fill();
			B.fill();
			cout<<endl<<"Multiplicación Strassen:"<<endl;
			
			clock_t start=clock();
			ini->mulSt(A, B);
			clock_t end=clock();
			
			A.printCont();
			cout<<endl<<"LISTO"<<endl;
			cout<<"Tiempo: "<< (double)(end-start)/CLOCKS_PER_SEC<<"s"<<endl<<endl;
			cout<<endl;
			
			delete ini;
			
			A.eraseN();
			B.eraseN();
		}
	}
	else if (option==4)	//Para multiplicaciones Strassen con dimensión mayor a 16. No imprime resultado
	{
		Strassen* ini = new Strassen();	//inicializar
		int** dim;
		dim= ini->obtdim(3, argv);	//obtener dimensiones matrices
		int d=ini->ddn(dim);	//dimension correcta
		
		Strassen A= Strassen(dim[0][0], dim[0][1], d, 3);
		Strassen B= Strassen(dim[1][0], dim[1][1], d, 3);
	
		delete[] dim[0];
		delete[] dim[1];
		delete[] dim;
		
		A.fill();
		B.fill();
		
		cout<<endl<<"Multiplicación Strassen:"<<endl;
		cout<<d<<" x "<<d<<endl;
		clock_t start=clock();	
		ini->mulSt(A, B);
	    clock_t end=clock();
		cout<<endl<<"LISTO"<<endl;
		cout<<"Tiempo: "<< (double)(end-start)/CLOCKS_PER_SEC<<"s"<<endl<<endl;
		
		A.eraseN();
	}
	
	return 0;
}
