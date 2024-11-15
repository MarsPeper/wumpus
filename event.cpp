/******************************************************
** Program: wumpus.cpp
** Author: Loc Nguyen
** Date: 05/27/2019
** Description: Hunt the wumpus the game  
** Input: user's movement or shoot arrows
** Output: appropriate message following player's action
******************************************************/
//Abstract class so don't really need anything
#include "./event.h"
/*********************************************************************
** Function:percept abstract
** Description:percept abstract
** Parameters: None
** Pre-Conditions: None
** Post-Conditions:None
*********************************************************************/ 
void Event::percept()
{
  cout << "Percept" << endl;
}
/*********************************************************************
** Function:encounter abstract
** Description:encounter abstract
** Parameters: None
** Pre-Conditions: None
** Post-Conditions:None
*********************************************************************/ 
void Event::encounter(Player& the_player)
{
  cout << "Encounter" << endl;
}

