#include "Mesa.h"
#include <iostream>
#include "string"
#include "Carta.h"
#include "Mazo.h"
#include "Jugador.h"
#include "Fila.h"

///Constructor básico de la clase Mesa
Mesa::Mesa(){
	}
///Constructor con características de la clase Mesa
Mesa::Mesa(int numero){
 this->numero=numero;
 this->espaciosdisp = 3;
 this->Jugador1=Jugador(1);
 this->Jugador2=Jugador(2);
 this->Jugador3=Jugador(3);

}

///Destructor de la clase Mesa
Mesa::~Mesa(){
}

///Método de print para objetos Mesa
void Mesa::operator~(){
}

///Método en el cuál 1, 2 o 3 jugadores juegan una partida de blackjack
void Mesa::partida(Fila &fila){
	cout<<"Mesa "<<numero<<endl;
	cout<<endl;
	int espera =fila.filen;
	Mazo mazo;
	mazo.barajar();
	Jugador1.puntos=0;
	Jugador2.puntos=0;
	Jugador3.puntos=0;
	if(this->espaciosdisp==3 && espera ==0){
		cout<<"Mesa "<<numero<<" vacía"<<endl;
		cout<<endl;
			return ;
	}
	if(this->espaciosdisp==3){
		if(espera>=3){
		   espaciosdisp-=3;
		   espera-=3;
		   cout<<"Entra: "<< fila.pop(true)<<" a la mesa "<<numero<<endl;
		   cout<<"Entra: "<< fila.pop(true)<<" a la mesa "<<numero<<endl;
		   cout<<"Entra: "<< fila.pop(true)<<" a la mesa "<<numero<<endl;
		   Jugador1.activo=true;
		   Jugador2.activo=true;
		   Jugador3.activo=true;
			}
		else if(espera==2){
			espaciosdisp-=2;
		    espera-=2;
		    cout<<"Entra: "<< fila.pop(true)<<" a la mesa "<<numero<<endl;
		    cout<<"Entra: "<< fila.pop(true)<<" a la mesa "<<numero<<endl;
		    Jugador1.activo=true;
		    Jugador2.activo=true;
		    Jugador3.activo=false;
		}
		else if(espera==1){
			espaciosdisp-=1;
		    espera-=1;
		    cout<<"Entra: "<< fila.pop(true)<<" a la mesa "<<numero<<endl;
		    Jugador1.activo=true;
		    Jugador2.activo=false;
		    Jugador3.activo=false;
			}
		}
	else if(espaciosdisp==2){
		if(espera>=2){
		   espaciosdisp-=2;
		   espera-=2;
		   cout<<"Entra: "<< fila.pop(true)<<" a la mesa "<<numero<<endl;
		   cout<<"Entra: "<< fila.pop(true)<<" a la mesa "<<numero<<endl;
		   Jugador1.activo=true;
		   Jugador2.activo=true;
		   Jugador3.activo=true;
			}
		else if(espera==1){
			espaciosdisp-=1;
		    espera-=1;
		    cout<<"Entra: "<< fila.pop(true)<<" a la mesa "<<numero<<endl;
		    Jugador1.activo=true;
	   	    Jugador2.activo=true;
		    Jugador3.activo=false;
			}
		}
	else if(espaciosdisp==1){
		if(espera>=1){
		   espaciosdisp-=1;
		   espera-=1;
		   cout<<"Entra: "<< fila.pop(true)<<" a la mesa "<<numero<<endl;
		   Jugador1.activo=true;
		   Jugador2.activo=true;
		   Jugador3.activo=true;
			}
		}
	if(espera==0 && espaciosdisp==2){
		Jugador1.activo=true;
		}
	if(espera==0 && espaciosdisp==1){
		Jugador1.activo=true;
		Jugador2.activo=true;
		}
	if(espaciosdisp==0){
		Jugador1.activo=true;
		Jugador2.activo=true;
		Jugador3.activo=true;
		}
	if(espera==0||espaciosdisp==0){
		if(Jugador1.activo==true){
		cout<<"El jugador 1 come un: "; ~mazo.deck[mazo.cantcart-1];
		Jugador1.comer(mazo);
		cout<<"El jugador 1 come un: "; ~mazo.deck[mazo.cantcart-1];
		Jugador1.comer(mazo);
		}
		if(Jugador2.activo==true){
		cout<<"El jugador 2 come un: "; ~mazo.deck[mazo.cantcart-1];
		Jugador2.comer(mazo);
		cout<<"El jugador 2 come un: "; ~mazo.deck[mazo.cantcart-1];
		Jugador2.comer(mazo);
		}
		if(Jugador3.activo==true){
		cout<<"El jugador 3 come un: "; ~mazo.deck[mazo.cantcart-1];
		Jugador3.comer(mazo);
		cout<<"El jugador 3 come un: "; ~mazo.deck[mazo.cantcart-1];
		Jugador3.comer(mazo);
		}
		int lose=0;
		while(Jugador1.activo==true||Jugador2.activo==true||Jugador3.activo==true){
			if(Jugador1.activo==true && Jugador1.puntos>=19){
				cout<<endl;
				~Jugador1; 
				Jugador1.activo=false;
				}
			if(Jugador2.activo==true && Jugador2.puntos>=19){
				cout<<endl;
				~Jugador2; 
				Jugador2.activo=false;
				}
			if(Jugador3.activo==true && Jugador3.puntos>=19){
				cout<<endl;
				~Jugador3; 
				Jugador3.activo=false;
				}
			if(Jugador1.activo==true){
         		cout<<"El jugador 1 come un: "; ~mazo.deck[mazo.cantcart-1];
				Jugador1.comer(mazo);
				}
			if(Jugador2.activo==true){
    			cout<<"El jugador 2 come un: "; ~mazo.deck[mazo.cantcart-1];
				Jugador2.comer(mazo);
				}
			if(Jugador3.activo==true){
				cout<<"El jugador 3 come un: "; ~mazo.deck[mazo.cantcart-1];
				Jugador3.comer(mazo);
				}
			}
		if(Jugador1.puntos>21){
			espaciosdisp++;
			lose++;
			}
		if(Jugador2.puntos>21){
			espaciosdisp++;
			lose++;
			}
		if(Jugador3.puntos>21){
			espaciosdisp++;
			lose++;
			}
		if(lose!=0){
		cout<<"Pierde/n "<<lose<<" jugador/es, hay "<<espaciosdisp<<" espacio/s disponible/s en la mesa "<<numero<<endl;
	   }
    }
    cout<<endl;
}
