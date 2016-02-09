#ifndef menu_hpp
#define menu_hpp
#include <Arduino.h>
#include "drive.hpp"

int const forward=111;
int const back=122;
int const left=140;
int const right=150;
int const leftahead=114;
int const rightahead=115;
int const leftback=124;
int const rightback=125;

void menu(int zmienna,Drive* go);
      
#endif
