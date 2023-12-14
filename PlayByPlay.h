#ifndef PLAYBYPLAY_H
#define PLAYBYPLAY_H

#include "Account.h"
#include "GoFishGame.h"
#include "Mode.h"
#include "Card.h"
#include "Player.h"
#include "PlayerProfile.h"
#include "Deck.h"

#include <iostream>
#include <string>

using namespace std;
class PlayByPlay{
    public:
    PlayByPlay(); // Constructor

    void PlayerTurn(const string& playerName, string& chosenCard, bool& matchFound);
    void DrawCard(const string& playerName, Card& drawnCard); // Modify this line
    void BookFound(const string& playerName);
    void PrintSummary() const;



    private:




};
#endif
