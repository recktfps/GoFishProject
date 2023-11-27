#include "Account.h"
#include "GoFishGame.h"
#include "Mode.h"
#include "PlayByPlay.h"
#include "Player.h"
#include "PlayerProfile.h"
#include "Deck.h"

#include <iostream>
#include <string>

using namespace std;

GoFishGame::GoFishGame(){
}

string Menuchoice();
void menu();
bool ValidMenu(string i);
void MenuLines();

void GoFishGame::start(){
    MenuLines();
    string a = Menuchoice();
    //change mode to Human vs Computer
    if(a == "1"){

    }
    //change mode to Human vs Computer vs Computer
    if(a == "2"){

    }
    //change mode to Human vs Computer vs Computer vs Computer
    if(a == "3"){

    }





}

//Will loop until the user does a valid input
string Menuchoice(){
    menu();
    string MenuChoice;
    cin >> MenuChoice;
    while(!ValidMenu(MenuChoice)){
        cout << "Not a valid choice" << endl;
        cout << "Input a valid input : ";
        cin >> MenuChoice;
    }
    return MenuChoice;
}
//Displays the avaliable options
void menu(){
    cout << "Select the following game mode" << endl;
    cout << "1. Human vs Computer" << endl;
    cout << "2. Human vs Computer vs Computer" << endl;
    cout << "3. Human vs Computer vs Computer vs Computer" << endl;
    cout << "Enter : ";
}
//Returns true if the user does a valid input
bool ValidMenu(string i){
    return i == "1" || i == "2" || i == "3" || i == "4" || i == "5";
}
//Just visual effect to make it easier read instances in the terminal
void MenuLines(){
    cout << "-----------------------------------------------------------------------" << endl;
}