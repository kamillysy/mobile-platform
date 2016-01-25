
#include "drive.hpp"
#include "menu.hpp"
int message=0;

 unsigned int const ledPin=13;
 unsigned int const motorLpinF=2;
 unsigned int const motorLpinB=4;
 unsigned int const motorLpinPWM=3;
 unsigned int const encoderLeft=9;
 unsigned int const motorRpinF=5;
 unsigned int const motorRpinB=7;
 unsigned int const motorRpinPWM=6;
 unsigned int const encoderRight=8;

 Drive* go;
 motor* Mleft;
 motor*  Mright;
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
 Mleft=new motor(motorLpinPWM,motorLpinF,motorLpinB,encoderLeft);
  Mright=new motor(motorRpinPWM,motorRpinF,motorRpinB,encoderRight); 
   go=new Drive(Mleft,Mright);
  digitalWrite(ledPin, LOW);
 }
 void loop(){
  message=Serial.read();
  menu(message,go);
 }
 
 
