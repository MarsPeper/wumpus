/******************************************************
** Program: wumpus.cpp
** Author: Loc Nguyen
** Date: 05/27/2019
** Description: Hunt the wumpus the game  
** Input: user's movement or shoot arrows
** Output: appropriate message following player's action
******************************************************/
#ifndef WUMPUS_H
#define WUMPUS_H
#include "./event.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;
class Wumpus: public Event
{
    public:
      Wumpus();
      void percept();
      void encounter(Player& the_player);
      int initial_x;
      int initial_y;
      int w_x;
      int w_y;
};
#endif