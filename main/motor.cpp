#include "motor.hpp"
Motor::Motor(int pwmPin,int forwardPin,int backPin):
pwm(pwmPin),pinForward(forwardPin), pinBack(backPin),counter(0){
       softStop();      
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


void Motor::speed(int speed){
  settedSpeed=speed;
 
  analogWrite(pwm,speed);
}
int Motor::readSpeed(){
  return analogRead(pwm);
}


 
