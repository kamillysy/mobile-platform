#include "drive.hpp"
#include <Arduino.h>
Drive::Drive(motor* Mleft_,motor* Mright_){
  Mleft=Mleft_;
  Mright=Mright_;

  if(readspeed()==0){
    speed(120);
  }
  speed_=readspeed();

}
int Drive::readspeed(){
  int L=Mleft->readspeed();
  int R=Mright->readspeed();
  if(L==R)
    return L;
  return 0;
}



void Drive::X(bool direct){
  int counterL=0;
  int counterR=0;
  bool stateR=Mright->read();
  bool stateL=Mleft->read();

  while(160!=Serial.read()){
    if((counterL-counterR)>0){
      Mleft->stop1();
    }
    if((counterR-counterL)>0){
      Mright->stop1();
    }
    if(Mleft->read()!=stateL){
      stateL=chstate(stateL);
      counterL++;
    }
    if(Mright->read()!=stateR){
      stateR=chstate(stateR);
      counterR++;
    }
    Mright->run(direct);
    Mleft->run(direct);
  }
  Mright->stop1();
  Mleft->stop1(); 

}

void Drive::Y(bool direct){
  int counterL=0;
  int counterR=0;
  bool stateR=Mright->read();
  bool stateL=Mleft->read();
  while(160!=Serial.read()){
    if((counterL-counterR)>0){
      Mleft->stop1();
    }
    if((counterR-counterL)>0)
      Mright->stop1();
    if(Mleft->read()!=stateL){
      stateL=chstate(stateL);
      counterL++;
    }
    if(Mright->read()!=stateR){
      stateR=chstate(stateR);
      counterR++;
    }
    Mright->run(!direct);
    Mleft->run(direct);
  }
  Mright->stop1();
  Mleft->stop1(); 

}


void Drive::softTurn(bool direct,bool way){
  int counterF=0;
  int counterS=0;
  motor* Faster;
  motor* Slower;
  if (way){
    Faster=Mleft;
    Slower=Mright;
  }
  else{
    Slower=Mleft;
    Faster=Mright;
  }
  bool stateF=Faster->read();
  bool stateS=Slower->read();

 while(160!=Serial.read()){
    if((2*counterS>counterF)){
      Slower->stop1();
    }
    if(Faster->read()!=stateF){
      stateF=chstate(stateF);
      counterF++;
    }
    if(Slower->read()!=stateS){
      stateS=chstate(stateS);
      counterS++;
    }
    Faster->run(direct);
    Slower->run(direct);
    
  }
  Slower->stop1();
  Faster->stop1(); 

}


void Drive::speed(int speed){
  if(speed<=255&&speed>=0){
    Mright->speed(speed);
    Mleft->speed(speed);
  }
}
void Drive::stop(){
  Mright->stop();
  Mleft->stop();
}

void Drive::chspeed(int percent){
  int s=((int)percent*2.55);
  Serial.print(s);
  Serial.print('\n');
  speed(s);
}
bool Drive::chstate(bool Ostate){
  if(Ostate){
    return false;
  }
return true;  
} 
