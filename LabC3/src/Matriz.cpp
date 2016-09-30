#include "Matriz.h"
#include <cstdlib>
///Constructor simple.
Matriz::Matriz() 
{	
	
}
///Constructor con atributos
Matriz::Matriz(int m, int n, double** matrix) 
{
	this->m =m;
	this->n =n;
	this->matrix =matrix;
}
///Destructor.
Matriz::~Matriz() 
{	
}

///Método que sobrecarga el operador "+", que pertenece a la clase Matriz y que devuelve un objeto de tipo Matriz.
Matriz Matriz::operator+(const Matriz m2) 
{	Matriz m1(this->m, this->n, this->matrix);
	//Recibe objeto de tipo Matriz
	Matriz madd(m,n,this->matrix);
        if(this->m != m2.m||this->n != m2.n){
		cout<<"Las dimensiones no coinciden"<<endl;
		return m1;
		}
	else{
    for(int i=0;i<m;i++){
		for(int j=0; j<n; j++){
			madd.matrix[i][j]=this->matrix[i][j]+m2.matrix[i][j];
			}
		}
	}
	
	return madd;
}

///Método que sobrecarga el operador "-", que pertenece a la clase Matriz y que devuelve un objeto de tipo Matriz	
Matriz Matriz::operator-(const Matriz m2) 
{
	Matriz m1(this->m, this->n, this->matrix);
	//Recibe objeto de tipo Matriz
	Matriz madd(m,n,this->matrix);
    //this se refiere al objeto con el que estoy llamando al metodo (f1+) f1 es this
    if(this->m != m2.m||this->n != m2.n){
		cout<<"Las dimensiones no coinciden"<<endl;
		return m1;
		}
	else{
    for(int i=0;i<m;i++){
		for(int j=0; j<n; j++){
			madd.matrix[i][j]=this->matrix[i][j]-m2.matrix[i][j];
			}
		}
	}
	
	return madd;
}

///Método que sobrecarga el operador "*", que pertenece a la clase Matriz y que devuelve un objeto de tipo Matriz	
Matriz Matriz::operator*(const Matriz m2) 
{	double **mat2 = (double **) malloc(sizeof(double *)*this->m);
	for(int i=0; i<m; i++){
        mat2[i] = (double *) malloc(sizeof(double)*m2.n); 
	}
	for(int i=0;i<this->m;i++){
		for(int j=0; j<m2.n; j++){
            mat2[i][j]=0;
  			}
		}
	Matriz mmul(this->m,m2.n,mat2);
	Matriz m1(this->m, this->n, this->matrix);
	if(this->n != m2.m){
		cout<< "Las matrices no son multiplicables" << endl;
		return m1;
		}
	else{
		for(int i=0;i<this->m;i++){
			for(int j=0; j<m2.n; j++){
				for(int k=0; k<this->n; k++){
						mmul.matrix[i][j]+=this->matrix[i][k]*m2.matrix[k][j];
				}
			}
		}
		return mmul;
	}
}

///Método que sobrecarga el operador "/", que pertenece a la clase Matriz y que devuelve un objeto de tipo Matriz	
Matriz Matriz::operator/(const Matriz m2) 
{
	Matriz m1(this->m, this->n, this->matrix);
	//Recibe objeto de tipo Matriz
	Matriz madd(m,n,this->matrix);
    //this se refiere al objeto con el que estoy llamando al metodo (f1+) f1 es this
    if(this->m != m2.m||this->n != m2.n){
		cout<<"Las dimensiones no coinciden"<<endl;
		return m1;
		}
	else{
    for(int i=0;i<m;i++){
		for(int j=0; j<n; j++){
			madd.matrix[i][j]=this->matrix[i][j]/m2.matrix[i][j];
			}
		}
	}
	
	return madd;
}

///Método que sobrecarga el operador "~", que pertenece a la clase Matriz y que devuelve imprime al objeto matriz.
void Matriz::operator~() 
{
	for(int i=0;i<m;i++){
		for(int j=0; j<n; j++){
			cout<< this->matrix[i][j]<<"\t";
			}
		cout<<endl;
		}
}
