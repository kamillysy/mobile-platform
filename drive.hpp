#ifndef drive_hpp
#define drive_hpp
#include "motor.hpp"

#include <Arduino.h>

class Drive{
public:
  Drive(motor* Left,motor* Right);
  virtual ~Drive(){
  }


  void X(bool direct);
  void Y(bool direct);

  void softTurn(bool direct,bool way);

 void speed(int speed);
 void chspeed(int percent);

  void stop();

private:
  int  readspeed();
  bool chstate(bool Ostate);


  motor* Mleft;
  motor*Mright;
  int speed_;



};

#endif

