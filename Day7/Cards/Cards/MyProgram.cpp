//
//  MyProgram.cpp
//  Cards
//
//  Created by Jinny on 2022/8/30.
//

#include <iostream>
#include "MyProgram.hpp"
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// create a deck of card and save all representation
vector<Card> create(){
    
    vector<Card> card;
    vector<string> suit{"Spd","Hrt","Dmd","Clb"};
    vector<string> letter{"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    // fill in 3 elements in all card
    for(string el: suit){
        for( int i = 1; i <= 13; i++){
            card.push_back( (Card) { el, i, letter [i-1] } );
        }
    }
    return card;
}

// print out the cards
void printCard(const vector<Card>& c){
    for(Card el: c){
        cout << el.suit <<" "<< el.letter << endl;
    }
}

// shuffle the deck with reference
void shuffleDeck(vector<Card>& deck){
//    srand(time(0));
    for(int i = 0 ; i < 52 ; i++ ){
        int j = rand() % 52;
        swapCard( deck[i] , deck[j]);
    }
}

// swap card
void swapCard(Card& a, Card& b){
    Card temp = a;
    a = b;
    b = temp;
}

// take five cards from deck
vector<Card> fiveCard(vector<Card> deck){
    vector<Card> fiveCard;
    for(int i = 0 ; i < 5 ; i++ ){
        fiveCard.push_back(deck[i]);
    }
    return fiveCard;
}

// whether the 5 cards is flush
bool isFlush(const vector<Card>& fiveCard){
    for(Card el: fiveCard){
        if ( el.suit != fiveCard[0].suit ){
            return false;
        }
    }
    return true;
}

// whether the 5 cards is straight
bool isStraight(const vector<Card>& fiveCard){
    
    if(fiveCard[0].num == 1 && fiveCard[1].num == 10){ // 10-A
        for (int i = 2; i < 5 ; i++){
            if ( fiveCard[i].num != fiveCard[i-1].num +1 ){
                return false;
            }
        }
    }
    else{
        for (int i = 1; i < 5 ; i++){
            if ( fiveCard[i].num != fiveCard[i-1].num +1 ){
                return false;
            }
        }
    }
    return true;
}

// whether the 5 cards is straight flush
bool isStraightFlush(const vector<Card>& fiveCard){
    if( isFlush(fiveCard) && isStraight(fiveCard)){
        return true;
    }
    else{
        return false;
    }
}

// whether the 5 cards is royal flush
bool isRoyalFlush(const vector<Card>& fiveCard){
    if ( isStraightFlush(fiveCard) && minIsAceTen(fiveCard)){
        return true;
    }
    else{
        return false;
    }
}

// check the first two min number is 1 and 10
bool minIsAceTen(const vector<Card>& fiveCard){
    
    if( fiveCard[0].num == 1 && fiveCard[1].num == 10){
        return true;
    }
    else{
        return false;
    }
}

// whether the 5 cards is full house
bool isFullHouse(const vector<Card>& fiveCard){
    
    int numFH1 = fiveCard[0].num;
    int numFH2 = 0;
    int sameCount = 0;
    
    for (Card el:fiveCard){
        if( el.num != numFH1 && numFH2 == 0 ){
            numFH2 = el.num;
        }
        else if( el.num != numFH1 && el.num != numFH2){
            return false;
        }
        else if( el.num == numFH1){
            sameCount ++;
        }
    }
    if (sameCount == 1 || sameCount == 4){
        return false;
    }else{
        return true;
    }
}

void sortCard(vector<Card>& takeCard){
    for (int i = 0; i < 4 ; i++){
        for (int j = i+1 ; j < 5 ; j++){
            if ( takeCard[j].num < takeCard[i].num){
                swap( takeCard[i] , takeCard[j] );
            }
        }
    }
    
//    sort(takeCard.begin(),takeCard.end(),sortRule());
}

// for test
void testStraight(vector<Card>& testCard){
    testCard[0].num = 2;
    testCard[1].num = 3;
    testCard[2].num = 1;
    testCard[3].num = 4;
    testCard[4].num = 5;
}
void testFlush(vector<Card>& testCard){
    string suitTest = "Spd"; // input
    for (Card &el:testCard){
        el.suit = suitTest;
    }
//    testCard[3].suit = "Clb";
}
void testFullHouse(vector<Card>& testCard){
    int numFH1=4; // input
    int numFH2=8; // input
    for (int i = 0 ; i < 3 ; i++){
        testCard[i].num = numFH1;
    }
    for (int i = 3 ; i < 5 ; i++){
        testCard[i].num = numFH2;
    }
}


