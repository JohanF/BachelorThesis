#ifndef _Bluetooth_Controller_h_
#define _Bluetooth_Controller_h_

#include "Arduino.h"
/*
* Controlls the communication between the app and arduino
*/
class Bluetooth{
			
	public:
	/*
	*Creates a new Bluetooth, sets the color to default, turns on the lamp and sets the mode to indoor
	*/
		Bluetooth();
		/*
		*Check if the app are trying to communicate via bluetooth
		* if that are data waiting it will be decoded and the affected variables 
		* will be updated. 
		*/
		void update();
		/*
		*returns the color that is set by the app
		*/
		unsigned char* getColor();
		/**Returns the mode set by the app*/
		int getMode();
		/**Returns if the lamp is set to on or off by the app*/
		int isOn();

	private:
		unsigned char color[3];
		int mode;
		int onOff;
};

#endif