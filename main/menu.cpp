#include"menu.hpp"
void menu(int zmienna,Drive* go){
  switch(zmienna)
  {
    case forward:
    go->X(0);
    break;
    
    case back:
    go->X(1);
    break;
    
    case left:
    go->Y(1);
    break;
    
    case right:
    go->Y(0);
    break;
    
    case leftahead:
    go->softTurn(0,0);
    break;
    
    case rightahead:
    go->softTurn(0,1);
    break;
    
    case leftback:
    go->softTurn(1,0);
    break;
    
    case rightback:
    go->softTurn(1,1);
    break;
    
    default:
    if(zmienna>3){
    go->chspeed(zmienna);
    }
   }
 }
