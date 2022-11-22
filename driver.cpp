
/******************************************************************* ** 
** Program: assignment4.cpp
** Author: Kaushik Dontula
** Date: 10/23/2022
** Description: This program simulates a game of go fish
** Input: all class files
** Output: gofish game 
*******************************************************************/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>

#include "card.h"
#include "deck.h"
#include "hand.h"
#include "player.h"
#include "game.h"

using namespace std;






int main(){
     int play =0;
     do{
          int numberofbooks=0;
          int arraycount=0;
          int book =0;
          int computerarraycount =0;
          int computerbook =0;
          int cheatmode;
          Game gofish;

          cout << "Do you want to play in cheat mode? (0-no 1-yes): ";
          cin >> cheatmode;

          gofish.set_hands();
          if(cheatmode == 1){
                    gofish.player_shows();
                    gofish.computer_shows();
               do{
                    numberofbooks = gofish.game_over();
                    gofish.player_shows();
                    gofish.player_turn(arraycount, book, numberofbooks);
                    gofish.player_shows();
                    if(gofish.game_over() == 1){
                         break;
                    }
                    gofish.computer_shows();
                    gofish.computer_turn(computerarraycount, computerbook, numberofbooks);
                    gofish.computer_shows();

               }while(gofish.game_over() == 0);
          }

          if(cheatmode == 0){
               do{
                    gofish.player_shows();
                    gofish.player_turn(arraycount, book, numberofbooks);
                    gofish.player_shows();
                    if(gofish.game_over() == 1){
                         break;
                    }
                    gofish.computer_turn(computerarraycount, computerbook, numberofbooks);
               }while(gofish.game_over() == 0);
          }

          gofish.print_all_books(arraycount, book, computerarraycount, computerbook);
               if (computerarraycount>arraycount){
                    cout << endl << endl << endl<<  "THE  COMPUTER  WINS!!!!!" << endl << endl;
               }
                    else if(arraycount>computerarraycount){
                         cout << endl << endl << endl << "YOU WIN!!!!!" << endl << endl;
                    }
          cout << "Do you want to play again? (0-no 1-yes)";
          cin >> play;
     }while(play ==1);
     
     return 0;
}