//
//  main.cpp
//  RomanNumerals
//
//  Created by Jinny on 2022/8/26.
//

#include <iostream>
using namespace std;

int main() {
    
    int decimalNum;
    string romanNum;
    
    cout << "Enter decimal number: \n";
    cin >> decimalNum;
    
    if ( decimalNum <= 0){
        cout << "Invalid input \n";
    }
    else{
        while( decimalNum > 0){
            if( decimalNum >= 1000){
                romanNum += "M";
                decimalNum -= 1000;
            }
            else if( decimalNum >= 900){
                romanNum += "CM";
                decimalNum -= 900;
            }
            else if( decimalNum >= 500){
                romanNum += "D";
                decimalNum -= 500;
            }
            else if( decimalNum >= 400){
                romanNum += "CD";
                decimalNum -= 400;
            }
            else if( decimalNum >= 100){
                romanNum += "C";
                decimalNum -= 100;
            }
            else if( decimalNum >= 90){
                romanNum += "XC";
                decimalNum -= 90;
            }
            else if( decimalNum >= 50){
                romanNum += "L";
                decimalNum -= 50;
            }
            else if( decimalNum >= 40){
                romanNum += "XL";
                decimalNum -= 40;
            }
            else if( decimalNum >= 10){
                romanNum += "X";
                decimalNum -= 10;
            }
            else if( decimalNum >= 9){
                romanNum += "IX";
                decimalNum -= 9;
            }
            else if( decimalNum >= 5){
                romanNum += "V";
                decimalNum -= 5;
            }
            else if( decimalNum >= 4){
                romanNum += "IV";
                decimalNum -= 4;
            }
            else{
                romanNum += "I";
                decimalNum -= 1;
            }
        }
        cout << "Roman numeral version: \n" << romanNum + "\n";
    }
    return 0;
}
