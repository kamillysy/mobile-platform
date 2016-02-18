#include "drive.hpp"
#include <Arduino.h>
Drive::Drive(Motor* left, Motor* right): leftM(left), rightM(right) {
  speed = readSpeed();
}

Drive:: Drive(int leftPwm, int leftForward, int leftBack, int leftEncoder, int rightPwm, int rightForward, int rightBack, int rightEncoder ) {
  leftM = new Motor(leftPwm, leftForward, leftBack, leftEncoder);
  rightM = new Motor(rightPwm, rightForward, rightBack, rightEncoder);
  speed = readSpeed();
 
}

int Drive::readSpeed() {
  int L = leftM->readSpeed();
  int R = rightM->readSpeed();
  if (L == R)
    return L;
  return 0;
}


void Drive::stright(bool direct) {
  int counterL = 0;
  int counterR = 0;
  bool stateR = rightM->read();
  bool stateL = leftM->read();

  while (commandStop != Serial.read()) {
    if ((counterL - counterR) > 0) {
      leftM->softStop();
    }
    if ((counterR - counterL) > 0) {
      rightM->softStop();
    }
    if (leftM->read() != stateL) {
      stateL = chstate(stateL);
      counterL++;
    }
    if (rightM->read() != stateR) {
      stateR = chstate(stateR);
      counterR++;
    }
    rightM->run(direct);
    leftM->run(direct);
  }
  rightM->stop();
  leftM->stop();
}

void Drive::around(bool direct) {
  int counterL = 0;
  int counterR = 0;
  bool stateR = rightM->read();
  bool stateL = leftM->read();
  while (commandStop != Serial.read()) {
    if ((counterL - counterR) > 0) {
      leftM->softStop();
    }
    if ((counterR - counterL) > 0)
      rightM->softStop();
    if (leftM->read() != stateL) {
      stateL = chstate(stateL);
      counterL++;
    }
    if (rightM->read() != stateR) {
      stateR = chstate(stateR);
      counterR++;
    }
    rightM->run(!direct);
    leftM->run(direct);
  }
  rightM->stop();
  leftM->stop();
}


void Drive::softTurn(bool direct, bool way) {
  int counterF = 0;
  int counterS = 0;
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
  bool stateF = faster->read();
  bool stateS = slower->read();

  while (commandStop != Serial.read()) {
    if ((2 * counterS > counterF)) {
      slower->softStop();
    }
    if (faster->read() != stateF) {
      stateF = chstate(stateF);
      counterF++;
    }
    if (slower->read() != stateS) {
      stateS = chstate(stateS);
      counterS++;
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
bool Drive::chstate(bool oldState) {
  if (oldState) {
    return false;
  }
  return true;
}
