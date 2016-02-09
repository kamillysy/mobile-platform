#include"menu.hpp"
void menu(int order,Drive* platform){
  switch(order)
  {
    case forward:
    platform->stright(0);
    break;
    
    case back:
    platform->stright(1);
    break;
    
    case left:
    platform->around(1);
    break;
    
    case right:
    platform->around(0);
    break;
    
    case leftahead:
    platform->softTurn(0,0);
    break;
    
    case rightahead:
    platform->softTurn(0,1);
    break;
    
    case leftback:
    platform->softTurn(1,0);
    break;
    
    case rightback:
    platform->softTurn(1,1);
    break;
    
    default:
    platform->percentSpeed(order);
   }
 }
