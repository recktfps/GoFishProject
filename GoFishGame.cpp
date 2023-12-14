
#include "GoFishGame.h"
#include "Mode.h"
#include "PlayByPlay.h"
#include "Player.h"
#include "PlayerProfile.h"
#include "Account.h"
#include "Deck.h"
#include "Card.h"

#include <iostream>
#include <string>
#include <cstdlib>


using namespace std;

class Account;
class Player;
class PlayerProfile;
GoFishGame::GoFishGame(int GameCount){
    Game = GameCount;
}

int GoFishGame::GetGamesPlayed() const{
    return Game;
}
//Function prototypes
string MenuChoice();
void menu();
void betMenu();
void statsMenu();
bool ValidMenu(string i);
void MenuLines();
void Game2Players(Player& Human, Player& Computer);
int RandomNumber(int Players);
void RemoveErrors(Player currentPlayer, Player otherPlayer);
//Function to draw cards for players
void DrawCardsForPlayer(Player currentPlayer, int amount, int PlayerPosition);
//Function to print the players hand
void PrintPlayerHand(Player currentPlayer, int PlayerPosition);


//Prototypes for 2 player
int TwoPlayerGoFish(Player& Human, Player& Bot, Player& referencedPlayer);
void DealStartingCards(Player currentplayer, int amount, int PlayerPosition);
int ShowCardCount(Player currentplayer, int PlayerPosition);
bool CompareCards(Player currentplayer, string CurrentPlayerCard, Player otherplayer, int PlayerPosition, int BotOrHuman);
int bet = 0;

//Should move all the menu, gamemode to the mode file since mode is currently empty.
void GoFishGame::start(){
    currentPlayerIndex = 0;
    MenuLines();
    string a = MenuChoice();
    
    //change mode to Human vs Computer
    if(a == "1"){
        cout << "Beginning A Human vs Computer match " << endl;
        //Human Player Generation
        Account* PlayingDeck;
        PlayerProfile* stats;
        PlayingDeck = new Account();
        //Player 1 is a human
        Player Player1(true, PlayingDeck, stats);
        Player* Player1stats = new Player(true, PlayingDeck, stats);
        //Player 2 is a bot
        Player Player2(false, PlayingDeck, stats);
        //asking for bets
        int humanBalance = Player1stats->stats->getBalance();
        cout << "Your Balance is "<<humanBalance<<endl;
        cout <<"How much would you like to bet?"<<endl;
        int userBet = 0;
        cin>> userBet;
        bet = userBet;
        Player1stats->stats->setBet(userBet);


        //Sending to Function to do Game Logic
        Player& referencePlayer = *Player1stats;
        TwoPlayerGoFish(Player1, Player2,referencePlayer);

    }
    //change mode to Human vs Computer vs Computer
    if(a == "2"){

    }
    //change mode to Human vs Computer vs Computer vs Computer
    if(a == "3"){

    }
    //Will be used for testing purpose
    if(a == "4"){
        //Test for player Named Generation
        
        Account* PlayingDeck;
        PlayerProfile* stats;
        PlayingDeck = new Account();
        Player P1(true, PlayingDeck, stats);
        Player P2(false, PlayingDeck, stats);
        Game2Players(P1, P2);
    }





}


