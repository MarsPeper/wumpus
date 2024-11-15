/******************************************************
** Program: wumpus.cpp
** Author: Loc Nguyen
** Date: 05/27/2019
** Description: Hunt the wumpus the game  
** Input: user's movement or shoot arrows
** Output: appropriate message following player's action
******************************************************/
#ifndef ROOM_H
#define ROOM_H
#include "./event.h"
#include "./wumpus.h"
#include "./pit.h"
#include "./bats.h"
#include "./gold.h"
#include "./rope.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;
class Room
{
    private:
        Event* room_event;
        string symbol;
    public:
        void set_event_wumpus(Wumpus& temp_wumpus);
        void set_event_pits(Pits& temp_pits);
        void set_event_bats(Bats& temp_bats);
        void set_event_gold(Gold& temp_gold);
        void set_event_empty();
        void set_event_rope(Rope& temp_rope);
        Event* get_event();
        string get_symbol();
        void set_symbol(string temp);

        
};
#endif