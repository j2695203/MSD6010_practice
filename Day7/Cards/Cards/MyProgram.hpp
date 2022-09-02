//
//  MyProgram.hpp
//  Cards
//
//  Created by Jinny on 2022/8/30.
//

#ifndef MyProgram_hpp
#define MyProgram_hpp

#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

struct Card{
    string suit; // Spd, Hrt, Dmd, Clb
    int num; // 13, 12, ...
    string letter; // K, Q, J, 10, ..., 2, A
};

vector<Card> create();

void printCard(const vector<Card>& card);

void shuffleDeck(vector<Card>& deck);

void swapCard(Card& a, Card& b);

vector<Card> fiveCard(vector<Card> deck);

bool isFlush(const vector<Card>& fiveCard);

bool isStraight(const vector<Card>& fiveCard);

bool isStraightFlush(const vector<Card>& fiveCard);

bool isRoyalFlush(const vector<Card>& fiveCard);

bool isFullHouse(const vector<Card>& fiveCard);

bool minIsAceTen(const vector<Card>& fiveCard);

void sortCard(vector<Card>& fiveCard);

void testStraight(vector<Card>& testCard);
void testFlush(vector<Card>& testCard);
void testFullHouse(vector<Card>& testCard);

#endif /* MyProgram_hpp */