int TwoPlayerGoFish(Player& Human, Player& Bot, Player& referencedPlayer){
    Player Gamer[2] = {Human, Bot};

    //Random Number Generation in order to see who goes first
    int WhoGoesFirst = RandomNumber(2);
    cout << "random number generated: " << WhoGoesFirst << endl;
    if (WhoGoesFirst == 0){
        cout << "Player 1(Human) will go first" << endl;
    }else{
        cout << "Player 2(Bot) will go first" << endl;
    }
    //Start the game by dealing cards to both players

    cout << "Dealing Cards to Players" << endl;
        
    //Deal Cards to Human
    DealStartingCards(Gamer[0], 5, 0);

    //Test to see correct card amount
    //ShowCardCount(Gamer[0], 1);
    //Correct 5 cards are dealt


    //Deal Cards to Bot
    DealStartingCards(Gamer[1], 5, 1);

    //Test to see correct card amount
    //ShowCardCount(Gamer[1], 2);
    //Correct 5 cards are dealt


    //Will hold what player will go first and continoulsy be updated by % 2 in order to loop players
    int PlayerIndex = WhoGoesFirst;
    //Bool logic to continue game until it is over.
    //While loop for actual game
    
    //While loop is breaking game need to make it s
    //bool IsGameFinished = false;
    bool AreThereCardsLeft = true;
    while(AreThereCardsLeft){
        cout << "------------------------------------------------------------------------------------------------"<< endl;
        cout << "Amount of Cards Pulled from the Deck: " << Gamer[0].PlayingCards->numCards << endl;
        cout << "Amount of Cards left for " << Gamer[0].GetPlayerName() << " are: " << ShowCardCount(Gamer[0], 0)<<  endl;
        cout << "Amount of Books that " << Gamer[0].GetPlayerName() << " has: " << Gamer[0].GetNumberBooks() << endl;
        cout << "Amount of Cards left for " << Gamer[1].GetPlayerName() << " are: " << ShowCardCount(Gamer[1], 1)<<  endl;
        cout << "Amount of Books that " << Gamer[1].GetPlayerName() << " has: " << Gamer[1].GetNumberBooks() << endl;
        //Start off the game by asking the first player to pick a card from their deck
        cout << Gamer[PlayerIndex].GetPlayerName() << ", please pick a card!" << endl;
        //Will always sort the players when a new turn is started
        Gamer[0].PlayingCards->SortHand(0);
        Gamer[1].PlayingCards->SortHand(1);
        //PlayerIndex should be 0 and int PlayerPosition should be 1
        if(PlayerIndex == 0){
            string HumanCard = Gamer[PlayerIndex].PlayingCards->GrabSpecificcard();
            cout << "The Card you have chosen is " << HumanCard << endl;
            //Now we need to send to see if the other player has the card, if they have it then current player will gain the card
            //Else, the player will draw a card from the deck

            if(CompareCards(Gamer[PlayerIndex], HumanCard, Gamer[PlayerIndex+1], PlayerIndex+1, 1) == true)
            
            {
                //CompareCards will already add the card to this player if found in the other players hand
                while(CompareCards(Gamer[PlayerIndex], HumanCard, Gamer[PlayerIndex+1], PlayerIndex+1, 1) == true){}
            }
            else if(CompareCards(Gamer[PlayerIndex], HumanCard, Gamer[PlayerIndex+1], PlayerIndex+1, 1) == false){
                if(Gamer[0].PlayingCards->numCards < 52){
                    cout << "GoFish! Grabbing a card from the deck. Turn is Over" << endl;
                    DrawCardsForPlayer(Gamer[PlayerIndex], 1, PlayerIndex);
                    AreThereCardsLeft = true;
                } else{
                    cout << "No More cards can be grabbed from the deck!" << endl;
                    AreThereCardsLeft = false;
                }
            }
            //Check to see if the player has books
            if(Gamer[PlayerIndex].PlayingCards->CheckForBooks(PlayerIndex) == true){
                //display that book has been found and increment in one line
                cout << "Congrats! You have found a Book!" << endl;
                Gamer[PlayerIndex].SetNumberBooks();
                //Means that the player has a book
                //Gamer[0].SetNumberBooks();
            }
        }
        //PlayerIndex should be 1 and int PlayerPosition should be 2
        if(PlayerIndex == 1){ //We sorted the players by humans, then bot so if PlayerIndex is 1 then it is a bot
            string BotCard = Gamer[PlayerIndex].PlayingCards->GrabRandomCard();
            cout << Gamer[PlayerIndex].GetPlayerName() << " has chosen the card " << BotCard << endl;

            cout << "The Card you have chosen is " << BotCard << endl;
            //Now we need to send to see if the other player has the card, if they have it then current player will gain the card
            //Else, the player will draw a card from the deck
            if(CompareCards(Gamer[PlayerIndex], BotCard, Gamer[PlayerIndex-1], PlayerIndex, 2) == true){
                //CompareCards will already add the card to this player if found in the other players hand
                while(CompareCards(Gamer[PlayerIndex], BotCard, Gamer[PlayerIndex-1], PlayerIndex, 2) == true){}
            }
            else if(CompareCards(Gamer[PlayerIndex], BotCard, Gamer[PlayerIndex-1], PlayerIndex, 2) == false){
                if(Gamer[1].PlayingCards->numCards < 52){
                    cout << "GoFish! Grabbing a card from the deck. Turn is Over" << endl;
                    DrawCardsForPlayer(Gamer[PlayerIndex], 1, PlayerIndex);
                    AreThereCardsLeft = true;
                } else{
                    cout << "No More cards can be grabbed from the deck!" << endl;
                    AreThereCardsLeft = false;
                }
            }
            //Check to see if the player has books
            if(Gamer[PlayerIndex].PlayingCards->CheckForBooks(PlayerIndex) == true){
                cout << "Congrats! You have found a Book!" << endl;
                //Means that the player has a book
                Gamer[PlayerIndex].SetNumberBooks();
            }
        }
        //Increment PlayerIndex so that next player goes
        PlayerIndex++;
        //One more check for cards just incase they werent fixed inside the if statements
        Gamer[0].PlayingCards->CheckForBooks(1);
        Gamer[1].PlayingCards->CheckForBooks(2);
        //Adjust based on players
        if(PlayerIndex > 1){
            //Reset the playerindex back to zero so that it loop back to player1
            PlayerIndex = 0;
        }
        //Ending game logic is bugged need to find a proper fix
    }
    cout << "This Game of GoFish is officially over!" << endl;
    if(Gamer[0].GetNumberBooks() > Gamer[1].GetNumberBooks()){
        cout << Gamer[0].GetPlayerName() << " has won this game of GoFish, thank you for playing!" << endl;
        //Increment the win counter player1;
        //!Need to do: Increment the win counter for player1
    }else{
        cout << Gamer[1].GetPlayerName() << " has won this game of GoFish, thank you for playing!" << endl;
    }
    int books = Gamer[0].PlayingCards->CheckForBooks(1);
    referencedPlayer.stats->payoutBet(bet,books);
    //Return a 1 to indicate that the game is over
    return 1;
}

