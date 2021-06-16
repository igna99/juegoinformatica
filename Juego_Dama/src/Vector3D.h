#pragma once
class Vector3D
{
private:
	float x;
	float y;
	float z;

public:
	Vector3D();
	void set(float xi, float yi) { x = xi; y = yi; };
	void set(Vector3D dato) { x = dato.x, y = dato.y, z = dato.z; };
	void set_Z(float nz) { z = nz; }
	bool operator == (Vector3D primero);
	float getX() { return x; };
	float getY() { return y; };
	float getZ() { return z; };
	void Dividir2() { x = x / 2; y = y / 2; }
};