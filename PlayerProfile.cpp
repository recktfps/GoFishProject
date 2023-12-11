#include "PlayerProfile.h"


#include <iostream>
#include <string>

//Default Constructor with empty name and 0 wins&losses
PlayerProfile::PlayerProfile() : name(""), wins(0), losses(0) {}

//Constructor for PlayerProfile with player's name
PlayerProfile::PlayerProfile(const string& Name) : name(Name), wins(0), losses(0) {}

//Setter for the player's name
void PlayerProfile::setName(const string& Name) {
    name = Name;
}

//Getter for player name
string PlayerProfile::getName() const {
    return name;
}

//Increment wins by 1
void PlayerProfile::incrementWins() {
    wins++;
}

//Increment losses by 1
void PlayerProfile::incrementLosses() {
    losses++;
}

//Getter for wins
int PlayerProfile::getWins() const {
    return wins;
}

//Getter for losses
int PlayerProfile::getLosses() const {
    return losses;
}