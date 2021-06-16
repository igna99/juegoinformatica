#include "Vector3D.h"
Vector3D::Vector3D()
{
	x = y = z = 0;
}
bool Vector3D:: operator==(Vector3D primero)
{
	if (x == primero.x && y == primero.y) return true;
	else return false;
}