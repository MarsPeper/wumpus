/******************************************************
** Program: wumpus.cpp
** Author: Loc Nguyen
** Date: 05/27/2019
** Description: Hunt the wumpus the game  
** Input: user's movement or shoot arrows
** Output: appropriate message following player's action
******************************************************/
//Don't really need this
#ifndef EMPTY_H
#define EMPTY_H
#include "./event.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;
class Empty: public Event
{
    private:
    public:
      void percept();
      void encounter(Player& the_player);

};
#endif
