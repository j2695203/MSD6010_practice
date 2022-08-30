//
//  MyProgram.cpp
//  Cards
//
//  Created by Jinny on 2022/8/30.
//

#include <iostream>
#include "MyProgram.hpp"
#include <vector>
using namespace std;

// create a deck of card and save all representation
vector<Card> create(){
    vector<Card> card;
    vector<string> suit{"Spd","Hrt","Dmd","Clb"};
    vector<string> letter{"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    
    for(string el: suit){
        for( int i = 1; i <= 13; i++){
            card.push_back( (Card) { el, i, letter [i-1] } );
        }
    }
    return card;
}

// print out the cards
void printCard(vector<Card> c){
    for(Card el: c){
        cout << el.suit <<" "<< el.letter << endl;
    }
}

