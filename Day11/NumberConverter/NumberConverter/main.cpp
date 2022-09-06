//
//  main.cpp
//  NumberConverter
//
//  Created by Jinny Jeng on 9/6/22.
//

#include <iostream>
#include "myFunc.hpp"
#include <math.h>
#include <string>
using namespace std;

int main() {
    int numericalValue;
    numericalValue = stringToInt("F00D",16);
//    cout << numericalValue << "\n";
    cout << intToDecimalString(numericalValue) << " (decimal)" << "\n";
    cout << intToBinaryString(numericalValue) << " (binary)" << "\n";
    cout << intToHexadecimalString(numericalValue) << " (hexadecimal)" <<"\n";

    return 0;
}
