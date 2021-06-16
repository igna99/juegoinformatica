#include "ListaFichas.h"
bool ListaFichas::agregar(Ficha* f)
{
	for (int i = 0; i <= numero; i++)
	{
		if (f == lista[numero])
		{
			return false;
		}
	}
	if (numero < MAX_FICHAS)
		lista[numero++] = f; // último puesto sin rellenar
	else
		return false; // capacidad máxima alcanzada
	return true;
}
void ListaFichas::Dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->Dibuja();
}
void ListaFichas::getPos_disp()
{
		for (int i = 0; i < numero; i++)
		lista[i]->PosicionesDisp();

}
void ListaFichas::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}
void ListaFichas::destruirContenido()
{
	for (int i = 0; i < numero; i++) // destrucci¨®n de esferas contenidas
		delete lista[i];
	numero = 0; // inicializa lista
}

