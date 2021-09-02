#include "MotorLibrary.h"

namespace motor
{
    MotorShield::MotorShield()
    {
        Serial.println("initializing motor shield object...");
    }

    void MotorShield::setup(void)
    {
        pinMode(M1_pin, OUTPUT);
        pinMode(E1_pin, OUTPUT);
    }

    void MotorShield::moveMotor(float pwm)
    {
        // if pwm is greater than or equal to 0, move in counter-clockwise direction
        if (pwm >= 0) {
            digitalWrite(M1_pin, HIGH);
        }
        // if pwm is less than 0, move in clockwise direction
        else if (pwm < 0) {
            digitalWrite(M1_pin, LOW);
        }

        delay(30);

        // set pwm to the motor pin
        analogWrite(E1_pin, pwm);

        delay(30);
    }
}