//EmmaDu 
#include "Strassen.h"
#include "Cuadrante.h"

//constructores y destructor
Strassen::Strassen() {
}
///Constructor de matriz con contenido de números aleatorios de 0 a n
Strassen::Strassen(int f, int c, int d, int n) {
	this->f= f;
	this->c= c;
	this->d= d;
	this->coord= Cuadrante(d);
	int** cont= contx(f, c, n); // contenido numeros aleatorios
	this->cont= cont;
}
///Constructor de matriz con contenido de ceros
Strassen::Strassen(int f, int c) {
	this->f= f;
	this->c= c;
	this->cont= contnull(f, c);
}
///Constructor de matriz cuadrada con dimensión potencia de dos y contenido de ceros
Strassen::Strassen(int d) {
	this->d= d;
	this->coord= Cuadrante(d);
	int** cont= contnull(d); // contenido numeros aleatorios
	this->cont= cont;
}
///Destructor
Strassen::~Strassen() {
}

int** Strassen::obtdim(int a, char** entrada) {
	///@brief Método que pertenece a la clase Strassen y que devuelve un puntero de ints 
	///@param entrada Dimensiones desde la terminal
    ///@return Arreglo con las dimensiones de las matrices
	string sp, st;	//string principal y string temporal
	char* at;		//arreglo temporal
	int k=0, j=0, intt=0, n=0;
    int** d= new int*[2];
    d[0]= new int[2];	//dimensiones de matriz A
	d[1]= new int[2];	//dimensiones de matriz B
	for (int i = 1; i < a; i++)
	{
		sp= entrada[i];
		while (sp[k]!='\0')	//recorre string principal
		{
			if (sp[k]!=44)	//si caracter es distinto de ','
			{
				st += sp[k];	//concatena a string temporal
			}
			else 
			{
				at= new char;		//reserva memoria para arreglo temporal
				while (st[j]!='\0')	//recorre string temporal
				{
					at[j]= st[j];
					j++;
				}
				intt= atoi(at);	//convierte arreglo temporal a int temporal
				delete[] at;	//libera memoria
				st.clear();		//limpia string temporal
				j=0;
				d[i-1][n]= intt;	//dimensiones de las matrices
				n++;
			}
			k++;
		}
		at= new char;		//reserva memoria para arreglo temporal
		while (st[j]!='\0')	//recorre string temporal
		{
			at[j]= st[j];
			j++;
		}
        intt= atoi(at);		//convierte arreglo temporal a int temporal
        delete[] at;		//libera memoria
		d[i-1][n]= intt;	//dimensiones de las matrices
		st.clear();
		j=0;
		n=0;
		k=0;
	}
	return d;
	delete[] d;
}

