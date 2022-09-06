//
//  myFunc.cpp
//  NumberConverter
//
//  Created by Jinny Jeng on 9/6/22.
//

#include "myFunc.hpp"
#include <math.h>
#include <string>
#include <cctype>
#include <algorithm>
#include <iostream>
using namespace std;

/*
 convert string to integer based on 2, 10, 16 bases
 */
int stringToInt( string stringInput, int base){
    int numericValue = 0;
    int totalValue = 0;
    bool minus = false;
    
    // erase '-' first and record
    if(stringInput[0] == '-'){
        stringInput.erase(0,1);
        minus = true;
    }
    
    // for decimal input
    if (base == 10){
        for (int i = 0; i < stringInput.length(); i++){
            numericValue = stringInput[i]-'0';
            totalValue += numericValue * pow(10, stringInput.length()-i-1);
        }
    }
    // for binary input
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
                cout << "not available input for hexadecimal base \n";
                exit(0);
            }
            totalValue += numericValue * pow(16, stringInput.length()-i-1 );
        }
    }
    // for input other than 2, 10, 16
    else{
        cout << "not available base \n";
        exit(1);
    }
    
    // add minus symbol back
    if (minus){
        return totalValue * -1;
    }
    else{
        return totalValue;
    }
}

/*
 convert integer (decimal) to Decimal string
 */
string intToDecimalString( int numerical){
    string decimalString;
    return ( to_string(numerical) );
}

/*
 convert integer (decimal) to Binary string
 */
string intToBinaryString( int numerical){
    string binaryString;
    bool minus = false;
    if (numerical < 0){
        numerical *= -1;
        minus = true;
    }
    while(numerical > 0){
        if( numerical % 2 == 1){
            binaryString += '1';
        }
        else{
            binaryString += '0';
        }
        numerical /= 2;
    }
    reverse(binaryString.rbegin(),binaryString.rend());
    if ( minus ){
        return ( "-" + binaryString);
    }
    return binaryString;
}

/*
 convert integer (decimal) to Hexadecimal string
 */
string intToHexadecimalString( int numerical){
    string hexString;
    bool minus = false;
    if (numerical < 0){
        numerical *= -1;
        minus = true;
    }
    
    while(numerical > 0){
        if( numerical % 16 >= 0 && numerical % 16 <= 9){
            hexString += to_string(numerical % 16);
        }
        else{
            hexString += char (numerical % 16 - 10 + 'A');
        }
        numerical /= 16;
    }
    reverse(hexString.rbegin(),hexString.rend());
    if ( minus ){
        return ("-" + hexString);
    }
    else{
        return hexString;
    }
}
