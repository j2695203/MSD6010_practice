//
//  myFunc.cpp
//  NumberConverter
//
//  Created by Jinny Jeng on 9/6/22.
//

#include "myFunc.hpp"
#include <iostream>
#include <math.h>
//#include <string>
//using namespace std;

/*
 convert string to integer based on 2, 10, 16 bases
 */
int stringToInt( std::string stringInput, int base){
    int numericValue;
    int totalValue = 0;
    bool minusCheck = false;
    
    // erase '-' first and record
    if(stringInput[0] == '-'){
        stringInput.erase(0,1);
        minusCheck = true;
    }
    
    // for decimal input (assume user entered a valid number)
    if (base == 10){
        for (int i = 0; i < stringInput.length(); i++){
            numericValue = stringInput[i]-'0';
            totalValue += numericValue * pow(10, stringInput.length()-i-1 );
        }
    }
    // for binary input (assume user entered a valid number)
    else if (base == 2){
        for (int i = 0; i < stringInput.length(); i++){
            numericValue = stringInput[i]-'0';
            totalValue += numericValue * pow(2, stringInput.length()-i-1 );
        }
    }
    // for hexadecimal
    else if (base == 16){
        for (int i = 0; i < stringInput.length(); i++){
            stringInput[i] = tolower(stringInput[i]);
            if ( stringInput[i] >= '0' && stringInput[i] <= '9'){
                numericValue = stringInput[i] - '0';
            }
            else if ( stringInput[i] >= 'a' && stringInput[i] <= 'f' ){
                numericValue = stringInput[i] - 'a' + 10;
            }
            else{
                std::cout << "Not available input for hexadecimal digit. \n";
                exit(0);
            }
            totalValue += numericValue * pow(16, stringInput.length()-i-1 );
        }
    }
    // for base other than 2, 10, 16
    else{
        std::cout << "Not available base. \n";
        exit(1);
    }
    
    // add minus symbol back
    if (minusCheck){
        return totalValue * -1;
    }
    else{
        return totalValue;
    }
}

/*
 convert integer (decimal) to Decimal string
 */
std::string intToDecimalString( int numerical){
    std::string decimalString;
    return ( std::to_string(numerical) );
}

/*
 convert integer (decimal) to Binary string
 */
std::string intToBinaryString( int numerical){
    std::string binaryString;
    // check whether it is negative
    bool minusCheck = false;
    if (numerical < 0){
        minusCheck = true;
    }
    // convert to 0 or 1
    while( abs(numerical) > 0){
        if( abs(numerical) % 2 == 1){
            binaryString = '1' + binaryString;
        }
        else{
            binaryString = '0' + binaryString;
        }
        numerical /= 2;
    }
    // return positve or negative
    if ( minusCheck ){
        return ( "-" + binaryString);
    }
    return binaryString;
}

/*
 convert integer (decimal) to Hexadecimal string
 */
std::string intToHexadecimalString( int numerical){
    std::string hexString;
    // check whether it is negative
    bool minusCheck = false;
    if (numerical < 0){
        minusCheck = true;
    }
    // convertation
    while( abs(numerical) > 0){
        if( abs(numerical) % 16 >= 0 && abs(numerical) % 16 <= 9){
            hexString = std::to_string( abs(numerical) % 16) + hexString;
        }
        else{
            hexString = char ( abs(numerical) % 16 - 10 + 'A') + hexString;
        }
        numerical /= 16;
    }
    // return positive or negative
    if ( minusCheck ){
        return ("-" + hexString);
    }
    else{
        return hexString;
    }
}
