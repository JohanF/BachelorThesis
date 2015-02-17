#include "BatteryController.h"

BatteryController::BatteryController(int batteryPin)
{
	_batteryPin = batteryPin;
	_fadeValue = 940;
	_stopValue = 840;
}

void BatteryController::update()
{	
	//Read the value from the battery
	_batteryValue =  analogRead(_batteryPin);
	Serial.println(analogRead(_batteryPin));
}


bool BatteryController::isOk()
{
	return _batteryValue > _fadeValue;
}
