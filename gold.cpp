/******************************************************
** Program: wumpus.cpp
** Author: Loc Nguyen
** Date: 05/27/2019
** Description: Hunt the wumpus the game  
** Input: user's movement or shoot arrows
** Output: appropriate message following player's action
******************************************************/
#include "./gold.h"

/*********************************************************************
** Function:default constructor for gold
** Description:default constructor for gold
** Parameters: None
** Pre-Conditions: None
** Post-Conditions:None
*********************************************************************/ 
Gold::Gold()
{
  cout << "Loading gold..." << endl;
}

/*********************************************************************
** Function:percept gold
** Description:percept gold
** Parameters: None
** Pre-Conditions: None
** Post-Conditions:None
*********************************************************************/ 
void Gold::percept()
{
  cout << "You see a glimmer nearby." << endl;
}

/*********************************************************************
** Function:encounter gold
** Description:encounter gold
** Parameters: Player& the_player
** Pre-Conditions: None
** Post-Conditions:None
*********************************************************************/ 
void Gold::encounter(Player& the_player)
{
  ///Note (May 20th): If you enter the cave, retrieve the gold, and escape without killing the Wumpus, that's okay too. The player still wins.
  cout << "You've found the gold. Gold collected." << endl;
  the_player.win_con = true; 
}
