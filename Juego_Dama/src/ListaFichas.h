#pragma once
#define MAX_FICHAS 100 
#include "Ficha.h"
class ListaFichas
{
public:
	bool agregar(Ficha* e);
	void Dibuja();
	Ficha* get_p_ficha(int i) { return lista[i]; };
	void getPos_disp();
	void eliminar(int index);
	int getNumero() { return numero; }
	void destruirContenido();

private:
	int numero;
	Ficha* lista[MAX_FICHAS];
};

