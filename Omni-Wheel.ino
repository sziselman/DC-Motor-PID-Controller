/*****************************
 * Rotary Encoder for Omni Wheel
 * **************************/
#include "PIDcontroller.h"
#include "MotorLibrary.h"
#include "OmniWheel_lib.h"

#define OUTPUT_A 2      // output pins for encoder A
#define OUTPUT_B 3      // output pins for encoder B

#define _kP 1.0         // proportional control constant
#define _kI 1.0         // integral control constant
#define _kD 1.0         // derivative control constant

motor::MotorShield motor_shield;
control::PIDController pid_controller;

volatile long counter = 0;
static char msg_out[128];
static char fstr[10];

static int input = 0;

void setup() 
{
  Serial.begin(9600);
  Serial.println("setup()");

  pinMode(OUTPUT_A, INPUT_PULLUP); // internal pullup input pin 2 
  pinMode(OUTPUT_B, INPUT_PULLUP); // internal pullup input pin 3

  // Setting up interrupts 0 (pin 2) and 1 (pin 3)
  attachInterrupt(digitalPinToInterrupt(OUTPUT_A), encoderA, RISING);
  attachInterrupt(digitalPinToInterrupt(OUTPUT_B), encoderB, RISING);

  motor_shield.setup();

  // tuning the pid controller
  pid_controller.tune(_kP, _kI, _kD);

}
   
void loop() 
{
  using namespace Omni;

  Serial.println("loop()");

  // print the counter value
  sprintf(msg_out, "count is %i\n", counter);
  Serial.println(msg_out);

  // print the encoder angle
  float encoder_angle = countToRad(counter);
  dtostrf(encoder_angle, 6, 3, fstr);
  sprintf(msg_out, "angle is %s radians\n", fstr);
  Serial.println(msg_out);

  // set the initial input value to 0
  char incomingByte;

  // check for an integer value
  while (Serial.available())
  {
    // store the inputed integer value
    input = Serial.parseInt();
    // store the \n character
    incomingByte = Serial.read();
    // if new line character is received, continue in the loop
    if (incomingByte == '\n') continue;
  }

  sprintf(msg_out, "inputted value is %i\n", input);
  Serial.println(msg_out);

  pid_controller.setDesiredValue(input);

  float motor_output = pid_controller.compute(encoder_angle);

  dtostrf(motor_output, 6, 3, fstr);
  sprintf(msg_out, "motor output is %s radians\n", fstr);
  Serial.println(msg_out);

  motor_shield.moveMotor(200);
}

/// \brief encoderA : if activated, digital pin 2 is going from LOW to HIGH, also checks pin 3 to determine the direction
/// if pin3 is low, then encoder is moving in clockwise direction (counter decreases)
/// if pin 3 is high, then encoder is moving in counter-clockwise direction (counter increases)
void encoderA(void) 
{
  if (digitalRead(OUTPUT_B) == LOW) 
  {
      counter--;
  }
  else
  {
      counter++;
  }
}

/// \brief encoderB : if activated, digital pin3 is going from LOW to HIGH, also chcks pin 2 to determine the direction
/// if pin 2 is high, then encoder is moving in clockwise direction (counter decreases)
/// if pin 2 is low, then encoder is moving in counter clockwise direction (counter increases)
void encoderB(void)
{
  if (digitalRead(OUTPUT_A) == LOW)
  {
      counter++;
  }
  else 
  {
      counter--;
  }
}

