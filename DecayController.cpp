#include "DecayController.h"
#include "Arduino.h"
#include "Math.h"

#define RAND() (random(0,1000)/1000.0)


DecayController::DecayController(WindSensor* wind) 
: _wind(wind), _pos(0), _vel(0),_sensitivity(1)
{	
}


void
DecayController::update() {


		const float windFactor = 0.7;
		const float randPosFactor = 0.10;

		const float springStiffness = 5.0;
		const float springDampning = 0.25;//0.30

		const float mass = 0.05;
		const float deltaTime = 1 / 30.0;
		int k;

		

		if(_isOff)
		{
			_intensity = 1;
			return;
		}
		
		_wind->update();
		if(_wind->isBlownOut())
		{
			_intensity = 0;
			return;
		}
		float wind = _wind->value() / 255.0*_sensitivity;
		float windDir = _wind->isIncreasing() ? 1 : 0;
		
	
		if (windDir)
		{
			_vel = 0;
			k = springStiffness;
		} else
			k = 6;
	

		double windAngle = (RAND() - 0.5) * M_PI * 0.25;
		double force = cos(windAngle) * windDir * wind +
			RAND() * (windFactor * windDir + 0.15);

		// Apply spring forces.
		force += -k * _pos - springDampning * _vel;

		// Euler integration.
		_vel += force / mass * deltaTime;
		_pos += _vel * deltaTime;

		windDir = !windDir;

		_pos += (RAND() - 0.7) * windDir * _vel * randPosFactor;

		// Calculate light intensity.
		_intensity = (1 - _pos) * (1 - _pos) - 0.02;
		_intensity = constrain(_intensity, 0.0, 1.0);
	/*	
		Serial.write(_wind->value());
		Serial.write(_wind->value() >> 8);
		Serial.write((unsigned char)constrain((int)255 * intensity, 0, 255));
*/
}

float
DecayController::getDecay()
{
	return _intensity;
}
void
DecayController::setOff()
{
	_isOff = true;

}

void 
DecayController::setOn()
{
	_isOff = false;
}

void
DecayController::setOut()
{
	_isOff = false;
	_sensitivity = 0.3;
}

void
DecayController::setIn()
{
	_isOff = false;
	_sensitivity = 1;
}



