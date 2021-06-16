
#include "Mundo.h"
#include "freeglut.h"
#include "ETSIDI.h"
#include <math.h>

Mundo::Mundo()
{

}
void Mundo::dibuja()
{
	gluLookAt(3, 3.5, 15,  // posicion del ojo
			3.5, 3.5, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 0.0, 1.0);      // definimos hacia arriba (eje Z)    

	//aqui es donde hay que poner el codigo de dibujo
	//dibujo del suelo
	glDisable(GL_LIGHTING);
	glColor3ub(182, 145, 112);
	glBegin(GL_POLYGON);
	glVertex3f(-0.1, -0.1, -0.01);
	glVertex3f(8.1, -0.1, -0.01);
	glVertex3f(8.1, 8.1, -0.01);
	glVertex3f(-0.1, 8.1, -0.01);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_LIGHTING);
	glColor3ub(78, 55, 49);
	glBegin(GL_POLYGON);
	glVertex3f(-0.6, -0.6, -0.02);
	glVertex3f(8.6, -0.6, -0.01);
	glVertex3f(8.6, 8.6, -0.01);
	glVertex3f(-0.6, 8.6, -0.01);
	glEnd();
	glEnable(GL_LIGHTING);
	ETSIDI::setTextColor(182, 145, 112);
	ETSIDI::setFont("fuentes/Classical.otf", 40);
	ETSIDI::printxy("Turno  : ", 7.5, -1.35);
	if (turn == 1)
	{
		ETSIDI::setTextColor(182, 145, 112);
		ETSIDI::setFont("fuentes/Classical.otf", 40);
		ETSIDI::printxy("Blancas", 6, -1.25);
	}
	if (turn == 2)
	{
		ETSIDI::setTextColor(182, 145, 112);
		ETSIDI::setFont("fuentes/Classical.otf", 40);
		ETSIDI::printxy("Negras", 6, -1.25);
	}
	Marcador();
	tablero.Dibuja();
	//inicio.DibujaInicio();

	

}


