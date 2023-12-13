#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>

//Was required since the class has to be forward-declared before the deck class. Allows for implementation in the Deck class
class Card;

class Deck {
public:
    static Deck* instance(); //Function to get the instance of the deck
    void destroy(); //Function to delete the instance of the deck
    Card draw(); //Function to draw a card from the deck
    void shuffleDeck(); //Function to shuffle the Deck
    Deck(); //Constructor for the deck
private:
    //Deck(); //Constructor for the deck
    void newDeck(); //Function to create a new deck
    static Deck* inst; //Static pointer to the deck instance
    std::vector<Card> cards; //Vector to store the cards in the deck
};

#endif
