// Dunia Barahona
#include "Matriz.h"

Matriz::Matriz() 
{	
	///@brief Constructor simple
}
Matriz::Matriz(int m, int n, double** matrix) 
{	
	///@brief Constructor con atributos
	this->m =m;
	this->n =n;
	this->matrix =matrix;
}
Matriz::~Matriz() 
{	
	///@brief Destructor	
}
Matriz Matriz::operator+(const Matriz m2) 
{	///@brief Sobrecarga del operador @b +
	///
	///Método que pertenece a la clase Matriz y que devuelve un objeto de tipo Matriz 
	///@param m2 objeto de tipo Matriz
    ///@return Suma de las matrices dadas
	Matriz m1(this->m, this->n, this->matrix);
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
Matriz Matriz::operator-(const Matriz m2) 
{   ///@brief Sobrecarga del operador @b -
	///
	///Método que pertenece a la clase Matriz y que devuelve un objeto de tipo Matriz 
	///@param m2 objeto de tipo Matriz
    ///@return Resta de las matrices dadas
	Matriz m1(this->m, this->n, this->matrix);
	Matriz madd(m,n,this->matrix);
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
Matriz Matriz::operator*(const Matriz m2) 
{	///@brief Sobrecarga del operador @b *
	///
	///Método que pertenece a la clase Matriz y que devuelve un objeto de tipo Matriz 
	///@param m2 objeto de tipo Matriz
    ///@return Multiplicación de las matrices dadas
	double **mat2 = (double **) malloc(sizeof(double *)*this->m);
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
Matriz Matriz::operator/(const Matriz m2) 
{   ///@brief Sobrecarga del operador @b /
	///
	///Método que pertenece a la clase Matriz y que devuelve un objeto de tipo Matriz. 
	///@param m2 objeto de tipo Matriz
    ///@return División de las matrices dadas
	Matriz m1(this->m, this->n, this->matrix);
	Matriz madd(m,n,this->matrix);
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
void Matriz::operator~() 
{   ///@brief Sobrecarga del operador @b ~
	///
	///Método que pertenece a la clase Matriz
	///
    ///Imprime la matriz especificada
	for(int i=0;i<m;i++){
		for(int j=0; j<n; j++){
			cout<< this->matrix[i][j]<<"\t";
		}
		cout<<endl;
	}
}
