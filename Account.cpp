
#include "GoFishGame.h"
#include "Account.h"
#include "Mode.h"
#include "PlayByPlay.h"
#include "Player.h"
#include "PlayerProfile.h"
#include "Deck.h"
#include "Card.h"

//Other includes
#include <iostream>
#include <cstdlib>
#include <vector>


class Card;
class Deck;

Account::Account(){ //Constructor for Account which creates a new array of the total amount of cards
    numCards = 0;//num cards indicates how many cards have been pulled from the deck
    /*
    vector<Card> numCardsP1;
    vector<Card> numCardsP2;
    vector<Card> numCardsP3;
    vector<Card> numCardsP4;
    */
    cards = new Card[52];
    numCardsP1.clear();
    numCardsP2.clear();

}


Account::~Account(){ //Destructor for Account
  delete[] cards;
}

void Account::addCard(Card card, int PlayerCardPos) {
        if(PlayerCardPos == 0){
            if (numCards < 52) {
                //numCardsP1[numCards] = card;
                numCardsP1.push_back(card);
                numCards++;
                //std::sort(cards, cards + numCards); //Just a sort function
            } else {
                // Handle the case where the player's hand is full
                std::cerr << "They are no more cards in the deck" << std::endl;
            }
        }else{
            if (numCards < 52) {
                //numCardsP2[numCards] = card;
                numCardsP2.push_back(card);
                numCards++;
                //std::sort(cards, cards + numCards);
            } else {
                // Handle the case where the player's hand is full
                std::cerr << "They are no more cards in the deck" << std::endl;
            }
        }
    }

