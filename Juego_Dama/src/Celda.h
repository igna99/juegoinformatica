#pragma once
#include "ColorRGB.h"
#include "Vector3D.h"
class Celda
{
private:
	float lado=1;
	ColorRGB color;
	bool ocupada= false; //true si esta ocupada
	Vector3D posicion; //esquina inferior izquierda de la celda 
public:
	void setColor(unsigned char r, unsigned char v, unsigned char a);
	void setPos(float x, float y, float z);
	void Dibuja();
	float getLado();
	Vector3D getPos();
	float getX() { return posicion.getX(); }; //devuelve la coordenada x de la celda
	float getY() { return posicion.getY(); }; //devuelve la coordenada y de la celda
	void Ocupar_celda() { ocupada = true; }; //marca la celda como ocupada
	void Desocupar_celda() { ocupada = false; };//marca la celda como desocupada
	bool getOcupacion() { return ocupada; };// true si est?ocupada
};

