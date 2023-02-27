/*

ServoStep.h - Library for simplifying local servo commands

*/

#include "Arduino.h"
#include "ServoStep.h"

ServoStep::ServoStep(int pin){
    _pin=pin;
    ledcSetup(0,200,8);
    ledcAttachPin(_pin,0);
    
}

void ServoStep::servoSet(int angle){
    duty=(map(angle,0,180,5,25))*5.1;
    //5.1 is the ratio of pulse width (in decimilliseconds)to duty cycle at a fequency of 200Hz (the minimum for ledc on esp32c3)
    ledcWrite(0,duty);//write to servo
    delay(300);

}

void ServoStep::servoUp(){
    ledcWrite(0,77); //90degress
    ledcWrite(0,128);//180 degrees
    delay(300);
    ledcWrite(0,77);//90 degrees
}

void ServoStep::servoDown(){
    ledcWrite(0,77); //90degress
    ledcWrite(0,26);//0 degrees
    delay(300);
    ledcWrite(0,77);//90 degrees
}