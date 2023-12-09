#include "Deck.h"
#include <ctime>
#include <cstdlib>
#include <random>
#include <vector>
#include <algorithm>

Deck* Deck::inst = nullptr; //Initializing the static member variable

Deck::Deck() {
    newDeck(); //Constructor initializes a new deck
}

Deck* Deck::instance() {
    if (!inst)
        inst = new Deck(); //Create a new instance if it doesn't exist
    return inst;
}

void Deck::destroy() {
    delete inst; //Delete the instance of the deck
    inst = nullptr; //Reset the pointer to null
}

Card Deck::draw() {
    Card c;
    if (!cards.empty()) {
        c = cards.back(); //Draw the top card from the deck
        cards.pop_back();
        return c;
    }
    c.set(-1, -1); //Return an invalid card if the deck is empty
    return c;
}

void Deck::newDeck() {
    Card c;
    for (char s = 0; s < 4; s++) {
        for (char r = 0; r < 13; r++) {
            c.set(s, r); // Create and set each card's suit and rank
            cards.push_back(c); // Add the card to the deck
        }
    }
    // Shuffle the deck using std::shuffle
    std::random_device rd;
    std::mt19937 g(rd()); // Standard mersenne_twister_engine seeded with rd()
    std::shuffle(cards.begin(), cards.end(), g);
}
