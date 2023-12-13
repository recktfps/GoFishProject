#ifndef DECK_H
#define DECK_H

#include "Account.h"
#include "GoFishGame.h"
#include "Mode.h"
#include "PlayByPlay.h"
#include "PlayerProfile.h"
#include "Deck.h"
#include "Card.h"
#include <vector>

//Was required since the class has to be forward-declared before the deck class. Allows for implementation in the Deck class
class Card;

class Deck {
public:
    static Deck* instance(); //Function to get the instance of the deck
    void destroy(); //Function to delete the instance of the deck
    Card draw(); //Function to draw a card from the deck
    Deck(); //Constructor for the deck
    void shuffleDeck();
private:
    //Deck(); //Constructor for the deck
    void newDeck(); //Function to create a new deck
    static Deck* inst; //Static pointer to the deck instance
    std::vector<Card> cards; //Vector to store the cards in the deck
};

#endif
