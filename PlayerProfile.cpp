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

//Increment games played by 1
void PlayerProfile::incrementGames() {
    gamesPlayed++;
}

//Increment wins by 1
void PlayerProfile::incrementWins() {
    wins++;
}

//Increment losses by 1
void PlayerProfile::incrementLosses() {
    losses++;
}

//Take bet and subtract it from the players balance
void PlayerProfile::setBet(int insertBet){
    balance = (balance - insertBet);
    bet = insertBet;
}

//
void PlayerProfile::payoutBet(int bet, int completedSets){
    balance = balance + (bet * completedSets);
}

//Getter for wins
float PlayerProfile::getWinPercent() const {
    return (wins/losses);
}

//Getter to get toal of games played
int PlayerProfile::getGamesPlayed() const {
    return gamesPlayed;
}