/******************************************************
** Program: wumpus.cpp
** Author: Loc Nguyen
** Date: 05/27/2019
** Description: Hunt the wumpus the game  
** Input: user's movement or shoot arrows
** Output: appropriate message following player's action
******************************************************/
#include "./bats.h"

/*********************************************************************
** Function: Default constructor
** Description: Default constructor
** Parameters: none
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/ 

Bats::Bats()
{
  cout << "Loading bats" << endl;
}
/*********************************************************************
** Function: Percept
** Description: Percept function of bat
** Parameters: none
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/ 
void Bats::percept()
{
  cout << "You hear wings flapping." << endl;
}
/*********************************************************************
** Function: encounter
** Description: encounter function of bat
** Parameters: Player& the_player
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/ 
void Bats::encounter(Player& the_player)
{
  cout << "You've encountered a swarm of bats..." << endl;
  cout << "You will now be teleported to another random room..." << endl;
  the_player.set_x(rand() % the_player.map_size);
  the_player.set_y(rand() % the_player.map_size);
}

