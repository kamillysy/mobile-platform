#ifndef Motor_hpp
#define Motor_hpp
#include <Arduino.h>



class Motor
{
  public:
    Motor(int pwmPin,int forwardPin,int backPin);
	  ~Motor();
	
        
        void run(bool direct);
        void speed(int speed);
        int  readSpeed();
        void stop();
        void softStop();
        int counter;
        

private:
       
       void ahead();
       void back();
      
       int pwm;
       int pinBack;
       int pinForward;
       int settedSpeed;
       

};

 
#endif
