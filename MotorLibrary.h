#ifndef MOTOR_LIBRARY_h
#define MOTOR_LIBRARY_h

#include "Arduino.h"

#define E1_pin 10
#define M1_pin 12

namespace motor
{
    class MotorShield
    {
        private:
        public:
            MotorShield();

            /// \brief setup : function that sets up arduino pins for Motor shield
            void setup(void);

            /// \brief moveMotor : function that rotates the motor based on a control value
            /// \param pwm : the pulse width module of the motor, calculated using PID controller
            void moveMotor(float pwm);
    };
}

#endif
