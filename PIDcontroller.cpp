#include "PIDcontroller.h"

namespace control
{
    PIDController::PIDController()
    {
        limit_output = true;

        prev_time = millis();
        curr_time = millis();
    }

    void PIDController::tune(float kP_value, float kI_value, float kD_value)
    {
        if (kP_value < 0) {
            kP = 1.0;
        }
        else {
            kP = kP_value;
        }

        if (kI_value < 0) {
            kI = 1.0;
        }
        else {
            kI = kI_value;
        }

        if (kD_value < 0) {
            kD = 1.0;
        }
        else {
            kD = kD_value;
        }
    }

    void PIDController::setDesiredValue(float desired)
    {
        desired_value = desired;
    }

    float PIDController::compute(float actual_value)
    {
        char msg[128];
        char fstr[10];

        // calculate time difference since last execution (s)
        curr_time = millis();
        dt = (float)(curr_time - prev_time) / 1000.0;

        // calculate the error, total error and change in error
        error = desired_value - actual_value;
        total_error += error * dt;
        d_error = (error - prev_error) / dt;

        // calculate the new output
        float output = (kP * error) + (kI * total_error) + (kD * d_error);

        dtostrf(output, 6, 3, fstr);
        sprintf(msg, "pid output is %s\n", fstr);
        Serial.println(msg);

        // if limiting the output, apply limits
        if (limit_output)
        {
            output = constrain(output, minOut, maxOut);
        }

        // set current values to previous
        prev_error = error;
        prev_time = curr_time;

        return output;
    }
}