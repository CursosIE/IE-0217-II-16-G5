#include "Tablero.h"
#include "Ficha.h"

//using namespace std;
/// @mainpage Juego Hex
/// @author Dunia Barahona <s4si@hotmail.com>
/// @author Emmanuel Bustos 
/// @date 1 de diciembre de 2016
/// @version 1.0
/// @par Descripción
/// Implementación del juego Hex en el lenguaje de programación C++, mediante la clase @link Ficha @endlink, la clase @link Tablero @endlink y el @link main @endlink.  

int main(int argc, char** argv) {
    
    //Variables utilizadas durante el juego
	int a= -1; 
	int b= -1;
	int opc= 0; //opción
	int tab;
	bool turno; //Booleano que indica si el turno de un jugador está activo 
	
	cout<<endl<<"Ingrese el tamaño del tablero:"<<endl;
	cin>>tab;
	Tablero t(tab); ///Se inicializa el tablero.
	
	cout<<endl<<"Turno de";
	printf("%c[%d;%dm jugador 1%c[%dm",27,1,31,27,0);
	cout<<", coloque una ficha"<<endl;

    while ( (a<0 || a>=tab) || (b<0 || b>=tab) ) {
		cout<<"Pos x:"<<endl; ///Se piden las posiciones "x" y "y" de la ficha deseada.
		cin>>a; 
		cout<<"Pos y:"<<endl;
		cin>>b;
					
		if ( (a<0 || a>=tab) || (b<0 || b>=tab) ) {
			cout<<"Posición fuera del tablero."<<endl<<endl;
		}
	}
	
	turno=t.ponroja(a,b);
	cout<<endl;
	~t;    
	
	while (opc!=1 && opc!=2) {
		cout<<endl<<"Turno de";
		printf("%c[%d;%dm jugador 2%c[%dm",27,1,34,27,0);
		cout<<", elija una opción:"<<endl;
		cout<<"\t 1) Continuar con fichas azules."<<endl<<"\t 2) Usar fichas rojas."<<endl;
		cin>>opc;
		if (opc!=1 && opc!=2) {
			cout<<opc<<" no es una opción."<<endl;
		}
	}
		
	while(t.ganar==false){ ///Mientras ninguno de los jugadores haya ganado, el juego seguirá activo.
		turno=false;
		if (opc==1) {
			while(turno!=true){ //turno del jugador azul
				if(t.ganar==true){break;}
				cout<<endl<<"Turno de";
				printf("%c[%d;%dm jugador 2%c[%dm",27,1,34,27,0);
				cout<<", coloque una ficha"<<endl;
				
				a= -1;
				b= -1;
				while ( (a<0 || a>=tab) || (b<0 || b>=tab) ) {
					cout<<"Pos x:"<<endl;
					cin>>a;	
					cout<<"Pos y:"<<endl;
					cin>>b;
					
					if ( (a<0 || a>=tab) || (b<0 || b>=tab) ) {
						cout<<"Posición fuera del tablero."<<endl<<endl;
					}
				}	
				//Esto hace que el jugador coloque la ficha, si la posición deseada no es válida, el turno se repite, si no, el turno termina.
				turno=t.ponazul(a,b); 
				if(*t.tablero[a][b].conectainicio==true && *t.tablero[a][b].conectafinal==true){t.ganar=true;}
				cout<<endl;
				///Se imprime el tablero después de cada turno.
				///
				///Si la ficha colocada por el jugador conecta con el inicio y el final del tablero, el jugador gana.
				~t; 
			}
			turno=false;
				
			while(turno!=true){
				///Si alguno de los jugadores gana, se termina el juego inmediatamente. 
				if(t.ganar==true){break;} 
				cout<<endl<<"Turno de";
				printf("%c[%d;%dm jugador 1%c[%dm",27,1,31,27,0);
				cout<<", coloque una ficha"<<endl;
					
				a= -1;
				b= -1;
				while ( (a<0 || a>=tab) || (b<0 || b>=tab) ) {
					cout<<"Pos x:"<<endl;
					cin>>a;
					cout<<"Pos y:"<<endl;
					cin>>b;
						
					if ( (a<0 || a>=tab) || (b<0 || b>=tab) ) {
						cout<<"Posición fuera del tablero."<<endl<<endl;
					}
				} 
					
				turno=t.ponroja(a,b);
				if(*t.tablero[a][b].conectainicio==true && *t.tablero[a][b].conectafinal==true){t.ganar=true;} 
				cout<<endl;
				~t; 
			}
		}
			
		else if (opc==2)
		{
			while(turno!=true){ //turno del jugador azul
				if(t.ganar==true){break;}
				cout<<endl<<"Turno de";
				printf("%c[%d;%dm jugador 1%c[%dm",27,1,34,27,0);
				cout<<", coloque una ficha"<<endl;
					
				a= -1;
				b= -1;
				while ( (a<0 || a>=tab) || (b<0 || b>=tab) ) {
					cout<<"Pos x:"<<endl;
					cin>>a;
					cout<<"Pos y:"<<endl;
					cin>>b;
						
					if ( (a<0 || a>=tab) || (b<0 || b>=tab) ) {
						cout<<"Posición fuera del tablero."<<endl<<endl;
					}
				}

				turno=t.ponazul(a,b);
				if(*t.tablero[a][b].conectainicio==true && *t.tablero[a][b].conectafinal==true){t.ganar=true;}
				cout<<endl;
				~t;
			}
			turno=false;
				while(turno!=true){ 
					if(t.ganar==true){break;} //Si alguno de los jugadores ganó, terminar el juego inmediatamente
					cout<<endl<<"Turno de";
					printf("%c[%d;%dm jugador 2%c[%dm",27,1,31,27,0);
					cout<<", coloque una ficha"<<endl; 
					
					a= -1;
					b= -1;
					while ( (a<0 || a>=tab) || (b<0 || b>=tab) ) {
						cout<<"Pos x:"<<endl;
						cin>>a;
						cout<<"Pos y:"<<endl;
						cin>>b;
						
						if ( (a<0 || a>=tab) || (b<0 || b>=tab) ) {
							cout<<endl<<"Posición fuera del tablero."<<endl<<endl;
						}
					}
					
					turno=t.ponroja(a,b); 
					if(*t.tablero[a][b].conectainicio==true && *t.tablero[a][b].conectafinal==true){t.ganar=true;}
					cout<<endl;
					~t;
				}
			}
		}
	///Se anuncia al Ganador.
	if (opc==1)
	{
		cout<<"Partida terminada, ganó el";
		if(t.tablero[a][b].rojo==true){
			printf("%c[%d;%dm jugador 1 %c[%dm",27,1,31,27,0);
			cout<<endl;
		}
		else if(t.tablero[a][b].azul==true){
			printf("%c[%d;%dm jugador 2 %c[%dm",27,1,34,27,0);
			cout<<endl;
		}
	}
	else if (opc==2)
	{
		cout<<"Partida terminada, ganó el";
		if(t.tablero[a][b].azul==true){
			printf("%c[%d;%dm jugador 1 %c[%dm",27,1,34,27,0);
			cout<<endl;
		}
		else if(t.tablero[a][b].rojo==true){
			printf("%c[%d;%dm jugador 2 %c[%dm",27,1,31,27,0);
			cout<<endl;
		}
	}
	cout<<endl;
	return 0;
}
