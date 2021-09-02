#ifndef ROTARYENCODER_h
#define ROTARYENCODER_h

#include "Arduino.h"

// pins for the rotary encoder
#define OUTPUT_A 2
#define OUTPUT_B 3

static char msg[128];

namespace encoder
{
    class RotaryEncoder
    {
        private:
            volatile unsigned int counter = 0;
        public:
            RotaryEncoder();

            /// \brief setup : sets up pins and interrupts for rotary encoder
            void setup(void);

            /// \brief encoderA : if activated, digital pin 2 is going from LOW to HIGH, also checks pin 3 to determine the direction
            /// if pin3 is low, then encoder is moving in clockwise direction (counter decreases)
            /// if pin 3 is high, then encoder is moving in counter-clockwise direction (counter increases)
            static void encoderA(void);

            /// \brief encoderB : if activated, digital pin3 is going from LOW to HIGH, also chcks pin 2 to determine the direction
            /// if pin 2 is high, then encoder is moving in clockwise direction (counter decreases)
            /// if pin 2 is low, then encoder is moving in counter clockwise direction (counter increases)
            static void encoderB(void);

            /// \brief print_counter : function that prints the counter values from rotary encoder
            void printCounterValue(void);

            /// \brief getCounterValue : function that returns the counter value
            /// \returns a float value representing the encoder count
            float getCounterValue(void);

    };
}

#endif
