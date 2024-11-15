/******************************************************
** Program: wumpus.cpp
** Author: Loc Nguyen
** Date: 05/27/2019
** Description: Hunt the wumpus the game  
** Input: user's movement or shoot arrows
** Output: appropriate message following player's action
******************************************************/
#include "./wumpus.h"
/*********************************************************************
** Function:default constructor for Wumpus
** Description:default constructor for Wumpus
** Parameters: None
** Pre-Conditions: None
** Post-Conditions:None
*********************************************************************/ 
Wumpus::Wumpus()      
{
  cout << "Loading Wumpus." << endl;
}

/*********************************************************************
** Function:percept for Wumpus
** Description:percept for Wumpus
** Parameters: None
** Pre-Conditions: None
** Post-Conditions:None
*********************************************************************/ 
void Wumpus::percept()
{
  cout << "You smell a terrible stench." << endl;    
}

/*********************************************************************
** Function:encounter for Wumpus
** Description:encounter for Wumpus
** Parameters: None
** Pre-Conditions: None
** Post-Conditions:None
*********************************************************************/ 
void Wumpus::encounter(Player& the_player)
{
  cout << "You woke the Wumpus up..." << endl;
  cout << "You've been eaten by the Wumpus..." << endl;
  cout << "You lost..." << endl;
  the_player.instant_lost = true;
}