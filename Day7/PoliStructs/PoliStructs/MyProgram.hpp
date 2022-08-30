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

struct Polician{
    string name;
    string party; //republican or democratic
    string stateOrFederal; // state or federal
    string JavaOrCplus; //javacans or cplusers
};

bool Javacans(Polician policians);

bool federalCplusers(Polician policians);

#endif /* MyProgram_hpp */
