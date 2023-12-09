#include "Card.h"
#include <algorithm>
#include <string>

const std::string suits = "CDHS";
const std::string ranks = "A23456789TJQK";

std::ostream& operator<< (std::ostream& os, const Card& c) {
    os << ranks[c.rank] << suits[c.suit]; //Outputting the card rank and suit
    return os;
}

bool Card::isValid() const {
    return rank > -1; //Check if the card is valid
}

void Card::set(char s, char r) {
    suit = s; //Set the suit of the card
    rank = r; //Set the rank of the card
}

char Card::getRank() const {
    return ranks[rank]; //Get the rank of the card
}

char Card::getSuit() const{
    return suits[suit]; //Get suit of the card
}

bool Card::operator==(const Card& other) const {
    return (rank == other.rank); //Compare cards rank
}

bool Card::operator<(const Card& other) const {
    return rank < other.rank; //Compare based on cards rank for sort function in Account.cpp
}