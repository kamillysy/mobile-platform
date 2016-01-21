#include <Arduino.h>

class motor
{
  public:
	motor(int pwm,int pinF,int pinB,int encoder);
	virtual ~motor(){}
	
        void ahead();
        void back();
        void run(bool direct);
        void speed(int speed);
        int  readspeed();
        void stop();
        void stop1();      
        bool read(); 
        void set(bool state,bool direct);
        void changestate(bool direct);
        void chstate(bool direct);
        int encoder_;
private:
	
        //void count(int &counter,bool direct);
        bool base();
     	
       int PWM_;
       int pinB_;
       int pinF_;
       

};


motor::motor(int pwm,int pinF,int pinB,int encoder){
        PWM_=pwm;
        pinB_=pinB;
        pinF_=pinF;
        encoder_=encoder;
        base();
        
}
void motor::run(bool direct){
  if(direct){
    ahead();
  }
  else{
    back();
  }
}
void motor::ahead(){
    digitalWrite(pinF_,HIGH);
    digitalWrite(pinB_,LOW); 
 }

 


void motor::back(){
  digitalWrite(pinF_,LOW);
  digitalWrite(pinB_,HIGH); 
}

void motor::stop(){
  digitalWrite(pinF_,HIGH);
  digitalWrite(pinB_,HIGH);
  delay(3);
  digitalWrite(pinF_,LOW);
  digitalWrite(pinB_,LOW);
}
void motor::stop1(){
  digitalWrite(pinF_,LOW);
  digitalWrite(pinB_,LOW);
}

bool motor::read(){
 return digitalRead(encoder_); 
}

void motor::set(bool state,bool direct){
  while(state!=read()){
    if(direct)
     ahead();
     else
     back();
   }
   stop();
   
 }
 void motor::changestate(bool direct){
 set(!read(),direct);
 }
void motor::chstate(bool direct){
 while(read()!=CHANGE){
   if(direct){
     ahead();
     }
     else{
       back();
     }
 } 
 stop1();
}

bool motor::base(){
 if(read()){
   set(1,1);
 }
 if(!read()){
   return 0;
   }
return 1;
 
}
void motor::speed(int speed){
  analogWrite( PWM_, speed);
}
int motor::readspeed(){
  return analogRead(PWM_);
}
