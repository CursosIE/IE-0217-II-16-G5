//EmmaDu 
#include "Strassen.h"
#include "Cuadrante.h"

//constructores y destructor
Strassen::Strassen() {
}
//Constructor de matriz tipo Strassen con contenido de ceros, d es la dimensión
Strassen::Strassen(int d) {
	this->coord= Cuadrante(d);
	this->d= d;
	int** c= contCero(); 
	this->cont= c;
}
//Constructor de matriz tipo Strassen con contenido de números aleatorios de 0 a n
Strassen::Strassen(int d, int n) {
	this->coord= Cuadrante(d);
	this->d= d;
	int** c= contx(n); // contenido numeros aleatorios
	this->cont= c;
}
Strassen::~Strassen() {
}

//obtener dimensiones de las matrices
int** Strassen::obtdim(int a, char** entrada) {
	string sp, st;	//string principal y string temporal
	char* at;	//arreglo temporal
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
//determinar dimension adecuada 2^n. Devuelve el 2^n indicado
int Strassen::ddn(int** dms) {	//recibe dimensiones
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
//Devuelve un puntero int** con números aleatorios de 0 a n
int** Strassen::contx(int n) {
	int** c= new int*[this->d];
	for(int i=0; i< this->d; i++){  //filas de a
		c[i]= new int[this->d];
		
		for(int j=0; j< this->d; j++){	//columnas de b
			c[i][j]= rand() % n+1;
		}
	}
	return c;
	delete[] c;
}
//Devuelve un puntero int** con ceros
int** Strassen::contCero() {
	int** c= new int*[this->d];
	for(int i=0; i< this->d; i++){  //filas de a
		c[i]= new int[this->d];
		
		for(int j=0; j< this->d; j++){	//columnas de b
			c[i][j]= 0;
		}
	}
	return c;
	delete[] c;
}
//Modifica el contenido de la matriz. La llena con ceros
void Strassen::modContCero() {
	for(int i=0; i< this->d; i++){  //filas de a
		for(int j=0; j< this->d; j++){	//columnas de b
			this->cont[i][j]= 0;
		}
	}
}
//Modifica el contenido de la matriz. Sobreescribe contenido de un cuadrante en especifico
void Strassen::sobreCont( int** cA, Cuadrante t, Cuadrante a) {
	//sobreescribe el contenido de THIS. Reemplaza el contenido de this por el de A
	//int** cA corresponde al contenido de A
	//cuadrante a corresponde al cuadrante de A 
	//cuadrante t corresponde al cuadrante de this 
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
//Imprime el contenido de una matriz de tipo Strassen
void Strassen::printCont() {
	for(int i=0; i< this->d; i++){  
		for(int j=0; j< this->d; j++){	
			cout<<this->cont[i][j]<<"\t";
		}
		cout<<endl;
	}
}
//Mult normal. Recibe dos matrices tipo Strassen que se van a multiplicar: A*B= C. Cambios se escriben en C. C es this
void Strassen::mulNormal(Strassen A, Strassen B) {
	for (int i = 0; i < A.d; i++)	//desde coordenada de inicio de A hasta coordenada de cierre de A. Filas
	{
		for (int j = 0; j < A.d; j++)	//columnas
		{ 
			for (int k = 0; k < A.d; k++)
			{
				this->cont[i][j]+= A.cont[i][k]*B.cont[k][j];
			}			
		}	
	}
}
//Caso base. Debe ser 2x2. Multiplico A por B y lo guardo en this
void Strassen::casobase(Strassen A, Strassen B, Cuadrante a, Cuadrante b) {
	
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
//RECURSIVIDAD. Multiplicar cuadrantes. Cambios se guardan this
void Strassen::mulCuad(Strassen A, Strassen B, Cuadrante a, Cuadrante b) {
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
//Obtiene un cuadrante en especifico de la multiplicación de A por B y lo guarda en this
//Recibe cual cuadrante desea obtener
void Strassen::cuadx(Strassen A, Strassen B, Cuadrante a, Cuadrante b, int c) {
	
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
			
			delete[] AT.cont;
			delete[] AT.coord.ci;
			delete[] AT.coord.cc;
			delete[] BT.cont;
			delete[] BT.coord.ci;
			delete[] BT.coord.cc;
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
			
			delete[] AT.cont;
			delete[] AT.coord.ci;
			delete[] AT.coord.cc;
			delete[] BT.cont;
			delete[] BT.coord.ci;
			delete[] BT.coord.cc;
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
			
			delete B.cont;	//Libera el espacio de la matriz B
			delete[] AT.cont;
			delete[] AT.coord.ci;
			delete[] AT.coord.cc;
			delete[] BT.cont;
			delete[] BT.coord.ci;
			delete[] BT.coord.cc;
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
//Multiplica A por B y sobreescribe a A
void Strassen::mulSt(Strassen A, Strassen B) {	
	int d= A.d;
	if (d<=2)
	{
		Strassen C= Strassen(d);	//temporal
		C.casobase(A, B, A.coord, B.coord);
		A.sobreCont(C.cont, A.coord, C.coord);
		delete[] C.cont;
		delete[] C.coord.ci;
		delete[] C.coord.cc;
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
		delete[] t.cont;
		delete[] t.coord.ci;
		delete[] t.coord.cc;
		delete[] tt.cont;
		delete[] tt.coord.ci;
		delete[] tt.coord.cc;
    }
}

//libera espacio de filas en especifico
//recibe la primera fila que se desea liberar y la última
void Strassen::deleteRows(int fi, int fc) {
	for (int i = fi; i <=fc ; i++)
	{
		delete[] this->cont[i];
	}
}

void Strassen::operator+=(Strassen C) {
	//suma de matrices no convencional
	Cuadrante coordA= this->coord;
	Cuadrante coordC= C.coord;
	for (int i = coordA.ci[0]; i <= coordA.cc[0]; i++)
	{
		for (int j = coordA.ci[1]; j <= coordA.cc[1]; j++)
		{ 		
			this->cont[i][j]+= C.cont[i][j];		
		}	
	}
}
