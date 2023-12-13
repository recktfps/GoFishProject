#ifndef PLAYERPROFILE_H
#define PLAYERPROFILE_H

#include "Account.h"
#include "GoFishGame.h"
#include "Mode.h"
#include "PlayByPlay.h"
#include "Player.h"
#include "Deck.h"

#include <iostream>
#include <string>

using namespace std;

class PlayerProfile{
    public:
    PlayerProfile(); //Default Constructor
    PlayerProfile(const string& Name); //Constructor for PlayerProfile with player's name

    void setName(const string& playerName); //Setter for player name
    string getName() const; //Getter for player name

    void incrementGames(); //Increment total amount of games played by 1
    void incrementWins(); //Increment wins by 1
    void incrementLosses(); //Increment losses by 1

    void setBet(int insertBet); //set users bet and take it out of their balance
    void payoutBet(int bet, int completedSets); //Multiply bet * completed sets and add it to the players balance


    float getWinPercent() const; //Getter to get win percentage
    int getGamesPlayed() const; //Getter to get total of games played


    private:
    string name;
    int gamesPlayed;
    float winPercent;
    int wins;
    int losses;
    int balance;
    int bet;
    int completedSets;
};
#endif