#include "Color.h"
#include "Arduino.h"

Color::Color()
: _r(0), _g(0), _b(0) 
{
}

Color::Color(unsigned char r, unsigned char g, unsigned char b)
: _r(r), _g(g), _b(b) 
{
}

Color& 
Color::operator= (const Color& other) {
  	if (this != &other) {
		_r = other.r();
		_g = other.g();
		_b = other.b();
	}

	return *this;
}

void Color::setColor(unsigned char r, unsigned char g, unsigned char b)
{
	_r = r;
	_g = g;
	_b = b;
}
