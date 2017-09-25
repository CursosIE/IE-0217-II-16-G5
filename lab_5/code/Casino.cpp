#include "Casino.h"

/// Constructor
Casino::Casino() {
	this->P= new Portero();
	
	this->mesa_1= new Mesa();
	this->mesa_2= new Mesa();
	this->mesa_3= new Mesa();
}
/// Destructor
Casino::~Casino() {
}

void Casino::jugar() {
	///@brief Las mesas juegan hasta que se hayan ido todos los clientes
	char j='i';
	int ell;
	while (j!='o')
	{
		ell= mesa_1->esta_llena();
		if (ell==0)	// si hay campos disponibles
		{			// llenar la mesa
			cout<<"Mesa 1 //////////////// Llama jugadores"<<endl;
			cout<<"Jugadores antes:   ";
			mesa_1->jugadores->print();
			
			while (ell==0)
			{
				j= P->llamar_jugador();
				if (j!='n')
				{
					mesa_1->jugadores->add_tail(j);
				}
				ell= mesa_1->esta_llena();
			}
			mesa_1->jugadores->find_rm('o');
			cout<<"Jugadores después: ";
			mesa_1->jugadores->print();
			cout<<endl;
		}
		else
		{
			cout<<"Mesa 1";
			mesa_1->partida();
		}
		
		ell= mesa_2->esta_llena();
		if (ell==0)	//si hay campos disponibles
		{
            cout<<"Mesa 2 //////////////// Llama jugadores"<<endl;
			cout<<"Jugadores antes:   ";
			mesa_2->jugadores->print();
			
			while (ell==0)
			{
				j= P->llamar_jugador();
				if (j!='n')
				{
					mesa_2->jugadores->add_tail(j);
				}
				ell= mesa_2->esta_llena();
			}
			mesa_2->jugadores->find_rm('o');
			cout<<"Jugadores después: ";
			mesa_2->jugadores->print();
			cout<<endl;
		}
		else
		{
			cout<<"Mesa 2";
			mesa_2->partida();
		}
		ell= mesa_3->esta_llena();
		if (ell==0)	//si hay campos disponibles
		{
			cout<<"Mesa 3 //////////////// Llama jugadores"<<endl;
			cout<<"Jugadores antes:   ";
			mesa_3->jugadores->print();
			
			while (ell==0)
			{
				j= P->llamar_jugador();
				if (j!='n')
				{
					mesa_3->jugadores->add_tail(j);
				}
				ell= mesa_3->esta_llena();
			}
			mesa_3->jugadores->find_rm('o');
			cout<<"Jugadores después: ";
			mesa_3->jugadores->print();
			cout<<endl;
		}
		else
		{
			cout<<"Mesa 3";
			mesa_3->partida();
		}
	}
	///////////////////////////////////// cuando ya no hay más clientes en sala de espera
	int cont= 100;
			
	while (cont>0)
	{
		if (mesa_1->jugadores->cn>0)
		{
			cout<<"Mesa 1";
			mesa_1->partida();
		}
		if (mesa_2->jugadores->cn>0)
		{
			cout<<"Mesa 2";
			mesa_2->partida();
		}
		if (mesa_3->jugadores->cn>0)
		{
			cout<<"Mesa 3";
			mesa_3->partida();
		}
		
		cont= mesa_1->jugadores->cn + mesa_2->jugadores->cn + mesa_3->jugadores->cn;
		
	}
}
