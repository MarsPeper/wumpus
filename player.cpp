/******************************************************
** Program: wumpus.cpp
** Author: Loc Nguyen
** Date: 05/27/2019
** Description: Hunt the wumpus the game  
** Input: user's movement or shoot arrows
** Output: appropriate message following player's action
******************************************************/
#include "./player.h"

/*********************************************************************
** Function:default constructor for player
** Description:default constructor for player
** Parameters: None
** Pre-Conditions: None
** Post-Conditions:None
*********************************************************************/ 
Player::Player()
{
  arrows = 3;
}
/*********************************************************************
** Function:mutator for player_X
** Description:mutator for player_X
** Parameters: int temp
** Pre-Conditions: None
** Post-Conditions:None
*********************************************************************/ 
void Player::set_x(int temp)
{
  x = temp;
}

/*********************************************************************
** Function:mutator for player_y
** Description:mutator for player_y
** Parameters: int temp
** Pre-Conditions: None
** Post-Conditions:None
*********************************************************************/ 
void Player::set_y(int temp)
{
  y = temp;
}

/*********************************************************************
** Function:accessor for player_X
** Description:accessor for player_X
** Parameters: None
** Pre-Conditions: None
** Post-Conditions:None
*********************************************************************/ 
int Player::get_x()
{
  return x;
}

/*********************************************************************
** Function:accessor for player_y
** Description:accessor for player_y
** Parameters: None
** Pre-Conditions: None
** Post-Conditions:None
*********************************************************************/ 
int Player::get_y()
{
  return y;
}
