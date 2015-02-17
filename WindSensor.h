#ifndef _WIND_SENSOR_H_
#define _WIND_SENSOR_H_

#include "Arduino.h"

enum {
	/** Number of samples used to calculate the mean wind value. */
	WIND_MEAN_SAMPLES = 4
};

/**
 * A WindSensor communicates and interprets the signal from a hardware wind 
 *   sensor.
 */
class WindSensor {
public:
	/**
	 * Create a new WindSensor that will get its data from the supplied pins.
	 * @param windPin - analog input pin for wind speed sensor.
	 * @param temperaturPin - analog input pin for temperatur sensor.
	 */
	WindSensor(int windPin, int temperaturePin);

	/**
	 * Samples the external sensors and calculates the wind speed. This function
	 *   must be called from the update loop.
	 */
	void update();

	int value() const { return _windValue; }
	int temperature() const { return _temperatureValue; }
	double mean() const { return _windMean; }
	bool isIncreasing() const { return _windIsIncreasing; }
	bool isBlownOut() const { return _isBlownOut; }
	void setSensitivity(int);

private:
	/** Analog input pins from external sensors. */
	int _windPin, _temperaturePin;

	/** Raw values from external sensors (0-1023). */
	int _windValue, _temperatureValue;

	/** Mean wind value. */
	double _windMean;

	/** Sum of the last _windSumNumberOfValues number of _windValue. */
	double _windSum;

	/** Number of values added togheter to form _windSum. */
	int _windSumNumberOfValues;

	/** Indicates if the wind is increasing. */
	bool _windIsIncreasing;

	/*If the wind has blown out the lamp*/
	bool _isBlownOut;
	/*How much time has elapsed since last time the lamp was blown out*/
	unsigned long _blowOutTime;
	/*Array containg the sampled windvalues*/
	int _values [WIND_MEAN_SAMPLES];
	/**How sensitive the the lamp is to wind before it blows out*/
    float _sensitivity;
};

#endif // _WIND_SENSOR_H_
