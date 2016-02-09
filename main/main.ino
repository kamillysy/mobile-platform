#include "drive.hpp"
#include "menu.hpp"
static int message=160;

 unsigned int const ledPin=13;
 unsigned int const motorLpinF=2;
 unsigned int const motorLpinB=4;
 unsigned int const motorLpinPWM=3;
 unsigned int const encoderLeft=9;
 unsigned int const motorRpinF=7;
 unsigned int const motorRpinB=5;
 unsigned int const motorRpinPWM=6;
 unsigned int const encoderRight=8;

 Drive* go;
 
 void setup(){
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  Serial.begin(9600);
  pinMode(motorLpinB,OUTPUT);
  pinMode(motorLpinF,OUTPUT);
  analogWrite( motorLpinPWM, 128);
  pinMode(motorRpinB,OUTPUT);
  pinMode(motorRpinF,OUTPUT);  
  analogWrite( motorRpinPWM, 128);
  digitalRead(encoderLeft);
  digitalRead(encoderRight);
  go=new Drive(motorLpinPWM,motorLpinF,motorLpinB,encoderLeft,motorRpinPWM,motorRpinF,motorRpinB,encoderRight);
  digitalWrite(ledPin, LOW);
 }
 
 void loop(){
  message=Serial.read();
  menu(message,go);
 }

 
