/******************************************************
** Program: wumpus.cpp
** Author: Loc Nguyen
** Date: 05/27/2019
** Description: Hunt the wumpus the game  
** Input: user's movement or shoot arrows
** Output: appropriate message following player's action
******************************************************/
#include "./points.h"
/*********************************************************************
** Function:get_x
** Description:accessor for x
** Parameters: None
** Pre-Conditions: None
** Post-Conditions:None
*********************************************************************/
int points::get_x()
{
    return x;
}

/*********************************************************************
** Function:set_y
** Description:mutator for y
** Parameters: int temp
** Pre-Conditions: None
** Post-Conditions:None
*********************************************************************/
void points::set_x(int temp)
{
    x = temp;
}

/*********************************************************************
** Function:get_y
** Description:accessor for y
** Parameters: None
** Pre-Conditions: None
** Post-Conditions:None
*********************************************************************/
int points::get_y()
{
    return y;
}

/*********************************************************************
** Function:set_y
** Description:mutator for y
** Parameters: int temp
** Pre-Conditions: None
** Post-Conditions:None
*********************************************************************/
void points::set_y(int temp)
{
    y = temp;
}

