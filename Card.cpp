#include "Card.h"
#include <algorithm>
#include <string>
#include <iostream>

const std::string suits = "CDHS";
const std::string ranks = "A23456789TJQK";

std::ostream& operator<< (std::ostream& os, const Card& c) {
    os << ranks[c.rank] << suits[c.suit]; // Outputting the card rank and suit
    return os;
}

bool Card::isValid() const {
    return rank > -1; // Check if the card is valid
}

void Card::set(char s, char r) {
    suit = s; // Set the suit of the card
    rank = r; // Set the rank of the card
}

char Card::getRank() const {
    return ranks[rank]; // Get the rank of the card
}

bool Card::operator==(const char o) const {
    return ranks[rank] == o; // Check if the card's rank is equal to a char value
}
