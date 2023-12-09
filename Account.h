#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "Card.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <new>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>     

class Account{
    public:
    Account(); //Constructor
    ~Account(); //Destructor
    void addCard(Card card); //Function to add a card to the account
    Card removeCard(int rank); //Function to remove a card from the account
    bool sameRank(int rank); //Function to check if there are cards of the same rank in the account
    bool checkSet(int rank); //Function to check if a set (four cards of the same rank) exists
    void printHand(); //Function to print the cards in hand
    int getCardCount(); //Function to get the number of cards in hand
    Card* getCards(); //Function to get a pointer to the cards in hand

    private:
    int numCards; //Amount of cards in hand
    Card *cards; //Pointer to array of card in the hand
};
#endif