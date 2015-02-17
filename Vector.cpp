#include "Vector.h"
#include <math.h>
#include "Arduino.h"

Vector::Vector(){
	_degree = 0;
	_radius = 1;
	_x = 0;
	_y = 0;
}

Vector::Vector(short degree, char radius){

	_degree = degree;
	_radius = radius;
	calculate();

}


void Vector::setDegree(short degree){
	if(degree == 360)
		degree = 0;
	_degree = degree;
	calculate();
}

void Vector::setRadius(char radius){
	if(radius > MAX_RADIUS)
		radius = MAX_RADIUS;
	_radius = radius;
	calculate();
}


float Vector::getDistance(Vector* v){
	float tempX = _x - v->x();
	float tempY = _y - v->y();
	float temp = sqrt(tempX*tempX + tempY*tempY);
	return temp;
}
void Vector::calculate(){
	//Calculate the x and y coordinates
	_x = _radius*cos(_degree*((float)M_PI)/180.0);
	_y = _radius*sin(_degree*((float)M_PI)/180.0);

}

