#ifndef drive_hpp
#define drive_hpp
#include "motor.hpp"

#include <Arduino.h>

class Drive{
public:
  Drive(Motor* left,Motor* right);
  Drive(int leftPwm,int leftForward,int leftBack,int leftEncoder,int rightPwm,int rightForward,int rightBack,int rightEncoder);
  ~Drive(){delete leftM; delete rightM;}


  void stright(bool direct);
  void around(bool direct);

  void softTurn(bool direct,bool way);

 
 void percentSpeed(int percent);

  void stop();
  void softStop();
private:
  int  readSpeed();
  bool chstate(bool oldState);
  void changeSpeed(int speed);

  Motor* leftM;
  Motor* rightM;
  int speed;



};

unsigned int const commandStop=160;
#endif


