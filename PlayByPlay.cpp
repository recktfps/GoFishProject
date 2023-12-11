#include "Account.h"
#include "GoFishGame.h"
#include "Mode.h"
#include "PlayByPlay.h"
#include "Player.h"
#include "PlayerProfile.h"
#include "Deck.h"

#include <iostream>
#include <string>
#include <fstream>

/*
PlayByPlay should send every single move to an OutFile. From that OutFile we should be able to show the user a previous game play by play.
*/
   ofstream outFile;
    outFile.open("Play_By_Play.txt");

PlayByPlay::PlayByPlay(){

    
}
