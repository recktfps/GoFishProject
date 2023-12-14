#ifndef MODE_H
#define MODE_H

#include "Account.h"
#include "GoFishGame.h"
#include "PlayByPlay.h"
#include "Player.h"
#include "PlayerProfile.h"
#include "Deck.h"

#include <iostream>
#include <string>

using namespace std;
class Mode{
    public:
    Mode();
    string GameMode;
    void assignGameMode(int selection); //Function to select the game mode before starting the game

    private:
    string TwoPlayerGoFish;
    string ThreePlayerGoFish;
    string FourPlayerGoFish;
};
#endif