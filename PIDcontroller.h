#ifndef PIDCONTROLLER_h
#define PIDCONTROLLER_h

#include "Arduino.h"

namespace control
{
    class PIDController 
    {
        private:
            float error = 0.0;          // error (difference between actual and desired)
            float total_error = 0.0;    // total error accumulated over time
            float d_error = 0.0;        // change in error from previous time step to current time step
            float prev_error = 0.0;     // the previous error value

            float kP = 1.0;             // proportional constant
            float kI = 1.0;             // integral constant
            float kD = 1.0;             // derivative constant

            float dt;                   // time change from previous time stamp to current time stamp

            unsigned long prev_time;    // the prvious time (milliseconds)
            unsigned long curr_time;    // the current time (milliseconds)

            bool limit_output;          // boolean to represent if the output is limited within a designated range
            float minOut = -255.0;      // minimum output value
            float maxOut = 255.0;       // maximum output value

            float desired_value;        // desired value for the motor to achieve
        public:
            PIDController();

            /// \brief tune : function that tunes the PID constants to ensure they are never negative
            /// \param kP_value : proportional constant value
            /// \param kI_value : integral constant value
            /// \param kD_value : derivative constant value
            void tune(float kP_value, float kI_value, float kD_value);

            /// \brief setDesiredValue : function that inputs the desired value
            /// \param desired : desired angle of the motor
            void setDesiredValue(float desired);

            /// \brief compute : function that calculates the output using the PID controller
            /// \param actual : the actual angle of the motor
            /// \return float : the output value
            float compute(float actual);

            /// \brief limitOutput : limits the output of the PID controller to be between minOutput and maxOutput
            /// this is used to reduce integral windup
            void limitOutput(void);
    };
}

#endif
