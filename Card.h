#ifndef CARD_H
#define CARD_H

#include <iostream>

class Card {
public:
    //Friend function to overload the << operator for Card objects
    friend std::ostream& operator<< (std::ostream& os, const Card& c);
    
    //Function to check if the card is valid
    bool isValid() const;

    //Function to set the suit and rank of the card
    void set(char s, char r);

    //Function to get the rank of the card
    char getRank() const;

    //Function to get the suit of the card
    char getSuit() const;

    //Overloading the equality operator to compare a card's rank
    bool operator==(const Card& other) const;

    //Overloading operator to allow sort in Account Class
    bool operator<(const Card& other) const;

private:
    char suit, rank; //Private member variables for suit and rank of the card
};

#endif 
