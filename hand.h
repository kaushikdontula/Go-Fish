#ifndef hand_h
#define hand_h

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>

#include "card.h"

using namespace std;



class Hand {
     private:
          Card* cards;  // An array of cards in hand
          int n_cards;  // Number of cards in the hand.
     public:
     Hand();
     Hand(const Hand&); //copy constructor
     Hand& operator=(const Hand &); //assignment operator overload
     int get_num_cards();
     int pass_rank(int);
     ~Hand();
     void add_card(Card&);
     void show_hand();
     Card remove_card(int);
     void del_card( int);

// must have constructors, destructor, accessors, and mutators 
};

// void Hand:: distribute_cards(){

// }

#endif