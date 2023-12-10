#include "Account.h"
#include "GoFishGame.h"
#include "Mode.h"
#include "PlayByPlay.h"
#include "Player.h"
#include "PlayerProfile.h"
#include "Deck.h"
#include "Card.h"

class Card;
class Deck;

Account::Account(){ //Constructor for Account which creates a new array of the total amount of cards
    numCards = 0;
    cards = new Card[52];
}


Account::~Account(){ //Destructor for Account
  delete[] cards;
}

void Account::addCard(Card card){
    cards[numCards] = card; //Assign the incoming card to the next available index in the array
    this -> numCards++; //Increment the count of cards in the account
    std::sort(cards, cards + numCards); //Sort the cards in the account after adding the new card
}

Card Account::removeCard(int rank){
    Card removedCard;
    int cardIndex = -1; //will only remove card if card of asked rank if found. if its found cardIndex is replaced with card that is getting removed. If not cardIndex is -1 which is a invalid index so no card is removed.

    for (int i =0; i<numCards; i++){ //Loop that finds card of the same rank
        if (cards[i].getRank()== rank){
            cardIndex = i; //Stores index of the card that is the same rank
            break;
        }
    }
    removedCard = cards[cardIndex]; 
    cards[cardIndex].set(100,100); //Setting card rank and suit high so when sorting card is sorted to the end of the array which "marks it for removal"
    std::sort(cards, cards + numCards);
    this->numCards = this -> numCards -1; //Removes last card in our array which was the card we just sorted
    return removedCard; //Returns the card that was removed
}

bool Account::sameRank(int rank){
    for (int i =0; i<numCards; i++){
        if (cards[i].getRank() == rank){
            return true;
        }
    }
}

bool Account::checkSet(int rank){
    int temp = 0;
    for (int i =0; i< numCards; i++){ //Goes through the hand and counts the amount of cards of the same rank
        if (cards[i].getRank() == rank){
            temp++;
        }
    }
    if (temp > 3){ //If the for loop previously counts 3 other cards of the same rank it means there are 4 of the same cards which is a set
        return true; //Returns true if a new set is made
    }
    else{
        return false; //Returns false if no new set is made
    }
}

void Account:: printHand(){
    for (int i =0; i<numCards; i++){ //Goes through every card in hand and prints rank/suit of each card
        std::cout << cards[i].getRank() << cards[i].getSuit() << std::endl;
    }
}

int Account::getCardCount(){ //Outputs int of total cards in hand
    return numCards;
}

Card* Account::getCards(){ //Function that returns cards in the players hand
  return cards;
}

Deck* Account::printDeck(){//more for testing purpose but need something to print the amount of cards in the Dec

}


