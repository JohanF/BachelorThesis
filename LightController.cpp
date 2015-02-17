#include "LightController.h"
#include "Arduino.h"
LightController::LightController(DecayController* decay, PointController* point,
	ColorController* color)
{
    
    _decay = decay;
    _point = point;
    _color = color;    
	_led_1 = new RgbLed (7,6,5);
	_led_2 = new RgbLed (10,9,8);
	_led_3 = new RgbLed (13,12,11);
	_old_1 = 1;
	_old_2 = 1;
	_old_3 = 1;
	
}

void LightController::update(){
	_decay->update();
	_point->update();
	//Update the color, decay and point intensity values
	float decay = _decay->getDecay();
	float* prop = _point->getPoint();
	_light = _color->getColor();

	//The new intensity, decay*where the point is.

	float int_1 = prop[0]*decay;
	float int_2 = prop[1]*decay;
	float int_3 = prop[2]*decay;

	float diff = 0.001;

	//A more smooter change of intensity
	if((int_1 - _old_1) > 0)
		changeColorUp(_old_1,int_1, diff, _led_1);
	else
		changeColorDown(_old_1,int_1, diff, _led_1);

	if((int_2 - _old_2) > 0)
		changeColorUp(_old_2,int_2, diff, _led_2);
	else
		changeColorDown(_old_2,int_2, diff, _led_2);

	if((int_3 - _old_3) > 0)
		changeColorUp(_old_3,int_3, diff, _led_3);
	else
		changeColorDown(_old_3,int_3, diff, _led_3);

	_old_1 = int_1;
	_old_2 = int_2;
	_old_3 = int_3;
}

void LightController::changeColorUp(float start, float stop, float diff, RgbLed* led)
{
	for(float i = start; i <= stop; i+=diff){
		led->setColor(_light->r()*i,_light->g()*i,_light->b()*i);
		led->update();
	}
}
void LightController::changeColorDown(float start, float stop, float diff, RgbLed* led)
{
	for(float i = start; i >= stop; i-=diff){
		led->setColor(_light->r()*i,_light->g()*i,_light->b()*i);
		led->update();
	}
}
