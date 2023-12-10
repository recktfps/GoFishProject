#include "Account.h"
#include "GoFishGame.h"
#include "Mode.h"
#include "PlayByPlay.h"
#include "Player.h"
#include "PlayerProfile.h"
#include "Deck.h"
#include "Card.h"

#include <iostream>

using namespace std;


int main(){
    //Will indicate how many games have been started/played
    int GameStarted = 1;
    //Then Send into an infinite Loop
    GoFishGame game(GameStarted);
    game.start();
}

