/******************************************************
** Program: wumpus.cpp
** Author: Loc Nguyen
** Date: 05/27/2019
** Description: Hunt the wumpus the game  
** Input: user's movement or shoot arrows
** Output: appropriate message following player's action
******************************************************/
#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include "./empty.h"
#include "./rope.h"
#include "./points.h"
#include "./room.h"
#include "./bats.h"
#include "./event.h"
#include "./gold.h"
#include "./pit.h"
#include "./wumpus.h"
#include "./player.h"
class Game
{
  public:
    int map_size;
    
    Wumpus the_wumpus;
    Bats the_bats[2];
    Pits the_pits[2];
    Gold the_gold;
    Rope the_rope;
    Player new_player;    
    Game(int temp_size);
    bool debug;
    vector  <vector <Room> > cave;
    void initialize_game();
    void initialize_map();
    void encounter_event();
    
    //events
    void generate_wumpus(vector <points>& points_set);
    void generate_bats(vector <points>& points_set);
    void generate_pits(vector <points>& points_set);
    void generate_gold(vector <points>& points_set);
    void generate_player(vector <points>& points_set);
    
    void wake_wumpus();
    void print_map_debug();
    void print_map_normal();
    void move();
    void shoot_arrows(string temp);
    void nearby_event();
    void game_flow();
    void reset_game();
};

#endif