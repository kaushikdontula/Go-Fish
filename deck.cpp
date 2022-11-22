/******************************************************************* ** 
** Program: deck.cpp
** Author: Kaushik Dontula
** Date: 10/23/2022
** Description: This program creates the class deck
** Input: all class files
** Output: deck class 
*******************************************************************/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <cstring>
#include "deck.h"
#include <string>
#include "card.h"

using namespace std;

Deck :: Deck(){
     //cout << inside the constructor << endl;
}


/******************************************************************* 
** Function: set_ncards
** Description: This sets the number of cards to 52
** Parameters: int n 
** Pre-conditions: n_cards
** Post-conditions:puts the updated value of the n_cards into the private variable
*******************************************************************/
void Deck::set_ncards(int n){
     this -> n_cards = 52;
}

/******************************************************************* 
** Function: get_ncards
** Description: This gets the number of cards in the deck
** Parameters:  none 
** Pre-conditions: n_cards
** Post-conditions:returns the number of cards in the deck
*******************************************************************/
int Deck::get_ncards(){
     cout << this -> n_cards;
     return this -> n_cards;
}


/******************************************************************* 
** Function: set_deck
** Description: This is a mutator that mutates the deck to initialize it
** Parameters: none 
** Pre-conditions: card class
** Post-conditions: updates the deck
*******************************************************************/
void Deck::set_deck(){
          int k=0;
          for(int i=1; i<=13; i++){
               for(int j=1; j<=4;j++){
                    //cout << "Card: " << k << endl;
                    cards[k].set_rank(i);
                    cards[k].set_suit(j);
                    //cards[k].output_card();
                    cout << endl << endl;
                    k++;
               }
          }
}


/******************************************************************* 
** Function: shuffle_deck
** Description: This is a mutator that shuffles the deck of cards
** Parameters: none 
** Pre-conditions: deck initialization
** Post-conditions:returns a shuffled deck
*******************************************************************/
void Deck::shuffle_deck(){
     for (int i=0; i<52; i++){
          srand(time(NULL));

          //swap 2 
          for (int i=0; i<51;i++){
               Card temp;
               Card a;
               Card b;

               int one = rand()%52;
               int two = rand()%52;

               

               a = cards[one];
               b = cards[two];
               
               // cout << "Before" << endl;
               //  a.output_card();
               //  cout << endl; 
               //  b.output_card();
               //  cout << endl << endl;
               
               temp = a;
               a = b;
               b = temp;
               
               cards[one] = a;
               cards[two] = b;

               // cout << "After" << endl;
               //  cards[one].output_card();
               //  cout << endl; 
               //  cards[two].output_card();
               //  cout << endl << endl;
          }
     }
}

/******************************************************************* 
** Function: print_deck
** Description: This is a function that just prints the deck
** Parameters: none
** Pre-conditions: deck 
** Post-conditions: outputs the deck in the terminal
*******************************************************************/
void Deck::print_deck(){
          for(int i=0; i<52; i++){
               cout << i << endl;
                cards[i].output_card();

          }
}


/******************************************************************* 
** Function: draw_from_deck
** Description: This is a function that allows players to draw from the deck of cards
** Parameters: none 
** Pre-conditions: deck initilization and shuffle
** Post-conditions:n_cards and the card given
*******************************************************************/
Card& Deck::draw_from_deck(){
     this-> n_cards --;
     //cout << endl << "amount of cards left: " << n_cards << endl << endl;
     //cout << "The card you drew: ";
     //cards[n_cards].output_card();
     cout << "AMOUNT OF CARDS LEFT: " << n_cards << endl;
     return this->cards[this->n_cards];
}



