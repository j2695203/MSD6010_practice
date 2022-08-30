//
//  main.cpp
//  PoliStructs
//
//  Created by Jinny on 2022/8/30.
//

#include <iostream>
#include "MyProgram.hpp"
using namespace std;

int main() {

    Polician Adam{"Adam", "republican", "state", "javacans"};
    Polician Ben{"Ben", "republican", "federal", "javacans"};
    Polician Cyan{"Cyan", "democratic", "federal", "cplusers"};
    Polician Dav{"Dav", "depublican", "state", "cplusers"};
    
    assert(Javacans(Adam));
    assert(!Javacans(Cyan));
    assert(!federalCplusers(Ben));
    assert(!federalCplusers(Dav));
    assert(federalCplusers(Cyan));
    
    return 0;
}
