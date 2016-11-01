#ifndef MESA_H
#define MESA_H

#include "LCP.h"
#include "math.h"

class Mesa {
public:
	//Atributos
    /// Maso de cartas
	LCP<int>* maso;
	/// Cartas de cada jugador
	LCP<int>* cartas;
	/// Jugadores de la mesa
	LCP<char>* jugadores;
	/// Campos de la mesa
	int campos;
	string ganador;
	string perdedor;

	Mesa();
    ~Mesa();
    
    int esta_llena();
    void barajar();
    int dar_carta();
    void repartir(LCP<int>* cartas, int k);
    int turno();
    void partida();
    void print_jugada(LCP<char>* jugadores, LCP<int>* cartas);
    void print_maso();
};
#endif /* MESA_H */
