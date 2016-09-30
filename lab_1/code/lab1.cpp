#include <iostream>
#include "string"

using namespace std;


/// @file
/// @author  Dunia Barahona <s4si@hotmail.com>
/// @version 1.0
/// @brief Memoria dinámica, arreglos, funciones y sintaxis en general de C++.
/// @section DESCRIPCIÓN
/// Programa que genera animoácidos a partir de los codones de un código genético (ARN) cualquiera, mediante la tabla de conversión ARN-aminoácidos.
///
/// Imprime los aminoácidos que se traducen a partir de la serie de bases nitrogenadas (A, G, C, U) recibida de la línea de comandos.

// Función 1
int cont (char **bss)	 
{
	/// @brief Obtiene el tamaño del código genético (ARN) ingresado desde la línea de comandos.
	/// @param **bss es un puntero doble de char que contiene la dirección de memoria del ARN ingresado.
	/// @return Variable de tipo entero. Cantidad de caracteres (bases) ingresados.

	int n = 0;
	while (bss[1][n] != '\0')
	{
		n++;
	}
	return n;
}
// Función 2
char amino(int b1, int b2, int b3)	
{
	/// @brief Determina cual aminoácido corresponde al codón de ARN ingresado según la tabla de conversión ARN a aminoácido.
	/// @param b1 es un entero que representa la primer base del codón.
	/// @param b2 es un entero que representa la segunda base del codón.
	/// @param b3 es un entero que representa la tercera base del codón.
	/// @return Variable de tipo char. Aminoácido correspondiente al codón de bases ingresado.
	
	char **comb[4];				// crea un puntero que señala la dirección de otro puntero de cuatro
	comb[0] = new char*[4];	
	comb[1] = new char*[4];	
	comb[2] = new char*[4];		// en esa dirección crea puntero que señala a otro puntero de 4
	comb[3] = new char*[4];
		
	comb[0][0] = new char[4];	// en esa posicion de memoria esta el puntero que señala la dirección donde
	comb[0][1] = new char[4];	// esta el contenido de 4. (señala a un arreglo de 4 chars)
	comb[0][2] = new char[4];
	comb[0][3] = new char[4];
		
	comb[1][0] = new char[4];	
	comb[1][1] = new char[4];
	comb[1][2] = new char[4];
	comb[1][3] = new char[4];
		
	comb[2][0] = new char[4];
	comb[2][1] = new char[4];
	comb[2][2] = new char[4];
	comb[2][3] = new char[4];
		
	comb[3][0] = new char[4];
	comb[3][1] = new char[4];
	comb[3][2] = new char[4];
	comb[3][3] = new char[4];
	//
	comb[0][0][0] = 'K';
	comb[0][0][1] = 'N';
	comb[0][0][2] = 'K';
	comb[0][0][3] = 'N';
	 
	comb[0][1][0] = 'T';
	comb[0][1][1] = 'T';
	comb[0][1][2] = 'T';
	comb[0][1][3] = 'T';
	 
	comb[0][2][0] = 'R';
	comb[0][2][1] = 'S';
	comb[0][2][2] = 'R';
	comb[0][2][3] = 'S';
	 
	comb[0][3][0] = 'I';
	comb[0][3][1] = 'I';
	comb[0][3][2] = 'M';
	comb[0][3][3] = 'I';
	 
	comb[1][0][0] = 'Q';
	comb[1][0][1] = 'H';
	comb[1][0][2] = 'Q';
	comb[1][0][3] = 'H';
	 
	comb[1][1][0] = 'P';
	comb[1][1][1] = 'P';
	comb[1][1][2] = 'P';
	comb[1][1][3] = 'P';
	 
	comb[1][2][0] = 'R';
	comb[1][2][1] = 'R';
	comb[1][2][2] = 'R';
	comb[1][2][3] = 'R';
	 
	comb[1][3][0] = 'L';
	comb[1][3][1] = 'L';
	comb[1][3][2] = 'L';
	comb[1][3][3] = 'L';
	 
	comb[2][0][0] = 'E';
	comb[2][0][1] = 'D';
	comb[2][0][2] = 'E';
	comb[2][0][3] = 'D';
	 
	comb[2][1][0] = 'A';
	comb[2][1][1] = 'A';
	comb[2][1][2] = 'A';
	comb[2][1][3] = 'A';
	 
	comb[2][2][0] = 'G';
	comb[2][2][1] = 'G';
	comb[2][2][2] = 'G';
	comb[2][2][3] = 'G';
	 
	comb[2][3][0] = 'V';
	comb[2][3][1] = 'V';
	comb[2][3][2] = 'V';
	comb[2][3][3] = 'V';
	 
	comb[3][0][0] = '|';
	comb[3][0][1] = 'Y';
	comb[3][0][2] = '|';
	comb[3][0][3] = 'Y';
	 
	comb[3][1][0] = 'S';
	comb[3][1][1] = 'S';
	comb[3][1][2] = 'S';
	comb[3][1][3] = 'S';
	 
	comb[3][2][0] = '|';
	comb[3][2][1] = 'C';
	comb[3][2][2] = 'W';
	comb[3][2][3] = 'C';
	 
	comb[3][3][0] = 'L';
	comb[3][3][1] = 'F';
	comb[3][3][2] = 'L';
	comb[3][3][3] = 'F';
	
	char pt = comb[b1][b2][b3];
	
	delete[] *(comb);
	//delete *(comb);
	
	return pt;
}
// Función 3
char triplete (char *bss)		
{
	/// @brief Traduce las bases del codón recibido según lo siguiente:
	/// - A = 0
	/// - C = 1
	/// - G = 2
	/// - U = 3
	
	/// Guarda los valores en un puntero de enteros temporal @b temp y lo usa como parámetro en la función @link amino @endlink la cual determina el aminoácido resultante.
	
	/// @code char AA = amino(temp[0], temp[1], temp[2]); @endcode
	/// @param *bss puntero de tipo char, donde cada char corresponde a un base nitrogenada.
	/// @return Variable de tipo char. Aminoácido correspondiente al codón ingresado. 
	
	int* temp= new int[3];		// arreglo temporal
		
	for (int i = 0; i < 3; i++)
	{
		switch (*(bss+i))
		{
			case 'A':
				*(temp+i) = 0;
				break;
			case 'C':
				*(temp+i) = 1;
				break;
			case 'G':
				*(temp+i) = 2;
				break;
			case 'U':
				*(temp+i) = 3;
				break;
			default:
				*(temp+i) = -1;
				break;
		}
	}
	// temp quedó lleno
	
	char AA = amino(temp[0], temp[1], temp[2]);		//llama a la función amino
	
	delete[] temp;
	return AA;
}
//Función 4
int insp(char **bss)
{
	/// @brief Verifica si el ARN ingresado cumple con las siguientes condiciones:
	/// - La cantidad de bases que lo componen es multiplo de 3.
	/// - Está compuesto únicamente por los caracteres que corresponden a bases nitrogenadas (A, C, G, U).
	/// 
	/// @param **bss es un puntero doble de char. Es el ARN ingresado desde la línea de comandos.
	/// @return Variable de tipo entero. Si retorna cero el ARN ingresado cumple las condiciones.
	
	int swch= 0;
	int error = 0;
	int n = cont(bss);
	
	int resto = n % 3;
	if (resto!= 0)
	{
		swch= 1;
		cout << "\n La serie ingresada no es multiplo de 3" << endl;
	}
	bss++;
	for (int i = 0; i < n; i++)
	{
		char tp = *(*bss+i);
		if (tp!='A' && tp!='C' && tp!='G' && tp!='U')
		{
			error= 1;
			swch= 1;
		}
	}
	if (error != 0)
	{
		cout << "\n La serie ingresada contiene caracteres que no corresponden a las bases nitrogenadas (A, G, C, U)" << endl;
	}
	return swch;
}
//Función 5
char* traducirARNaAA(char **arn)
{
	/// Llama a la función @link insp @endlink para asegurarse que el ARN ingresado es válido.
	/// @code int swch= insp(arn); @endcode
	/// Luego recorre el código génético ingresado para traducir cada codón por medio de la función @link triplete @endlink .
	/// @code
	/// char amac;
	/// amac= triplete(temp);
	/// @endcode
	/// @param **arn es un puntero doble de char con el ARN.
	/// @return Nuevo arreglo de char con los animoacidos que conforman la proteína resultante.
	
	int n = cont(arn);
	char* pt = new char[n/3];
	int swch= insp(arn);
	if (swch==0)
	{
		char* temp = new char[3];
		char amac;
		
		int m= 0;
		
		
		for (int i = 0; i < n; i++)
		{
			*temp = *(*(arn+1)+i);
			*(temp+1) = *(*(arn+1)+i+1);	// Es lo mismo que: temp[1]= bss[1][i+1];
			*(temp+2) = *(*(arn+1)+i+2);
				
			amac = triplete(temp);
			*(pt+m)= amac;
			m++;
			//cout<< *(pt+m) << endl;
			i+=2;
		}
		delete[] temp;
	}
	return pt;
	delete[] pt;
}
//Función 6
int imprimirArregloDeChar(char* a, int n)
{
	/// @brief Imprime @b n caracteres de @b a.
	/// @param *a es un puntero de char.
	/// @param n es un entero que representa la cantidad de chars del arreglo recibido.
	
	for (int i = 0; i < n; i++)
	{
		cout << *(a+i);
	}
	cout << endl;
	
	return 0;
}

int main(int argc, char **argv) 
{
	/// @brief Esta es la función principal.
	/// @param argc es la cantidad de elementos que recibe.
	/// @param **argv son los valores recibidos.
	
	int n = cont(argv)/3;
	char* amac= traducirARNaAA(argv);
	imprimirArregloDeChar(amac, n);

	return 0;
}