int Strassen::ddn(int** dms) {	
    ///@brief Determinar cual es la dimension potencia de dos adecuada  
	///@param dms Dimensiones de las matrices
    ///@return Dimensión correcta
	int k=0, mg=0, n=0, d=0;	//más grande
	bool fin= false;
	for (int i = 0; i < 2; i++)
	{	
		for (int j = 0; j < 2; j++)
		{
			if (dms[i][j]>mg)
			{
				mg= dms[i][j];
			}
		}
	}
	while (!fin)
	{
		if (pow(2, n)==mg)
		{
            d=pow(2, n);
			fin= true;
		}
		else if (pow(2, n)<mg && mg<=pow(2, n+1))
		{
			d=pow(2, n+1);
			fin= true;
		}
		else
		{
			n++;
		}	
	}
	return d;
}
int** Strassen::contx(int f, int c, int n) {
	///@brief Genera contenido de una matriz 
	///@param f cantidad de filas
	///@param c cantidad de columnas
	///@param n rango de números aleatorios
    ///@return Puntero int** con números aleatorios de 0 a n

	int** cont= new int*[f];
	for(int i=0; i< f; i++){  //filas de a
		cont[i]= new int[c];
		
		for(int j=0; j< c; j++){	//columnas de b
			cont[i][j]= rand() % n+1;
		}
	}
	return cont;
	for (int i = 0; i < f; i++)
	{
		delete[] cont[i];
	}
	delete[] cont;
}
int** Strassen::contnull(int f, int c) {
    ///@brief Genera contenido de una matriz 
	///@param f cantidad de filas
	///@param c cantidad de columnas
    ///@return Puntero int** con ceros
	int** cont= new int*[f];
	for(int i=0; i< f; i++){  //filas de a
		
		cont[i]= new int[c];
		for (int j = 0; j < c; j++)
		{
			cont[i][j]= 0;
		}
	}
	return cont;
	for (int i = 0; i < f; i++)
	{
		delete[] cont[i];
	}
	delete[] cont;
}
int** Strassen::contnull(int d) {
    ///@brief Genera contenido de una matriz 
	///@param d dimensión de la matriz
    ///@return Puntero int** con ceros
	int** cont= new int*[d];
	for(int i=0; i< d; i++){  //filas de a
		cont[i]= new int[d];
		
		for(int j=0; j< d; j++){	//columnas de b
			cont[i][j]= 0;
		}
	}
	return cont;
	for (int i = 0; i < f; i++)
	{
		delete[] cont[i];
	}
	delete[] cont;
}
void Strassen::fill() {
	///@brief Llena las filas y columnas faltantes con ceros 
	int fi=0, ci=0; 
	int** CS= new int*[this->d];
	
	for(int i=0; i< this->d; i++){  //filas de a
		CS[i]= new int[this->d];
		
		for(int j=0; j< this->d; j++){	//columnas de b
			if (fi<this->f && ci<this->c)
			{
				CS[i][j]= this->cont[fi][ci];
				ci++;
			}
			else
			{
				CS[i][j]= 0;
			}
		}
		fi++;
		ci= 0;
	}
	for (int i = 0; i < f; i++)
	{
		delete[] this->cont[i];
	}
	delete[] this->cont;
	this->cont= CS;
}
void Strassen::modContCero() {
	///@brief Modifica el contenido de la matriz sustituyendolo por ceros
	for(int i=0; i< this->d; i++){  //filas de a
		for(int j=0; j< this->d; j++){	//columnas de b
			this->cont[i][j]= 0;
		}
	}
}
void Strassen::sobreCont( int** cA, Cuadrante t, Cuadrante a) {
	///@brief Sobreescribe el contenido de la matriz en un cuadrante en especifico
	///
	///Reemplaza el contenido de this por el de A
	///@param cA corresponde al contenido de A
	///@param t corresponde al cuadrante de this 
	///@param a corresponde al cuadrante de A 
	//cuadrantes a y t deben tener la misma dimensión
    int n= a.ci[0];	//fila de inicio de A 
    int m= a.ci[1];	//columna de inicio de A
	for(int i=t.ci[0]; i<= t.cc[0]; i++){  
		for(int j=t.ci[1]; j<= t.cc[1]; j++){	
			this->cont[i][j]= cA[n][m];
			m++;
		}
		m= a.ci[1];
		n++;
	}
}
void Strassen::printContN() {
	///@brief Imprime el contenido de una matriz convencional
	for(int i=0; i< this->f; i++){  
		for(int j=0; j< this->c; j++){	
			cout<<this->cont[i][j]<<"\t";
		}
		cout<<endl;
	}
}
void Strassen::printCont() {
	///@brief Imprime el contenido de una matriz tipo Strassen
	for(int i=0; i< this->d; i++){  
		for(int j=0; j< this->d; j++){	
			cout<<this->cont[i][j]<<"\t";
		}
		cout<<endl;
	}
}

