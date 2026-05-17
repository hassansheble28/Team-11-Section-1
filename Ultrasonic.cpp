#include "Ultrasonic.h"

Ultrasonic::Ultrasonic(PinName trigPin, PinName echoPin) : _trig(trigPin), _echo(echoPin) {
    _echo.rise(callback(this, &Ultrasonic::onRise));
    _echo.fall(callback(this, &Ultrasonic::onFall));
}

void Ultrasonic::trigger() {
    _trig = 0;
    wait_us(2);
    _trig = 1;
    wait_us(10);
    _trig = 0;
}

float Ultrasonic::getDistance() {
    return _distance;
}

void Ultrasonic::onRise() {
    _timer.reset();
    _timer.start();
}

void Ultrasonic::onFall() {
    _timer.stop();
    // Using the modern Chrono API to get microseconds as an integer
    _distance = (_timer.elapsed_time().count() * 0.0343f) / 2.0f;
}