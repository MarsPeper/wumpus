/******************************************************
** Program: wumpus.cpp
** Author: Loc Nguyen
** Date: 05/27/2019
** Description: Hunt the wumpus the game  
** Input: user's movement or shoot arrows
** Output: appropriate message following player's action
******************************************************/
#include "./game.h"

/*********************************************************************
** Function:Default constructor for game
** Description:Default constructor for game
** Parameters: temp_size
** Pre-Conditions: None
** Post-Conditions:None
*********************************************************************/ 
Game::Game(int temp_size)
{
  map_size = temp_size;
  initialize_game();
}
/*********************************************************************
** Function:initialize game
** Description:initialize game
** Parameters: None
** Pre-Conditions: None
** Post-Conditions:None
*********************************************************************/ 
void Game::initialize_game()
{
  if (map_size < 4)
  {
    cout << "Map size must be greater or equal to 4." << endl;
    while (map_size < 4)
    {
      cout << "Please enter map size: ";
      cin >> map_size;
      cin.ignore();
      if (map_size < 4)
      {
        cout << "Map size must be greater or equal to 4." << endl;
      }
    }
  }

  cave.resize(map_size, vector <Room>(map_size));
  initialize_map();
}
/*********************************************************************
** Function:initialize map
** Description:initialize map
** Parameters: None
** Pre-Conditions: None
** Post-Conditions:None
*********************************************************************/ 
void Game::initialize_map()
{
  //initialize point point array to randomize map

  vector <points> points_set;
  points_set.resize(map_size*map_size);
  int temp_count = 0;
  for (int i = 0; i < map_size; i++)
  {  
    for (int j = 0; j < map_size; j++)
      {
          points_set[temp_count].set_x(i);
          points_set[temp_count].set_y(j);
          temp_count += 1;
      }
  }
  ////////////////////////////////////////////////
  //Randomize map
    generate_wumpus(points_set);
    generate_bats(points_set);
    generate_pits(points_set);
    generate_gold(points_set);
    generate_player(points_set);

  //fill everything else with empty events
    for (unsigned int i = 0; i < points_set.size(); i++)
    {
      cave[points_set[i].get_x()][points_set[i].get_y()].set_event_empty();
      cave[points_set[i].get_x()][points_set[i].get_y()].set_symbol("E");
    }
}

/*********************************************************************
** Function:generate wumpus
** Description:generate wumpus
** Parameters: cave map
** Pre-Conditions: None
** Post-Conditions:None
*********************************************************************/ 
void Game::generate_wumpus(vector <points>& points_set)
{
  //generate wumpus
  int temp_index;
  temp_index = rand() % points_set.size(); //Generate a random index from 0 to points_set size
  cave[points_set[temp_index].get_x()][points_set[temp_index].get_y()].set_event_wumpus(the_wumpus);
  cave[points_set[temp_index].get_x()][points_set[temp_index].get_y()].set_symbol("W");
  the_wumpus.initial_x = points_set[temp_index].get_x();
  the_wumpus.w_x = points_set[temp_index].get_x();
  the_wumpus.initial_y = points_set[temp_index].get_y();
  the_wumpus.w_y = points_set[temp_index].get_y();
  points_set.erase(points_set.begin() + temp_index );

}

/*********************************************************************
** Function:generate bat
** Description:generate bat
** Parameters: cave map
** Pre-Conditions: None
** Post-Conditions:None
*********************************************************************/ 
void Game::generate_bats(vector <points>& points_set)
{
  //generate bats
  int temp_index;
  for (int i = 0; i < 2; i++)
  {
    temp_index = rand() % points_set.size(); //Generate a random index from 0 to points_set size
    cave[points_set[temp_index].get_x()][points_set[temp_index].get_y()].set_event_bats(the_bats[i]);
    cave[points_set[temp_index].get_x()][points_set[temp_index].get_y()].set_symbol("B");
    points_set.erase(points_set.begin() + temp_index);
  }
}

/*********************************************************************
** Function:generate pit
** Description:generate pit
** Parameters: cave map
** Pre-Conditions: None
** Post-Conditions:None
*********************************************************************/ 
void Game::generate_pits(vector <points>& points_set)
{
  int temp_index;
  //generate pits
  for (int i = 0; i < 2; i++)
  {
      temp_index = rand() % points_set.size(); //Generate a random index from 0 to points_set size
      cave[points_set[temp_index].get_x()][points_set[temp_index].get_y()].set_event_pits(the_pits[i]);
      cave[points_set[temp_index].get_x()][points_set[temp_index].get_y()].set_symbol("P");
      points_set.erase(points_set.begin() + temp_index);
  }
}


