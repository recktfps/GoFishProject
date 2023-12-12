
#include "GoFishGame.h"
#include "Mode.h"
#include "PlayByPlay.h"
#include "Player.h"
#include "PlayerProfile.h"
#include "Account.h"
#include "Deck.h"
#include "Card.h"

#include <iostream>
#include <string>
#include <cstdlib>


using namespace std;

class Account;
class Player;
GoFishGame::GoFishGame(int GameCount){
    Game = GameCount;
}

int GoFishGame::GetGamesPlayed() const{
    return Game;
}
//Function prototypes
string MenuChoice();
void menu();
bool ValidMenu(string i);
void MenuLines();
void Game2Players(Player& Human, Player& Computer);
int RandomNumber(int Players);


//Should move all the menu, gamemode to the mode file since mode is currently empty.
void GoFishGame::start(){
    currentPlayerIndex = 0;
    MenuLines();
    string a = MenuChoice();
    //change mode to Human vs Computer
    if(a == "1"){
        //Human Player Generation
        
    }
    //change mode to Human vs Computer vs Computer
    if(a == "2"){

    }
    //change mode to Human vs Computer vs Computer vs Computer
    if(a == "3"){

    }
    //Will be used for testing purpose
    if(a == "4"){
        //Test for player Named Generation
        
        Account* PlayingDeck;
        PlayingDeck = new Account();
        Player P1(true, PlayingDeck);
        Player P2(false, PlayingDeck);
        Game2Players(P1, P2);

    }





}

//Will loop until the user does a valid input
string MenuChoice(){
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
//Displays the available options
void menu(){
    cout << "Select the following game mode" << endl;
    cout << "1. Human vs Computer" << endl;
    cout << "2. Human vs Computer vs Computer" << endl;
    cout << "3. Human vs Computer vs Computer vs Computer" << endl;
    cout << "4. Testing" << endl;
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

/*
void GoFishGame::playerTurn() {
    cout << "Player " << currentPlayerIndex + 1 << "'s turn." << endl;
    processPlayerMove(currentPlayer, otherPlayer, rank);
    if (currentPlayer.getHandSize() == 0) {
        gameOver = true;
        // Determine the winner
        // Update statistics
        cout << "Player " << currentPlayerIndex + 1 << " has no cards left. Game over!" << endl;
    }

    // Move to the next player
    currentPlayerIndex = (currentPlayerIndex + 1) % 4;
   
}
*/
void GoFishGame::processPlayerMove(Player& currentPlayer, Player& otherPlayer, int rank) {
    // Process the player's move, check for matches, what have you
}

bool GoFishGame::checkForMatches(Player& currentPlayer) {
    // Check if the player has a matching set of cards
    // If yes, remove those cards and return true, else return false
    return false;
}

void GoFishGame::drawCard(Player& currentPlayer) {
    // Draw a card from the deck and add it to the current player's hand
}

void Game2Players(Player& Human, Player& Computer){

    //Current Deck that will be played with 
    //Deck CurrentDeck;

    //Storing Players into an array for easy access
    
    Player Gamer[2] = {Human, Computer};

    //Generation for Which Player Goes First
    int PlayerChoice = RandomNumber(2);
    if (PlayerChoice == 0){
        cout << "Human Will Start the Game First " << endl;
    } else{
        cout << "Computer Will start the Game First " << endl;
    }
    
    //Bool condition to check if the game is still running
    bool GameFinished = false;
    //Will Start at which ever player was picked first
    int PlayerIndex = PlayerChoice;
    cout << "Working" << endl;
    cout << Gamer[0].PlayingCards->getCardCount() << endl;
    cout << Gamer[1].PlayingCards->getCards() << endl;
    cout << Gamer[1].PlayingCards->getCardCount() << endl;
    //while(!GameFinished){
    //}
}

int RandomNumber(int Players){
    srand(static_cast<unsigned int>(time(nullptr)));
    // Generate a random number between 0 and 1
    int randomNumber = rand() % Players;
    return randomNumber;
}