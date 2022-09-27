//
//  main.cpp
//  Palindromes
//
//  Created by Jinny on 2022/8/26.
//

// PALINDROMES OR NOT//////

#include <iostream>
using namespace std;

int main() {
   
    string inputString;
    string reversed;
    
    cout << "Enter a word: \n";
    cin >> inputString;
    
    for ( int i = 0 ; i < inputString.length() ; i++ ){
        reversed += inputString[ inputString.length() -1-i  ];
    }

    // compare two strings
    if ( inputString == reversed ){
        cout << inputString << " is a palindrome. \n";
    }
    else{
        cout << inputString << " is NOT a palindrome. \n";
    }

    return 0;
}
