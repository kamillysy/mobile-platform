
#include "drive.h"
#include "menu.h"
int message=0;

 unsigned int ledPin=13;
 unsigned int motorLpinF=2;
 unsigned int motorLpinB=4;
 unsigned int motorLpinPWM=3;
 unsigned int encoderLeft=9;
 unsigned int motorRpinF=5;
 unsigned int motorRpinB=7;
 unsigned int motorRpinPWM=6;
 unsigned int encoderRight=8;

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
 
 
