#include <iostream>
#include "string"
#include <cstdio>
#include <cstdlib>
using namespace std;

///Función que encuentra la posición de el codón de entrada y del codón de salida.
int* codonpos(char** chain){
int* codonpos = new int[2];
codonpos = (int *)malloc(2 * sizeof(int));
int trig=0;
int i=0;
while(trig!=2){
	if(*(*chain+i) == 'U'){
		if(*(*chain +1+i) =='A'){
			if(*(*chain +2+i) =='A'){
				*(codonpos+trig)=i;
				trig++;
			}
			if(*(*chain +2+i) =='G'){
				*(codonpos+trig)=i;
				trig++;
			}
		}
		if(*(*chain +1+i)=='G'){
			if(*(*chain +2+i)=='A'){
 				*(codonpos+trig)=i;
				trig++;
			}
		}
	 }
	 i=i+3;
}
return codonpos;
}

///Función que toma cadenas de ARN y la ordena según sus aminoácidos.
char* traduce(char** chain){
int* arr = codonpos(chain);
int a=arr[0];
int b=arr[1];
int c= b-a+3;
char* aa = new char[c];
aa = (char *)malloc(c * sizeof(char));
int i = a;
int n = 0;
for(i=a; i<=b; i+=3){
	if(*(*chain+i) == 'U'){
		if(*(*chain +1+i) =='A'){
			if(*(*chain +2+i) =='U'|| *(*chain +2+i) =='C'){
				aa[n]='Y';
				n++;
			}
			if(*(*chain +2+i) =='A' || *(*chain +2+i) =='G'){
				aa[n]='-';
				n++;
			}
		}
		if(*(*chain +1+i) =='G'){
			if(*(*chain +2+i) =='G'){
				aa[n]='W';
				n++;
			}
			if(*(*chain +2+i) =='A'){
				aa[n]='-';
				n++;
			}
			if(*(*chain +2+i) =='U'|| *(*chain +2+i) =='C'){
				aa[n]='C';
				n++;
			}
		}
		if(*(*chain +1+i) =='C'){
			if(*(*chain +2+i) =='U'|| *(*chain +2+i) =='C' || *(*chain +2+i) =='A' || *(*chain +2+i) =='G'){
				aa[n]='S';
				n++;
			}
		}
		if(*(*chain +1+i) =='U'){
			if(*(*chain +2+i) =='G'|| *(*chain +2+i) =='A'){
				aa[n]='L';
				n++;
			}
			if(*(*chain +2+i) =='U'|| *(*chain +2+i) =='C'){
				aa[n]='F';
				n++;
			}
		}
	}
	if(*(*chain+i) == 'G'){
		if(*(*chain +1+i) =='G'){
			if(*(*chain +2+i) =='U'|| *(*chain +2+i) =='C' || *(*chain +2+i) =='A' || *(*chain +2+i) =='G'){
				aa[n]='G';
				n++;
			}
		}
		if(*(*chain +1+i) =='A'){
			if(*(*chain +2+i) =='G'|| *(*chain +2+i) =='A'){
				aa[n]='E';
				n++;
			}
			if(*(*chain +2+i) =='U'|| *(*chain +2+i) =='C'){
				aa[n]='D';
				n++;
			}
		}
		if(*(*chain +1+i) =='C'){
			if(*(*chain +2+i) =='U'|| *(*chain +2+i) =='C' || *(*chain +2+i) =='A' || *(*chain +2+i) =='G'){
				aa[n]='A';
				n++;
			}
		}
		if(*(*chain +1+i) =='U'){
			if(*(*chain +2+i) =='U'|| *(*chain +2+i) =='C' || *(*chain +2+i) =='A' || *(*chain +2+i) =='G'){
				aa[n]='V';
				n++;
			}
		}
	}
	if(*(*chain+i) == 'A'){
		if(*(*chain +1+i) =='G'){
			if(*(*chain +2+i) =='G'|| *(*chain +2+i) =='A'){
				aa[n]='R';
				n++;
			}
			if(*(*chain +2+i) =='C'|| *(*chain +2+i) =='U'){
				aa[n]='S';
				n++;
			}
		}
		if(*(*chain +1+i) =='A'){
			if(*(*chain +2+i) =='G'|| *(*chain +2+i) =='A'){
				aa[n]='K';
				n++;
			}
			if(*(*chain +2+i) =='C'|| *(*chain +2+i) =='U'){
				aa[n]='N';
				n++;
			}
		}
		if(*(*chain +1+i) =='C'){
			if(*(*chain +2+i) =='U'|| *(*chain +2+i) =='C' || *(*chain +2+i) =='A' || *(*chain +2+i) =='G'){
				aa[n]='T';
				n++;
			}
		}
		if(*(*chain +1+i) =='U'){
			if(*(*chain +2+i) =='U'|| *(*chain +2+i) =='C' || *(*chain +2+i) =='A'){
				aa[n]='I';
				n++;
			}
			if(*(*chain +2+i) =='G'){
				aa[n]='M';
				n++;
			}	
		}

	}
	if(*(*chain+i) == 'C'){
		if(*(*chain +1+i) =='G'){
			if(*(*chain +2+i) =='U'|| *(*chain +2+i) =='C' || *(*chain +2+i) =='A' || *(*chain +2+i) =='G'){
				aa[n]='R';
				n++;
			}	
		}
		if(*(*chain +1+i) =='A'){
			if(*(*chain +2+i) =='G'|| *(*chain +2+i) =='A'){
				aa[n]='Q';
				n++;
			}
			if(*(*chain +2+i) =='C'|| *(*chain +2+i) =='U'){
				aa[n]='H';
				n++;
			}
		}
		if(*(*chain +1+i) =='C'){
			if(*(*chain +2+i) =='U'|| *(*chain +2+i) =='C' || *(*chain +2+i) =='A' || *(*chain +2+i) =='G'){
				aa[n]='P';
				n++;
			}	
		}
		if(*(*chain +1+i) =='U'){
			if(*(*chain +2+i) =='U'|| *(*chain +2+i) =='C' || *(*chain +2+i) =='A' || *(*chain +2+i) =='G'){
				aa[n]='L';
				n++;
			}	
		}	
	}

}
	return aa;

}

///Recibe puntero(contenido) de tipo int llamado vector e imprime n caracteres de este.
void imprimirVc(char* vector, int size){	
  int i;
  for (i = 0; i < size; i++) {
    printf("%c", *(vector+i));		
  }
  printf("\n");
}

///Programa principal que ejecuta la clasificación de codones.
int main(int argc, char** argv){
	argv++;
  int* arreglo = codonpos(argv);
	char* prueba = traduce(argv);
	//cout << prueba << endl;
	imprimirVc(prueba, 2); //el método imprime hasta el caracter que el usuario indique.
	imprimirVc(prueba, 7);
	delete prueba;

}
