#ifndef deck_h
#define deck_h
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>

#include "card.h"
using namespace std;



class Deck {
     private:
          Card cards[52]; //A full deck of cards
          int n_cards; // Number of cards remaining in the deck. public:
// must have constructors, destructor, accessors, and mutators 
     public:
          Deck(); // deck constructor
          void set_ncards(int);
          int get_ncards();
          void set_deck();
          void shuffle_deck();
          void print_deck();
          Card& draw_from_deck();
          
};


#endif