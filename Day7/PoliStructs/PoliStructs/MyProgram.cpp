//
//  MyProgram.cpp
//  PoliStructs
//
//  Created by Jinny on 2022/8/30.
//

#include "MyProgram.hpp"

bool Javacans(Polician policians){
    return (policians.JavaOrCplus == "javacans");
};

bool federalCplusers(Polician policians){
    return(policians.JavaOrCplus == "cplusers" && policians.stateOrFederal == "federal");
};
