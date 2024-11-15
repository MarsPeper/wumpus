/******************************************************
** Program: wumpus.cpp
** Author: Loc Nguyen
** Date: 05/27/2019
** Description: Hunt the wumpus the game  
** Input: user's movement or shoot arrows
** Output: appropriate message following player's action
******************************************************/
#ifndef PITS_H
#define PITS_H
#include "./event.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;
class Pits: public Event
{
    public:
      void percept();
      void encounter(Player& the_player);
      Pits();
};
#endif
