#include "RgbLed.h"
#include "Arduino.h"

RgbLed::RgbLed(int pinR, int pinG, int pinB)
: _pinR(pinR), _pinG(pinG), _pinB(pinB) 
{
	_color = Color();
}

void RgbLed::setColor(unsigned char r, unsigned char g, unsigned char b) {
	_color.setColor(r,g,b);
}

void RgbLed::update() {
	analogWrite(_pinR, 255 - _color.r());
	analogWrite(_pinG, 255 - _color.g());                   
	analogWrite(_pinB, 255 - _color.b());
}


