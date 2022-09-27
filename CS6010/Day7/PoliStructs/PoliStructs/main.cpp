//
//  main.cpp
//  PoliStructs
//
//  Created by Jinny on 2022/8/30.
//

#include <iostream>
#include "MyProgram.hpp"
#include <vector>
using namespace std;

int main() {

    Politician Adam{"Adam", "republican", "state", "javacans"};
    Politician Ben{"Ben", "republican", "federal", "javacans"};
    Politician Cyan{"Cyan", "democratic", "federal", "cplusers"};
    Politician Dav{"Dav", "depublican", "state", "cplusers"};
    
    vector<Politician> politiciansList;
    politiciansList.push_back(Adam);
    politiciansList.push_back(Ben);
    politiciansList.push_back(Cyan);
    politiciansList.push_back(Dav);

    vector<Politician> javacansList = Javacans(politiciansList);
    vector<Politician> cplusersList = Cplusers(politiciansList);
    
    assert(javacansList[0].name == "Adam");
    assert(javacansList[1].name == "Ben");
    assert(cplusersList[0].name == "Cyan");
    
    return 0;
}
