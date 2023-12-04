#include "Account.h"
#include "GoFishGame.h"
#include "Mode.h"
#include "PlayByPlay.h"
#include "Player.h"
#include "PlayerProfile.h"
#include "Deck.h"

#include <iostream>
#include <string>

using namespace std;

GoFishGame::GoFishGame(){
}

string Menuchoice();
void menu();
bool ValidMenu(string i);
void MenuLines();

void GoFishGame::start(){
    currentPlayerIndex = 0;
    MenuLines();
    string a = Menuchoice();
    //change mode to Human vs Computer
    if(a == "1"){

    }
    //change mode to Human vs Computer vs Computer
    if(a == "2"){

    }
    //change mode to Human vs Computer vs Computer vs Computer
    if(a == "3"){

    }





}

//Will loop until the user does a valid input
string Menuchoice(){
    menu();
    string MenuChoice;
    cin >> MenuChoice;
    while(!ValidMenu(MenuChoice)){
        cout << "Not a valid choice" << endl;
        cout << "Input a valid input : ";
        cin >> MenuChoice;
    }
    return MenuChoice;
}
//Displays the avaliable options
void menu(){
    cout << "Select the following game mode" << endl;
    cout << "1. Human vs Computer" << endl;
    cout << "2. Human vs Computer vs Computer" << endl;
    cout << "3. Human vs Computer vs Computer vs Computer" << endl;
    cout << "Enter : ";
}
//Returns true if the user does a valid input
bool ValidMenu(string i){
    return i == "1" || i == "2" || i == "3" || i == "4" || i == "5";
}
//Just visual effect to make it easier read instances in the terminal
void MenuLines(){
    cout << "-----------------------------------------------------------------------" << endl;
}


void GoFishGame::playerTurn() {
    cout << "Player " << currentPlayerIndex + 1 << "'s turn." << endl;
    processPlayerMove(currentPlayer, otherPlayer);
    if (currentPlayer.getHandSize() == 0) {
        gameOver = true;
        // Determine the winner
        // Update statistics
        cout << "Player " << currentPlayerIndex + 1 << " has no cards left. Game over!" << endl;
    }

    // Move to the next player
    currentPlayerIndex = (currentPlayerIndex + 1) % 4;
   
}

void GoFishGame::processPlayerMove(Player& currentPlayer, Player& otherPlayer) {
    // Process the player's move, check for matches, what have you
}

bool GoFishGame::checkForMatches(Player& currentPlayer) {
    // Check if the player has a matching set of cards
    // If yes, remove those cards and return true, else return false
}

void GoFishGame::drawCard(Player& currentPlayer) {
    // Draw a card from the deck and add it to the curernt player's hand
}



