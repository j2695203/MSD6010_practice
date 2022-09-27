//
//  MyProgram.cpp
//  PoliStructs
//
//  Created by Jinny on 2022/8/30.
//

#include "MyProgram.hpp"
#include <vector>
using namespace std;


vector<Politician> Javacans(vector<Politician>politiciansList){
    vector<Politician> javacansList;
    for (Politician el: politiciansList){
        if(el.JavaOrCplus == "javacans"){
            javacansList.push_back(el);
        }
    }
    return javacansList;
}

vector<Politician> Cplusers(vector<Politician>politiciansList){
    vector<Politician> cplusersList;
    for (Politician el: politiciansList){
        if(el.JavaOrCplus == "cplusers" && el.stateOrFederal == "federal"){
            cplusersList.push_back(el);
        }
    }
    return cplusersList;
}
