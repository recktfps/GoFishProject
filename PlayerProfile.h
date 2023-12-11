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

    void incrementWins(); //Increment wins by 1
    void incrementLosses(); //Increment losses by 1

    int getWins() const; //Getter for wins
    int getLosses() const; //Getter for losses

    private:
    string name;
    int wins;
    int losses;
};
#endif