#include "ColorController.h"

ColorController::ColorController( BatteryController* battery)
: _battery(battery){
	_r = 255;
	_g = 125;
	_b = 14;
	_color.setColor(_r,_g,_b);

}


void ColorController::update(){


	_battery->update();
	//If the battery has enough power left, then we do nothing,
	// otherwise we start to change the color to a more blue ish color
	if(!_battery->isOk())
	{
		//How much battery left until it's time to change
		float ratio = (_battery->value() - _battery->stopValue())/100.0;
		ratio = constrain(ratio, 0.0, 1.0);
		if(ratio > 0)
			_color.setColor(ratio*_r, ratio*_g,_b);
		else //The battery is out
			_color.setColor(0,0,_b*0.7);
	}else
		_color.setColor(_r,_g,_b);
}

Color*
ColorController::getColor()
{
	return &_color;
}
void ColorController::setColor(unsigned char r, unsigned char g,unsigned char b){
  
  _r = r;
  _g = g;
  _b = b;
}
