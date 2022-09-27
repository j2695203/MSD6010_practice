//
//  main.cpp
//  Poker
//
//  Created by Jinny on 2022/8/30.
//
/*
 < MY RECORD >
 Times: 1,000,000
 Royal Flush:  3 (0.0003%)
 Straight Flush: 12 (0.0012%)
 Full House:  1428 (0.1428%)
 Flush:  1971 (0.1971%)
 Straight:  3876 (0.3876%)
 */

#include <iostream>
#include "MyProgram.hpp"

int main() {

    vector<Card> newDeck;
    vector<Card> takeCard;
    int countFlush = 0;
    int countStraight = 0;
    int countStraightFlush = 0;
    int countRoyalFlush = 0;
    int countFullHouse = 0;
    
    newDeck=create(); // create a deck of card
    
    for (int i = 0; i < 1000000; i++){
        
        shuffleDeck(newDeck); // shuffle card
        takeCard=fiveCard(newDeck); // take 5 cards
        sortCard(takeCard);

        if (isRoyalFlush(takeCard)){
            countRoyalFlush++;
        }
        else if (isStraightFlush(takeCard)){
            countStraightFlush++;
        }
        else if (isFullHouse(takeCard)){
            countFullHouse++;
        }
        else if (isFlush(takeCard)){
            countFlush++;
        }
        else if (isStraight(takeCard)){
            countStraight++;
        }
    }

    // result
    cout << "Royal Flush:  " << countRoyalFlush << endl;
    cout << "Straight Flush: " << countStraightFlush << endl;
    cout << "Full House:  " << countFullHouse  << endl;
    cout << "Flush:  " << countFlush << endl;
    cout << "Straight:  " << countStraight << endl;
    
    return 0;
}