//Function to deal the starting cards to the player
void DealStartingCards(Player currentplayer, int amount, int PlayerPosition){
    int StartingCards = amount;
    DrawCardsForPlayer(currentplayer, StartingCards, PlayerPosition);
}

//Function to show card count
int ShowCardCount(Player currentplayer, int PlayerPosition){
    //Will return numerical values of cards
    return currentplayer.PlayingCards->getCardCount(PlayerPosition);
}
//Bool function that will return true if there are cards with the same rank
bool CompareCards(Player currentplayer, string CurrentPlayerCard, Player otherplayer, int PlayerPosition, int BotOrHuman){
    if(BotOrHuman == 1){
        for(int i = 0; i < ShowCardCount(otherplayer, PlayerPosition); i++){
            if(CurrentPlayerCard[0] == otherplayer.PlayingCards->numCardsP2[i].getRank()){
                cout << otherplayer.GetPlayerName() << " has the following card: " <<  otherplayer.PlayingCards->numCardsP2[i].getRank() << otherplayer.PlayingCards->numCardsP2[i].getSuit() << endl;
                currentplayer.PlayingCards->TransferCard(PlayerPosition, PlayerPosition-1,i);
                //currentplayer.PlayingCards->addCard(otherplayer.PlayingCards->numCardsP2[i], PlayerPosition);
                return true;
            }
        }
        return false;
    }else{
        for(int i = 0; i < ShowCardCount(otherplayer, PlayerPosition); i++){
            if(CurrentPlayerCard[0] == otherplayer.PlayingCards->numCardsP1[i].getRank()){
                cout << otherplayer.GetPlayerName() << " has the following card: " <<  otherplayer.PlayingCards->numCardsP1[i].getRank() << otherplayer.PlayingCards->numCardsP1[i].getSuit() << endl;
                currentplayer.PlayingCards->TransferCard(PlayerPosition-1, PlayerPosition,i);
                //currentplayer.PlayingCards->addCard(otherplayer.PlayingCards->numCardsP1[i], PlayerPosition);
                return true;
            }
        }
        return false;        
    }   
}



//Function used to draw cards for the players
void DrawCardsForPlayer(Player currentPlayer, int amount, int PlayerPosition){
    for(int i = 0; i < amount; i++){
        currentPlayer.PlayingCards->addCard(currentPlayer.PlayingCards->printDeck()->draw(), PlayerPosition);
    }
}
//Function to print the players hand
void PrintPlayerHand(Player currentPlayer, int PlayerPosition){
    currentPlayer.PlayingCards->printHand(PlayerPosition);
}


