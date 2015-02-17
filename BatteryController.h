#ifndef _BATTERY_CONTROLLER_
#define _BATTERY_CONTROLLER_

#include "Arduino.h"
/*A class that reads the status of the battery, and knows when it running low*/
class BatteryController
{
public:
	/*Creates a new BatteryController that reads the data from
	@param batteryPin the pin that to read the batterystatus from*/
	BatteryController(int batteryPin);
	/*Reads from _batterypPin and updates all values*/
	void update();
	/*Returns the raw inputvalue from the _batteryPin*/
	float value ()		const {return _batteryValue;};
	/*Returns the value the battery has when it starts to running low*/
	float fadeValue() 	const {return _fadeValue;};
	/*Returns the value the battery has when it will turn off*/
	float stopValue() 	const {return _stopValue;};
	/*Returns a bool, if true the battery has enough power left, otherwise false*/
	bool isOk();

private:
	float _batteryValue, _fadeValue, _stopValue;
	int _batteryPin;

};

#endif