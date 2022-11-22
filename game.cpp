/******************************************************************* ** 
** Program: game.cpp
** Author: Kaushik Dontula
** Date: 10/23/2022
** Description: This program creates the game class
** Input: all class files
** Output: game class 
*******************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <cstring>
#include "game.h"
#include "player.h"
#include <string>

using namespace std;

Game::Game(){
    cout << "Inside default constructor " << endl;
    d.set_ncards(51);
    d.get_ncards();
    d.set_deck();
    d.shuffle_deck();
    //d.print_deck();
}


/******************************************************************* 
** Function: game_over
** Description: This function checks if the game is over
** Parameters: none 
** Pre-conditions: player books
** Post-conditions:returns the bool
*******************************************************************/
int Game::game_over(){
    //cout << players[0].get_nbooks()+players[1].get_nbooks() << endl;
    if(players[0].get_nbooks()+players[1].get_nbooks() > 12){
        //cout << "GAME OVERRRRRRRRRRRRRRRRR BITCH" << endl;
        return 1;
    }
}


/******************************************************************* 
** Function: set_hands
** Description: This is a mutator that mutates the rhand of the player
** Parameters: none 
** Pre-conditions: hand h
** Post-conditions:returns the drawn card from the deck to the players hand
*******************************************************************/
void Game::set_hands(){
    for(int i=0;i<7;i++){
        Card a = this->d.draw_from_deck();
        this->players[0].get_card(a);
    }
    for(int j=0;j<7;j++){
        Card b = this->d.draw_from_deck();
        this->players[1].get_card(b);
    }
}


/******************************************************************* 
** Function: player_shows
** Description: This is a function that simply shows the players hand
** Parameters: none
** Pre-conditions: hand creation
** Post-conditions: shows the cards that the player has
*******************************************************************/
void Game::player_shows(){
    cout << endl << "Player hand has..." << endl;
    players[0].get_hand();
}


/******************************************************************* 
** Function: computer_shows
** Description: This is a function that outputs the cards in the computers hand
** Parameters: none 
** Pre-conditions: hand creation of computer
** Post-conditions: shows the cards that the computer has
*******************************************************************/
void Game:: computer_shows(){
    cout << endl << "Computer hand has..." << endl;
    players[1].get_hand();
}


/******************************************************************* 
** Function: check_if_empty
** Description: check if both the players hands are empty and if so draw a card from the deck
** Parameters: none 
** Pre-conditions: num_cards
** Post-conditions: draw a card from the deck
*******************************************************************/
void Game:: check_if_empty(){
    if(players[0].retrieve_num_cards()<1){
        cout << "THE HAND IS EMPTY SO YOU DREW A CARD-------------------" << endl;
        Card h;
        h = d.draw_from_deck();
        players[0].get_card(h);
        player_shows();
    }
    if(players[1].retrieve_num_cards()<1){
        cout << "THE HAND IS EMPTY SO COMPUTER DREW A CARD---------------" << endl;
        Card g;
        g = d.draw_from_deck();
        players[1].get_card(g);
        computer_shows();
    }
}


/******************************************************************* 
** Function: check_book
** Description: this will check if there any books in the players hand
** Parameters: int arraycount, int book, int player 
** Pre-conditions: array and book and player
** Post-conditions: outputs the books that the players have
*******************************************************************/
void Game:: check_book(int arraycount, int book, int player){
        if(player ==0){
            cout << "The rank of books that you currently have are... " << endl;
        }
        if(player==1){
            cout << "The rank of books that the computer currently has are..." << endl;
        }
        for (int j=0; j<arraycount;j++ ){
            cout << "Rank " << players[player].print_book(j) << endl << endl << endl;
        }
}


