#ifndef ROBOTDRIVE_H
#define ROBOTDRIVE_H

#include "mbed.h"

class RobotDrive {
public:
    RobotDrive(PinName lpwm, PinName lin1, PinName lin2, 
               PinName rpwm, PinName rin3, PinName rin4) 
               : _lpwm(lpwm), _lin1(lin1), _lin2(lin2), 
                 _rpwm(rpwm), _rin3(rin3), _rin4(rin4) {
        _lpwm.period(0.001f);
        _rpwm.period(0.001f);
    }

    void drive(float speed) {
        _lin1 = 1; _lin2 = 0;
        _rin3 = 1; _rin4 = 0;
        _lpwm = speed;
        _rpwm = speed;
    }

    void stop() {
        _lpwm = 0;
        _rpwm = 0;
    }

private:
    PwmOut _lpwm, _rpwm;
    DigitalOut _lin1, _lin2, _rin3, _rin4;
};

#endif