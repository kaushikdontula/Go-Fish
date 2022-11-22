/******************************************************************* ** 
** Program: player.cpp
** Author: Kaushik Dontula
** Date: 10/23/2022
** Description: This program creates the class player
** Input: all class files
** Output: card player 
*******************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <cstring>
#include "card.h"
#include "hand.h"
#include "player.h"
#include <string>

using namespace std;

Player::Player(){
    this->books = 0;
    this->books = new int [13];
    this->n_books = 0;
};

//non-default constructor
// Player::Player (int size) {
//     this->n_books = size;
//     this->books = new int [13];
// }



//destructor
Player::~Player(){
    //cout << "Inside the destructor... " << endl;
    
    if (this->books != NULL){
        delete [] this->books;
        this->books = NULL;
    }
}


//copy constructor
Player:: Player(const Player &k){
    cout << "Inside the copy constructor... " << endl;

    this->hand = k.hand;
    this->n_books = k.n_books;

    //deep copy 
    this->books = new int [this->n_books];
    
    for (int i=0; i<this->n_books; ++i){
        this->books[i] = k.books[i];
    }
}


//assignment operator overload
Player& Player::operator=(const Player &a){
    cout << "Inside the assignment operator overload... " << endl;

    //member wise copy
    this->hand = a.hand;
    this->n_books = a.n_books;

    //free memory
    if (this->books != NULL){
        delete [] this->books;
        this->books = NULL;
    }

    //deep copy
    this->books = new int [this->n_books];
    for (int i=0; i<this->n_books; ++i){
        this->books[i] = a.books[i];
    }

    return *this;
}


/******************************************************************* 
** Function: get_nbooks
** Description: This is a accessor tat gets the variable nbooks
** Parameters: none 
** Pre-conditions: nbooks
** Post-conditions:returns the n_books variable
*******************************************************************/
int Player::get_nbooks(){
    return this->n_books;
}


/******************************************************************* 
** Function: print_book
** Description: this prints the book of cards at i
** Parameters: int i 
** Pre-conditions: books
** Post-conditions:returns the books at the array value of i
*******************************************************************/
int Player::print_book(int i){
    return this-> books[i];
}


/******************************************************************* 
** Function: get_card
** Description: this adds a card to the array
** Parameters: Card &a 
** Pre-conditions: Card created
** Post-conditions: adds a card to the hand
*******************************************************************/
void Player::get_card(Card& a){
    this->hand.add_card(a);
}


/******************************************************************* 
** Function: delete_card
** Description: this function deletes a card 
** Parameters: int rank 
** Pre-conditions: rank
** Post-conditions: deletes a card
*******************************************************************/
void Player::delete_card( int rank){
    this->hand.del_card(rank);
}


/******************************************************************* 
** Function: get_hand
** Description: This is a accessor that accesses the hand
** Parameters: none 
** Pre-conditions: hand created
** Post-conditions: shows the cards in a hand
*******************************************************************/
void Player::get_hand(){
    hand.show_hand();
}



/******************************************************************* 
** Function: error_player
** Description: This is a function that error handles the players rank input
** Parameters: none 
** Pre-conditions: get rank from player
** Post-conditions: returns the rank
*******************************************************************/
int Player::error_player(){
    bool turnover = 0;
    int rank;
    do{

        cout << "What is the rank of card you are fishing for: ";
        cin >> rank;

        for(int i=0; i<hand.get_num_cards(); i++){
            if(rank == hand.pass_rank(i)){
                //cout << "That is a valid input" << endl;
                //hand.show_hand();
                //hand.remove_card(i);

                turnover = 1;
                

            }
            else {
                //cout << "Sorry that was not a valid rank in your deck..." << endl;
                //turnover = 0;
            }
        };
        //turnover = 1;
    }while(turnover == 0);
    return rank;
}


/******************************************************************* 
** Function: check_playerhand
** Description: this checks the playerhand for the amount of cards they have a rank for
** Parameters: int rank 
** Pre-conditions: rank
** Post-conditions: returns the count
*******************************************************************/
int Player::check_playerhand(int rank){
    int count=0;
    for(int i=0; i<hand.get_num_cards();i++){
        if (rank == hand.pass_rank(i)){
            count++;
        }
    }
    return count;
}


/******************************************************************* 
** Function: retrieve num_cards
** Description: This is a function that returns the number of cards
** Parameters: none 
** Pre-conditions: get num cards
** Post-conditions:returns the number of cards from hand
*******************************************************************/
int Player::retrieve_num_cards(){
    return this->hand.get_num_cards();
}


/******************************************************************* 
** Function: retrieve_card
** Description: This is a function that retrieves the card
** Parameters: int rank , int i
** Pre-conditions: rank, and i
** Post-conditions:returns the card associated with the rank
*******************************************************************/
Card Player::retrieve_card(int rank, int i){

    //for(i; i<hand.get_num_cards();i++){
        if (rank == hand.pass_rank(i)){
            Card h;
            h = hand.remove_card(i);
            return h;
        }
    //}
}


/******************************************************************* 
** Function: error_computer
** Description: This is a function that error handles the computer
** Parameters: none 
** Pre-conditions: computer player
** Post-conditions:returns the rank
*******************************************************************/
int Player::error_computer(){
    int rank=0;
    for(int i=0; i<hand.get_num_cards(); i++){
        for(rank=1;rank<14;rank++){
            if(rank == hand.pass_rank(i)){
                //cout << "That is a valid input" << endl;
                //hand.show_hand();
                //hand.remove_card(i);

            return rank;

            }
        }
    }
}


/******************************************************************* 
** Function: get_book
** Description: gets the book from the player
** Parameters: int arraycount 
** Pre-conditions: arraycount
** Post-conditions:returns i
*******************************************************************/
int Player:: get_book(int &arraycount){
    //Player(arraycount);
    for(int i =1; i<14; i++){
        int count=0;
        for (int j=0; j<hand.get_num_cards();j++){
            if(hand.pass_rank(j) == i){
                count++;
                //this->n_books++;
            }
        }
        //cout << "rank ===== " << i << "the count is" << count << endl;
        
        if(count>3){

            cout << "BOOK LAID DOWN.................................." << endl;
            
            //cout << books << endl;
            this->n_books++;
            this->books[arraycount] = i;

            cout << "THE BOOK JUST RECIEVED  IS:  "<< this->books[arraycount] << endl;
            arraycount++;
            cout <<  "The amount of books are: " << arraycount << endl << endl;
            return i;
        }
    }

}


