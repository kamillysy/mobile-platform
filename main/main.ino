
#include "menu.hpp"
static int message=160;

 unsigned int const ledPin=13;
  unsigned int const encoderLeft=2;
 unsigned int const encoderRight=3;

 
 unsigned int const motorLpinF=4;
 unsigned int const motorLpinPWM=5;
 unsigned int const motorLpinB=6;
 
 unsigned int const motorRpinB=7;
 unsigned int const motorRpinF=8;
 unsigned int const motorRpinPWM=9;


 Drive* go;
 
 void setup(){
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  Serial.begin(9600);
  pinMode(motorLpinB,OUTPUT);
  pinMode(motorLpinF,OUTPUT);
  pinMode(motorLpinPWM,OUTPUT);
  analogWrite( motorLpinPWM, 0);
  pinMode(motorRpinB,OUTPUT);
  pinMode(motorRpinF,OUTPUT);
  pinMode(motorRpinPWM,OUTPUT);  
  analogWrite( motorRpinPWM, 0);
  pinMode(encoderLeft,INPUT);
  pinMode(encoderRight,INPUT);
  go=new Drive(motorLpinPWM,motorLpinF,motorLpinB,motorRpinPWM,motorRpinF,motorRpinB);
  attachInterrupt(digitalPinToInterrupt(2),changeLeft,CHANGE);
  attachInterrupt(digitalPinToInterrupt(3),changeRight,CHANGE);
  go->percentSpeed(50);
  digitalWrite(ledPin, LOW);
 }
 
 void loop(){
  message=Serial.read();
  menu(message,go);
  
 }
 void changeRight(){
  go->encoderRightChanged();
 }
 void changeLeft(){
  go->encoderLeftChanged();
 }

 
