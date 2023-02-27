/*

ServoStep.h - Library for simplifying local servo commands

*/
#ifndef ServoStep_h
#define ServoStep_h

#include "Arduino.h"

class ServoStep
{
    public:
        ServoStep(int pin);

    public:
        void servoUp();
        void servoDown();
        void servoSet(int angle);
        double duty;
    private:
        int _pin;

};

#endif