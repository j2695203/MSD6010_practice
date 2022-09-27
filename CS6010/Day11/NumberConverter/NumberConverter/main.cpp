//
//  main.cpp
//  NumberConverter
//
//  Created by Jinny Jeng on 9/6/22.
//

#include <iostream>
#include "myFunc.hpp"
//using namespace std;

int main() {
    std::string inputString;
    int inputSystem;
    
    // input
    std::cout << "Enter numbers and digit system:\n";
    std::cin >> inputString >> inputSystem;
    int numericalValue = stringToInt(inputString, inputSystem);
    
    // result
    std::cout << "\nConverting result: \n";
    std::cout << " "<< intToDecimalString(numericalValue) << " (decimal)" << "\n";
    std::cout << " "<< intToBinaryString(numericalValue) << " (binary)" << "\n";
    std::cout << " "<< intToHexadecimalString(numericalValue) << " (hexadecimal)" <<"\n";

    return 0;
}
