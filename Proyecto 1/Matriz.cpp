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

Matriz Matriz::mat2x2(const Matriz m2){
	if(this->m==2 && this->n==2 && m2.m==2 && m2.n==2){
	double **m3 = (double **) malloc(sizeof(double *)*2);
	for(int i=0; i<2; i++){
        m3[i] = (double *) malloc(sizeof(double)*2); 
	}
	double p1=(this->matrix[0][0]+this->matrix[1][1])*(m2.matrix[0][0]+m2.matrix[1][1]);
	double p2=(this->matrix[1][0]+this->matrix[1][1])*m2.matrix[0][0];
	double p3=this->matrix[0][0]*(m2.matrix[0][1]-m2.matrix[1][1]);
	double p4=this->matrix[1][1]*(m2.matrix[1][0]-m2.matrix[0][0]);
	double p5=(this->matrix[0][0]+this->matrix[0][1])*m2.matrix[1][1];
	double p6=(this->matrix[1][0]-this->matrix[0][0])*(m2.matrix[0][0]+m2.matrix[0][1]);
	double p7=(this->matrix[0][1]-this->matrix[1][1])*(m2.matrix[1][0]+m2.matrix[1][1]);
	m3[0][0]=p1+p4-p5+p7;
	m3[0][1]=p3+p5;
	m3[1][0]=p2+p4;
	m3[1][1]=p1-p2+p3+p6;
	Matriz mr(2,2,m3);
	return mr;
	}
	else{
		cout<<"Esta función solo admite matrices 2x2"<<endl;
		}
}

Matriz Matriz::matblock(int b){
	if(b>4){
		cout<<"El número de bloque debe ser menor a 4"<<endl;
		}
	else if(b==1){
		int len=(this->m)/2;
		double **m2 = (double **) malloc(sizeof(double *)*len);
		for(int i=0; i<m; i++){
        m2[i] = (double *) malloc(sizeof(double)*len); 
		}
		Matriz mr(len,len,m2);
		for(int i=0; i<len; i++){
			for(int j=0; j<len;j++){
				mr.matrix[i][j]=this->matrix[i][j];
				}
			}
		return mr;
		}
	else if(b==2){
		int len=(this->m)/2;
		double **m2 = (double **) malloc(sizeof(double *)*len);
		for(int i=0; i<m; i++){
        m2[i] = (double *) malloc(sizeof(double)*len); 
		}
		Matriz mr(len,len,m2);
		for(int i=0; i<len; i++){
			for(int j=len; j<this->m;j++){
				mr.matrix[i][j-len]=this->matrix[i][j];
				}
			}
		return mr;
		}
	else if(b==3){
		int len=(this->m)/2;
		double **m2 = (double **) malloc(sizeof(double *)*len);
		for(int i=0; i<m; i++){
        m2[i] = (double *) malloc(sizeof(double)*len); 
		}
		Matriz mr(len,len,m2);
		for(int i=len; i<this->m; i++){
			for(int j=0; j<len;j++){
				mr.matrix[i-len][j]=this->matrix[i][j];
				}
			}
		return mr;
		}
		else if(b==4){
		int len=(this->m)/2;
		double **m2 = (double **) malloc(sizeof(double *)*len);
		for(int i=0; i<m; i++){
        m2[i] = (double *) malloc(sizeof(double)*len); 
		}
		Matriz mr(len,len,m2);
		for(int i=len; i<this->m; i++){
			for(int j=len; j<this->m;j++){
				mr.matrix[i-len][j-len]=this->matrix[i][j];
				}
			}
		return mr;
		}
	}

Matriz::Matriz(Matriz m1, Matriz m2, Matriz m3, Matriz m4, int len){
	if(len==m1.m && m1.m==m2.m && m2.m==m3.m && m3.m==m4.m){
	double **mat2 = (double **) malloc(sizeof(double *)*2*len);
		for(int i=0; i<2*len; i++){
        mat2[i] = (double *) malloc(sizeof(double)*2*len); 
		}
		Matriz mr(2*len,2*len,mat2);
		for(int i=0; i<len; i++){
			for(int j=0; j<len;j++){
				mr.matrix[i][j]=m1.matrix[i][j];
				}
			}
		for(int i=0; i<len; i++){
			for(int j=len; j<2*len;j++){
				mr.matrix[i][j]=m2.matrix[i][j-len];
				}
			}
		for(int i=len; i<2*len; i++){
			for(int j=0; j<len;j++){
				mr.matrix[i][j]=m3.matrix[i-len][j];
				}
			}
		for(int i=len; i<2*len; i++){
			for(int j=len; j<2*len;j++){
				mr.matrix[i][j]=m4.matrix[i-len][j-len];
				}
			}
		this->m=2*len;
		this->n=2*len;
		this->matrix=mr.matrix;
	}
}

Matriz Matriz::strassen(Matriz m2){
//	if(this->n=!m2.m){cout<<"No se pueden multiplicar"<<endl;}
//	if(matrices no son cuadradas de orden n²){aplicar Duniafunción}
	if(this->m > 2){
		Matriz m3;
		m3.m=this->m;
		m3.n=this->n;
		m3.matrix=this->matrix;
		Matriz a11 = m3.matblock(1);
		Matriz a12 = m3.matblock(2);
		Matriz a21 = m3.matblock(3);
		Matriz a22 = m3.matblock(4);
		Matriz b11 = m2.matblock(1);
		Matriz b12 = m2.matblock(2);
		Matriz b21 = m2.matblock(3);
		Matriz b22 = m2.matblock(4);
		Matriz c11 = a11.strassen(b11)+a12.strassen(b21);
		Matriz c12 = a11.strassen(b12)+a12.strassen(b22);
		Matriz c21 = a21.strassen(b11)+a22.strassen(b21);
		Matriz c22 = a21.strassen(b12)+a22.strassen(b22);
		Matriz mr(c11,c12,c21,c22,(this->m)/2);
		return mr;
		}
	else{
		Matriz m3;
		m3.m=this->m;
		m3.n=this->n;
		m3.matrix=this->matrix;
		return m3.mat2x2(m2);
		}
	
	}
