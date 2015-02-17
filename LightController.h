#ifndef LightController_h
#define LightController_h 
#include "RgbLed.h"
#include "DecayController.h"
#include "PointController.h"
#include "ColorController.h"

class LightController{

	private:
		DecayController* _decay;
		PointController* _point;
		ColorController* _color;

		Color* _light;
		float _old_1, _old_2, _old_3;
		RgbLed* _led_1;
		RgbLed* _led_2;
		RgbLed* _led_3;

		void changeColorUp(float, float, float, RgbLed*);
		void changeColorDown(float, float, float, RgbLed*);
	
	
	public:
		/*
		* Creates a new LightController, initilizes the color to default
		*/
		LightController(DecayController* decay, PointController* point, ColorController* color);	
		/**
		 * Updates the RGBLeds with the right color, gets information from
		 * decay, point and color controller
		 */
		void update();
};


#endif
