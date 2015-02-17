#ifndef PointController_h
#define PointController_h
#include "Vector.h"
#include "WindSensor.h"

/**
 * Simulates a point that moves around in a circle, the purpouse is to mimic the
 * movmentof a real flame.
 */
class PointController
{

private:
    /*Vectors that represent the leds*/
    Vector *led_1;
    Vector *led_2;
    Vector *led_3;
    /*Vector that reprecent the point aka flame*/
    Vector *point;
   // LightController *_light;
    WindSensor* _wind;
    float _intensity [3];
    /*The time sence last change of radius */
    unsigned long _radiusTime;
    unsigned long _time;
    /*the directoin of the point*/
    char _dir;
    /*Calculates the proportion of distance between the point and 3 lamps.*/
    void calculate();
    /*Calculate how much the radius will change, eighter -1,0 or 1
     * Takes the current radius and returns the new one*/
    char newRadius(char);
    /*Calculate if the direction will change, return -1 or 1*/
    char direction();
    /*If the pointmovment is on or off*/
    bool _isOff;

public:
    /*Creates a new Pointcontroller*/
    PointController(WindSensor* wind);
    /*Updates the location of the point and notify Color*/
    void update();
    /*Turns off the movment*/
    void setOff();
    /*Turns on the movement*/
    void setOn();
    /**Returns the intensty the different leds will have to simulate the point*/
    float* getPoint();



};


#endif
