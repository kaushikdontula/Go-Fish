#ifndef player_h
#define player_h
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>

#include "hand.h"

using namespace std;



class Player {
     private:
          Hand hand;
          int* books; // Array with ranks for which the player has books. int n_books;
          int n_books;
     public:
     // must have constructors, destructor, accessors, and mutators
     Player();
     //Player (int size);
     ~Player(); //destructor
     Player (const Player &); //copy constructor
     Player& operator=(const Player &); //assignment operator overload
     void get_card(Card&);
     void get_hand();
     int error_player();
     int check_playerhand(int);
     Card retrieve_card(int, int);
     void delete_card( int);
     int error_computer();
     int retrieve_num_cards();
     int get_book(int&);
     int print_book(int);
     int get_nbooks();


};





#endif