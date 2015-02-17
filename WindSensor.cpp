#include "WindSensor.h"
#include "Arduino.h"

#define RAND() (random(0,1000)*0.001)

WindSensor::WindSensor(int windPin, int temperaturePin) 
: _windPin(windPin), _temperaturePin(temperaturePin),_sensitivity(1)
{
		
	_isBlownOut = false;
	_blowOutTime = millis();
}

void
WindSensor::setSensitivity(int mode)
{
	switch(mode)
	{
		case 1:
			_sensitivity = 1.0;
		break;
		case 2:
			_sensitivity = 2.0;
		break;
	}
}


void
WindSensor::update() {

	// Sample the hardware wind sensor.
	_windValue = analogRead(_windPin);
	_temperatureValue = analogRead(_temperaturePin);


	_values[_windSumNumberOfValues] = _windValue;
	_windSumNumberOfValues++;

	if(_windSumNumberOfValues == WIND_MEAN_SAMPLES)
		_windSumNumberOfValues = 0;

	for(char i = 0; i < WIND_MEAN_SAMPLES; i++)
		_windSum += _values[i];
	//Calculate new meanValue 
	double newMean = (double)_windSum/WIND_MEAN_SAMPLES;
	_windSum = 0;

	//Is the change big enough to think the wind is increasing
	_windIsIncreasing = newMean - 2 > _windMean;
	_windMean = newMean;

	//Enough wind to blow out the lamp, and has it been 2.5 sek since last time?
	if((_windMean > 800*_sensitivity ||
	 (newMean/_windMean > 1.18*_sensitivity))
	  && millis() - _blowOutTime > 2500)
	{
		_isBlownOut = !_isBlownOut;
		_blowOutTime = millis();
	}
}
