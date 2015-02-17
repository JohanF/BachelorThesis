#include "LightController.h"
#include "WindSensor.h"
#include "DecayController.h"
#include "PointController.h"
#include "ColorController.h"
#include "Bluetooth.h"

WindSensor wind (A1, A0);
BatteryController battery(A7);
DecayController decay(&wind);
PointController point(&wind);
ColorController color(&battery);
LightController light(&decay, &point, &color);
Bluetooth bt;
boolean isOn;
unsigned long _time;

void setup(){
				Serial.begin(115200);
				Serial3.begin(115200);
				isOn = false;
				_time = millis();
}

void loop() { 
	/*Call the update method in Bluetooth*/   
	bt.update();
	/*Sets mode and color*/
	int mode = bt.getMode();
	unsigned char* newColor = bt.getColor();
	if((millis() -_time)> (1000/30)){
		if(bt.isOn() ){

			
			switch(mode)
			{
				/*Decay and point movment disabled, just a constant light, 
				different colors is available*/
				case 0:
					decay.setOff();
					point.setOff();
				break;
				/*indoor mode, realistic behavior of the decay controller*/
				case 1:
					decay.setOn();
					point.setOn();
					decay.setIn();    
					wind.setSensitivity(mode);
				break;
				/*outdoor mode, realistic behavior of the decayController,
				less sensitive to wind and blow out function is disabled*/
				case 2:
					decay.setOn();
					point.setOn();
					decay.setOut();
					wind.setSensitivity(mode);
				break;
			}
			/*Set the new color*/
			color.setColor(newColor[0],newColor[1],newColor[2]);
			_time = millis();
		}else{
		color.setColor(0,0,0);
		}

	color.update();
	light.update(); 
	
	} 
	
}
