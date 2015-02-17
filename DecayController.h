#ifndef _DECAY_CONTROLLER_H_
#define _DECAY_CONTROLLER_H_

#include "WindSensor.h"
#include "Color.h"

/*
* Calculates the light intensity when affected by wind.
* This is done by modulating a spring.
*/
class DecayController {
public:
	/*
	*Creates a new DecayController with a supplied Windsensor and LightController
	*/
	DecayController(WindSensor* wind);
/*
* Updates the intensity and sends it to LightController
*/
	void update();
	/*
	*The intensity modulation will be normal, i.e sensitive to winds
	*/
	void setIn();
	/*
	* The intensity modulation will be less sensitive by winds
	*/
	void setOut();
	/*
	*Turns of the DecayController, i.e sets the intensity to 1.0
	*/
	void setOff();
	/*
	* Turns on the DecayController, i.e it will calculate the intensity normal.
	*/
	void setOn();
	/**Returns the intensity*/
	float getDecay();

private:

	WindSensor* _wind;

	float _pos, _vel, _intensity;

	bool _isOff;
	float _sensitivity;
};

#endif // _DECAY_CONTROLLER_H_