Card Account::removeCard(char rank, char suit){
    Card removedCard;
    int cardIndex = -1; //will only remove card if card of asked rank if found. if its found cardIndex is replaced with card that is getting removed. If not cardIndex is -1 which is a invalid index so no card is removed.

    for (int i =0; i<numCards; i++){ //Loop that finds card of the same rank
        if (cards[i].getRank() == rank and cards[i].getSuit() == suit){
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
    for (int i =0; i < numCards; i++){
        if (cards[i].getRank() == rank){
            //return true;
        }
    }
    return false;
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

void Account::printHand(int PlayerCardPos){
    if (PlayerCardPos == 0){
        for (int i = 0; i < numCardsP1.size(); i++){ //Goes through every card in hand and prints rank/suit of each card
            std::cout << numCardsP1[i].getRank() << numCardsP1[i].getSuit() << std::endl;
        }
    }else{
        for (int i = 0; i < numCardsP2.size(); i++){ //Goes through every card in hand and prints rank/suit of each card
            std::cout << numCardsP2[i].getRank() << numCardsP2[i].getSuit() << std::endl;
        }
    }
}

string Account::GrabSpecificcard(){
    string SpecificCard;
    cout << "Please Pick one of the following Cards From your Deck" << endl;
    for(int i = 0; i < numCardsP1.size();i++){
        cout << i+1 <<" : " << numCardsP1[i].getRank() << numCardsP1[i].getSuit() << endl;
    }
    int ChosenCard;
    cout << "Enter Number: ";
    cin >> ChosenCard;
    //Allow it to go to 0
    ChosenCard-=1;
    char temp1 = numCardsP1[ChosenCard].getRank();
    char temp2 = numCardsP1[ChosenCard].getSuit();
    SpecificCard += temp1;
    SpecificCard += temp2;
    return SpecificCard;
}
//Function used for bots
string Account::GrabRandomCard(){
    int lower_limit = 0;
    int upper_limit = numCardsP2.size();

    // Generate a random number using a for loop (in this case, the loop runs only once)
    int random_index;
    for (int i = 0; i < 1; ++i) {
        random_index = std::rand() % (upper_limit - lower_limit + 1) + lower_limit;
    }
    char temp1 = numCardsP2[random_index].getRank();
    char temp2 = numCardsP2[random_index].getSuit();
    //Will return a random card for the bot
    //cout << "This is the random card that was grabbed for the bot " << temp1 << temp2 << endl;
    string RandomCard = "";
    RandomCard += temp1;
    RandomCard += temp2;
    return RandomCard;
    
}
void Account::TransferCard(int PlayerGain, int PlayerLose, int PLayerLoseCardPosition){
    if(PlayerGain == 0 and PlayerLose == 1){
        /*
        //transfer card to player if other player had the card they asked for
        cout << "The following card has been transfered from Player2 to Player1: " << numCardsP2[PLayerLoseCardPosition] << endl;
        numCardsP1.push_back(numCardsP2[PLayerLoseCardPosition]);
        numCardsP2.erase(numCardsP2.begin() + PLayerLoseCardPosition);
        //Should remove the card
        //numCardsP2.erase(numCardsP2.begin() + PLayerLoseCardPosition);
        */

        //cout << "-------------This is where card transfer for player1 to player2 occurs--------------------" << endl;
        //transfer card to player if other player had the card they asked for
        cout << "The following card has been transfered from Player1 to Player2: " << numCardsP1[PLayerLoseCardPosition] << endl;
        numCardsP2.push_back(numCardsP1[PLayerLoseCardPosition]);
        //Should remove the card
        numCardsP1.erase(numCardsP1.begin() + PLayerLoseCardPosition);
        //Should remove the card
        //numCardsP1.erase(numCardsP1.begin() + PLayerLoseCardPosition);
    }else{
        /*
        //cout << "-------------This is where card transfer for player1 to player2 occurs--------------------" << endl;
        //transfer card to player if other player had the card they asked for
        cout << "The following card has been transfered from Player1 to Player2: " << numCardsP1[PLayerLoseCardPosition] << endl;
        numCardsP2.push_back(numCardsP1[PLayerLoseCardPosition]);
        //Should remove the card
        numCardsP1.erase(numCardsP1.begin() + PLayerLoseCardPosition);
        //Should remove the card
        //numCardsP1.erase(numCardsP1.begin() + PLayerLoseCardPosition);
        */
        //transfer card to player if other player had the card they asked for
        cout << "The following card has been transfered from Player2 to Player1: " << numCardsP2[PLayerLoseCardPosition] << endl;
        numCardsP1.push_back(numCardsP2[PLayerLoseCardPosition]);
        numCardsP2.erase(numCardsP2.begin() + PLayerLoseCardPosition);
        //Should remove the card
        //numCardsP2.erase(numCardsP2.begin() + PLayerLoseCardPosition);
    }
}

void Account::SortHand(int PlayerPosition){
    if(PlayerPosition == 0){
        std::sort(numCardsP1.begin(), numCardsP1.end());
    } else{
        std::sort(numCardsP2.begin(), numCardsP2.end());
    }
}

//Not completly correct, needs to
bool Account::CheckForBooks(int PlayerPosition){
    if(PlayerPosition == 0){
        for (size_t i = 0; i < numCardsP1.size() - 3; ++i) {
            if (numCardsP1[i].getRank() == numCardsP1[i + 1].getRank() &&
                numCardsP1[i].getRank() == numCardsP1[i + 2].getRank() &&
                numCardsP1[i].getRank() == numCardsP1[i + 3].getRank()) {
                // Found four consecutive characters, return true
                std::cout << "Book Found, the rank was: " << numCardsP1[i].getRank() << "'s" << std::endl;

                // Remove those characters from the vector
                numCardsP1.erase(numCardsP1.begin() + i, numCardsP1.begin() + i + 4);

                return true;
            }
        }
        return false;
    } else{
        for (size_t i = 0; i < numCardsP2.size() - 3; ++i) {
            if (numCardsP2[i].getRank() == numCardsP2[i + 1].getRank() &&
                numCardsP2[i].getRank() == numCardsP2[i + 2].getRank() &&
                numCardsP2[i].getRank() == numCardsP2[i + 3].getRank()) {
                // Found four consecutive characters, return true
                std::cout << "Book Found, the rank was: " << numCardsP2[i].getRank() << "'s" << std::endl;

                // Remove those characters from the vector
                numCardsP2.erase(numCardsP2.begin() + i, numCardsP2.begin() + i + 4);

                return true;
            }
        }
        return false;
    }
}

int Account::getCardCount(int PlayerPosition){ //Outputs int of total cards in hand
    if(PlayerPosition == 0){
        return numCardsP1.size();
    }else{
        return numCardsP2.size();
    }
}


Card Account::getCards(){ //Function that returns cards in the players hand
    return *cards;
}

Deck* Account::printDeck(){//more for testing purpose but need something to print the amount of cards in the Dec
    return GameDeck->instance();
}


void Account::IncrementHand(int increment){
    numCards = increment + numCards;
}