//Will loop until the user does a valid input
string MenuChoice(){
    menu();
    string MenuChoice;
    cin >> MenuChoice;
    while(!ValidMenu(MenuChoice)){
        cout << "Not a valid choice" << endl;
        cout << "Input a valid input : ";
        cin >> MenuChoice;
    }
    return MenuChoice;
}
//Displays the available options
void menu(){
    cout << "Select the following game mode" << endl;
    cout << "1. Human vs Computer" << endl;
    cout << "2. Human vs Computer vs Computer" << endl;
    cout << "3. Human vs Computer vs Computer vs Computer" << endl;
    cout << "4. Testing" << endl;
    cout << "Enter : ";
}


//Returns true if the user does a valid input
bool ValidMenu(string i){
    return i == "1" || i == "2" || i == "3" || i == "4" || i == "5";
}
//Just visual effect to make it easier read instances in the terminal
void MenuLines(){
    cout << "-----------------------------------------------------------------------" << endl;
}

/*
void GoFishGame::playerTurn() {
    cout << "Player " << currentPlayerIndex + 1 << "'s turn." << endl;
    processPlayerMove(currentPlayer, otherPlayer, rank);
    if (currentPlayer.getHandSize() == 0) {
        gameOver = true;
        // Determine the winner
        // Update statistics
        cout << "Player " << currentPlayerIndex + 1 << " has no cards left. Game over!" << endl;
    }

    // Move to the next player
    currentPlayerIndex = (currentPlayerIndex + 1) % 4;
   
}
*/
void GoFishGame::processPlayerMove(Player& currentPlayer, Player& otherPlayer, int rank) {
    // Process the player's move, check for matches, what have you
}

bool GoFishGame::checkForMatches(Player& currentPlayer) {
    // Check if the player has a matching set of cards
    // If yes, remove those cards and return true, else return false
    return false;
}

void GoFishGame::drawCard(Player& currentPlayer) {
    // Draw a card from the deck and add it to the current player's hand
}










void Game2Players(Player& Human, Player& Computer){

    //Current Deck that will be played with 
    //Deck CurrentDeck;

    //Storing Players into an array for easy access
    
    Player Gamer[2] = {Human, Computer};

    //Generation for Which Player Goes First
    /*
    int PlayerChoice = RandomNumber(2);
    if (PlayerChoice == 0){
        cout << "Human Will Start the Game First " << endl;
    } else{
        cout << "Computer Will start the Game First " << endl;
    }
    */
    //Bool condition to check if the game is still running
    //Will Start at which ever player was picked first


    cout << "Player 1 has drawn 5 cards" << endl;
    DrawCardsForPlayer(Gamer[0], 50, 1);
    Gamer[0].PlayingCards->SortHand(1);
    int i = 0;
    while(Gamer[0].PlayingCards->CheckForBooks(1)){
        i++;
    }
    
    Gamer[0].PlayingCards->printHand(1);
    cout << "Books found: "<<i<<endl;
    /*
    //Gamer[0].PlayingCards->printHand(1);
    PrintPlayerHand(Gamer[0], 1);
    ShowCardCount(Gamer[0], 1);
    cout << "The Card You have chosen: "<< Gamer[0].PlayingCards->GrabSpecificcard() << endl;
    cout << "Player 2 has drawn 5 cards" << endl;
    DrawCardsForPlayer(Gamer[1], 5, 2);
    //Gamer[1].PlayingCards->printHand(2);
    //PrintPlayerHand(Gamer[1], 2);
    ShowCardCount(Gamer[1], 2);

    cout << "A random card from the bots hand : "<< Gamer[1].PlayingCards->GrabRandomCard();
    */
}

int RandomNumber(int Players){
    srand(static_cast<unsigned int>(time(nullptr)));
    // Generate a random number between 0 and 1
    int randomNumber = rand() % Players;
    return randomNumber;
}

void RemoveErrors(Player currentPlayer, Player otherPlayer){
    
}
/*
//Function used to draw cards for the players
void DrawCardsForPlayer(Player currentPlayer, int amount, int PlayerPosition){
    for(int i = 0; i < amount; i++){
        currentPlayer.PlayingCards->addCard(currentPlayer.PlayingCards->printDeck()->draw(), PlayerPosition);
    }
}
//Function to print the players hand
void PrintPlayerHand(Player currentPlayer, int PlayerPosition){
    currentPlayer.PlayingCards->printHand(PlayerPosition);
}
*/