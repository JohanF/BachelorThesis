#ifndef _Color_Controller_h_
#define _Color_Controller_h_
#include "BatteryController.h"
#include "Color.h"

/*Controlls the color of the leds*/
class ColorController{

	private:
		unsigned char _r,_g,_b;
		Color _color;
	//	LightController* _light;
		BatteryController* _battery;
		
		
	
	public:
		/*
		 * Creates a new ColorController, with the suplied LightController and
		 * BatteryController
		*/
		ColorController(BatteryController* battery);
		/**
		 * Updates the color and send the color to LightController, checks the
		 * battery status and modifies the color to a more blue color*/
		void update();
		/**Returns the current color*/
		Color* getColor();
		/**Sets the color with the supplied values*/
		void setColor(unsigned char r, unsigned char g, unsigned char b);


};

#endif
