# Omni Wheel PID Controller
Software package that implements a PID controller on an Omni Wheel. Written by Sarah Ziselman during September 2021.

## Software Requirements
Open a terminal/command prompt and navigate to the directory in which the sketch will be stored. Enter the following command:
```
git clone 
```
The repository should now be in the following directory and availale for usage. The Arduino IDE is available for free download [here](https://www.arduino.cc/en/software). There are three libraries used within this repository:
* OmniWheel_lib
* PIDcontroller
* MotorLibrary

## Hardware Requirements
The following hardware componenets are used:
* Arduino Mega 2560 Rev 3 found [here](https://store-usa.arduino.cc/products/arduino-mega-2560-rev3?queryID=undefined)
* Rotary Encoder LPD3806-600BM-G5-24C found [here](https://www.amazon.com/Jammas-E38-S6-600-2-N-24-lpd3806-600bm-g5-24c-Incremental-Optical/dp/B07RYV5F6G)
* L298P Motor Driver Shield found [here](https://protosupplies.com/product/l298p-motor-driver-shield/)
* DC Geared Motor 12V found [here](https://www.amazon.com/ZYTD520-Silver-Control-Electric-300PRM/dp/B07W53BVHM)
* 12V Power Supply
* Omni Wheel

## Overview
The work flow of the Arduino sketch can be summarized as follows:
1. Get the angle of the encoder (from -PI to +PI).
2. Wait until an input command is received (angle in degrees).
3. Set the desired angle of the omni wheel.
4. Compute the control value using the PID controller.
5. Apply the PWM to the Motor Driver Shield.
