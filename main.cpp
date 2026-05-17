#include "mbed.h"
#include "Ultrasonic.h"
#include "RobotDrive.h"

// Hardware Pins
Ultrasonic sensor(D3, D2); // Trigger, Echo
RobotDrive robot(D5, D7, D4, D6, D11, D8); // L_PWM, L_IN1, L_IN2, R_PWM, R_IN3, R_IN4

// Settings
const float SPEED_FAR    = 0.30f;
const float SPEED_NEAR   = 0.18f; 
const float DIST_TARGET  = 25.0f;
const float DIST_SAFE    = 12.0f;

int main() {
    printf("Robot Initialized. Starting loop...\r\n");

    while(1) {
        sensor.trigger();
        
        // Brief wait for the ISR to update the distance value
        ThisThread::sleep_for(10ms); 
        
        float currentDist = sensor.getDistance();

        // Serial Output (Casting to int for compatibility)
        printf("Distance: %d cm\r\n", (int)currentDist);

        // Logic Control
        if (currentDist < DIST_SAFE || currentDist > 400.0f) {
            robot.stop();
        } 
        else if (currentDist > 50.0f) {
            robot.drive(SPEED_FAR);
        } 
        else if (currentDist > DIST_TARGET) {
            robot.drive(SPEED_NEAR);
        } 
        else {
            robot.stop();
        }

        ThisThread::sleep_for(90ms); // Total loop ~100ms
    }
}

