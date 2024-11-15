/******************************************************
** Program: wumpus.cpp
** Author: Loc Nguyen
** Date: 05/27/2019
** Description: Hunt the wumpus the game  
** Input: user's movement or shoot arrows
** Output: appropriate message following player's action
******************************************************/
#include "./pit.h"
/*********************************************************************
** Function:default constructor for pits
** Description:default constructor for pits
** Parameters: None
** Pre-Conditions: None
** Post-Conditions:None
*********************************************************************/ 
Pits::Pits()
{
   cout << "Loading bottomless pits" << endl;
}

/*********************************************************************
** Function:percept
** Description:percept for pits
** Parameters: None
** Pre-Conditions: None
** Post-Conditions:None
*********************************************************************/ 
void Pits::percept()
{
  cout << "You feel a breeze." << endl;
}
/*********************************************************************
** Function:encounter for pits
** Description:encounter function for pits
** Parameters: Player& the_player
** Pre-Conditions: None
** Post-Conditions:None
*********************************************************************/ 
void Pits::encounter(Player& the_player)
{
 cout << "You fell into the bottomless pit." << endl;
 cout << "You lost..." << endl;
 the_player.instant_lost = true; 
}

