/******************************************************************* ** 
** Program: hand.cpp
** Author: Kaushik Dontula
** Date: 10/23/2022
** Description: This program creates the hand card
** Input: all class files
** Output: hand class 
*******************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <cstring>
#include "hand.h"
#include <string>

using namespace std;

Hand::Hand(){
    this->n_cards = 0;
    this->cards = NULL;
};


/******************************************************************* 
** Function: get_num_cards
** Description: gets the number of cards in hand
** Parameters: none 
** Pre-conditions: numberofcards
** Post-conditions:returns the updated numberofcards
*******************************************************************/
int Hand::get_num_cards(){
    //cout << this->n_cards;
    return this->n_cards;
}


/******************************************************************* 
** Function: pass_rank
** Description: This is a accessor that accesses the rank
** Parameters: int rank 
** Pre-conditions: rank
** Post-conditions:returns the updated rank
*******************************************************************/
int Hand::pass_rank(int i){
    return this-> cards[i].get_rank();
}


//destructor function
Hand::~Hand(){
    if (this->cards != NULL){
        delete[] this ->cards;
        this->cards=NULL;
    }
}


/******************************************************************* 
** Function: add_card
** Description: This is a mutator that adds a card to a dynamic array and returns it
** Parameters: Card &a 
** Pre-conditions: Card variable
** Post-conditions:returns the new card to add to the array
*******************************************************************/
void Hand::add_card(Card& a){
    Card* temp = new Card[this->n_cards +1];

    for(int j=0; j<this->n_cards;j++){
        temp[j] = this->cards[j];
    }

    temp[this->n_cards] = a;

    if(this->cards != NULL){
        delete [] this->cards;
    }

    this->cards = temp;

    this->n_cards++;
}


/******************************************************************* 
** Function: show_hand
** Description: This is a function that shows the hand of the player
** Parameters: none 
** Pre-conditions: hand created
** Post-conditions:outputs the card for the number of cards the player has
*******************************************************************/
void Hand::show_hand(){
    for(int i =0; i<this->n_cards;i++){
        this->cards[i].output_card();
    }
}


/******************************************************************* 
** Function: remove_card
** Description: This is a function that removes the card from the card array
** Parameters: int i 
** Pre-conditions: cards array
** Post-conditions: returns the value at the i value of cards
*******************************************************************/
Card Hand::remove_card(int i){
    return this->cards[i];
}


/******************************************************************* 
** Function: del_card
** Description: This is a function that deletes cards
** Parameters: int rank 
** Pre-conditions: rank
** Post-conditions:deletes the cards associated with the rank
*******************************************************************/
void Hand::del_card(int rank){

    int i =0;
    while(i<this->n_cards){
        if(cards[i].get_rank() == rank){
            if(i<(this->n_cards-1)){
                for(int j =i; j<(n_cards -1);j++){
                    this->cards[j] = this->cards[j+1];
                }
            }
            this->n_cards--;
        }
        else i++;
    }

}


//copy constructor
Hand:: Hand(const Hand &k){
    cout << "Inside the copy constructor for hand... " << endl;

    //this->cards = k.cards;
    this->n_cards = k.n_cards;

    //deep copy 
    this->cards = new Card [this->n_cards];
    
    for (int i=0; i<this->n_cards; ++i){
        this->cards[i] = k.cards[i];
    }
}


//assignment overload operator
Hand& Hand::operator=(const Hand &a){
    cout << "Inside the assignment operator overload for hand... " << endl;

    //member wise copy
    //this->hand = a.hand;
    this->n_cards = a.n_cards;

    //free memory
    if (this->cards != NULL){
        delete [] this->cards;
        this->cards = NULL;
    }

    //deep copy
    this->cards = new Card [this->n_cards];
    for (int i=0; i<this->n_cards; ++i){
        this->cards[i] = a.cards[i];
    }

    return *this;
}