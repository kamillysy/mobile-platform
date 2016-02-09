#ifndef motor_hpp
#define motor_hpp
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


#endif