/*********************************************************************
** Function:generate gold
** Description:generate gold
** Parameters: cave map
** Pre-Conditions: None
** Post-Conditions:None
*********************************************************************/ 
void Game::generate_gold(vector <points>& points_set)
{
  //generate gold
  int temp_index;
  temp_index = rand() % points_set.size(); //Generate a random index from 0 to points_set size
  cave[points_set[temp_index].get_x()][points_set[temp_index].get_y()].set_event_gold(the_gold);
  cave[points_set[temp_index].get_x()][points_set[temp_index].get_y()].set_symbol("G");
  the_gold.initial_x = points_set[temp_index].get_x();
  the_gold.initial_y = points_set[temp_index].get_y();
  points_set.erase(points_set.begin() + temp_index);
}

/*********************************************************************
** Function:generate player
** Description:generate player
** Parameters: cave map
** Pre-Conditions: None
** Post-Conditions:None
*********************************************************************/ 
void Game::generate_player(vector <points>& points_set)
{
    //generate player's random position
    int temp_index;
    temp_index = rand() % points_set.size(); //Generate a random index from 0 to points_set size
    cave[points_set[temp_index].get_x()][points_set[temp_index].get_y()].set_event_rope(the_rope);
    cave[points_set[temp_index].get_x()][points_set[temp_index].get_y()].set_symbol("R");
    new_player.set_x(points_set[temp_index].get_x());
    new_player.set_y(points_set[temp_index].get_y());
    new_player.initial_x = new_player.get_x();
    new_player.initial_y = new_player.get_y();
    new_player.instant_lost = false;
    new_player.win_con = false;
    new_player.map_size = map_size;
    points_set.erase(points_set.begin() + temp_index);
    new_player.flag = false;
    new_player.arrows = 3;
}


/*********************************************************************
** Function:print map debug
** Description:print map debug mode
** Parameters: None
** Pre-Conditions: None
** Post-Conditions:None
*********************************************************************/ 
void Game::print_map_debug()
{
  cout << "Printing map in debug mode." << endl;
  cout << "Symbols of events:" << endl;
  cout << "W - Wumpus" << endl;
  cout << "G - Gold" << endl;
  cout << "B - Bats" << endl;
  cout << "P - Pits" << endl;
  cout << "R - Rope" << endl;
  cout << "E - Empty" << endl;
  cout << "* - Player" << endl;
  for (int i = 0; i < map_size; i++)
  {
    for (int j = 0; j < map_size; j++)
    {
      if ((i == new_player.get_x()) && (j == new_player.get_y()))
      {
        cout << "|  *  |";
      }
      else
      {
        cout << "|  " << cave[i][j].get_symbol() << "  |"; 
      }
    }
    cout << endl;
  }
}
/*********************************************************************
** Function:print map normal
** Description:print map normal mode
** Parameters: None
** Pre-Conditions: None
** Post-Conditions:None
*********************************************************************/ 
void Game::print_map_normal()
{
  for (int i = 0; i < map_size; i++)
  {
    for (int j = 0; j < map_size; j++)
    {
      if ((i == new_player.get_x()) && (j == new_player.get_y()))
      {
        cout << "|  *  |";
      }
      else
      {
        cout << "|     |";
      }
    }
    cout << endl;
  }
}

/*********************************************************************
** Function:move
** Description:get input for player's movement or shoot arrows
** Parameters: None
** Pre-Conditions: None
** Post-Conditions:None
*********************************************************************/ 
void Game::move()
{
  string temp;
  getline(cin, temp);
  cout << endl;
  if (temp == "w")
  {
    if (new_player.get_x() - 1 >= 0)
    {
      new_player.set_x(new_player.get_x()-1);
    }
    else
    {
      cout << "Error. You can't go there because there's the wall." << endl;
    }
  }
  else if (temp == "s")
  {
    if (new_player.get_x() + 1 < map_size)
    {
      new_player.set_x(new_player.get_x() + 1);
    }
    else
    {
      cout << "You can't go there because there's the wall." << endl;
    }
  }
  else if (temp == "a")
  {
    if (new_player.get_y() - 1 >= 0)
    {
      new_player.set_y(new_player.get_y()-1);
    }
    else
    {
      cout << "You can't go there because there's the wall." << endl;
    }
  }
  else if (temp == "d")
  {
    if (new_player.get_y() + 1 < map_size)
    {
      new_player.set_y(new_player.get_y() + 1);
    }
    else
    {
      cout << "You can't go there because there's the wall." << endl;
    }
  }
  else if ((temp == " a") || (temp == " d") || (temp == " s") || (temp == " w"))
  {
    shoot_arrows(temp);
  }
  else
  {
    cout << "Invalid input. Please try again..." << endl;
  }
}

