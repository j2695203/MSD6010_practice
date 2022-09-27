//
//  MyProgram.hpp
//  PoliStructs
//
//  Created by Jinny on 2022/8/30.
//

#ifndef MyProgram_hpp
#define MyProgram_hpp

#include <stdio.h>
#include <string>
using namespace std;

struct Politician{
    string name;
    string party; //republican or democratic
    string stateOrFederal; // state or federal
    string JavaOrCplus; //javacans or cplusers
};

vector<Politician> Javacans(vector<Politician>politiciansList);
vector<Politician> Cplusers(vector<Politician>politiciansList);

#endif /* MyProgram_hpp */
