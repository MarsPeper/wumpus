/******************************************************
** Program: wumpus.cpp
** Author: Loc Nguyen
** Date: 05/27/2019
** Description: Hunt the wumpus the game  
** Input: user's movement or shoot arrows
** Output: appropriate message following player's action
******************************************************/
#ifndef GOLD_H
#define GOLD_H
#include "./event.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;
class Gold: public Event
{
    private:
    public:
      void percept();
      void encounter(Player& the_player);
      Gold();
      int initial_x;
      int initial_y;
}; 
#endif