/*********************************************************************
** Function:nearby events
** Description: trigger percept of nearby events
** Parameters: None
** Pre-Conditions: None
** Post-Conditions:None
*********************************************************************/ 
void Game::nearby_event()
{
  //polymorphism used here
  if (new_player.get_x() - 1 >= 0)
  {
    if (cave[new_player.get_x() - 1][new_player.get_y()].get_event() != NULL)
    {
      cave[new_player.get_x() - 1][new_player.get_y()].get_event()->percept();
    }
  }
  
  if (new_player.get_x() + 1 < map_size)
  {
    if (cave[new_player.get_x() + 1][new_player.get_y()].get_event() != NULL)
    {
      cave[new_player.get_x() + 1][new_player.get_y()].get_event()->percept();
    }
  }
  
  
  if (new_player.get_y() - 1 >= 0)
  {
    if (cave[new_player.get_x()][new_player.get_y() - 1].get_event() != NULL)
    {
      cave[new_player.get_x()][new_player.get_y() - 1].get_event()->percept();
    }
  }
  
  if (new_player.get_y() + 1 < map_size)
  {
    if (cave[new_player.get_x()][new_player.get_y() + 1].get_event() != NULL)
    {
      cave[new_player.get_x()][new_player.get_y() + 1].get_event()->percept();
    }
  }
}
/*********************************************************************
** Function:encounter_event
** Description:trigger nearby encounter event
** Parameters: None
** Pre-Conditions: None
** Post-Conditions:None
*********************************************************************/ 
void Game::encounter_event()
{
  if (cave[new_player.get_x()][new_player.get_y()].get_event() != NULL)
  {
    cave[new_player.get_x()][new_player.get_y()].get_event()->encounter(new_player);
  }
}

/*********************************************************************
** Function:shoot_arrows
** Description: let the player shoot arrows
** Parameters: temp
** Pre-Conditions: None
** Post-Conditions:None
*********************************************************************/ 
void Game::shoot_arrows(string temp)
{
  if (new_player.arrows >0)
  {
    new_player.arrows -= 1;
    if (temp == " w")
     {
       cout << "You shoot an arrow North" << endl;
       for (int i = 1; i <= 3; i++)
       {
         if (new_player.get_x() - i >= 0)
         {
           if (cave[new_player.get_x() - i][new_player.get_y()].get_symbol() == "W")
           {
             new_player.flag = true;
             cave[new_player.get_x() - i][new_player.get_y()].set_event_empty();
             cave[new_player.get_x() - i][new_player.get_y()].set_symbol("E");
             cout << "You killed the Wumpus..." << endl;
           }
         }
       }
     }
     else if (temp == " s")
     {
     cout << "You shoot an arrow South" << endl;
       for (int i = 1; i <= 3; i++)
       {
         if (new_player.get_x() + i < map_size)
         {
           if (cave[new_player.get_x() + i][new_player.get_y()].get_symbol() == "W")
           {
             new_player.flag = true;
             cave[new_player.get_x() - i][new_player.get_y()].set_event_empty();
             cave[new_player.get_x() - i][new_player.get_y()].set_symbol("E");
             cout << "You killed the Wumpus..." << endl;
           }
         }
       }
     }
     else if (temp == " a")
     {
       cout << "You shoot an arrow West" << endl;
       for (int i = 1; i <= 3; i++)
       {
         if (new_player.get_y() - i >= 0)
         {
           if (cave[new_player.get_x()][new_player.get_y() - i].get_symbol() == "W")
           {
             new_player.flag = true;
             cave[new_player.get_x() - i][new_player.get_y()].set_event_empty();
             cave[new_player.get_x() - i][new_player.get_y()].set_symbol("E");
             cout << "You killed the Wumpus..." << endl;
           }
         }
       }
     }
     else if (temp == " d")
     {
       cout << "You shoot an arrow East" << endl;
       for (int i = 1; i <= 3; i++)
       {
         if (new_player.get_y() + i < map_size)
         {
           if (cave[new_player.get_x()][new_player.get_y() + i].get_symbol() == "W")
           {
             new_player.flag = true;
             cave[new_player.get_x()][new_player.get_y() + i].set_event_empty();
             cave[new_player.get_x()][new_player.get_y() + i].set_symbol("E");
             cout << "You killed the Wumpus..." << endl;
           }
         }
       }
      }
      if (new_player.flag == false) // if missed the shot
      {
        wake_wumpus();
      }
  }
  else
  {
    cout << "You don't have any arrows left..." << endl;
  }
}

