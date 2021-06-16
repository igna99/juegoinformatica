#pragma once
#include "Mundo.h"

class Coordinador
{
protected:
	enum Estado { INICIO, JUEGO ,FIN};
	Mundo mundo;
	Estado estado;
	float time = 0;

public:
	Coordinador();
	~Coordinador();
	void Teclado(unsigned char key);
	void Dibuja();
	void mouse(int button, int state, int mousex, int mousey) { mundo.mouse(button, state, mousex, mousey); };
	int win;
	void Fin();



};


