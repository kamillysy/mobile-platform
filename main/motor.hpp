#ifndef Motor_hpp
#define Motor_hpp
#include <Arduino.h>

 
class Motor
{
  public:
    Motor(int pwmPin,int forwardPin,int backPin,int encoderPin);
	  ~Motor();
	
        
        void run(bool direct);
        void speed(int speed);
        int  readSpeed();
        void stop();
        void softStop();      
        bool read(); 
        void set(bool state,bool direct);
        void changeState(bool direct);
        
        
private:
       
	     void ahead();
       void back();
       bool base();
     	
       int pwm;
       int pinBack;
       int pinForward;
       int encoder;

};


#endif
