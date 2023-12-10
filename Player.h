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
class Player{
    public:
    //default Constructor will be used to create CPU
    Player(); 
    //Overload Constructor will be used to create Human Player
    //Will Prompt the user to provide a name
    Player(bool IsHuman);
    //Will ask the user to pick a card
    //void PlayerCardSelection();
    string GetPlayerName() const;

    private:
    //Deck PlayersHand;
    //Account GameDeck;
    //Will hold the name of the player to then use for PlayerProfile
    string Name;
    //Create a function to prompt the user for a card



};
#endif