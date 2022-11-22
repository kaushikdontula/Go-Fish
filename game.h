#ifndef game_h
#define game_h
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>

#include "player.h"
#include "deck.h"
using namespace std;


class Game {
     private:
          Deck d;
          Player players[2];
     public:
     Game();
     void initialize_shuffle();
     void set_hands();
     void player_shows();
     void computer_shows();
     void player_turn(int&, int&, int&);
     void computer_turn(int&, int&, int&);
     int game_over();
     void check_book(int, int, int);
     int get_numberofbooks();
     void check_if_empty();
     void print_all_books(int, int, int, int);
// must have constructors, destructor, accessors, and mutators 
};






#endif