#include "Coordinador.h"
#include "Mundo.h"
#include "ETSIDI.h"
Coordinador::Coordinador()
{
	estado = INICIO;
}

Coordinador::~Coordinador()
{

}

void  Coordinador::Dibuja()
{
	if (estado == INICIO)
	{
		time += 0.025;


		gluLookAt(0, 7.5, 30, // posicion del ojo
			0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
	
		glDisable(GL_LIGHTING);
		glColor3ub(182, 145, 112);
		glBegin(GL_POLYGON);
		glVertex3f(-11, 16, -0.01);
		glVertex3f(12, 16, -0.01);
		glVertex3f(12, 12, -0.01);
		glVertex3f(-11, 12, -0.01);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_LIGHTING);
		glColor3ub(78, 55, 49);
		glBegin(GL_POLYGON);
		glVertex3f(-11.6, 16.6, -0.02);
		glVertex3f(12.6, 16.6, -0.01);
		glVertex3f(12.6, 11.4, -0.01);
		glVertex3f(-11.6, 11.4, -0.01);
		glEnd();
		glEnable(GL_LIGHTING);


		ETSIDI::setTextColor(182, 145, 112);
		ETSIDI::setFont("fuentes/Classical.otf", 70);
		//ETSIDI::printxy("Damas Hispanochinas  ", -10, 13);
		//if (time < 0.2) { ETSIDI::printxy("JUEGO ", -10, 13); }
		if ((time > 0.2) && (time < 0.4)) { ETSIDI::printxy("Dam ", -10, 13); }
		if ((time > 0.4) && (time < 0.6)) { ETSIDI::printxy("Damas ", -10, 13); }
		if ((time > 0.6) && (time < 0.8)) { ETSIDI::printxy("Damas Hispano ", -10, 13); }
		if ((time > 0.8) && (time < 1.0)) { ETSIDI::printxy("Damas Hispanochinas ", -10, 13); }
		if ((time > 1.0)) { ETSIDI::printxy("Damas Hispanochinas ", -10, 13); }

		if (time > 1.5) {
			ETSIDI::setTextColor(182, 145, 112);
			ETSIDI::setFont("fuentes/Classical.otf", 40);
			ETSIDI::printxy("Pulse cualquier tecla para empezar", -9, 6);
	
		}
	}
	else if (estado == JUEGO)
		mundo.dibuja();
	
	else if(estado == FIN)
	{
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)

		

		ETSIDI::setTextColor(182, 145, 112);
		ETSIDI::setFont("fuentes/Classical.otf", 70);
		ETSIDI::printxy("Game Over", -6, 7);

		if (mundo.ganador() == 2)
		{
			ETSIDI::printxy("White player wins", -6, 2);
		}
		else if (mundo.ganador()==1)
		{
			ETSIDI::printxy("Black player wins", -6, 2);
		}
	}
		



	}


void Coordinador::Teclado(unsigned char key)
{

	if (estado == INICIO) {
		estado = JUEGO;
	}
}

void Coordinador::Fin()
{
	
	if (estado == JUEGO)
	{
		if (mundo.Getmarcador())
		{
			estado = FIN;
		}
	}
}
