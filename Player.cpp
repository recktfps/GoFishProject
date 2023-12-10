#include "Account.h"
#include "GoFishGame.h"
#include "Mode.h"
#include "PlayByPlay.h"
#include "Player.h"
#include "PlayerProfile.h"
#include "Deck.h"
#include "Card.h"

#include <iostream>
#include <string>

/*
Notes:
So Far the Player Class has the Following Functions
-Player()
    Will create a CPU player and name them BOT
-Player(bool IsHuman)
    Will prompt the user to enter a name and will store that name
-GetPlayerName()
    Will allow us to get the user name and user it for the player profile

*/


//default Constructor will be used to create CPU

Player::Player(){
    Name = "Bot";

}

Player::Player(bool IsHuman){
    //WIll prompt the player to provide a name in order to create their player
    cout << "Please Enter A Name For Your Player: ";
    cin >> Name;

}

string Player::GetPlayerName() const{
    return Name;
}

//Create an object to be able to grab the players hand to show it to the player

//Overload Constructor will be used to create Human Player
