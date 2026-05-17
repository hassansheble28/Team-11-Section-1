#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include "mbed.h"

class Ultrasonic {
public:
    // Constructor: Sets up the pins
    Ultrasonic(PinName trigPin, PinName echoPin);

    // Public methods
    void trigger();
    float getDistance();

private:
    DigitalOut _trig;
    InterruptIn _echo;
    Timer _timer;
    volatile float _distance;

    // Internal ISR methods
    void onRise();
    void onFall();
};

#endif