#include <Arduino.h>

void menu(int zmienna,Drive* go){
  switch(zmienna)
  {
    case 111:
    go->X(0);
    break;
    
    case 122:
    go->X(1);
    break;
    
    case 140:
    go->Y(1);
    break;
    
    case 150:
    go->Y(0);
    break;
    
    case 114:
    go->softTurn(0,0);
    break;
    
    case 115:
    go->softTurn(0,1);
    break;
    
    case 124:
    go->softTurn(1,0);
    break;
    
    case 125:
    go->softTurn(1,1);
    break;
    
    default:
    if(zmienna>3){
    go->chspeed(zmienna);
    }
   }
 }
      
