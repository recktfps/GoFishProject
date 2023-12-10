#ifndef GOFISHGAME_H
#define GOFISHGAME_H

#include "Account.h"
#include "Mode.h"
#include "PlayByPlay.h"
#include "Player.h"
#include "PlayerProfile.h"
#include "Deck.h"
#include "Card.h"

#include <iostream>
#include <string>

class Account;

class GoFishGame{
    public:
    //Will store the amount of games played/started
    GoFishGame(int GameCount);
    //Will prompt the user to enter a menu selection
    //Will ask for amount of players
    void start();
    int GetGamesPlayed() const;


    private:
    int Game;
    Account* Deck;
    Player players[4]; // Assuming a maximum of 4 players
    int currentPlayerIndex; // Index of the current player
    bool gameOver;

    void displayGameStatus();
    void playerTurn();
    void processPlayerMove(Player& currentPlayer, Player& otherPlayer, int rank);
    bool checkForMatches(Player& currentPlayer);
    void drawCard(Player& currentPlayer);
};
#endif
