#pragma once
#include "ColorRGB.h"
#include "Vector3D.h"
class Ficha
{
private:
	float radio;
	float altura;
	ColorRGB color;
	float xRot;
	float yRot;
	float zRot;
	Vector3D posicion;
	Vector3D movimientos[2];// movimientos[0] -> Derecha (respecto de la persona que mira la pantalla) movimientos[1] -> Izquierda (0,0)->No se puede mover (1,1)->movimiento básico (2,2)->movimiento para comer
	Vector3D posiciones[2]; //posiciones[0] -> Derecha (respecto de la persona que mira la pantalla) posiciones[1] -> Izquierda (posiciones que estando en la celda (i,j) puede alcanzar la ficha teniendo en cuenta los movimientos
public:
	Ficha();
	~Ficha();
	Ficha(int i, int j, unsigned char r, unsigned char v, unsigned char a);
	void setColor(unsigned char r, unsigned char v, unsigned char a);
	void setAltura(float altura);
	void setMovimiento(int i, Vector3D movimiento) { movimientos[i] = movimiento; }
	void setPos(float x, float y, float z);
	void setPos_Z(float z) { posicion.set_Z(z); }
	void setPos(Vector3D nueva_pos) { posicion.set(nueva_pos); };
	void dibujarCilindro();
	void dibujarCirculo();
	bool DispMovimientos();//TRUE si la ficha tiene movimientos disponibles
	void PosicionesDisp(); // Establece las posiciones disponibles a partir de los movimientos obtenidos en Tablero:: GetMov()

	float getX() { return posicion.getX(); };
	float getY() { return posicion.getY(); };
	float getZ() { return posicion.getZ(); };
	Vector3D getPos() { return posicion; };
	ColorRGB getColor() { return color; };
	Vector3D getPosDisponible(int i) { return posiciones[i]; };
	Vector3D getMovDisponible(int i) { return movimientos[i]; };
	void Dibuja();
};

