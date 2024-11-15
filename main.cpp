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
#include "./game.h"
using namespace std;

int main(int argc,char* argv[])
{
    string user_dec;
    //initialize random seed
    string temp_size(argv[1]);
    srand(time(NULL));
    Game new_game(atoi(temp_size.c_str()));

    string temp(argv[2]);
    if (temp == "true")
    {
      new_game.debug = true;
    }
    else
    {
      new_game.debug = false;
    }
    new_game.game_flow();
    
    do
    {
      cout << "Would you like to play in the same cave configuration(1), a new one(2) or quit(0)?" << endl;
      getline(cin, user_dec);
      if (user_dec == "1")
      {
        new_game.reset_game();
        new_game.game_flow();
      }
      else if (user_dec == "2")
      {
        new_game.initialize_game();
        new_game.game_flow();
      }
      else if (user_dec == "0")
      {
        cout << "Ending game..." << endl;
      }
      else
      {
        cout << "Invalid input... Please try again..." << endl;
      }
     }
    while(user_dec != "0");
    return 0;
}
