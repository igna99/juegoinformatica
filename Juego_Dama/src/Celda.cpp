#include "Celda.h"
void Celda::setColor(unsigned char r, unsigned char v, unsigned char a)
{
	color.set(r, v, a);
}

void Celda::setPos(float x, float y, float z)
{
	posicion.set(x, y);
}
Vector3D Celda::getPos()
{
	return posicion;
}

void Celda::Dibuja()
{
	glDisable(GL_LIGHTING);
	glColor3ub(color.r, color.g, color.b);
	glBegin(GL_POLYGON);
	float supiz = posicion.getX() + lado;
	float supdch = posicion.getY() + lado;
	glVertex3f(posicion.getX(), posicion.getY(), 0.0f); 
	glVertex3f(posicion.getX(), supdch, 0.0f);
	glVertex3f(supiz, supdch, 0.0f);
	glVertex3f(supiz, posicion.getY(), 0.0f);
	glEnd();
	glEnable(GL_LIGHTING);
}
float Celda::getLado()
{
	return lado;
}

