#include "Tablero.h"
Tablero::Tablero()
{
	//Inicializacion de las celdas
	int i = 0;
	int j = 0;
	for ( i; i < 8; i++)//Columnas
	{
		float y = i * celda_tablero[1][1].getLado();
		j=0;
		for (  j ; j < 8; j++)//Filas
		{
			float x = j * celda_tablero[i][j].getLado();
			celda_tablero[i][j].setPos(y, x, 0);

			
			if ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1))
			{
				
				celda_tablero[i][j].setColor(241, 241, 209);
			}
			else 
			{
				
				celda_tablero[i][j].setColor(18, 19, 24);
			}
			
		}
	}
	 i = 0;
	 j = 0;
	int num_ficha = 0;
	int contador = 0;
	
	// recorrido por las filas y las columnas para colocar la fichas negras
	for (i; i < 8; i++)//Columnas
	{
		j = 0;

		for (j; j < 3; j++)//Filas
		{
			if (!(contador % 2))//para hacer el patron inicial de la colocación fichas
			{
				num_ficha = (contador / 2);
				//fichas_negras[num_ficha].setPos(j, i, 0); //establece la posicion de la ficha
				//fichas_negras[num_ficha].setColor(78, 55, 49); //establece el color de la ficha
				Ficha* aux = new Ficha(j,i,78,55,49);
				fichas_negras.agregar(aux);
				celda_tablero[j][i].Ocupar_celda(); //marca la celda que toque como ocupada
			}
			contador++;
		}

	}
	contador = 1;
	num_ficha = 0;
	i = 0;
	// recorrido por las filas y las columnas para colocar la fichas blancas
	for (i; i < 8; i++)//Columnas
	{
		j = 5;

		for (j; j < 8; j++)//Filas
		{
			if (!(contador % 2))//para hacer el patron inicial de la colocación fichas
			{
				num_ficha = (contador / 2) - 1;
				Ficha* aux = new Ficha(j, i, 182, 145, 112);
				fichas_blancas.agregar(aux);
				celda_tablero[j][i].Ocupar_celda(); //marca la celda que toque como ocupada
			}
			contador++;
		}
	}


}

void Tablero::Dibuja()
{

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			celda_tablero[i][j].Dibuja();
		}
	}
	fichas_blancas.Dibuja();
	fichas_negras.Dibuja();
	getMov();
	getPosDisponibles();
	for (int k = 0; k < 8; k++)//Columnas
	{

		for (int l = 0; l < 8; l++)//Filas
		{
			getOcupacion(k, l);
		}
	}
}
void Tablero::getMov()
{
	for (int  i = 0; i <fichas_blancas.getNumero(); i++)
	{

		getMovFichaB(fichas_blancas.get_p_ficha(i));
		
	}
	for (int i = 0; i < fichas_negras.getNumero(); i++)
	{

		
		getMovFichaN(fichas_negras.get_p_ficha(i));
	}
}
Tablero:: ~Tablero()
{
	fichas_blancas.destruirContenido();
    fichas_negras.destruirContenido();
}

void Tablero::getPosDisponibles()
{

	fichas_blancas.getPos_disp();
	fichas_negras.getPos_disp();

}

