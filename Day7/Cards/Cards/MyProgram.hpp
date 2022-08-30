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

void printCard(vector<Card>);

#endif /* MyProgram_hpp */
