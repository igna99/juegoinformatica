#include "Ficha.h"
#include <math.h>
Ficha::Ficha()
{
    color.set(255, 255, 255);
}

Ficha::~Ficha()
{

}
Ficha::Ficha(int i, int j, unsigned char r, unsigned char v, unsigned char a)
{
    setColor(r, v, a);
    setPos(i, j, 0);
    
}

void Ficha::setColor(unsigned char r, unsigned char v, unsigned char a)
{
	color.set(r, v, a);
}
void Ficha::setAltura(float altura)
{
	this->altura = altura;
}
void Ficha::setPos(float x, float y, float z)
{
    posicion.set(x, y);
}

void Ficha::Dibuja()
{
    glColor3ub(color.r, color.g, color.b);
    glTranslatef(posicion.getX() + 0.5, posicion.getY() + 0.5, 0);
    glutSolidSphere(0.325, 20, 20);
    glTranslatef(-(posicion.getX() + 0.5), -(posicion.getY() + 0.5), 0);
}
void Ficha::dibujarCilindro()
{
   
        
        glBegin(GL_QUAD_STRIP);
        int i = 0;
        for (i = 0; i <= 360; i += 15)
        {
            float p = i * 3.14 / 180;
            glVertex3f(sin(p), cos(p), 1.0f);
            glVertex3f(sin(p), cos(p), 0.0f);
        }
        glEnd();
        //bottom circle
        glColor3f(1, 0, 0);
        dibujarCirculo();
        glTranslatef(0, 0, 1);
        //top circle
        glColor3f(0, 0, 1);
        dibujarCirculo();
        glColor3f(0, 1, 0);
    }

void Ficha::dibujarCirculo()
{
    glBegin(GL_TRIANGLE_FAN);           
    glVertex3f(0.0f, 0.0f, 0.0f);
    int i = 0;
    for (i = 0; i <= 360; i += 15)
    {
        float p = i * 3.14 / 180;
        glColor3f(sin(p), cos(p), tan(p));
        glVertex3f(sin(p), cos(p), 0.0f);
    }
    glEnd();
}
bool Ficha::DispMovimientos()
{
    Vector3D movimiento_nulo;
    if (movimientos[0] == movimiento_nulo && movimientos[1] == movimiento_nulo) //se comparan los dos movimientos almacenados si los dos son (0,0) la ficha no se puede mover return-> FALSE
        return false;
    else return true;
}
void Ficha::PosicionesDisp()
{
    posiciones[0].set(posicion.getX() + movimientos[0].getX(), posicion.getY() + movimientos[0].getY()); // se le suma a la posición actual el movimiento disponible. Posición a la derecha de la pieza respecto del jugador que mira la pantalla
    posiciones[1].set(posicion.getX() + movimientos[1].getX(), posicion.getY() + movimientos[1].getY()); // se le suma a la posición actual el movimiento disponible. Posición a la izquierda de la pieza respecto del jugador que mira la pantalla

}