void Tablero::getMovFichaN(Ficha* ficha)
{
	Vector3D movimiento;
	ColorRGB negro;
	negro.set(78, 55, 49);// variable para realiza la comprobacion
	/////////////////MOVIMIENTO HACIA LA DERECHA y<0
	if ((ficha->getX() == 7) || (ficha->getY() ==0)) //comprueba que la ficha no esta ni en al fila de mas arriba ni en la columna mas a la derecha. Si se  da el caso el movimiento 1 pasa a ser (0,0)
	{
		movimiento.set(0, 0);
		ficha->setMovimiento(0, movimiento);

	}
	else // en el caso de que la ficha no se encuentre en la fila de mas arriba ni en la columna de mas a la derecha se comprueban los demás movimientos posibles
	{
		if (celda_tablero[(int)(ficha->getX() + 1)][(int)ficha->getY() - 1].getOcupacion())//(IF TRUE SI ESTA OCUPADA) comprueba que la primera celda en diagonal a la derecha esta ocuapada. Si esta vacia ->else
		{
			if (ficha->getX() > 5 || ficha->getY() < 2) // copmrueba que la  ficha esta en la penultima columna. Si lo esta (IF TRUE) la ficha no se puede mover. Si no lo esta (IF FALSE) se sigue haciendo comprobaciones
			{
				movimiento.set(0, 0);
				ficha->setMovimiento(0, movimiento);
			}
			else// la ficha no est?ni en la segunda columna mas  a la derecha ni en la penúltima fila por lo que se siguen haciendo comprobaciones
			{
				if (getColorFichaCelda((int)(ficha->getX()+ 1), (int)(ficha->getY() - 1)) == negro)//Comprueba el color de  ficha que ocupa la celda [+1][-1]. Si es negra (IF = TRUE) se determina el movimiento 1 como (0,0) (la ficha no se puede mover porque no se puede comer una ficha del mismo color que el de la que come)
				{
					movimiento.set(0, 0);
					ficha->setMovimiento(0, movimiento);
				}
				else// al no ser la ficha negra hay que comprobar que la celda [+2][-2] esta vacia si est?vacía el moviemiento 1 ser?(2,-2) en el caso contrario sera (0,0)
				{
					if (celda_tablero[(int)(ficha->getX() + 2)][(int)ficha->getY()- 2].getOcupacion())//(IF TRUE SI ESTA OCUPADA)comprueba la ocupacion de la celda (+2,-2). Si esta ocupada la ficha no podría moverser por lo que el movimiento 1 ser?(0,0). Si esta vacía -> else
					{
						movimiento.set(0, 0);
						ficha->setMovimiento(0, movimiento);
					}
					else // al estar la celda vacía la ficha se puede mover para comer. El movimiento 1 ser?(2,-2)
					{
							movimiento.set(2, -2);
							ficha->setMovimiento(0, movimiento);
					}
				}

			}
			
		}
			
		else // la celda [+1][-1]esta vacia por lo que se determina el movimiento de tipo mover (1,-1).
		{
			movimiento.set(1, -1);
			ficha->setMovimiento(0, movimiento);
		}

		
	}
	//////////////////////////////////////////MOVIMIENTO HACIA LA IZQUIERDA Y>0
	if ((ficha->getX() == 7) || (ficha->getY() == 7)) //comprueba que la ficha no esta ni en al fila de mas arriba ni en la columna mas a la izquierda. Si se  da el caso el movimiento 1 pasa a ser (0,0)
	{
		movimiento.set(0, 0);
		ficha->setMovimiento(1, movimiento);

	}
	else // en el caso de que la ficha no se encuentre en la fila de mas arriba ni en la columna de mas a la derecha se comprueban los demás movimientos posibles
	{
		if (celda_tablero[(int)(ficha->getX() + 1)][(int)ficha->getY() + 1].getOcupacion())//(IF TRUE SI ESTA OCUPADA) comprueba que la primera celda en diagonal a la derecha esta ocuapada. Si esta vacia ->else
		{
			if (ficha->getX()>5 || ficha->getY() > 5) // copmrueba que la  ficha esta en la penultima columna o la penultima fila. Si lo esta (IF TRUE) la ficha no se puede mover. Si no lo esta (IF FALSE) se sigue haciendo comprobaciones
			{
				movimiento.set(0, 0);
				ficha->setMovimiento(1, movimiento);
			}
			else // la ficha no esta en la penúltima fila ni en la penúltima columna por lo que se siguen haciendo las comprobaciones
			{
				if (getColorFichaCelda((int)(ficha->getX() + 1), (int)(ficha->getY() + 1)) == negro)//Comprueba el color de  ficha que ocupa la celda [+1][+1]. Si es negra (IF = TRUE) se determina el movimiento 1 como (0,0) (la ficha no se puede mover)
				{
				movimiento.set(0, 0);
				ficha->setMovimiento(1, movimiento);
				}
				else// al no ser la ficha negra hay que comprobar que la celda [+2][+2] esta vacia si est?vacía el moviemiento 1 ser?(2,2) en el caso contrario sera (0,0)
				{
					if (celda_tablero[(int)(ficha->getX() + 2)][(int)ficha->getY() + 2].getOcupacion())//(IF TRUE SI ESTA OCUPADA)comprueba la ocupacion de la celda [+2][+2]. Si esta ocupada la ficha no podría moverser por lo que el movimiento 1 ser?(0,0). Si esta vacía -> else
					{
						movimiento.set(0, 0);
						ficha->setMovimiento(1, movimiento);
					}
					else // al estar la celda [+2][+2] vacía la ficha se puede mover para comer. El movimiento 1 ser?(2,2)
					{
						movimiento.set(2, 2);
						ficha->setMovimiento(1, movimiento);
					}
				}

			}

		}

		else // la celda (+1,+1) esta vacia por lo que se determina el movimiento de tipo mover (1,1).
		{
			movimiento.set(1, 1);
			ficha->setMovimiento(1, movimiento);
		}


	}
}
void Tablero::getMovFichaB(Ficha* ficha)
{
	Vector3D movimiento;
	ColorRGB	blanco;
	blanco.set(182, 145, 112);// variable para realizar la comprobacion
	/////////////////MOVIMIENTO HACIA LA DERECHA (DESDE EL PUNTO DE VISTA DEL JUGADOR QUE MIRA LA PANTALLA) y<0
	if ((ficha->getY() == 0) || (ficha->getX() == 0)) //comprueba que la ficha no esta ni en al fila de mas abajo ni en la columna mas a la derecha. Si se  da el caso el movimiento 1 pasa a ser (0,0)
	{
		movimiento.set(0, 0);
		ficha->setMovimiento(0, movimiento);
	}
	else // en el caso de que la ficha no se encuentre en la fila de mas arriba ni en la columna de mas a la derecha se comprueban los demás movimientos posibles
	{
		if (celda_tablero[(int)(ficha->getX()- 1)][(int)ficha->getY() - 1].getOcupacion())//(IF TRUE SI ESTA OCUPADA) comprueba que la primera celda en diagonal a la derecha esta ocuapada. Si esta vacia ->else
		{
			if (ficha->getX() < 2 || ficha->getY() < 2) // comprueba que la  ficha esta en la penultima columna o penultima fila. Si lo esta (IF TRUE) la ficha no se puede mover. Si no lo esta (IF FALSE) se sigue haciendo comprobaciones
			{
				movimiento.set(0,0);
				ficha->setMovimiento(0, movimiento);
			}
			else //la ficha no est?en la penúltima columna o en la penúltima fila por lo que se siguen haciendo comprobaciones
			{
				if (getColorFichaCelda((int)(ficha->getX() - 1), (int)(ficha->getY()- 1)) == blanco)//Comprueba el color de  ficha que ocupa la celda [-1][-1]. Si es blanca (IF = TRUE) se determina el movimiento 1 como (0,0) (la ficha no se puede mover porque no se puede comer una ficha del mismo color que la que come)
				{
				movimiento.set(0, 0);
				ficha->setMovimiento(0, movimiento);
				}
				else// al no ser la ficha blanca hay que comprobar que la celda [-2][-2] esta vacia si est?vacía el moviemiento 1 ser?(2,2) en el caso contrario sera (0,0)
				{
					if (celda_tablero[(int)(ficha->getX()- 2)][(int)ficha->getY()- 2].getOcupacion())//(IF TRUE SI ESTA OCUPADA)comprueba la ocupacion de la celda [+2][+2]. Si esta ocupada la ficha no podría moverser por lo que el movimiento 1 ser?(0,0). Si esta vacía -> else
					{
						movimiento.set(0, 0);
						ficha->setMovimiento(0, movimiento);
					}
					else // al estar la celda vacía la ficha se puede mover para comer. El movimiento 1 ser?(-2,-2)
					{
						movimiento.set(-2, -2);
						ficha->setMovimiento(0, movimiento);
					}
				}

			}

		}

		else // la celda (-1,-1) esta vacia por lo que se determina el movimiento de tipo mover (-1,-1).
		{
			movimiento.set(-1,-1);
			ficha->setMovimiento(0, movimiento);
		}


	}
	//////////////////////////////////////////MOVIMIENTO HACIA LA IZQUIERDA Y>0
	if ((ficha->getX() == 0) || (ficha->getY() == 7)) //comprueba que la ficha no esta ni en al fila de mas abajo ni en la columna mas a la izquierda. Si se  da el caso el movimiento 1 pasa a ser (0,0)
	{
		movimiento.set(0, 0);
		ficha->setMovimiento(1, movimiento);

	}
	else // en el caso de que la ficha no se encuentre en la fila de mas arriba ni en la columna de mas a la derecha se comprueban los demás movimientos posibles
	{
		if (celda_tablero[(int)(ficha->getX() - 1)][(int)ficha->getY() + 1].getOcupacion())//(IF TRUE SI ESTA OCUPADA) comprueba que la primera celda en diagonal a la izquierda esta ocuapada. Si esta vacia ->else
		{
			if (ficha->getX()< 2 || ficha->getY() > 5) // comprueba que la  ficha esta en la penultima columna. Si lo esta (IF TRUE) la ficha no se puede mover. Si no lo esta (IF FALSE) se sigue haciendo comprobaciones
			{
				movimiento.set(0, 0);// se podria modificar para que comiera
				ficha->setMovimiento(1, movimiento);
			}
			else
			{
				ColorRGB prueba = getColorFichaCelda((int)((ficha->getX()) - 1), (int)(ficha->getY() + 1));
				if (prueba == blanco)//HAY QUE SOBRECARGAR EL OPERADOR == Comprueba el color de  ficha que ocupa la celda [-1][+1]. Si es blanca (IF = TRUE) se determina el movimiento 1 como (0,0) (la ficha no se puede mover, porque no puede comerser un ficha del mismo color que la que come)
				{
				movimiento.set(0, 0);
				ficha->setMovimiento(1, movimiento);
				}
				else// al no ser la ficha blanca hay que comprobar que la celda [-2][+2] esta vacia si est?vacía el moviemiento 1 ser?(-2,2) en el caso contrario sera (0,0)
				{
					if (celda_tablero[(int)(ficha->getX() - 2)][(int)ficha->getY() + 2].getOcupacion())//(IF TRUE SI ESTA OCUPADA)comprueba la ocupacion de la celda [-2][+2]. Si esta ocupada la ficha no podría moverser por lo que el movimiento 1 ser?(0,0). Si esta vacía -> else
					{
						movimiento.set(0, 0);
						ficha->setMovimiento(1, movimiento);
					}
					else // al estar la celda vacía la ficha se puede mover para comer. El movimiento 1 ser?(-2,2)
					{
						movimiento.set(-2, 2);
						ficha->setMovimiento(1, movimiento);
					}
				}

			}

		}

		else // la celda [-1][+1] esta vacia por lo que se determina el movimiento de tipo mover (-1,1).
		{
			movimiento.set(-1, 1);
			ficha->setMovimiento(1, movimiento);
		}


	}
}
ColorRGB Tablero::getColorFichaCelda(int i, int j) {

	for (int k = 0; k < 12; k++) //recorre las fichas blancas buscando una coincidencia con la celda (i,j) que se le ha pasado a la funcion
	{
		if (fichas_blancas.get_p_ficha(k)->getX() == i && fichas_blancas.get_p_ficha(k)->getY() == j) {
			return fichas_blancas.get_p_ficha(k)->getColor(); // devuelve el color de la ficha
			k=12;
		}
	}
	for (int k = 0; k < 12; k++) //recorre las fichas negras buscando una coincidencia con la celda (i,j) que se le ha pasado a la funcion
	{
		if (fichas_negras.get_p_ficha(k)->getX() == i && fichas_negras.get_p_ficha(k)->getY() == j) {
			return fichas_negras.get_p_ficha(k)->getColor(); // devuelve el color de la ficha
			k = 12;
	}
}


}

Ficha* Tablero::get_p_Ficha_blanca(int i)
{
	return fichas_blancas.get_p_ficha(i);
}
Ficha* Tablero::get_p_Ficha_negra(int i)
{
	return fichas_negras.get_p_ficha(i);
}
Celda* Tablero::get_p_Celda(int i, int j)
{
	Celda* puntero;
	puntero = &celda_tablero[i][j];
	return puntero;
}