/******************************************************************* 
** Function: print_all_books
** Description: prints all the books that the player has at the end of the game
** Parameters: int arraycount, int book, int computerarraycount, int computerbook 
** Pre-conditions: books, array, hand
** Post-conditions: outputs all the books that are made
*******************************************************************/
void Game:: print_all_books(int arraycount, int book, int computerarraycount, int computerbook){
    cout << "The rank of books that you had are: " << endl;
    for(int i=0; i<arraycount; i++){
        cout << "Rank " << players[0].print_book(i) << endl;
    }

    cout << "The rank of books the computer had are: " << endl;
    for(int j=0; j<computerarraycount;j++){
        cout << "Rank " << players[1].print_book(j) << endl;
    }
}


/******************************************************************* 
** Function: player_turn
** Description: this is the function for the player turn
** Parameters: int arraycount, int book, int numberofbooks 
** Pre-conditions: variable declarations
** Post-conditions: does the whole player turn
*******************************************************************/
void Game::player_turn(int &arraycount, int &book, int&numberofbooks){
    bool turnover = 0;
    int rank;

        check_if_empty();
        rank = players[0].error_player();
        int count;
        count = players[1].check_playerhand(rank);
        cout << "The amount of cards the computer has is: " << count << endl;
        turnover == 1;
        
        if(count>0){
            for(int i=0; i<players[1].retrieve_num_cards(); i++){
                
                Card c = players[1].retrieve_card(rank,i);
                    if(c.get_rank() == rank){
                        players[0].get_card(c);
                    }
            }
            players[1].delete_card(rank);
        }
            else if(count == 0){
                cout << "Go FISH!!! " << endl;
                Card a = d.draw_from_deck();
                players[0].get_card(a);
                if(a.get_rank() == rank){
                    turnover =0;
                }
            }
        
        cout << endl << endl << "arraycount = " << arraycount << " book = " << book << endl;
        check_book(arraycount, book, 0);
        book = players[0].get_book(arraycount);
        if(book>0){
            players[0].delete_card(book);
        }
}


/******************************************************************* 
** Function: computer_turn
** Description: This is a function that allows the computer to do its turn
** Parameters: int computerarraycount, computerbook, numberofbooks 
** Pre-conditions: variable declarations 
** Post-conditions: does the entire computer turn in this function
*******************************************************************/
void Game::computer_turn(int& computerarraycount, int& computerbook, int& numberofbooks){
    srand(time(NULL));
    bool turnover = 0;
    int rank = 0;
    int playerrank=0;
    int playercount =0;
    int computercount = 0;
        
        check_if_empty();
        int i =1;
        for(i; i<14; i++){
            playercount = players[0].check_playerhand(i);
            computercount = players[1].check_playerhand(i);
            //cout << playercount << computercount << endl;
            
            if((playercount >0) && (computercount > 0)){
                rank = i;
                break;
            }
        }

        if (rank == 0){
            while( rank == 0){
                int temp;
                temp = rand()%13;

                if (players[1].check_playerhand(temp)>0){
                    rank = temp;
                    playercount = 0;
                }
            }
        }
        
        cout << endl << endl << "The rank the computer chose was... " << rank << endl;
        cout << "The amount of cards that you have are: " << playercount << endl;
        if(playercount >0){
            for(int i=0; i<players[0].retrieve_num_cards(); i++){      
                Card a = players[0].retrieve_card(rank,i);
                    if(a.get_rank() == rank){
                        players[1].get_card(a);
                    }
            }
            players[0].delete_card(rank);
        }
            else if(playercount == 0){
                cout << "The computer has to GO FISH!!" << endl;
                Card a = d.draw_from_deck();
                players[1].get_card(a);
            }
        //cout << endl << endl << "computerarraycount = " << computerarraycount << " computerbook = " << computerbook << endl;
        check_book(computerarraycount, computerbook, 1);
        computerbook = players[1].get_book(computerarraycount);
        if(computerbook>0){
            players[1].delete_card(computerbook);
        }
    
}


/******************************************************************* 
** Function: get_numberofbooks
** Description: this is a accessor 
** Parameters: none 
** Pre-conditions: numberofbooks in player
** Post-conditions:returns the numberofbooks of player0
*******************************************************************/
int Game::get_numberofbooks(){
    return this-> players[0].get_nbooks();
}