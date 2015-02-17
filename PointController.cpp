#include "PointController.h"
#include <math.h>

PointController::PointController(WindSensor* wind)
{
	led_1 = new Vector(0, MAX_RADIUS);
	led_2 = new Vector(120, MAX_RADIUS);
	led_3 = new Vector(240, MAX_RADIUS);
	point = new Vector(0, MAX_RADIUS*0.4);

	_time = millis();
	_radiusTime = millis();
	_dir = 1;
	_wind = wind;
	_isOff = false;

}

float*
PointController::getPoint()
{
	return _intensity;
}

void PointController::update()
{
	//If the point movment is off, then return full intensity on all three leds
	if(_isOff)
	{
		_intensity[0] = 1;
		_intensity[1] = 1;
		_intensity[2] = 1;
		return;
	}
	
	//To get a "random" movment of the point vector, we change the direction and length
	//of the vector
	float newDegree = point->getDegree() + direction()*5;//5
	point->setDegree(newDegree);

	if(millis() - _radiusTime > 1000){
		//Change the radius of the point vector
		point->setRadius(newRadius(point->getRadius()));
		_radiusTime = millis();
	}
	
	//Calculate the new proportions for the point vector to the three led vectors
	calculate();
	
}


void PointController::calculate()
{
	//Calculate the distance to all leds
	float length_1 = led_1->getDistance(point);
	float length_2 = led_2->getDistance(point);
	float length_3 = led_3->getDistance(point);
	float max_Distance = 2*MAX_RADIUS;

	//Calculate the intesity
	_intensity [0] = 1.0 - length_1/max_Distance;
	_intensity [1] = 1.0 - length_2/max_Distance;
	_intensity [2] = 1.0 - length_3/max_Distance;

}


char PointController::newRadius(char radius)
{
	//Calculate the new radius, eighter it will increase, decrease or stay the same
	//unless the maximun or minimul values is reached
	if(radius == MAX_RADIUS*0.8)//0.8
		return radius+((char)random(0,2)-1);
	else if(radius == MAX_RADIUS*0.3)//0.3
		return radius + (char)random(0,2);
	else
		return radius + (char)(random(0,3)-1);
}

char PointController::direction()
{
	//Change the direction the point vector is rotating in
	//90 % change of direction staying the same
	char temp = random(0,10);
	if(!(temp < 9)){
		if(millis() - _time > 500){
			_dir = -_dir;
			_time = millis();
		}
	}

	return _dir;
	
}



void PointController::setOff()
{
	_isOff = true;
}

void PointController::setOn()
{
	_isOff = false;
}

