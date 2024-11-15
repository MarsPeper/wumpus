/******************************************************
** Program: wumpus.cpp
** Author: Loc Nguyen
** Date: 05/27/2019
** Description: Hunt the wumpus the game  
** Input: user's movement or shoot arrows
** Output: appropriate message following player's action
******************************************************/
#include "./room.h"
/*********************************************************************
** Function:set_event_wumpus
** Description:set up polymorphism
** Parameters: temp event
** Pre-Conditions: None
** Post-Conditions:None
*********************************************************************/ 
void Room::set_event_wumpus(Wumpus& temp_wumpus)
{
    room_event = &temp_wumpus;
}

/*********************************************************************
** Function:set_event_pits
** Description:set up polymorphism
** Parameters: temp event
** Pre-Conditions: None
** Post-Conditions:None
*********************************************************************/ 
void Room::set_event_pits(Pits& temp_pits)
{
    room_event = &temp_pits;
}

/*********************************************************************
** Function:set_event_bats
** Description:set up polymorphism
** Parameters: temp event
** Pre-Conditions: None
** Post-Conditions:None
*********************************************************************/ 
void Room::set_event_bats(Bats& temp_bats)
{
    room_event = &temp_bats;
}

/*********************************************************************
** Function:set_event_gold
** Description:set up polymorphism
** Parameters: temp event
** Pre-Conditions: None
** Post-Conditions:None
*********************************************************************/ 
void Room::set_event_gold(Gold& temp_gold)
{
    room_event = &temp_gold;
}

/*********************************************************************
** Function:set_event_empty
** Description:set up polymorphism
** Parameters: None
** Pre-Conditions: None
** Post-Conditions:None
*********************************************************************/ 
void Room::set_event_empty()
{
  room_event = NULL;
}

/*********************************************************************
** Function:set_event_rope
** Description:set up polymorphism
** Parameters: temp event
** Pre-Conditions: None
** Post-Conditions:None
*********************************************************************/ 
void Room::set_event_rope(Rope& temp_rope)
{
    room_event = &temp_rope;
}

/*********************************************************************
** Function:get_event
** Description:accessor for event
** Parameters: none
** Pre-Conditions: None
** Post-Conditions:None
*********************************************************************/ 
Event* Room::get_event()
{
  return room_event;
}

/*********************************************************************
** Function:get_symbol
** Description:accessor for symbol
** Parameters: none
** Pre-Conditions: None
** Post-Conditions:None
*********************************************************************/ 
string Room::get_symbol()
{
  return symbol;
}

/*********************************************************************
** Function:set_symbol
** Description:mutator for event
** Parameters: string temp
** Pre-Conditions: None
** Post-Conditions:None
*********************************************************************/   
void Room::set_symbol(string temp)
{
  symbol = temp;
}