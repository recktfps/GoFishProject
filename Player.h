#ifndef PLAYER_H
#define PLAYER_H

#include "Account.h"
#include "GoFishGame.h"
#include "Mode.h"
#include "PlayByPlay.h"
#include "PlayerProfile.h"
#include "Deck.h"
#include "Card.h"

#include <iostream>
#include <string>

class Account;

class Player{
    public:
    Account* PlayingCards;
    //default Constructor will be used to create CPU
    Player();

    //Player(Account c); 
    //Overload Constructor will be used to create Human Player
    //Will Prompt the user to provide a name
    Player(bool IsHuman,Account* c);
    //Player(bool IsHuman, Account c);
    //Will ask the user to pick a card
    //void PlayerCardSelection();
    std::string GetPlayerName() const;
    int GetNumberBooks() const;
    int SetNumberBooks();
    //std::string Get

    private:
    //Deck PlayersHand;
    //Account GameDeck;
    //Will hold the name of the player to then use for PlayerProfile
    std::string Name;
    int books;
    //Account* PlayingCards;
    //Create a function to prompt the user for a card



};
#endif