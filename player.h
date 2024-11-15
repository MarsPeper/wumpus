/******************************************************
** Program: wumpus.cpp
** Author: Loc Nguyen
** Date: 05/27/2019
** Description: Hunt the wumpus the game  
** Input: user's movement or shoot arrows
** Output: appropriate message following player's action
******************************************************/
#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

class Player
{
  private:
    int x;
    int y;
  public:
    int arrows;
    int map_size;
    Player();
    bool instant_lost;
    int initial_x;
    int initial_y;
    bool win_con;
    bool flag; // If arrows hit then set flag too true
    void set_x(int temp);
    void set_y(int temp);
    int get_x();
    int get_y();


    
};
#endif