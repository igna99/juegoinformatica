#pragma once
#include "Tablero.h"
#include "ListaFichas.h"

class Mundo
{ 
private:
	Tablero tablero;
	bool fase_movimiento=TRUE;
	int turn = 1; // turno 1 blancas turno 2 negras
	int fase_movimento = 1;
	int comidas_b=0;
	int comidas_n=0;

public: 


	Mundo();
	void mouse(int button, int state, int mousex, int mousey);
	void dibuja();
	bool getFase_movimiento() { return fase_movimiento; }
	void setFase_movimiento(bool fase) { fase_movimiento = fase; }
	bool getOcupacion(int i, int j) { return tablero.getOcupacion(i, j); } //return true si est?ocupada
	int getTurno() { return tablero.getTurno(); }
	void setTurno(int t) { tablero.setTurno(t); }

	void Marcador();
	bool Getmarcador();
	int ganador();

	float getFicha_blanca_X(int i) { return tablero.getFicha_blanca(i)->getX(); }//Devuelve  la coordenada x de la ficha blanca que se le pasa
	float getFicha_blanca_Y(int i) { return tablero.getFicha_blanca(i)->getY(); }//Devuelve  la coordenada y de la ficha blanca que se le pasa
	float getFicha_blanca_Z(int i) { return tablero.getFicha_blanca(i)->getZ(); }//Devuelve  la coordenada z de la ficha blanca que se le pasa

	float getFicha_negra_X(int i) { return tablero.getFicha_negra(i)->getX(); }//Devuelve  la coordenada x de la ficha blanca que se le pasa
	float getFicha_negra_Y(int i) { return tablero.getFicha_negra(i)->getY(); }//Devuelve  la coordenada y de la ficha blanca que se le pasa
	float getFicha_negra_Z(int i) { return tablero.getFicha_negra(i)->getZ(); }//Devuelve  la coordenada z de la ficha blanca que se le pasa

	ListaFichas* getListaFichasB() { return tablero.getListaFichasB(); }
	ListaFichas* getListaFichasN() { return tablero.getListaFichasN(); }


	bool getFicha_blanca_DispMov(int i) { return tablero.getFicha_blanca(i)->DispMovimientos(); }//TRUE cuando la ficha que se le pasa tiene movimientos disponibles
	bool getFicha_negra_DispMov(int i) { return tablero.getFicha_negra(i)->DispMovimientos(); }

	void setFicha_aux(Ficha* ficha) { tablero.setFicha_aux(ficha); }
	Ficha* get_p_Ficha_blanca(int i) { return tablero.get_p_Ficha_blanca(i); }
	Ficha* get_p_Ficha_negra(int i) { return tablero.get_p_Ficha_negra(i); }
	Ficha* getFicha_aux() { return tablero.getFicha_aux(); }
	Celda* get_p_Celda(int i, int j) { return tablero.get_p_Celda(i, j); }
	Ficha* getFicha_comida() { return tablero.getFicha_comida(); }
	void setFicha_comida(Ficha* ficha) { tablero.setFicha_comida(ficha); }
	

};
