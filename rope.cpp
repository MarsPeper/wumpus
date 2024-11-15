/******************************************************
** Program: wumpus.cpp
** Author: Loc Nguyen
** Date: 05/27/2019
** Description: Hunt the wumpus the game  
** Input: user's movement or shoot arrows
** Output: appropriate message following player's action
******************************************************/
#include "./rope.h"

/*********************************************************************
** Function:default constructor for rope
** Description:default constructor for rope
** Parameters: None
** Pre-Conditions: None
** Post-Conditions:None
*********************************************************************/ 
Rope::Rope()      
{
  cout << "Loading Rope" << endl;
}
/*********************************************************************
** Function:percept for rope
** Description:percept for rope
** Parameters: None
** Pre-Conditions: None
** Post-Conditions:None
*********************************************************************/ 
void Rope::percept()
{
  //no percept needed...
}

/*********************************************************************
** Function:encounter for rope
** Description:encounter for rope
** Parameters: None
** Pre-Conditions: None
** Post-Conditions:None
*********************************************************************/ 
void Rope::encounter(Player& the_player)
{
  if (the_player.win_con)
  {
    cout << "You win. YOU SUCCESSFULLY ESCAPED" << endl;
  }
}