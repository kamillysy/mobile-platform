#include "motor.hpp"
Motor::Motor(int pwmPin,int forwardPin,int backPin,int encoderPin):
pwm(pwmPin),pinForward(forwardPin), pinBack(backPin),encoder(encoderPin){
       base();      
}
Motor::~Motor(){}
void Motor::run(bool direct){
  if(direct){
    ahead();
  }
  else{
    back();
  }
}
void Motor::ahead(){
    digitalWrite(pinForward,HIGH);
    digitalWrite(pinBack,LOW); 
 }

 


void Motor::back(){
  digitalWrite(pinForward,LOW);
  digitalWrite(pinBack,HIGH); 
}

void Motor::stop(){
  digitalWrite(pinForward,HIGH);
  digitalWrite(pinBack,HIGH);
  delay(3);
  digitalWrite(pinForward,LOW);
  digitalWrite(pinBack,LOW);
}
void Motor::softStop(){
  digitalWrite(pinForward,LOW);
  digitalWrite(pinBack,LOW);
}

bool Motor::read(){
 return digitalRead(encoder); 
}

void Motor::set(bool state,bool direct){
  while(state!=read()){
    if(direct)
     ahead();
     else
     back();
   }
   stop();
   
 }
 void Motor::changeState(bool direct){
 set(!read(),direct);
 }


bool Motor::base(){
 if(read()){
   set(1,1);
 }
 if(!read()){
   return 0;
   }
return 1;
 
}
void Motor::speed(int speed){
  analogWrite( pwm, speed);
}
int Motor::readSpeed(){
  return analogRead(pwm);
}
