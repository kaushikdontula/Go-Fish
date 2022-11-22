#ifndef card_h
#define card_h
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;



class Card {
     private:
         int rank;  // Should be in the range 0-12.
         int suit;  // Should be in the range 0-3.
     public:
          Card(); //Card constructor void set_rank(int);
          void set_rank(int);
          int get_rank();
          void set_suit(int);
          int get_suit();
          string map_rank(); //convert the int suit to corresponding string string map_rank();
          string map_suit(); 
          void output_card();
           //convert the int rank to corresponding string void print_card(); //print the card out
// must have constructors, destructor, accessors, and mutators 
};







#endif