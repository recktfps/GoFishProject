#include "Account.h"
#include "GoFishGame.h"
#include "Mode.h"
#include "PlayByPlay.h"
#include "Player.h"
#include "PlayerProfile.h"
#include "Deck.h"

#include <iostream>
#include <string>

Mode::Mode(){
    string GameMode = "not selected";
    TwoPlayerGoFish = "TwoPlayerGoFish";
    ThreePlayerGoFish = "ThreePlayerGoFish";
    FourPlayerGoFish = "ThreePlayerGoFish";
}

void Mode::assignGameMode(int selection){ //Function that will change the gamemode based on user selection
    if (selection == 2){
        GameMode = TwoPlayerGoFish;
    }
    else if(selection == 3){
        GameMode = ThreePlayerGoFish;
    }
    else if(selection == 4){
        GameMode = FourPlayerGoFish;
    }
}