void Mundo::Marcador()
{

	const char* vector[13];
	char aux0 = '0';
	vector[0] = &aux0;
	char aux1 = '1';
	vector[1] = &aux1;
	char aux2 = '2';
	vector[2] = &aux2;
	char aux3 = '3';
	vector[3] = &aux3;
	char aux4 = '4';
	vector[4] = &aux4;
	char aux5 = '5';
	vector[5] = &aux5;
	char aux6 = '6';
	vector[6] = &aux6;
	char aux7 = '7';
	vector[7] = &aux7;
	char aux8 = '8';
	vector[8] = &aux8;
	char aux9 = '9';
	vector[9] = &aux9;
	char aux10 = '1';
	vector[10] = &aux10;
	char aux11 = '1';
	vector[11] = &aux11;
	char aux12 = '1';
	vector[12] = &aux12;
	ListaFichas* blancas = getListaFichasB();
	ListaFichas* negras = getListaFichasN();



	int quedan_b = blancas->getNumero();
	int quedan_n = negras->getNumero();
	int comidas_n = 12 - quedan_n;
	int comidas_b = 12 - quedan_b;
	ETSIDI::setTextColor(182, 145, 112);
	ETSIDI::setFont("fuentes/Classical.otf", 37);
	ETSIDI::printxy("Marcador", 5, -1);
	ETSIDI::setTextColor(182, 145, 112);
	ETSIDI::setFont("fuentes/Classical.otf", 40);
	ETSIDI::printxy("B", 4, -1.5);
	ETSIDI::setTextColor(182, 145, 112);
	ETSIDI::setFont("fuentes/Classical.otf", 40);
	ETSIDI::printxy("N", 2, -1.5);
	for (int i = 0; i < 13; i++)
	{
		if (comidas_n == i)
		{
			ETSIDI::setTextColor(182, 145, 112);
			ETSIDI::setFont("fuentes/Classical.otf", 40);
			ETSIDI::printxy(vector[i], 3.0, -1.25);
			if (i > 9)
			{
				int a = i - 10;
				ETSIDI::setTextColor(182, 145, 112);
				ETSIDI::setFont("fuentes/Classical.otf", 40);
				ETSIDI::printxy(vector[a], 3, -2);
			}
		}



		if (comidas_b == i)
		{
			ETSIDI::setTextColor(182, 145, 112);
			ETSIDI::setFont("fuentes/Classical.otf", 40);
			ETSIDI::printxy(vector[i], 1, -1.25);
			if (i > 9)
			{
				int b = i - 10;
				ETSIDI::setTextColor(182, 145, 112);
				ETSIDI::setFont("fuentes/Classical.otf", 40);
				ETSIDI::printxy(vector[b], 1, -2);
			}
		}
	}

	
	
	 
	
}
void Mundo::mouse(int button, int state, int mousex, int mousey)
{
	int i = 0;
	int j = 0;
	bool h;
	Vector3D posicion_deseada;
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		switch (fase_movimento)//comprueba que se ejecuta si es el primer pinchazo del movimiento y se obtiene la ficha que se quiere mover
		{
		case 1:
		{
			for (i; i < 8; i++)//Columnas //se recorren todas las celdas y  se comparan las coordenadas de las mismas con las del pinchazo (las coordenas de las celdas coinciden con (i,j))
			{
				j = 0;

				for (j; j < 8; j++)//Filas
				{
					if ((mousex < 594 - 55 * j) && (mousex > 539 - 55 * j) && (mousey < 494 - 55 * i) && (mousey > 439 - 55 * i) &&
						getOcupacion(i, j)) //true cuando se pincha en la celda (i,j) y esta ocupada
					{
						switch (turn)
						{
						case 1://Se ejecutan estas lineas si el turno es de las blancas
						{
							for (int h = 0; h < 12; h++)
							{
								if (getFicha_blanca_X(h) == i && getFicha_blanca_Y(h) == j && getFicha_blanca_DispMov(h))//se comprueba que ficha esta en la celda (i,j) y si se puede mover. En el caso de que no se pueda mover la fase del movimiento no cambia. De esta manera el siguiente pinchazo seleccionar?otra ficha
								{
									setFicha_aux(get_p_Ficha_blanca(h)); //obtienes un puntero a la ficha que quieres mover y se guarda en una variable auxiliar 
									//mundo.setFase_movimiento(false); //al haberse completado la primera fase del movimiento correctamente (se ha seleccionado una ficha del color que corresponde) se pone la fase en FALSE para que la próxima vez que se pinche se ejecute la seguna fase del movimiento
									//mundo.setTurno(2);	// se pone el turno dos (esto es irrelevante para le segunda fase del movimiento)	
									fase_movimento = 2;
									//turn = 2;

								}

							}
							break;
						}
						case 2: //Se ejecutan estas lineas si el turno es de las negras
						{
							for (int h = 0; h < 12; h++)
							{
								if (getFicha_negra_X(h) == i && getFicha_negra_Y(h) == j && getFicha_negra_DispMov(h))//se comprueba que ficha esta en la celda (i,j) y que esta se puede mover.En el caso de que no se pueda mover la fase del movimiento no cambia. De esta manera el siguiente pinchazo seleccionar?otra ficha
								{
									setFicha_aux(get_p_Ficha_negra(h)); // igual que en el turno de las blancas
									//mundo.setFase_movimiento(false);
									//mundo.setTurno(2);
									fase_movimento = 2;
									//turn = 1;
								}
							}
							break;
						}
						}
					}
				}
			}
			break;
		}
		case 2:
		{
			for (int k = 0; k < 8; k++)//Columnas
			{

				for (int l = 0; l < 8; l++)//Filas
				{
					getOcupacion(k, l);
					if ((mousex < 594 - 55 * l) && (mousex > 539 - 55 * l) && (mousey < 494 - 55 * k) && (mousey > 439 - 55 * k) &&
						(!getOcupacion(k, l))) // comprueba que el click esta en la celda (k,l) y que esta vacia
					{
						posicion_deseada.set(k, l); // se establece la posicion (k,l) como posicion deseada
						if (posicion_deseada == getFicha_aux()->getPosDisponible(0) || posicion_deseada == getFicha_aux()->getPosDisponible(1)) // se compara la posicion deseada con las dos posibles posiciones de la ficha seleccionada, si coincide con alguna se cambia la posicion de la ficha
						{
							ColorRGB negro, blanco;
							negro.set(78, 55, 49);
							blanco.set(182, 145, 112);
							Ficha* pnt = getFicha_aux(); // Se guarda la ficha que se quiere mover en un puntero auxiliar
							if (pnt->getColor() == negro) { turn = 1; }
							if (pnt->getColor() == blanco) { turn = 2; }
							int x_deso = pnt->getX(); //Guardas las coordenadas de la ficha antes de moverla para poder marcarla como desocuapda una vez la muevas
							int y_deso = pnt->getY(); // "                                      "                            "                       "
							pnt->setPos(posicion_deseada);//Estableces la posicion deseada como la nueva posición de la ficha que se quiere mover
							Celda* a_okupar = get_p_Celda(k, l); //Puntero a la celda que se quiere ocupar
							a_okupar->Ocupar_celda();//Se marca la celda a la que se va a mover la ficha como posicion deseada
							Celda* a_desokupar = get_p_Celda(x_deso, y_deso);//Puntero a la celda  que se quiere desocupar
							a_desokupar->Desocupar_celda(); //Se marca la celda de la que se ha movido la ficha como desocupada
							fase_movimento = 1; //Se pone la fase de movimiento a 1 para el siguiente pinchazo
							if (((int)x_deso - (int)posicion_deseada.getX()) % 2 == 0 && ((int)y_deso - (int)posicion_deseada.getY()) % 2 == 0 && ((int)x_deso - (int)posicion_deseada.getX()) != 0 && ((int)y_deso - (int)posicion_deseada.getY()) != 0)// TRUE cuando el movimiento es de comer 
							{

								if (posicion_deseada == getFicha_aux()->getPosDisponible(0)) //TRUE cuando el movimiento de comer que se ha realizado estaba almacenado en posiciones[0]
								{
									Vector3D AUX = getFicha_aux()->getMovDisponible(0); //se obtiene el movimiento de comer  que se ha realizado
									AUX.Dividir2();//se obtiene el movimiento que hay que hacer para llegar a la celda cuya ficha se va  a eliminar ya que ha sido comida
									Vector3D posicion_comida;
									float nX = x_deso + AUX.getX();// x de la celda en la que esta la ficha que se quiere comer
									float nY = y_deso + AUX.getY();// y de la celda en la que esta la ficha que se quiere comer
									posicion_comida.set(nX, nY);//se guarda en posicion_comida la posicion de la celda en la que est?la ficha que se quiere comer

									for (int h = 0; h < 12; h++) // for para obtener la ficha que ha sido comida
									{
										if (getFicha_negra_X(h) == nX && getFicha_negra_Y(h) == nY) // si la ficha es blanca
										{
											setFicha_comida(get_p_Ficha_negra(h));
											Ficha* pnt_comida = getFicha_comida();
											int x_deson = pnt_comida->getX(); //Guardas las coordenadas de la ficha antes de eliminarla para poder marcarla como desocuapda una vez la muevas
											int y_deson = pnt_comida->getY();
											getListaFichasN()->eliminar(h);
											Celda* a_desocupar = get_p_Celda(x_deson, y_deson);
											a_desocupar->Desocupar_celda();
										}
										if (getFicha_blanca_X(h) == nX && getFicha_blanca_Y(h) == nY)// si la ficha es negra
										{
											setFicha_comida(get_p_Ficha_blanca(h));
											Ficha* pnt_comida = getFicha_comida();
											int x_desob = pnt_comida->getX(); //Guardas las coordenadas de la ficha antes de eliminarla para poder marcarla como desocuapda una vez la muevas
											int y_desob = pnt_comida->getY();
											getListaFichasB()->eliminar(h);
											Celda* a_desocupar = get_p_Celda(x_desob, y_desob);
											a_desocupar->Desocupar_celda();

										}

									}
								}
								if (posicion_deseada == getFicha_aux()->getPosDisponible(1)) //TRUE cuando el movimiento de comer que se ha realizado estaba almacenado en posiciones[0]
								{
									Vector3D AUX = getFicha_aux()->getMovDisponible(1); //se obtiene el movimiento de comer  que se ha realizado
									AUX.Dividir2();//se obtiene el movimiento que hay que hacer para llegar a la celda cuya ficha se va  a eliminar ya que ha sido comida
									Vector3D posicion_comida;
									float nX = x_deso + AUX.getX();// x de la celda en la que esta la ficha que se quiere comer
									float nY = y_deso + AUX.getY();// y de la celda en la que esta la ficha que se quiere comer
									posicion_comida.set(nX, nY);//se guarda en posicion_comida la posicion de la celda en la que est?la ficha que se quiere comer

									for (int h = 0; h < 12; h++) // for para obtener la ficha que ha sido comida
									{
										if (getFicha_negra_X(h) == nX && getFicha_negra_Y(h) == nY) // si la ficha es blanca
										{
											setFicha_comida(get_p_Ficha_negra(h));
											Ficha* pnt_comida = getFicha_comida();
											int x_deson = pnt_comida->getX(); //Guardas las coordenadas de la ficha antes de eliminarla para poder marcarla como desocuapda una vez la muevas
											int y_deson = pnt_comida->getY();
											getListaFichasN()->eliminar(h);
											Celda* a_desocupar = get_p_Celda(x_deson, y_deson);
											a_desocupar->Desocupar_celda();
										}
										if (getFicha_blanca_X(h) == nX && getFicha_blanca_Y(h) == nY)// si la ficha es negra
										{
											setFicha_comida(get_p_Ficha_blanca(h));
											Ficha* pnt_comida = getFicha_comida();
											int x_desob = pnt_comida->getX(); //Guardas las coordenadas de la ficha antes de eliminarla para poder marcarla como desocuapda una vez la muevas
											int y_desob = pnt_comida->getY();
											getListaFichasB()->eliminar(h);
											Celda* a_desocupar = get_p_Celda(x_desob, y_desob);
											a_desocupar->Desocupar_celda();
											int a = 2;
										}

									}
								}

							}
						}

					}
				}
			}
			break;
		}
		}



	}
}

bool Mundo::Getmarcador()
{
	ListaFichas* blancas = getListaFichasB();
	ListaFichas* negras = getListaFichasN();
	int quedan_b = blancas->getNumero();
	int quedan_n = negras->getNumero();
	if (quedan_b == 4 || quedan_n == 4)
		return true;
	else return false;
	
	
}


int Mundo::ganador()
{
	ListaFichas* blancas = getListaFichasB();
	ListaFichas* negras = getListaFichasN();
	int quedan_b = blancas->getNumero();
	int quedan_n = negras->getNumero();
	if (quedan_b == 4)
	{
		return 1;

	}
	else if (quedan_n == 4)
	{
		return 2;
	}
}


