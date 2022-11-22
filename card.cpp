/******************************************************************* ** 
** Program: card.cpp
** Author: Kaushik Dontula
** Date: 10/23/2022
** Description: This program creates the class card
** Input: all class files
** Output: card class 
*******************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <cstring>
#include "card.h"
#include <string>

using namespace std;

//default constructor
Card::Card(){
     //cout << "Inside the constructor... " << endl;
}

/******************************************************************* 
** Function: set_rank
** Description: This is a mutator that mutates the rank
** Parameters: int rank 
** Pre-conditions: rank
** Post-conditions:puts the updated rank in rank
*******************************************************************/
void Card::set_rank(int rankcard){
     this->rank = rankcard;
}

/******************************************************************* 
** Function: get_rank
** Description: This is a accessor that accesses the rank
** Parameters: none
** Pre-conditions: rank
** Post-conditions:returns the updated rank
*******************************************************************/
int Card::get_rank(){
     return this->rank;
}

/******************************************************************* 
** Function: set_suit
** Description: This is a mutator that mutates the suit
** Parameters: int suit 
** Pre-conditions: suit
** Post-conditions:returns the updated suit to the suit variable
*******************************************************************/
void Card::set_suit(int suitcard){
     this->suit = suitcard;
}

/******************************************************************* 
** Function: get_suit
** Description: This is a accessor that accesses the suit
** Parameters: int suit 
** Pre-conditions: suit
** Post-conditions:returns the updated suit
*******************************************************************/
int Card::get_suit(){
     return this->suit;
}


/******************************************************************* 
** Function: map_suit
** Description: This is a mutator that mutates the suit
** Parameters: none 
** Pre-conditions: suit
** Post-conditions:returns the updated suit
*******************************************************************/
string Card::map_suit(){
     string suitmap;
     suitmap = to_string(get_suit());

     if (this->suit == 1){
          suitmap = "Hearts";
     }
     if (this->suit == 2){
          suitmap = "Diamonds";
     }
     if (this->suit == 3){
          suitmap = "Clubs";
     }
     if (this->suit == 4){
          suitmap = "Spades";
     }
     return suitmap;
}


/******************************************************************* 
** Function: map_rank
** Description: This is a mutator that mutates the rank
** Parameters: none
** Pre-conditions: rank
** Post-conditions:returns the updated rank
*******************************************************************/
string Card::map_rank(){
     string rankmap="";
     rankmap = to_string(get_rank());

     if (rankmap == "11"){
          rankmap = "Jack";
          return rankmap;
     }
      else if (rankmap == "12"){
          rankmap = "Queen";
          return rankmap;
     }
     else if (rankmap == "13"){
          rankmap = "King";
          return rankmap;
     }
     else if (rankmap == "1"){
          rankmap = "Ace";
          return rankmap;
     }
          else{
               return rankmap;
          }
}


/******************************************************************* 
** Function: output_card
** Description: This is a function that outputs the card
** Parameters: none 
** Pre-conditions: map_rank and map_suit
** Post-conditions:outputs the card on the terminal
*******************************************************************/
void Card::output_card(){
     cout << endl << map_rank() << " of " << map_suit() << endl;
     //cout << endl << "Suit: " << map_suit() << endl << "Rank: " << map_rank() << endl;
}

