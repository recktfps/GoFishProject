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
   //ofstream outFile;
   //outFile.open("Play_By_Play.txt");

class PlayByPlay {
public:
    PlayByPlay(); // Constructor
    ~PlayByPlay(); // Destructor to close the file

    void PlayerTurn(const string& playerName, string& chosenCard, bool& matchFound);
    void DrawCard(const string& playerName, Card& drawnCard);
    // Add a function to log each move
    void LogMove(const string& playerName, const string& moveDescription);

private:
    ofstream outFile; // Member variable for ofstream
};

PlayByPlay::PlayByPlay() {
    outFile.open("Play_By_Play.txt"); // Open the file in the constructor
}

PlayByPlay::~PlayByPlay() {
    outFile.close(); // Close the file in the destructor
}

void PlayByPlay::PlayerTurn(const string& playerName, string& chosenCard, bool& matchFound) {

    // Log the move
    LogMove(playerName, "Player's turn");
}

void PlayByPlay::DrawCard(const string& playerName, Card& drawnCard) {

    // Log the move
    LogMove(playerName, "Drew a card");
}

// Function to log each move to the file
void PlayByPlay::LogMove(const string& playerName, const string& moveDescription) {
    outFile << playerName << ": " << moveDescription << endl;
}
