#pragma once
#include "freeglut.h"
typedef unsigned char Byte;
class ColorRGB
{
public:
	Byte r, g, b;
	ColorRGB(Byte red = 255, Byte green = 255, Byte blue = 255) {
		set(red, green, blue);
	};
	void set(Byte red, Byte green, Byte blue) {
		r = red; g = green; b = blue;
	}
	void ponColor() {
		glColor3ub(r, g, b);
	};
	bool operator == (ColorRGB segundo)
	{
		if ((r == segundo.r) && (g == segundo.g) && (b == segundo.b))
			return true;
		else return false;
	}
	
};