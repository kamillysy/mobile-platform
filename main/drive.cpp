#include "drive.hpp"
#include <Arduino.h>
Drive::Drive(Motor* leftM_, Motor* rightM_): leftM(leftM_), rightM(rightM_) {
  speed = readSpeed();
}
Drive:: Drive(int leftPwm, int leftForward, int leftBack, int rightPwm, int rightForward, int rightBack) {
  leftM = new Motor(leftPwm, leftForward, leftBack);
  rightM = new Motor(rightPwm, rightForward, rightBack);
  speed = readSpeed();

}

int Drive::readSpeed() {
  int L = leftM->readSpeed();
  int R = rightM->readSpeed();
  if (L == R)
    return L;
  return 0;
}
void Drive::encoderLeftChanged(){
  leftM->counter++;
}

void Drive::encoderRightChanged(){
  rightM->counter++;
}

void Drive::stright(bool direct) {
  leftM->counter=0;
  rightM->counter=0;
   
  while (160 != Serial.read()) {
    if ((leftM->counter - rightM->counter) > 0) {
      
      leftM->softStop();
    }
    if ((rightM->counter - leftM->counter) > 0) {
      rightM->softStop();
    }
    rightM->run(direct);
    leftM->run(direct);

  }
  rightM->stop();
  leftM->stop();
}

void Drive::around(bool direct) {
  leftM->counter=0;
  rightM->counter=0;
  
  while (160 != Serial.read()) {
    if ((leftM->counter - rightM->counter) > 0) {
      leftM->softStop();
    }
    if ((rightM->counter - leftM->counter) > 0) {
      rightM->softStop();
    }

    rightM->run(!direct);
    leftM->run(direct);
  }
  rightM->stop();
  leftM->stop();
}


void Drive::softTurn(bool direct, bool way) {
  Motor* faster;
  Motor* slower;
  if (way) {
    faster = leftM;
    slower = rightM;
    }
  else {
    slower = leftM;
    faster = rightM;
  }
  faster->counter=0;
  slower->counter=0; 


  while (160 != Serial.read()) {
    if ((2 * slower->counter > faster->counter)) {
      slower->softStop();
    }

    faster->run(direct);
    slower->run(direct);

  }
  slower->stop();
  faster->stop();

}


void Drive::changeSpeed(int speed) {
  if (speed <= 255 && speed >= 0) {
    rightM->speed(speed);
    leftM->speed(speed);
  }
}
void Drive::stop() {
  rightM->stop();
  leftM->stop();
}
void Drive::softStop() {
  rightM->softStop();
  leftM->softStop();
}

void Drive::percentSpeed(int percent) {
  int s = ((int)percent * 2.55);

  changeSpeed(s);
}

