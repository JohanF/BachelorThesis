#include "Bluetooth.h"

Bluetooth::Bluetooth(){
		color[0] = 255;
		color[1] = 125;
		color[2] = 14;
		onOff = 1;
		mode = 1;
}

void 
Bluetooth::update(){
	//Is there data trying to get thro
	if(Serial3.available() > 0){
		char received[5]; 
		Serial3.readBytes(received, 5);   
		//update the values 
		color[0] = received[2];
		color[1] = received[3];
		color[2] = received[4];
		mode = received[1] & 0xff;
		onOff = received[0] & 0xff;
							
	}
		
}

unsigned char*
Bluetooth::getColor(){
	return color;
}

int 
Bluetooth::getMode(){
	return mode;
}

int 
Bluetooth::isOn(){
	return onOff;
}