void Strassen::mulNormal(Strassen A, Strassen B) {
    ///@brief Método convencional de multiplicación de matrices
    ///
    ///Se multiplica la matriz A por la matriz B, el resultado se guarda en this
    ///@param A matriz tipo Strassen 
    ///@param B matriz tipo Strassen 
	for (int i = 0; i < A.f; i++)	//desde coordenada de inicio de A hasta coordenada de cierre de A. Filas
	{
		for (int j = 0; j < B.c; j++)	//columnas
		{ 
			for (int k = 0; k < A.c; k++)
			{
				this->cont[i][j]+= A.cont[i][k]*B.cont[k][j];
			}			
		}	
	}
}
void Strassen::casobase(Strassen A, Strassen B, Cuadrante a, Cuadrante b) {
	///@brief Caso base del algoritmo de Strassen
	///
	///Dimensión debe ser 2x2. Se multiplica A por B y se guarda en this
	int p1= (A.cont[a.ci[0]][a.ci[1]] + A.cont[a.cc[0]][a.cc[1]])*(B.cont[b.ci[0]][b.ci[1]] + B.cont[b.cc[0]][b.cc[1]]);
	int p2= (A.cont[a.cc[0]][a.ci[1]] + A.cont[a.cc[0]][a.cc[1]])*(B.cont[b.ci[0]][b.ci[1]]);
	int p3= (A.cont[a.ci[0]][a.ci[1]])*(B.cont[b.ci[0]][b.cc[1]] - B.cont[b.cc[0]][b.cc[1]]);
	int p4= (A.cont[a.cc[0]][a.cc[1]])*(B.cont[b.cc[0]][b.ci[1]] - B.cont[b.ci[0]][b.ci[1]]);
	int p5= (A.cont[a.ci[0]][a.ci[1]] + A.cont[a.ci[0]][a.cc[1]])*(B.cont[b.cc[0]][b.cc[1]]);
	int p6= (A.cont[a.cc[0]][a.ci[1]] - A.cont[a.ci[0]][a.ci[1]])*(B.cont[b.ci[0]][b.ci[1]] + B.cont[b.ci[0]][b.cc[1]]);
	int p7= (A.cont[a.ci[0]][a.cc[1]] - A.cont[a.cc[0]][a.cc[1]])*(B.cont[b.cc[0]][b.ci[1]] + B.cont[b.cc[0]][b.cc[1]]);
    
	this->cont[a.ci[0]][b.ci[1]]+= p1 + p4 - p5 + p7;
	this->cont[a.ci[0]][b.cc[1]]+= p3 + p5;
	this->cont[a.cc[0]][b.ci[1]]+= p2 + p4;
	this->cont[a.cc[0]][b.cc[1]]+= p1 - p2 + p3 + p6;
}
void Strassen::mulCuad(Strassen A, Strassen B, Cuadrante a, Cuadrante b) {
	///@brief Caso recursivo donde se multiplican los cuadrantes especificados de cada matriz
	///
	///El resultado se guarda en this	
	int d= a.d;
	if (d<=2)
	{
		this->casobase(A, B, a, b);
	}
	else
	{
		Cuadrante* CA= new Cuadrante[4];	//cuadrantes de A
		Cuadrante* CB= new Cuadrante[4];	//cuadrantes de B
		CA= a.dividir();
		CB= b.dividir();
	
		this->mulCuad(A, B, CA[0], CB[0]);
		this->mulCuad(A, B, CA[1], CB[2]);
		this->mulCuad(A, B, CA[0], CB[1]);
		this->mulCuad(A, B, CA[1], CB[3]);
		this->mulCuad(A, B, CA[2], CB[0]);
		this->mulCuad(A, B, CA[3], CB[2]);
		this->mulCuad(A, B, CA[2], CB[1]);
		this->mulCuad(A, B, CA[3], CB[3]);

		for (int i = 0; i < 4; i++)
		{
			delete[] CA[i].ci;
			delete[] CA[i].cc;
			delete[] CB[i].ci;
			delete[] CB[i].cc;
		}
		delete[] CA;
		delete[] CB;
	}
}
void Strassen::cuadx(Strassen A, Strassen B, Cuadrante a, Cuadrante b, int c) {
	///@brief Obtiene un cuadrante en especifico de la multiplicación A por B y lo guarda en this
	///param c cuadrante que se desea obtener
	int d= a.d;
	if (d<=2)
	{
		this->casobase(A, B, a, b);
	}
	else
	{
		Cuadrante* CA= new Cuadrante[4];	//cuadrantes de A
		Cuadrante* CB= new Cuadrante[4];	//cuadrantes de B
		CA= a.dividir();
		CB= b.dividir();

	    if (c==1) //devuelve primer cuadrante
		{
			this->mulCuad(A, B, CA[0], CB[0]);
			this->mulCuad(A, B, CA[1], CB[2]);
		}
	    else if (c==2)	//devuelve segundo cuadrante
		{
			Strassen AT= Strassen(this->d);
			Strassen BT= Strassen(this->d);
			
			AT.sobreCont(A.cont, AT.coord, CA[0]);
			BT.sobreCont(B.cont, AT.coord, CB[1]);
			this->mulCuad(AT, BT, AT.coord, BT.coord);
			
			AT.sobreCont(A.cont, AT.coord, CA[1]);
			BT.sobreCont(B.cont, AT.coord, CB[3]);
			this->mulCuad(AT, BT, AT.coord, BT.coord);
			
			AT.erase();
			BT.erase();
		}
	    else if (c==3)	//devuelve tercer cuadrante
		{
			Strassen AT= Strassen(this->d);
			Strassen BT= Strassen(this->d);
			
			AT.sobreCont(A.cont, AT.coord, CA[2]);
			BT.sobreCont(B.cont, AT.coord, CB[0]);
			this->mulCuad(AT, BT, AT.coord, BT.coord);
			
			AT.sobreCont(A.cont, AT.coord, CA[3]);
			BT.sobreCont(B.cont, AT.coord, CB[2]);
			this->mulCuad(AT, BT, AT.coord, BT.coord);
			
			AT.erase();
			BT.erase();
		}
	    else if (c==4)	//devuelve cuarto cuadrante
		{
			Strassen AT= Strassen(this->d);
			Strassen BT= Strassen(this->d);
			
			AT.sobreCont(A.cont, AT.coord, CA[2]);
			BT.sobreCont(B.cont, AT.coord, CB[1]);
			this->mulCuad(AT, BT, AT.coord, BT.coord);
			
			AT.sobreCont(A.cont, AT.coord, CA[3]);
			BT.sobreCont(B.cont, AT.coord, CB[3]);
			this->mulCuad(AT, BT, AT.coord, BT.coord);
			
			AT.erase();
			BT.erase();
			B.erase();	//Libera el espacio de la matriz B
		}
		
		for (int i = 0; i < 4; i++)
		{
			delete[] CA[i].ci;
			delete[] CA[i].cc;
			delete[] CB[i].ci;
			delete[] CB[i].cc;
		}
		delete[] CA;
		delete[] CB;
	}
}
void Strassen::mulSt(Strassen A, Strassen B) {
	///@brief Multiplica A por B y sobreescribe a la matriz A	
	int d= A.d;
	if (d<=2)
	{
		Strassen C= Strassen(d);	//temporal
		C.casobase(A, B, A.coord, B.coord);
		A.sobreCont(C.cont, A.coord, C.coord);
		
		C.erase();
	}
	else
	{
		Strassen t= Strassen(d/2);	//temporal
		Strassen tt= Strassen(d/2);	//temporal
		
		Cuadrante* CA= new Cuadrante[4];	//cuadrantes de A
		CA= A.coord.dividir();
		
		t.cuadx(A, B, A.coord, B.coord, 1);		//Obtener el cuadrante 1 y guardarlo en t  
		tt.sobreCont(t.cont, tt.coord, t.coord);	//Guardar en tt el cuadrante 1
	   
		t.modContCero();	//Limpiar t
		
		t.cuadx(A, B, A.coord, B.coord, 2);	//Obtener el cuadrante 2 y guardarlo en t
		
		A.sobreCont(tt.cont, CA[0], tt.coord);	//Cuadrante 1
		A.sobreCont(t.cont, CA[1], t.coord);   //Cuadrante 2
		
		t.modContCero();	//Limpiar t
		
		t.cuadx(A, B, A.coord, B.coord, 3);	//Obtener el cuadrante 3 y guardarlo en t
		tt.sobreCont(t.cont, tt.coord, t.coord);	//Guardar en tt el cuadrante 3
		
		t.modContCero();	//Limpiar t
		
		t.cuadx(A, B, A.coord, B.coord, 4);	//Obtener el cuadrante 4 y guardarlo en t
	   
		A.sobreCont(tt.cont, CA[2], tt.coord);	//Sobreescribe Cuadrante 3 en A
		A.sobreCont(t.cont, CA[3], t.coord);	//Sobreescribe Cuadrante 4 en A
		
		for (int i = 0; i < 4; i++)
		{
			delete[] CA[i].ci;
			delete[] CA[i].cc;
		}
		delete[] CA;
		t.erase();
		tt.erase();
    }
}
void Strassen::eraseN() {
	///@brief Libera el espacio correspondiente al contenido y el cuadrante de la matriz
	for (int i = 0; i < this->f ; i++)
	{
		delete[] this->cont[i];
	}
	delete[] this->cont;
	delete[] this->coord.ci;
	delete[] this->coord.cc;
}
void Strassen::erase() {
    ///@brief Libera el espacio correspondiente al contenido y el cuadrante de una matriz tipo Strassen
	for (int i = 0; i <this->d ; i++)
	{
		delete[] this->cont[i];
	}
	delete[] this->cont;
	delete[] this->coord.ci;
	delete[] this->coord.cc;
}
