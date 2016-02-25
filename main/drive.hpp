#ifndef drive_hpp
#define drive_hpp
#include "motor.hpp"

#include <Arduino.h>

class Drive{
public:
  Drive(Motor* left,Motor* right);
  Drive(int leftPwm,int leftForward,int leftBack,int rightPwm,int rightForward,int rightBack);
  ~Drive(){delete leftM; delete rightM;}


  void stright(bool direct);
  void around(bool direct);
 
  void softTurn(bool direct,bool way);

 void changeSpeed(int speed);
 void percentSpeed(int percent);
  void encoderLeftChanged();
  void encoderRightChanged();
  void stop();
  void softStop();

private:
  int  readSpeed();
  


  Motor* leftM;
  Motor* rightM;
  int speed;



};

#endif


