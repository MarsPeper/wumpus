/******************************************************
** Program: wumpus.cpp
** Author: Loc Nguyen
** Date: 05/27/2019
** Description: Hunt the wumpus the game  
** Input: user's movement or shoot arrows
** Output: appropriate message following player's action
******************************************************/
#ifndef EVENT_H
#define EVENT_H
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include "player.h"
using namespace std;
class Event
{
    public:
        virtual void percept() = 0;
        virtual void encounter(Player& the_player) = 0;
};  
#endif