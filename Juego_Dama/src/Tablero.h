#pragma once
#include "Celda.h"
#include "Ficha.h"
#include "ListaFichas.h"
class Tablero
{
private:

	Celda celda_tablero[8][8];
	Ficha* aux; //puntero a la ficha que se quiere mover
	Ficha* f_comida;//puntero a la ficha que se ha comido
	Ficha jugador1[12];
	Ficha jugador2[12];

	ListaFichas fichas_negras;
	ListaFichas fichas_blancas;
	int turno=1; // 1-> turno blancas   2-> turno negras

public:
	Tablero();
	~Tablero();
	void Dibuja();
	Celda getCelda(int posx, int posy) { return celda_tablero[posx][posy]; }
	bool getOcupacion(int i, int j) { return celda_tablero[i][j].getOcupacion(); }
	Ficha* get_p_Ficha_blanca(int i);
	Ficha* get_p_Ficha_negra(int i);
	Ficha* getFicha_blanca(int i) { return fichas_blancas.get_p_ficha(i); }
	Ficha* getFicha_negra(int i) { return fichas_negras.get_p_ficha(i); }
	ColorRGB getColorFichaCelda(int i, int j); // devuelve el color de la ficha que esta en la celda que se le pasa
	Ficha* getFicha_aux() { return aux; }
	Celda* get_p_Celda(int i, int j);
	int getTurno() { return turno; };
	void setTurno(int t) { turno = t; }
	void setFicha_aux(Ficha* ficha) { aux = ficha; }
	void getMovFichaB(Ficha* ficha); //Obtiene los movimientos de la ficha blanca que se le pase.
	void getMovFichaN(Ficha* ficha); //Obtiene los movimientos de la ficha negra que se le pase.

	void getPosDisponibles();
	void getMov();
	Ficha* getFicha_comida() { return f_comida; }
	void setFicha_comida(Ficha* ficha) { f_comida = ficha; }
	ListaFichas* getListaFichasB() { return &fichas_blancas; }
	ListaFichas* getListaFichasN() { return &fichas_negras; }




};

