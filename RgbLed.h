#ifndef _RGB_LED_H_
#define _RGB_LED_H_

#include "Arduino.h"
#include "Color.h"

/**
 * An RgbLed controlls a hardware RGB-LED, allowing its color to be easily
 *   controlled from software.
 */
class RgbLed {
public:
	/**
	 * Creates a new RGB-LED that will output its values on the supplied pins.
	 * @param pinR - analog pin for the red color component.
	 * @param pinG - analog pin for the green color component.
	 * @param pinB - analog pin for the blue color component.
	 */
	RgbLed (int pinR, int pinG, int pinB);

	/**
	 * Sets the color of the RGB-LED. This new color will be displayed when
	 *   when update() is called.
	 * @param color - the new color of the RGB-LED.
	 */
	void setColor(unsigned char, unsigned char, unsigned char);

	/**
	 * Updates the output signals of the Arduino. This function must be called
	 *   from the update loop.
	 */
	void update();


private:
	/** Analog pins for each color component. */
	int _pinR, _pinG, _pinB;
	
	/** Color displayed by the RGB-LED. */
	Color _color;

};

#endif // _RGB_LED_H_