/*********************************************************************
** Function:wake_wumpus
** Description:If miss then 75% chance wumpus wake up and changes room
** Parameters: None
** Pre-Conditions: None
** Post-Conditions:None
*********************************************************************/ 
void Game::wake_wumpus()
{
  int temp_ran = rand() % 100 + 1; //generate random number from 1 to 100
  if (temp_ran <= 75) //75% chance of changing room
  {
    cout << "Wumpus is awake. It's moving to a new room." << endl;
    int temp_x, temp_y;
    do
    {
      temp_x = rand() % map_size;
      temp_y = rand() % map_size;
    }
    while (cave[temp_x][temp_y].get_symbol() != "E"); //wumpus can only move to empty room
    cave[the_wumpus.w_x][the_wumpus.w_y].set_event_empty();
    cave[the_wumpus.w_x][the_wumpus.w_y].set_symbol("E");
    the_wumpus.w_x = temp_x;
    the_wumpus.w_y = temp_y;
    cave[temp_x][temp_y].set_event_wumpus(the_wumpus);
    cave[temp_x][temp_y].set_symbol("W");
  }
}
/*********************************************************************
** Function:reset_game()
** Description: reset the game with same configuration
** Parameters: None
** Pre-Conditions: None
** Post-Conditions:None
*********************************************************************/ 
void Game::reset_game()
{
  //reset_wumpus position
  cave[the_wumpus.w_x][the_wumpus.w_y].set_event_empty();
  cave[the_wumpus.w_x][the_wumpus.w_y].set_symbol("E");
  cave[the_wumpus.initial_x][the_wumpus.initial_y].set_event_wumpus(the_wumpus);
  cave[the_wumpus.initial_x][the_wumpus.initial_y].set_symbol("W");
  
  //reset_gold position
  cave[the_gold.initial_x][the_gold.initial_y].set_event_gold(the_gold);

  //reset player
  new_player.set_x(new_player.initial_x);
  new_player.set_y(new_player.initial_y);
  new_player.flag = false;
  new_player.win_con = false;
  new_player.instant_lost = false;
  new_player.arrows = 3;
}

/*********************************************************************
** Function:game_flow
** Description:control general game flow of the whole game
** Parameters: None
** Pre-Conditions: None
** Post-Conditions:None
*********************************************************************/ 
void Game::game_flow()
{
  while(new_player.instant_lost == false)
  {
    if (debug)
    {
      print_map_debug();
    }
    else
    {
      print_map_normal();
    }
    cout << "You have: " << new_player.arrows << " arrows left" << endl;
    /// check_win_con
    if ((cave[new_player.get_x()][new_player.get_y()].get_symbol() == "R") && (new_player.win_con))
    {
      break;
    }
    nearby_event();
    move(); // shoot arrows is included in this function as well
    //edge case for the game flow is the bats event
    // While teleporting, must trigger the event after teleporting
    // also if teleport to another bats, then keep doing it again
    if (cave[new_player.get_x()][new_player.get_y()].get_symbol() == "B")
    {
      do
      {
        encounter_event();
      }
      while (cave[new_player.get_x()][new_player.get_y()].get_symbol() == "B");
    }
    //edge case two... remove the Gold event out of the room after collecting the gold...
    if (cave[new_player.get_x()][new_player.get_y()].get_symbol() == "G")
    {
      encounter_event();
      cave[new_player.get_x()][new_player.get_y()].set_event_empty();
    }
    
    encounter_event();
  }
}  