#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "Card.h"
#include "Deck.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <new>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>    
 
class Card;
class Deck;
class Account{
    public:
    Account(); //Constructor
    ~Account(); //Destructor
    void addCard(Card card, int PlayerCardPos); //Function to add a card to the account
    Card removeCard(char rank, char suit); //Function to remove a card from the account
    bool sameRank(int rank); //Function to check if there are cards of the same rank in the account
    bool checkSet(int rank); //Function to check if a set (four cards of the same rank) exists
    void IncrementHand(int increment);
    void printHand(int PlayerCardPos); //Function to print the cards in hand
    string GrabSpecificcard();
    string GrabRandomCard();
    int getCardCount(int PlayerPosition); //Function to get the number of cards in hand
    //Function to allow transferring of cards between players
    void TransferCard(int PlayerGain,int PlayerLose,int PLayerLoseCardPosition);
    void SortHand(int PlayerPosition);
    //Function to check if player has 4 matching cards
    bool CheckForBooks(int PlayerPosition);
    Card getCards(); //Function to get a pointer to the cards in hand
    Deck* printDeck();
    
    int numCards, CardPos;
    vector<Card> numCardsP1, numCardsP2, numCardsP3, numCardsP4;
    private:
    //int numCards; //Amount of cards in hand

    Card *cards; //Pointer to array of card in the hand
    Deck *GameDeck;
};
#endif