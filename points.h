/******************************************************
** Program: wumpus.cpp
** Author: Loc Nguyen
** Date: 05/27/2019
** Description: Hunt the wumpus the game  
** Input: user's movement or shoot arrows
** Output: appropriate message following player's action
******************************************************/
#ifndef POINTS_H
#define POINTS_H
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;
class points
{
    private:
        int x;
        int y;
    public:
        int get_x();
        void set_x(int temp);

        int get_y();
        void set_y(int temp);
};
#endif